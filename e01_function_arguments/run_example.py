import cppimport

# cppimport will build the code and return a module
example = cppimport.imp("example")

print("Without py::arg")
example.hello("Universe")

print("\nWith py::arg")
example.hello1("Earth")
example.hello1(name="Earth")

print("\nWith py::arg and default value")
example.hello2("Jupiter")
example.hello2(name="Jupiter")
example.hello2()

print('\nWith "arg"_a shorthand')
example.hello3()
example.hello3("Saturn")
example.hello3(name="Saturn")
