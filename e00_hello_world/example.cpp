// A simple example with a hello world function
#include <iostream>

// Header required for pybind11
#include <pybind11/pybind11.h>

// Function to be called from Python
void hello() {
    std::cout << "Hello World" << std::endl;
}

// Steps to expose the above function to Python
// Module will be named "example"
PYBIND11_MODULE(example, m) {
    m.doc() = "An example module with a simple function to print hello world";

    m.def("hello", &hello, "Print hello world");
}

// Following is used by cppimport to convert the C++ source to a module.
// Code inside <% %> is python.
// The #if guard is optional (added to avoid confusing my editor).
#if 0
<%
cfg['compiler_args'] = ['-std=c++17', '-Wall', '-Wextra']
cfg['sources'] = []
setup_pybind11(cfg)
%>
#endif
