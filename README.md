# examples4pybind11

These are a set of beginner level examples I wrote as quick reference material
for a presentation I did at my work.

Examples are organized under different directories. Every example has a C++
source file named `example.cpp` and a python source file named `run_example.py`
which uses the C++ module.

Most of these examples use `cppimport` for building and importing C++ code to
python. At the end of the C++ source file, there is a section given in <%..%>.
These are used by `cppimport` to build the code. `cppimport` is good for quick
development, but probably not the best for production use. For that use the
example `e07_setup_py`, which uses `setup.py` for the build.

Note: I have no involvement in the pybind11 project. This is an independent work.

## Build & Run

- Create and enable a venv
    - `python -m venv my_env_name`
    - `source my_env_name/bin/activate`
    - `python3 -m pip install -r requirements.txt`
    - `deactivate` # to end your session in this venv
- Install the project requirements from requirements.txt
- For all directories except `e07_setup_py`:
    - cd to the directory
    - run the script: `python run_example.py`
- For `e07_setup_py`:
    - cd to the directory
    - install wheel: `pip install wheel`
    - build and install the library using `pip install .`
    - run the script: `python run_example.py`
