// A module with example for using inheritance to extend the functionality
// of a base class.
// Note: This example does not use any polymorphism.
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
using namespace pybind11::literals;


// An example base class.
class ContainerBase {
    std::vector<float> data_;

public:
    ContainerBase() = default;

    void append(float val) {
        data_.push_back(val);
    }

    float sum() {
        float result = 0.0f;
        for (float x: data_) {
            result += x;
        }
        return result;
    }
};


// Creating a derived class with additional features on the top of the above.
// Notice that the derived class does not change the behavior of any of the
// existing functions.
class NamedContainer: public ContainerBase {
    std::string name_;

public:
    NamedContainer(std::string name): ContainerBase(), name_(name) {}

    std::string getName() {
        return name_;
    }
};


PYBIND11_MODULE(example, m) {
    m.doc() = "A basic example showing handling of inheritance";

    // Handle base class and its functions
    py::class_<ContainerBase> base(m, "ContainerBase");
    base.def(py::init<>())
        .def("append", &ContainerBase::append, "Append to data")
        .def("sum", &ContainerBase::sum, "Sum all the values");

    // Use the above `base` when defining child class
    py::class_<NamedContainer>(m, "NamedContainer", base)
        .def(py::init<std::string>())
        .def("getName", &NamedContainer::getName, "Return name");
}

#if 0
<%
cfg['compiler_args'] = ['-std=c++17', '-Wall', '-Wextra']
cfg['sources'] = []
setup_pybind11(cfg)
%>
#endif
