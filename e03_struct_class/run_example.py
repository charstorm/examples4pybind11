import cppimport

# cppimport will build the code and return a module
example = cppimport.imp("example")
p1 = example.Point2d(30, 40)
print(p1)
print(p1.norm())

p2 = example.Point2d(1, 2)
print(example.add_points(p1, p2))
print(p2.scale(10))

acc = example.Accumulator()
for x in [1, 2, 3, 4]:
    acc.add(x)
print(acc.get())
help(example.Accumulator)
