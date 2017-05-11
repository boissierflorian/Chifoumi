cmake_minimum_required( VERSION 3.0 )
project( Chifoumi )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra" )
set( CMAKE_BUILD_TYPE Debug )

find_package( PkgConfig REQUIRED )
pkg_check_modules( PKG REQUIRED cpputest )
include_directories( ${PKG_INCLUDE_DIRS} )

add_executable( chifoumi.out src/main.cpp )

add_executable( chifoumi_test.out src/main_test.cpp )
target_link_libraries( chifoumi_test.out ${PKG_LIBRARIES} )
