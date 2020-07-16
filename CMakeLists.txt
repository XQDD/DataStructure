cmake_minimum_required(VERSION 3.10)
project(DataStructure)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. ALL_SRC)

file(GLOB SRC_DIR src/*)

foreach (subdir ${SRC_DIR})
    add_subdirectory(${subdir})
endforeach ()
