cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(cc-blockchain)
file(GLOB_RECURSE src "src/**.cpp" "src/**.hpp")
add_executable(${PROJECT_NAME} ${src})

if(WIN32) # WINDOWS
target_link_libraries(${PROJECT_NAME} glad glfw3 libcurl ws2_32) 
endif(WIN32)

if(UNIX AND NOT APPLE) # LINUX 
target_link_libraries(${PROJECT_NAME} GL GLEW glfw curl boost_system boost_filesystem boost_thread)
endif()