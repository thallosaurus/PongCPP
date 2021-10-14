cmake_minimum_required(VERSION 3.0.0)
project(PongCPP VERSION 0.1.0)
set(CMAKE_BUILD_TYPE Debug)

# add_custom_target(build-time-make-directory ALL
    # COMMAND ${CMAKE_COMMAND} -E make_directory /build)


# include(CTest)
# enable_testing()

file(GLOB pong_SRC
    "src/include/*.h"
     "src/*.cpp"
)

add_executable(PongCPP ${pong_SRC})
# add_executable(PongCPP Display.cpp)
target_link_libraries(PongCPP pthread)

link_directories(PongCPP $PROJECT_SOURCE_DIR/src

target_include_directories(texture_mapping PUBLIC ${PROJECT_SOURCE_DIR}/include))

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
