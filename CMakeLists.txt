cmake_minimum_required(VERSION 3.23)
project(Voting_Systems)

set(CMAKE_CXX_STANDARD 23)

add_executable(Voting_Systems src/main.cpp src/bordaCount.cpp src/pluralityVoting.cpp src/bucklinVoting.cpp src/secretBallot.cpp src/voteList.cpp src/voteList.h src/pluralityVoting.h)
