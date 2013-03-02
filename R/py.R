#'@export
py <- function(script) {
  script <- as.character(script)
  for(i in 1:length(script)) {
    .Call("Rython__run", script[i])
  }
}