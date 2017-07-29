cmake_minimum_required(VERSION 3.7)
project(Fortuna-Linux)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES FortunaMain.cpp Fortuna.cpp Fortuna.h FortunaTypes.h Pool.cpp Pool.h Source.cpp Source.h PoolManager.cpp PoolManager.h)
add_executable(FortunaMain ${SOURCE_FILES})