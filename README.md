# Natjecateljsko programiranje 2020 Pybind11 example

Primjer koristenja pybind11 za lako kreiranje Python modula oko svog C++ koda

Potrebni alati:
- Cmake
- Ninja
- Python3
- C++17 kompajler
- Conan (opcionalno)

Upute ako se koristi pybind11 submodule:

0) `git clone --recursive git@github.com:luka-papez/microblink-pybind-demo.git`
1) `cp CMakeLists_submodules.txt CMakeLists.txt`
2) `mkdir build && cd build`
3) `cmake -GNinja ..`
4) `ninja`
5) `build` folder u kojem smo trenutno bi trebao sadrzavati `my_cpp_module.so`
6) `cd ..`
7) `python3 test.py`

Upute ako se koristi Conan:

0) `git clone --recursive git@github.com:luka-papez/microblink-pybind-demo.git`
1) `cp CMakeLists_conan.txt CMakeLists.txt`
2) `mkdir build && cd build`
3) `conan install ..`
4) `cmake -GNinja ..`
5) `ninja`
6) `build` folder u kojem smo trenutno bi trebao sadrzavati `my_cpp_module.so`
7) `cd ..`
8) `python3 test.py`
