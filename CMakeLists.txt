cmake_minimum_required(VERSION 3.15)
project(game_motor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_subdirectory(lib)

file(GLOB_RECURSE GAME_MOTOR_SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*)
add_executable(${PROJECT_NAME} ${GAME_MOTOR_SOURCES} )

target_include_directories( ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} SDL2 JSON PLOG)



