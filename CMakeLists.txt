cmake_minimum_required(VERSION 3.23)
project(Voting_Systems)

set(CMAKE_CXX_STANDARD 23)

add_executable(Voting_Systems main.cpp bordaCount.cpp pluralityVoting.cpp bucklinVoting.cpp secretBallot.cpp voteList.cpp voteList.h)
