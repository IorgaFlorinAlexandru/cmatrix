cmake_minimum_required(VERSION 3.28)
project(CMatrix C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(cmatrix
  src/cmatrix.c
  src/droplet.c
  src/cloud.c
)

target_include_directories(cmatrix PRIVATE
  ${CMAKE_SOURCE_DIR}/include
 )
