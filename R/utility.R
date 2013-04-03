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

#'@export
import_pkg_module <- function(pkg_name, module_name) {
  path <- normalizePath(system.file("python", package=pkg_name), mustWork=TRUE)
  py("import sys")
  py(sprintf("sys.path.append('%s')", path))
  py(sprintf("import %s", module_name))
}