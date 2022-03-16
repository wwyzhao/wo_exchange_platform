cmake_minimum_required(VERSION 3.10)
project(Exchange_platform)

set(CMAKE_CXX_STANDARD 14)

add_library(Exchange_platformLib STATIC
        platform/wo_exchange
        platform/Admins
        platform/Goods
        platform/Users
        run/run_exchange_platform
)

target_include_directories(Exchange_platformLib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/platform
)

add_executable(Exchange_platform run/run_exchange_platform.cpp)
target_link_libraries(Exchange_platform
    PRIVATE
        Exchange_platformLib
)