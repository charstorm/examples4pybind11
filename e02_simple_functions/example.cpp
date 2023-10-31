// A module with a set of simple functions showing how different
// argument types are handled by pybind11

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <pybind11/pybind11.h>
// Needed for python-list to cpp-vector exchange of data
#include <pybind11/stl.h>

namespace py = pybind11;
using namespace pybind11::literals;

// Int type
int twice(int x) {
    return 2 * x;
}

// Float type
float min2(float x, float y) {
    return x <= y ? x : y;
}

// Boolean type
int select_value(bool sel, int x, int y) {
    return sel ? x : y;
}

// String type
void print_multiple(std::string &msg, size_t n) {
    for (size_t idx = 0; idx < n; idx++) {
        std::cout << msg << std::endl;
    }
}

// List type (gets converted to vector)
float sequence_sum(std::vector<float> &numbers) {
    float sum = 0;
    for (auto x: numbers) {
        sum += x;
    }
    return sum;
}

// Return a vector (will be converted to a list)
std::vector<std::string> convert_lower(std::vector<std::string> &lines) {
    std::vector<std::string> output;
    output.reserve(lines.size());
    for (std::string &line: lines) {
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        output.push_back(line);
    }
    return output;
}


PYBIND11_MODULE(example, m) {
    m.doc() = "A module with basic functions in C++";

    m.def("twice", &twice, "Return twice of input", "x"_a);

    m.def("min2", &min2, "Return minimum of two inputs", "x"_a, "y"_a);

    m.def("select_value", &select_value, "Return x if s, else y",
          "s"_a, "x"_a, "y"_a);

    m.def("print_multiple", &print_multiple, "Print msg n times",
          "msg"_a, "n"_a = 1);

    m.def("sequence_sum", &sequence_sum, "Sum input sequence",
          "numbers"_a);

    m.def("convert_lower", &convert_lower, "Convert lower",
          "lines"_a);
}

#if 0
<%
cfg['compiler_args'] = ['-std=c++17', '-Wall', '-Wextra']
cfg['sources'] = []
setup_pybind11(cfg)
%>
#endif
