cmake_minimum_required(VERSION 3.0.0)
project(PongCPP VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(PongCPP main.cpp)
target_link_libraries(PongCPP pthread)

link_directories(PongCPP $PROJECT_SOURCE_DIR

target_include_directories(texture_mapping PUBLIC ${PROJECT_SOURCE_DIR}/include))

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
