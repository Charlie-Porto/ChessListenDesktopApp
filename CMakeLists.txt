cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

# set project name
project(ChessListenDesktopApp)

# add the executable
add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} 
  PUBLIC include
  PUBLIC 3rdparty/flite.src
  PUBLIC 3rdparty/wxWidgets/src
  PUBLIC 3rdparty/libsndfile/src
  PUBLIC 3rdparty/portaudio/src
)





