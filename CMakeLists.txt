cmake_minimum_required(VERSION 3.8)
project(ChordPlayer2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Chord.cpp Chord.h Maj.cpp Maj.h)
add_executable(ChordPlayer2 ${SOURCE_FILES})