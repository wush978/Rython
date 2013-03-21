#'@title Execute python script
#'
#'@param script Python Script
#'@examples
#'library(Rython)
#'py("import sys")
#'py("def test_fun(src):\n    print src\n    return src\n") # define test_fun in python
#'@export
py <- function(script) {
  script <- as.character(script)
  for(i in 1:length(script)) {
    .Call("Rython__run", script[i])
  }
}

#'@title Call python function
#'
#'@param fun_name the name of function object in python
#'@param argv A character vector which will be converted to list of string in python and send to the called function
#'@param module the module where the function exists
#'@examples
#'library(Rython)
#'py("def test_fun(src):\n    print src\n    return src\n") # define test_fun in python
#'pyfun("test_fun", letters)
#'@export
pyfun <- function(fun_name, argv, module = "__main__") {
  if (! class(argv) %in% c("character", "list")) stop("invalid type")
  .Call("Rython__call", module, as.character(fun_name)[1], argv)
}