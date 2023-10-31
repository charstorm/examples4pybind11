import cppimport

# cppimport will build the code and return a module
example = cppimport.imp("example")

shifter = example.create_shifter(2)
scaler = example.create_scaler(10)

print(shifter.process(10))
print(scaler.process(3))

pipeline = [shifter, scaler]
result = example.pipeline_process(pipeline, 3)
print(result)

print(type(shifter))
print(type(scaler))
