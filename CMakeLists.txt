project(cmdline_app_sim)
cmake_minimum_required(VERSION 3.6.0)



add_executable(cmdline_app_sim source/cmdline_app_sim.cpp)

set_property(TARGET cmdline_app_sim PROPERTY CXX_STANDARD 17)


