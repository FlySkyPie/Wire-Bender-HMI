cmake_minimum_required(VERSION 3.0)
project(WireBenderHMI)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE theSoruces src/*)
#foreach(file IN LISTS files)
#    message(STATUS ${file})
#endforeach(file)


include_directories ("${PROJECT_SOURCE_DIR}/include")

#aux_source_directory(src DIR_SRCS)
#aux_source_directory(src/application DIR_SRCS)

#set(wxWidgets_CXX_FLAGS --cxxflags --libs std)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})



add_executable(WireBenderHMI ${theSoruces})

target_link_libraries(${PROJECT_NAME} -lserial)
target_link_libraries(${PROJECT_NAME} -lstdc++fs)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})