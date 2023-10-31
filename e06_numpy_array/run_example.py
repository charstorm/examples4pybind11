import numpy as np
import cppimport

# cppimport will build the code and return a module
example = cppimport.imp("example")

a = np.array([1, 1, 1], dtype=np.float32)

print(example.rms(a))

b = np.array([1, 2, 3, 4], dtype=np.float32)
c = np.empty_like(b)
example.cumulative_sum(b, c)
print(c)
