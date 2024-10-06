# tdd-boilerplate

# Badges
![CICD Workflow status](https://github.com/Abhey16/tdd-boilerplate/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg)
[![codecov](https://codecov.io/gh/Abhey16/tdd-boilerplate/branch/main/graph/badge.svg)](https://codecov.io/gh/Abhey16/tdd-boilerplate) 
[![codecov](https://codecov.io/gh/TommyChangUMD/cpp-boilerplate-v2/branch/main/graph/badge.svg)](https://codecov.io/gh/TommyChangUMD/cpp-boilerplate-v2) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)


## Overview

Simple starter C++ project with:

- CMake
- GoogleTest

## Authors
### Team 2

* Abhey Sharma (Navigator)
* Navdeep Singh (Driver)

## Standard install via command-line
```bash
# Download the code:
  git clone https://github.com/TommyChangUMD/cpp-boilerplate-v2
  cd cpp-boilerplate-v2
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

ref: https://cmake.org/cmake/help/latest/manual/cmake.1.html

## Building for code coverage (for assignments beginning in Week 4)

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

## How to use GitHub CI to upload coverage report to Codecov

### First, sign up Codecov with you GitHub account.

  https://about.codecov.io/sign-up/

### Enable the repository you want to upload from

After you sign in, you should see a list of your repositories (you may
have to refresh and reload the page a few times). Enable the one you
want to receive coverage data from.

### Create a GitHub CI yaml file

See below for the setup of this repo:

https://github.com/TommyChangUMD/cpp-boilerplate-v2/blob/main/.github/workflows/run-unit-test-and-upload-codecov.yml

### Add your Codecov and GitHub CI badge to README.md

Follow the instruction below to copy the badge (in markdown format)
and paste it at the top of your README.md file.

For example:
#### CICD Workflow status

https://docs.github.com/en/actions/monitoring-and-troubleshooting-workflows/adding-a-workflow-status-badge

For example,

To generate the CICD badge for this particular repo, I put the line below in this README.md file:
``` markdown
![CICD Workflow status](https://github.com/TommyChangUMD/cpp-boilerplate-v2/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg)
```
![CICD Workflow status](https://github.com/TommyChangUMD/cpp-boilerplate-v2/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg)


#### Code Coverage Report
https://docs.codecov.com/docs/status-badges

For example, to generate the Code Coverage badge for this particular repo,  I put the line below in this README.md file:
``` markdown
[![codecov](https://codecov.io/gh/TommyChangUMD/cpp-boilerplate-v2/branch/main/graph/badge.svg)](https://codecov.io/gh/TommyChangUMD/cpp-boilerplate-v2)
```

[![codecov](https://codecov.io/gh/TommyChangUMD/cpp-boilerplate-v2/branch/main/graph/badge.svg)](https://codecov.io/gh/TommyChangUMD/cpp-boilerplate-v2)



Note: When you click on the codecov badge, you should see the coverage
report.  You should also see the source file listing.  If not, you may
need to login your codecov account first.
