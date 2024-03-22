# author rayzhang 通用库
# details 
project(RyRegex LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME})

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
target_sources(${PROJECT_NAME}
    PRIVATE
    ${SOURCES}
)
add_compile_options(
  "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>"
)
add_compile_options(
  "$<$<CXX_COMPILER_ID:Clang>:-std=c++23;-finput-charset=UTF-8>"
  "$<$<CXX_COMPILER_ID:GNU>:-std=c++23;-finput-charset=UTF-8>"
)

# target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
#target_link_libraries(${PROJECT_NAME} PRIVATE )

# debug 输出带d的库
#set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX d)
# 预处理器/预定义宏
#target_compile_definitions(${PROJECT_NAME} PRIVATE LIBINTERPRETER_API_EXPORT)
#source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

#add_subdirectory(common_lib)
