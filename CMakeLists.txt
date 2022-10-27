cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(SupplyChainManagement VERSION 1.0)

add_subdirectory(src/main)
add_subdirectory(src/test EXCLUDE_FROM_ALL)
add_subdirectory(lib/googletest)
