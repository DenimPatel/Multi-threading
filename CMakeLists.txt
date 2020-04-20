cmake_minimum_required(VERSION 2.6)
project(coding_challenge)
add_definitions(-std=c++14)
cmake_minimum_required(VERSION 2.8.3)

################################
# BOOST
################################
find_package(Boost REQUIRED COMPONENTS system)
include_directories( ${Boost_INCLUDE_DIRS} )

################################
# GTest
################################
find_package(GTest REQUIRED)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
enable_testing()


################################
# C++ files
################################
add_executable( threading_1 
src/threading_1.cpp)
add_executable( threading_2 
src/threading_2.cpp)
add_executable( threading_3
src/threading_3.cpp)
add_executable( threading_4
src/threading_4.cpp)
add_executable( threading_5
src/threading_5.cpp)
add_executable( threading_6
src/threading_6.cpp)
add_executable( threading_7
src/threading_7.cpp)
add_executable( threading_8
src/threading_8.cpp)
add_executable( threading_9
src/threading_9.cpp)
add_executable( threading_10
src/threading_10.cpp)


# Link test executable against gtest & gtest_main
# target_link_libraries(runUnitTests ${GTEST_LIBRARIES} coding_challenge pthread)
# add_test( runUnitTests runUnitTests )