cmake_minimum_required(VERSION 3.21)
project (dataStructure C)

set(CMAKE_C_STANDARD 99)


add_executable(list_arraylist arrayList/arraylist.h)
add_executable(list_arrayList arrayList/arrayList.c)
add_executable(list_ALexec arrayList/ALexec.c)

add_executable(linkedList_linkedlist linkedList/linkedlist.h)
add_executable(network_echoclient network/echoclient.c)