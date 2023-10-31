// A simple example with a hello world function
#include <iostream>

#include <pybind11/pybind11.h>

void hello() {
    std::cout << "Hello World" << std::endl;
}

PYBIND11_MODULE(hello_world_example, m) {
    m.doc() = "An example module with a simple function to print hello world";
    m.def("hello", &hello, "Print hello world");
}
