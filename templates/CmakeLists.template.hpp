#pragma once

constexpr auto cmakelists_template = R"cmake(
cmake_minimum_required(VERSION 3.1)
project(<NAME> LANGUAGES CXX VERSION 1.0)

# --------------------------------------------------------------------------------------------------------
# Create executable
# --------------------------------------------------------------------------------------------------------

add_executable(${PROJECT_NAME} "src/main.cpp")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17 CXX_EXTENSIONS OFF CXX_STANDARD_REQUIRED ON)

# --------------------------------------------------------------------------------------------------------
# Fetch required content
# --------------------------------------------------------------------------------------------------------

include(FetchContent)

FetchContent_Declare(saucer GIT_REPOSITORY "https://github.com/saucer/saucer")
FetchContent_MakeAvailable(saucer)

# --------------------------------------------------------------------------------------------------------
# Link libraries
# --------------------------------------------------------------------------------------------------------

target_link_libraries(${PROJECT_NAME} PRIVATE saucer)
)cmake";