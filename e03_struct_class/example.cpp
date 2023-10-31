// A module with example classes
#include <iostream>
#include <cmath>

#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace pybind11::literals;


struct Point2d {
    float x_;
    float y_;

    Point2d(float x, float y): x_(x), y_(y) {
        // Nothing else to do
    }

    float norm() {
        return sqrt(x_ * x_ + y_ * y_);
    }

    Point2d scale(float s) {
        return Point2d {x_ * s, y_ * s};
    }
};


// Function taking struct as argument
Point2d add_points(Point2d &p1, Point2d &p2) {
    return Point2d {p1.x_ + p2.x_, p1.y_ + p2.y_};
}


class Accumulator {
    float total_ = 0;

public:
    Accumulator(float total): total_(total) {}

    void add(float val = 0) {
        total_ += val;
    }

    float get() {
        return total_;
    }
};


PYBIND11_MODULE(example, m) {
    m.doc() = "A basic example module with struct";

    // class_ is used for class/struct
    auto cls1 = py::class_<Point2d>(m, "Point2d");
    cls1.def(py::init<float, float>())
       .def("norm", &Point2d::norm, "Generate norm")
       .def("scale", &Point2d::scale, "Return a scaled point",
            "s"_a);

    // We can also use lambda functions
    cls1.def("__repr__", [](const Point2d &p) {
        return "Point2d(" + std::to_string(p.x_) + ", " +
            std::to_string(p.y_) + ")";
    });

    m.def("add_points", &add_points, "Add two points",
          "p1"_a, "p2"_a);

    py::class_<Accumulator>(m, "Accumulator")
        .def(py::init<float>(), "Constructor", "starting_value"_a = 0)
        .def("add", &Accumulator::add, "Add number to the accumulator")
        .def("get", &Accumulator::get, "Return the current total");
}

#if 0
<%
cfg['compiler_args'] = ['-std=c++17', '-Wall', '-Wextra']
cfg['sources'] = []
setup_pybind11(cfg)
%>
#endif
