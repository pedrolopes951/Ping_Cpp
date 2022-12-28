add_executable(Pong main.cpp)
target_compile_features(Pong PRIVATE cxx_std_17)

target_link_libraries(Pong PRIVATE Pong_Library )

file(COPY ../fonts DESTINATION ${CMAKE_CURRENT_BINARY_DIR})