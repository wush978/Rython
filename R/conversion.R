#'@export
pydict <- function(src, is_python_list = FALSE) {
  stopifnot(class(src) == "list")
  .Call("Rython__pydict", src, is_python_list)
}

#'@export
pylong <- function(src) {
  .Call("Rython__pylong", src)	
}

#'@export
pyfloat <- function(src) {
  .Call("Rython__pyfloat", src)  	
}

#'@export
pybool <- function(src) {
  .Call("Rython__pybool", src)
}

#'@export
pystr <- function(src) {
  .Call("Rython__pystr", src)
}

#'@export
pyobj <- function(module_name, obj_name) {
  .Call("Rython__retrieve_pyobj", module_name, obj_name)
}

#'@export
pycall <- function(py_callable, ...) {
  argv <- list(...)
  .Call("Rython__call", py_callable, argv);
}

#'@export
pywrap <- function(src, is_list = TRUE) {
  .Call("Rython__wrap", src, is_list);
} 