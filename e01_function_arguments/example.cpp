// A module showing how to handle function arguments

#include <iostream>
#include <string>

#include <pybind11/pybind11.h>

// Only for example
using namespace std;

// Shorthand since we need to use it often
namespace py = pybind11;

// This is needed for the "arg"_a trick to work.
// See m.def in PYBIND11_MODULE
using namespace pybind11::literals;

// The function to be called from Python
void hello(string &name) {
    cout << "Hello " << name << endl;
}

PYBIND11_MODULE(example, m) {
    m.doc() = "A module with basic functions in C++";

    // Register the function. Argument will be guessed by pybind11
    m.def("hello", &hello, "Say hello to a given argument");

    // The above function will have arguments named arg0, arg1, etc.
    // We can force a name for that argument by the following.
    m.def("hello1", &hello, "Say hello to the given name",
          py::arg("name"));

    // Similar to the above, but with a default value
    m.def("hello2", &hello, "Say hello to the optional given name",
          py::arg("name") = "World");

    // Similar to the above, but using a shorthand notation
    m.def("hello3", &hello, "Say hello to the optional name",
          "name"_a = "World");
}

#if 0
<%
cfg['compiler_args'] = ['-std=c++17', '-Wall', '-Wextra']
cfg['sources'] = []
setup_pybind11(cfg)
%>
#endif
