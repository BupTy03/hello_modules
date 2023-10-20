cmake_minimum_required(VERSION 3.28)
project(TestModernModules CXX)

# Turning off extensions avoids and issue with the clang 16 compiler
# clang 17 and greater can avoid this setting
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the version of C++ for the project
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_SCAN_FOR_MODULES ON)

# Create a library
add_library(shapes)

# Add the module file to the library
target_sources(shapes
  PUBLIC
    FILE_SET CXX_MODULES FILES
      shape.cxx
      rectangle.cxx
      triangle.cxx
      circle.cxx
      shape_factory.cxx
)

# Create an executable
add_executable(hello_modules main.cxx)

# Link to the library foo
target_link_libraries(hello_modules shapes)
