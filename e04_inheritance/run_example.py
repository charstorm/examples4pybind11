import cppimport

# cppimport will build the code and return a module
example = cppimport.imp("example")

obj = example.ContainerBase()
obj.append(1)
obj.append(2)
print(obj.sum())

obj = example.NamedContainer("C1")
obj.append(1)
obj.append(2)
print(obj.sum())
print(obj.getName())
