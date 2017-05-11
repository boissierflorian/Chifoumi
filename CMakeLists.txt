# En-tête du projet
cmake_minimum_required( VERSION 3.0 )
project( Chifoumi )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra" )
set( CMAKE_BUILD_TYPE Debug )

# Librairies
find_package( PkgConfig REQUIRED Doxygen )
pkg_check_modules( PKG REQUIRED cpputest libglog )
include_directories( ${PKG_INCLUDE_DIRS} )

# Programme principal
add_executable( chifoumi.out src/main.cpp src/Game.cpp src/Random.cpp )
target_link_libraries( chifoumi.out ${PKG_LIBRARIES} )

# Tests unitaires
add_executable( chifoumi_test.out src/main_test.cpp )
target_link_libraries( chifoumi_test.out ${PKG_LIBRARIES} )

# Documentation
add_subdirectory(doc_doxygen)