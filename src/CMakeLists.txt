# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/*.hpp")
# set(HEADER_LIST "${ModernCMakeExample_SOURCE_DIR}/include/lib.hpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(Pong_Library Bat.cpp 
                         Ball.cpp 
                         GameLibrary.cpp 
                         StructGame.cpp 
                         InitMenu.cpp ${HEADER_LIST})


# We need this directory, and users of our library will need it too
target_include_directories(Pong_Library PUBLIC ../include)

# This depends on (header only) boost
target_link_libraries(Pong_Library PRIVATE sfml-system sfml-window sfml-graphics sfml-network sfml-audio)


# All users of this library will need at least C++11
target_compile_features(Pong_Library PUBLIC cxx_std_17)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
