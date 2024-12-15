cmake_minimum_required(VERSION 3.20.0)

# variables
set(MAIN_TARGET_NAME main)
set(MOD1_TARGET_NAME mod1)
set(MOD2_TARGET_NAME mod2)

# files
file(GLOB_RECURSE MAIN_SRC "src/main/*.cpp")
file(GLOB_RECURSE MOD1_SRC "src/mod1/*.cpp")
file(GLOB_RECURSE MOD2_SRC "src/mod2/*.cpp")

# top project declare
project(DynamicModuleLoad CXX)

# targets
add_executable(${MAIN_TARGET_NAME} ${MAIN_SRC})
add_library   (${MOD1_TARGET_NAME} MODULE ${MOD1_SRC})
add_library   (${MOD2_TARGET_NAME} MODULE ${MOD2_SRC})

include_directories(BEFORE src)
