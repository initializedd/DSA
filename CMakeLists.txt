cmake_minimum_required(VERSION 3.27.0)
set(CMAKE_CXX_STANDARD 20)

project(DSA)

find_package(Catch2 3.4.0 REQUIRED)

add_executable(${PROJECT_NAME})

# add tests
target_sources(${PROJECT_NAME} PRIVATE
    "Tests/DataStructures/Array/FixedArrayTest.cpp"
    "Tests/DataStructures/HashTable/HashTableTest.cpp"
    "Tests/DataStructures/LinkedList/SingleLinkedListTest.cpp" 
    "Tests/DataStructures/Stack/StaticStackTest.cpp"
    "Tests/DataStructures/Stack/DynamicStackTest.cpp"
    "Tests/DataStructures/Queue/StaticQueueTest.cpp"
    "Tests/DataStructures/Queue/DynamicQueueTest.cpp"
    "Tests/DataStructures/Tree/BinarySearchTreeTest.cpp"
)

target_link_libraries(${PROJECT_NAME} Catch2::Catch2WithMain)