import cppimport

# cppimport will build the code and return a module
example = cppimport.imp("example")

print("\nTwice")
print(example.twice(10))

print("\nMin2")
print(example.min2(12, 8))

print("\nselect_value")
print(example.select_value(True, 10, 20))
print(example.select_value(False, 10, 20))

print("\nprint_multiple")
example.print_multiple("Hello", 4)

# Lists and tuples get conveted to vector in C++
print("\nsequence_sum")
print(example.sequence_sum([1, 2, 3, 4]))
print(example.sequence_sum((10, 20, 30, 40)))

# Sequence output (vector -> list)
print("\nReturning a sequence after processing")
print(example.convert_lower(["Hello How Are You?", "Whatsup?"]))
