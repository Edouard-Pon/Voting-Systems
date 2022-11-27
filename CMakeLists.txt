cmake_minimum_required(VERSION 3.16)
project(Voting_Systems)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRC src/*)
add_executable(Voting_Systems src/main.cpp ${SRC})
