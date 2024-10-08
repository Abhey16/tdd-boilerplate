# tdd-boilerplate

# Badges
![CICD Workflow status](https://github.com/Abhey16/tdd-boilerplate/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg)
[![codecov](https://codecov.io/gh/Abhey16/tdd-boilerplate/branch/main/graph/badge.svg)](https://codecov.io/gh/Abhey16/tdd-boilerplate) 
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)


## Overview

Simple starter C++ project with:

- CMake
- GoogleTest

## Authors
### Part1 - Team 2

* Abhey Sharma - 120110306 (Navigator)
* Navdeep Singh - 120098024 (Driver)

### Part2 - Team 1
* Rishie Raj - 120425554 (Navigator & Driver)
   
## Standard install via command-line
```bash
# Download the code:
  git clone https://github.com/Abhey16/tdd-boilerplate.git
  cd tdd-boilerplate
# Configure the project and generate a native build system:
  # Must re-run this command whenever any CMakeLists.txt file has been changed.
  cmake -S ./ -B build/
# Compile and build the project:
  # rebuild only files that are modified since the last build
  cmake --build build/
  # or rebuild everything from scracth
  cmake --build build/ --clean-first
  # to see verbose output, do:
  cmake --build build/ --verbose
# Run program:
  ./build/app/shell-app
# Run tests:
  cd build/; ctest; cd -
  # or if you have newer cmake
  ctest --test-dir build/
# Build docs:
  cmake --build build/ --target docs
  # open a web browser to browse the doc
  open docs/html/index.html
# Clean
  cmake --build build/ --target clean
# Clean and start over:
  rm -rf build/
```


## Building for code coverage

```bash
# if you don't have gcovr or lcov installed, do:
  sudo apt-get install gcovr lcov
# Set the build type to Debug and WANT_COVERAGE=ON
  cmake -D WANT_COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug -S ./ -B build/
# Now, do a clean compile, run unit test, and generate the covereage report
  cmake --build build/ --clean-first --target all test_coverage
# open a web browser to browse the test coverage report
  open build/test_coverage/index.html

This generates a index.html page in the build/test_coverage sub-directory that can be viewed locally in a web browser.
```

You can also get code coverage report for the *shell-app* target, instead of unit test. Repeat the previous 2 steps but with the *app_coverage* target:

``` bash
# Now, do another clean compile, run shell-app, and generate its covereage report
  cmake --build build/ --clean-first --target all app_coverage
# open a web browser to browse the test coverage report
  open build/app_coverage/index.html

This generates a index.html page in the build/app_coverage sub-directory that can be viewed locally in a web browser.
```
---

## UML Diagram
![UML class](https://github.com/user-attachments/assets/4aa4f27d-bc75-4656-a9bc-af6a5364d10d)

## clang-tidy output
![Screenshot from 2024-10-09 19-55-41](https://github.com/user-attachments/assets/284b7be2-2d95-494d-ae8b-86dde9b56c01)

## cpplint output
![Screenshot from 2024-10-09 20-04-52](https://github.com/user-attachments/assets/0c3270cc-c41b-4319-8bac-b1b4dcb1d98d)



