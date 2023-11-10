// An example that uses C++ code in a separate file.
#include "hello.h"

// Header required for pybind11
#include <pybind11/pybind11.h>

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
cfg['sources'] = ['hello.cpp']
setup_pybind11(cfg)
%>
#endif
