# Make sure that current cmake version is high enough
cmake_minimum_required(VERSION 3.7...3.29)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Project name and info
project(MyProject VERSION 1.0
                  DESCRIPTION "C++ Weather getter based on wttr.in and nloman json parser"
                  LANGUAGES CXX)

message("cppWeather is using current source dir = ${CMAKE_CURRENT_SOURCE_DIR}")

# Target 
add_executable(cppWeather src/weather.cpp)

# Using cpp23 standard
target_compile_features(cppWeather PUBLIC cxx_std_23)

# Finding curl 
find_package(CURL REQUIRED)
target_include_directories(cppWeather PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(cppWeather ${CURL_LIBRARIES})
