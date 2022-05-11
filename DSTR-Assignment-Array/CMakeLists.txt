cmake_minimum_required(VERSION 3.12)

project(DSTR-Assignment-Array)

# set(MY_FLAGS "-Wall -Wextra -Wshadow -std=c++17")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" "${MY_FLAGS}")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE) 
# message("generator is set to ${CMAKE_GENERATOR}")

add_compile_options(-Wall -Wextra -Wshadow $<$<COMPILE_LANGUAGE:CXX>:-std=c++17> $<$<COMPILE_LANGUAGE:CC>:-std=c99>)

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SRCS CMAKE_CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    )

add_executable(main.out ${SRCS})
