cmake_minimum_required(VERSION 3.0)
project(sendSMS)

# Find libcurl
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

# Add your source files
add_executable(${PROJECT_NAME} main.cpp)

# Link against libcurl
target_link_libraries(${PROJECT_NAME} PRIVATE CURL::libcurl)

