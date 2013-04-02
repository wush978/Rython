library(Rython)

for(i in 1:100) {
  a <- 1:10L
  stopifnot(class(a) == "integer")
  b <- pylong(a)
  rm(b)
  gc()
}
for(i in 1:100) {
  a <- rnorm(10)
  stopifnot(class(a) == "numeric")
  b <- pyfloat(a)
  rm(b)
  gc()
}
for(i in 1:100) {
  a <- sample(c(TRUE, FALSE), 10, TRUE)
  stopifnot(class(a) == "logical")
  b <- pybool(a)
  rm(b)
  gc()
}
for(i in 1:100) {
  a <- sample(letters, 10, TRUE)
  stopifnot(class(a) == "character")
  b <- pystr(a)
  rm(b)
  gc()
}

py("import urllib")
urllib.urlencode <- pyobj("urllib", "urlencode")

py("
def test_fun(*args):
    for arg in args:
        print 'another arg:', arg
    return arg
")

test_fun <- pyobj("", "test_fun")
gc()
temp <- capture.output(temp2 <- pycall(test_fun, pylong(1:10L), pystr(letters)))
stopifnot(length(temp) == 2)
stopifnot(temp[1] == "another arg: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]")
stopifnot(temp[2] == "another arg: ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']")
stopifnot(class(temp2) == "externalptr")

result <- pywrap(temp2)
stopifnot(class(result) == "list")
stopifnot(all.equal(unlist(result), letters))
result <- pywrap(temp2, FALSE)
stopifnot(all.equal(result, letters))
