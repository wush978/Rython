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
