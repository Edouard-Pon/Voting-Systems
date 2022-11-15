cmake_minimum_required(VERSION 3.22)
project(Voting_Systems)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE SRC src/*)
add_executable(Voting_Systems src/main.cpp ${SRC} secretBallot.cpp secretBallot.h)
