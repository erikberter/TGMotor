cmake_minimum_required(VERSION 3.15)
project(TempGameMotor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include/SDL2")
set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/libSDL2.dll.a;${CMAKE_CURRENT_LIST_DIR}/lib/libSDL2_image.dll.a;${CMAKE_CURRENT_LIST_DIR}/lib/libSDL2main.a;${CMAKE_CURRENT_LIST_DIR}/lib/libSDL2_test.a")

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)

include_directories(${SDL2_INCLUDE_DIRS} )

add_executable(${PROJECT_NAME} src/main.cpp src/game.cpp src/game.h src/entity.cpp src/entity.h src/texture_manager.h src/texture_manager.cpp)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})



