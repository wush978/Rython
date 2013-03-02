#'@useDynLib Rython
.onAttach <- function(libname, pkgname) {
  .Call("Rython__initialize")
}

#'@export
.Last.lib <- function(libpath) {
  .Call("Rython__finalize")
}
