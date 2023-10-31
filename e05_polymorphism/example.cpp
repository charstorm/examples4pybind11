// A module with example of using polymorphism.
#include <cmath>
#include <string>
#include <vector>
#include <memory>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
using namespace pybind11::literals;


// Base class representing an abstract processing module
class Base {
public:
    virtual float process(float x) = 0;
    virtual ~Base() {}
};


class Shifter: public Base {
    float shift_ = 0;

public:
    Shifter(float shift): shift_(shift) {}

    virtual float process(float x) {
        return x + shift_;
    }
};


class Scaler: public Base {
    float scale_ = 1;

public:
    Scaler(float scale): scale_(scale) {}

    virtual float process(float x) {
        return x * scale_;
    }
};

// Function taking a vector of base-class pointers as input.
// This will be automatically handled by pybind11.
float pipeline_process(std::vector<Base*> &blocks, float x) {
    float result = x;
    for (auto block: blocks) {
        result = block->process(result);
    }
    return result;
}


PYBIND11_MODULE(example, m) {
    m.doc() = "A basic example showing handling of polymorphism";

    py::class_<Base>(m, "Base")
        .def("process", &Base::process, "Process the input");
    py::class_<Shifter, Base>(m, "Shifter");
    py::class_<Scaler, Base>(m, "Scaler");

    m.def("create_shifter", [](float shift) {
            return std::unique_ptr<Base>(new Shifter(shift));
        }
    );

    m.def("create_scaler", [](float scale) {
            return std::unique_ptr<Base>(new Scaler(scale));
        }
    );

    m.def("pipeline_process", &pipeline_process,
          "Sequentially process each block in the pipeline",
          "blocks"_a, "x"_a);
}

#if 0
<%
cfg['compiler_args'] = ['-std=c++17', '-Wall', '-Wextra']
cfg['sources'] = []
setup_pybind11(cfg)
%>
#endif
