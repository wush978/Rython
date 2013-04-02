library(Rython)

script <- '
def test_Rython1(argv):
    print argv
    return argv
'

py(script)
pyfun("test_Rython1", letters)

temp <- capture.output({
  stopifnot(all.equal(letters, pyfun("test_Rython1", letters)))
}, file=NULL)
stopifnot(all.equal(temp, "['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']"))
