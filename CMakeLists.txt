cmake_minimum_required(VERSION 2.8)

project(Rython)

find_package(LibR REQUIRED)
set(Python_ADDITIONAL_VERSIONS 2.7)
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

if(${LIBR_FOUND})
else()
  message(FATAL_ERROR "No R...")
endif()
include_directories(BEFORE ${LIBR_INCLUDE_DIRS})

include_directories(BEFORE "/home/wush/R/x86_64-pc-linux-gnu-library/2.15/Rcpp/include")

add_custom_target(Rython ALL
	COMMAND find ${CMAKE_SOURCE_DIR} -name "*.o" -exec rm "{}" "\;"
	COMMAND find ${CMAKE_SOURCE_DIR} -name "*.so" -exec rm "{}" "\;"
	COMMAND ${LIBR_EXECUTABLE} --vanilla --slave --args /home/wush/R-package-project/Rython < "/home/wush/R/i686-pc-linux-gnu-library/2.15/RCMake/roxygenize/_collatenamespacerd.R"
	COMMAND ${LIBR_EXECUTABLE} CMD INSTALL "${CMAKE_SOURCE_DIR}")

