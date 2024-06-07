cmake_minimum_required(VERSION 3.28)

SET(CMAKE_CXX_STANDARD          20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS       OFF)

project(
	memory_thread
	VERSION 1.0.0
	LANGUAGES C CXX)

add_executable(Threads main.cpp)