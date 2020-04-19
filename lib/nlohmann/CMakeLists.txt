cmake_minimum_required(VERSION 3.10)
project(JSON)

set(JSON_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include/nlohmann")

add_library(JSON INTERFACE)
target_include_directories(JSON INTERFACE ${JSON_INCLUDE_DIRS} )