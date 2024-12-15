cmake_minimum_required(VERSION 3.20.0)

# variables
set(MAIN_TARGET_NAME main)
set(DYNM_TARGET_NAME dynm)
set(MOD1_TARGET_NAME mod1)
set(MOD2_TARGET_NAME mod2)

# files
file(GLOB_RECURSE MAIN_SRC "src/main/*.cpp")
file(GLOB_RECURSE DYNM_SRC "src/dynm/*.cpp")
file(GLOB_RECURSE MOD1_SRC "src/mod1/*.cpp")
file(GLOB_RECURSE MOD2_SRC "src/mod2/*.cpp")

# top project declare
project(DynamicModuleLoad CXX)

# targets
add_executable(${MAIN_TARGET_NAME} ${MAIN_SRC})
add_library   (${DYNM_TARGET_NAME} STATIC ${DYNM_SRC})
add_library   (${MOD1_TARGET_NAME} SHARED ${MOD1_SRC})
add_library   (${MOD2_TARGET_NAME} SHARED ${MOD2_SRC})

include_directories(src)
target_link_libraries(${MAIN_TARGET_NAME} ${DYNM_TARGET_NAME})
add_dependencies(
	${DYNM_TARGET_NAME}
	${MOD1_TARGET_NAME}
	${MOD2_TARGET_NAME}
)