cmake_minimum_required(VERSION 3.27.0)
set(CMAKE_CXX_STANDARD 23)

# for std module
 set(STL_MODULE_DIR "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.36.32532/modules") 

# turn on the experimental API
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API  "aa1f7df0-828a-4fcd-9afc-2dc80491aca7")

# turn on the dynamic depends for ninja
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

project(DSA)

add_executable(${PROJECT_NAME})

# add std modules
target_sources(${PROJECT_NAME} PRIVATE 
    FILE_SET CXX_MODULES 
    BASE_DIRS 
     ${STL_MODULE_DIR}
    FILES 
     ${STL_MODULE_DIR}/std.ixx 
     ${STL_MODULE_DIR}/std.compat.ixx
)

# add algorithm modules  
target_sources(${PROJECT_NAME} PRIVATE
    FILE_SET CXX_MODULES
    BASE_DIRS
     ${PROJECT_SOURCE_DIR}
    FILES
     "Algorithms/Sort/SelectionSort.ixx"
     "Algorithms/Sort/BubbleSort.ixx"
     "Algorithms/Sort/InsertionSort.ixx"
     "Algorithms/Sort/MergeSort.ixx"
     "Algorithms/Sort/QuickSort.ixx"
)

# add data structure modules  
target_sources(${PROJECT_NAME} PRIVATE
    FILE_SET CXX_MODULES
    BASE_DIRS
     ${PROJECT_SOURCE_DIR}
    FILES
     "DataStructures/Node/Node.ixx"
     "DataStructures/Node/BinaryNode.ixx"
     "DataStructures/LinkedList/SingleLinkedList.ixx"
     "DataStructures/Stack/StaticStack.ixx"
     "DataStructures/Stack/DynamicStack.ixx"
     "DataStructures/Queue/StaticQueue.ixx"
     "DataStructures/Queue/DynamicQueue.ixx"
     "DataStructures/Tree/BinarySearchTree.ixx"
     "DataStructures/HashTable/HashTable.ixx"
     "DataStructures/Array/FixedArray.ixx"
)

# add tests
target_sources(${PROJECT_NAME} PRIVATE
     "Tests/Main.cpp"
)