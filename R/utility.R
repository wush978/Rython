#'@useDynLib Rython
.onAttach <- function(libname, pkgname) {
  .Call("Rython__initialize")
  py("import sys")
  py("import redirection
class StdoutCatcher:
  def write(self, stuff):
    redirection.stdoutredirect(stuff)
")
  py("sys.stdout = StdoutCatcher()")
}

#'@export
.Last.lib <- function(libpath) {
  .Call("Rython__finalize")
}
