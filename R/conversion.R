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
pycomplex <- function(src) {
  .Call("Rython__pycomplex", src)	
}

#'@export
pystr <- function(src) {
  .Call("Rython__pystr", src)
}