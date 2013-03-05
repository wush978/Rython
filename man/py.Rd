\name{py}
\alias{py}
\title{Execute python script}
\usage{
  py(script)
}
\arguments{
  \item{script}{Python Script}
}
\description{
  Execute python script
}
\examples{
library(Rython)
py("import sys")
py("def test_fun(src):\\n    print src\\n    return src\\n") # define test_fun in python
}

