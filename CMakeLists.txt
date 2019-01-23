cmake_minimum_required(VERSION 3.1)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14)

project(quran)
file(GLOB SRC_FILES "src/*")

add_executable(
    main # executable file name
    ${SRC_FILES}
)

file(GLOB STATIC_LIB "lib/*.a")
target_link_libraries(main ${STATIC_LIB})

