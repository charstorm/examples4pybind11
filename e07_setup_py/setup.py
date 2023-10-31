from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

# Supports environment variables CFLAGS, CPPFLAGS, etc for
# controlling the build process.
ext_modules = [
    Pybind11Extension(
        "hello_world_example",
        ["example.cpp"],
    )
]

setup(
    name="hello_world_example",
    version="0.0.1",
    author="Someone Something",
    author_email="someone@example.com",
    url="https://example.com/something",
    description="A simple example with hello world",
    long_description="",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    python_requires=">=3.10",
)
