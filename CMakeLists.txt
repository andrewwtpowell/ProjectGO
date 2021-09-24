cmake_minimum_required(VERSION 3.1...3.21)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(ProjectGO VERSION 1.0
                  DESCRIPTION "Go project"
                  LANGUAGES CXX)

add_executable(PlayGo src/board.cpp src/group.cpp src/piece.cpp main.cpp)

add_executable(TestGo src/board.cpp src/group.cpp src/piece.cpp test/test.cpp)

add_library(MainLibrary src/board.cpp src/group.cpp src/piece.cpp main.cpp)

add_library(TestLibrary src/board.cpp src/group.cpp src/piece.cpp test/test.cpp)

target_include_directories(PlayGo PUBLIC include)

target_include_directories(TestGo PUBLIC include)

target_include_directories(MainLibrary PUBLIC include)

target_include_directories(TestLibrary PUBLIC include)

find_package(Catch2 3 REQUIRED)
target_link_libraries(TestGo PRIVATE Catch2::Catch2WithMain)
target_link_libraries(TestLibrary PRIVATE Catch2::Catch2WithMain)