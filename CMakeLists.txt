# CMakeList.txt : CMake project for ProgressQuestPlusPlus, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (ProgressQuestPlusPlus VERSION "6.2.0")
cmake_policy(SET CMP0092 OLD)
set(CMAKE_CXX_STANDARD 17)
configure_file("config.h.in" "${CMAKE_SOURCE_DIR}/src/config.h")
include_directories(${PROJECT_BINARY_BIN})

file(GLOB helloworld_SRC CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/**.h" "${CMAKE_SOURCE_DIR}/src/**.cpp")

add_executable(ProgressQuestPlusPlus ${helloworld_SRC})
target_link_libraries(ProgressQuestPlusPlus PRIVATE nana )
target_compile_definitions(ProgressQuestPlusPlus PUBLIC -D_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING -DNANA_IGNORE_CONF)

set_target_properties(ProgressQuestPlusPlus PROPERTIES CXX_EXTENSIONS ON)

add_subdirectory("${CMAKE_SOURCE_DIR}/lib/nana" "${CMAKE_SOURCE_DIR}/lib/nana/cmake-nana-build-${CONFIG}" )

 foreach(flag
        CMAKE_C_FLAGS              CMAKE_C_FLAGS_DEBUG             CMAKE_C_FLAGS_RELEASE
        CMAKE_C_FLAGS_MINSIZEREL   CMAKE_C_FLAGS_RELWITHDEBINFO
        CMAKE_CXX_FLAGS            CMAKE_CXX_FLAGS_DEBUG           CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
    if(${flag} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
    endif()
endforeach()

# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
set_property(GLOBAL PROPERTY USE_FOLDERS false)

# Set compiler flags and options. 
# Here it is setting the Visual Studio warning level to 4
message ("cxx Flags:" ${CMAKE_CXX_FLAGS})
string(REGEX REPLACE "/W[3|4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")



if(MSVC)
  string(REGEX REPLACE "/Zi" "/ZI" CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}")
  target_link_options(ProgressQuestPlusPlus PUBLIC "/ZI" "/INCREMENTAL")
endif()

message ("cxx Flags:" ${CMAKE_CXX_FLAGS})
message("Generated with config types: ${CMAKE_CONFIGURATION_TYPES}")
install(TARGETS ProgressQuestPlusPlus) # in ${CMAKE_INSTALL_PREFIX}/include/nana