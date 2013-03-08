library(Rython)

script <- '
def test_Rython1(argv1):
    print argv1
    return argv1
'

py(script)
temp <- capture.output({
  stopifnot(all.equal(letters, pyfun("test_Rython1", letters)))
}, file=NULL)
stopifnot(all.equal(temp, letters))