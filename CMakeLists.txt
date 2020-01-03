cmake_minimum_required(VERSION 3.10)
project(MongoHttpServer)

set(CMAKE_CXX_STANDARD 14)

find_package(libmongocxx REQUIRED)
find_package(libbsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIRS})
include_directories(${LIBBSONCXX_INCLUDE_DIRS})
include_directories("/usr/local/include/mongocxx/v_noabi")
include_directories("/usr/local/include/bsoncxx/v_noabi")
include_directories("/usr/local/include/libmongoc-1.0")
include_directories("/usr/local/include/libbson-1.0")
include_directories("/usr/local/lib")


file(GLOB ALL_SOURCES "*.h" "*.cpp")
add_executable(MongoHttpServer ${ALL_SOURCES})
target_link_libraries(MongoHttpServer ${LIBMONGOCXX_LIBRARIES})
target_link_libraries(MongoHttpServer ${LIBBSONCXX_LIBRARIES})