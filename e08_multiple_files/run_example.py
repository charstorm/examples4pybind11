import cppimport

# cppimport will build the code and return a module
example = cppimport.imp("example")

# Try these from python terminal:
# help(example)
# help(example.hello)

example.hello()
