cmake_minimum_required(VERSION 3.16.0)
project(MyLib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

file(GLOB INCLUDES include/MyLib/*.hpp)
file(GLOB SOURCES src/*.cpp)

find_package(Vulkan REQUIRED)
list(APPEND EXTRA_LIBRARIES ${Vulkan_LIBRARIES})
list(APPEND EXTRA_INCLUDES ${Vulkan_INCLUDE_DIRS})


include_directories(public/MyLib include ${EXTRA_INCLUDES})

add_library(${PROJECT_NAME} ${SOURCES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBRARIES})

target_include_directories(${PROJECT_NAME} PUBLIC public ${EXTRA_INCLUDES})

