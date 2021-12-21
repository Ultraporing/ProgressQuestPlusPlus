cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(zstr C CXX)

if(${CMAKE_VERSION} VERSION_LESS 3.13)
  message(WARNING "Interface libraries are not well supported before cmake 3.13, you will need to include within the parent CMakeLists.txt: INCLUDE_DIRECTORIES(zstr/src)") 
endif()

# zlib is required
#find_package(ZLIB 1.2.3 REQUIRED)
file(GLOB zstr_SRC CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/lib/zstr/src/**.h" "${CMAKE_SOURCE_DIR}/lib/zstr/src/**.hpp")

add_library(zstr INTERFACE)
add_subdirectory("${CMAKE_SOURCE_DIR}/lib/zlib" "${CMAKE_SOURCE_DIR}/lib/zlib/cmake-zlib-build" )
target_link_libraries(zstr INTERFACE zlib)
target_include_directories(zstr INTERFACE src "${CMAKE_SOURCE_DIR}/lib/zlib/cmake-zlib-build")


message(STATUS "Adding zstr and ZLIB for ${PROJECT_NAME}: includes: ${CMAKE_CURRENT_SOURCE_DIR}/src ${ZLIB_INCLUDE_DIRS} and libraries: ${ZLIB_LIBRARIES}")

