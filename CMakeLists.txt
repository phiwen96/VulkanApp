cmake_minimum_required(VERSION 3.16.0)
project(App)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)


file(GLOB INCLUDES include/*.hpp)
file(GLOB SOURCES src/*.cpp)

list(APPEND EXTRA_INCLUDES include)

option(USE_MYLIB "Use tutorial provided math implementation" ON)

if(USE_MYLIB)
  add_subdirectory(MyLib)
  list(APPEND EXTRA_LIBS MyLib)
  list(APPEND EXTRA_INCLUDES MyLib)
endif()

# add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})
target_include_directories(${PROJECT_NAME} PUBLIC ${EXTRA_INCLUDES})


# target_include_directories(${PROJECT_NAME} PUBLIC include)



