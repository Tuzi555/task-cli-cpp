cmake_minimum_required(VERSION 3.30)
project(task_cli)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 0c9fce2ffefecfdce794e1859584e25877b7b592 #11.0.2
)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(fmt json)

add_executable(task_cli main.cpp)

target_link_libraries(task_cli PRIVATE fmt::fmt)
target_link_libraries(task_cli PRIVATE nlohmann_json::nlohmann_json)
