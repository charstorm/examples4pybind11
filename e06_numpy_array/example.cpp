// A module with example of taking a numpy array as input
#include <cmath>
#include <exception>

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;
using namespace pybind11::literals;


// A function taking numpy array as input
float rms(py::array_t<float> &arr_in) {
    if (arr_in.ndim() != 1) {
        throw std::invalid_argument("need a single dimensional array");
    }

    if (arr_in.shape(0) == 0) {
        return 0;
    }

    float square_sum = 0;
    for (ssize_t ii = 0; ii < arr_in.shape(0); ii++) {
        square_sum += arr_in.at(ii) * arr_in.at(ii);
    }

    return std::sqrt(square_sum / arr_in.shape(0));
}

// Compute the cumulative sum
// Note: Creating and returning an array is painful. It is much easier to
// get the output array from python itself.
void cumulative_sum(py::array_t<float> &arr_in, py::array_t<float> &arr_out) {
    if (arr_in.ndim() != 1) {
        throw std::invalid_argument("need a single dimensional array");
    }

    if (arr_in.ndim() != arr_out.ndim()) {
        throw std::invalid_argument("input and output array dim should match");
    }

    if (arr_in.shape(0) != arr_out.shape(0)) {
        throw std::invalid_argument("input and output array shape should match");
    }

    float sum = 0;
    for (ssize_t ii = 0; ii < arr_in.shape(0); ii++) {
        sum += arr_in.at(ii);
        arr_out.mutable_at(ii) = sum;
    }
}


PYBIND11_MODULE(example, m) {
    m.doc() = "A module with functions using numpy arrays";

    m.def("rms", &rms, "Compute RMS for the input single dimensional array",
          "x"_a);
    m.def("cumulative_sum", &cumulative_sum, "Compute cumulative sum",
          "x"_a, "out"_a);
}


#if 0
<%
cfg['compiler_args'] = ['-std=c++17', '-Wall', '-Wextra']
cfg['sources'] = []
setup_pybind11(cfg)
%>
#endif
