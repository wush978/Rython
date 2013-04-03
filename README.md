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



## Demo of cql 1.4

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
