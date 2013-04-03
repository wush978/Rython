# Rython

Embed python in R

# Environment

Ubuntu with python 2.7

Please install the following ubuntu packages:

- python-dev
- libboost-python-dev

# Usage

```r
library(Rython)
py("python script")
```

# Type Mapping

To pass object from *R* to *python*, use the following functions:

<!-- html table generated in R 2.15.3 by xtable 1.7-1 package -->
<!-- Wed Apr  3 17:40:22 2013 -->
<TABLE border=1>
<TR> <TH>  </TH> <TH> function name </TH> <TH> R type </TH> <TH> python type </TH>  </TR>
  <TR> <TD align="right"> 1 </TD> <TD> pydict </TD> <TD> list </TD> <TD> dictionary </TD> </TR>
  <TR> <TD align="right"> 2 </TD> <TD> pylong </TD> <TD> integer </TD> <TD> list of long </TD> </TR>
  <TR> <TD align="right"> 3 </TD> <TD> pyfloat </TD> <TD> numeric </TD> <TD> list of float </TD> </TR>
  <TR> <TD align="right"> 4 </TD> <TD> pybool </TD> <TD> logical </TD> <TD> list of bool </TD> </TR>
  <TR> <TD align="right"> 5 </TD> <TD> pystr </TD> <TD> character </TD> <TD> list of str </TD> </TR>
   </TABLE>


## API



# Demo 

## cql 1.4

The following script query the Cassandra with python-cql 1.4 and pass the value back to R

```r
library(Rython)
py("import cql")
py("con = cql.connect(host, port, key_space, cql_version='3.0.0')")
py("cursor = con.cursor()")
py("cursor.execute('select * from column_family limit 1')")
py("result = cursor.fetchall()")
py("print result")
py("result1 = result[0]")
result1 <- pyobj(obj_name="result1", module_name="")
pywrap(result1)
```

## Demo for R package with python

Put your python script under `inst/python` and install it.

```r
#'@export
.onLoad <- function(libname, pkgname) {
  import_pkg_module(pkgname, "foo.py")
}
```

# NEWS

- 2013-04-03
    - add conversion functions(See `R/conversion.R`)
    - add import_pkg_module
