cmake_minimum_required(VERSION 3.0.0)
project(madgwick VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()


add_executable(madgwick main.c src/madgwick.c src/quaternions.c)
include_directories(inc/)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
