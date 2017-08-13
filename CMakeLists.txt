cmake_minimum_required(VERSION 3.7)

project(Fortuna-Linux C CXX)

FIND_PACKAGE ( Threads REQUIRED )

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES FortunaMain.cpp Fortuna.cpp Fortuna.h FortunaTypes.h Pool.cpp Pool.h Source.cpp Source.h
        PoolManager.cpp PoolManager.h SleepUtils.cpp SleepUtils.h SourceManager.cpp SourceManager.h)

add_executable(FortunaMain ${SOURCE_FILES})

target_link_libraries(FortunaMain ${CMAKE_THREAD_LIBS_INIT})