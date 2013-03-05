\name{pyfun}
\alias{pyfun}
\title{Call python function}
\usage{
  pyfun(fun_name, argv, module = "__main__")
}
\arguments{
  \item{fun_name}{the name of function object in python}

  \item{argv}{A character vector which will be converted to
  list of string in python and send to the called function}

  \item{module}{the module where the function exists}
}
\description{
  Call python function
}
\examples{
library(Rython)
py("def test_fun(src):\\n    print src\\n    return src\\n") # define test_fun in python
pyfun("test_fun", letters)
}

