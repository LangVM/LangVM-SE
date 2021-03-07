cmake_minimum_required(VERSION 3.19)
project(langvm)

include_directories(.)

aux_source_directory(runtime RUNTIME)
aux_source_directory(util UTIL)

add_link_options(-lpthread -lffi)
add_executable(langvm ${RUNTIME} ${UTIL})