cmake_minimum_required(VERSION 3.3)
project(Malloc_3_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp source/CLChunk.cpp include/CLChunk.h include/SLHeadOrFoot.h include/CLDoubleLinkListNode.h include/CLSingleLinkListNode.h source/SLHeadOrFoot.cpp include/define.h source/CLSingleLinkListNode.cpp source/CLDoubleLinkListNode.cpp source/CLPerThreadControlUnit.cpp include/CLPerThreadControlUnit.h source/CLFreeChunksManager.cpp include/CLFreeChunksManager.h source/CLAllocatedChunks.cpp include/CLAllocatedChunks.h source/CLMemoryAllocator.cpp include/CLMemoryAllocator.h source/CLInitAllocatedMomory.cpp include/CLInitAllocatedMomory.h source/CLPerTheadHeapControler.cpp include/CLPerTheadHeapControler.h source/CLMainHeapControler.cpp include/CLMainHeapControler.h include/ILMemoryFlusher.h)
add_executable(Malloc_3_cpp ${SOURCE_FILES})