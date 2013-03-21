library(Rython)

script <- '
def test_Rython1(argv):
    print argv
    return ["a","b"]
'

py(script)
pyfun("test_Rython1", letters)
pyfun("test_Rython1", list(letters, letters))

# temp <- capture.output({
#   stopifnot(all.equal(letters, pyfun("test_Rython1", letters)))
# }, file=NULL)
# stopifnot(all.equal(temp, letters))