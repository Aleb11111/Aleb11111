cmake_minimum_required(VERSION 3.22)
project(a23_Aleb1111 C)

set(CMAKE_C_STANDARD 11)

include_directories(Domains)
include_directories(Repo)
include_directories(Services)
include_directories(UI)
include_directories(Undo_Redo)

add_executable(a23_Aleb1111
        Domains/DynArr.c
        Domains/DynArr.h
        Domains/Product.c
        Domains/Product.h
        Repo/Repository.h
        Repo/Repository.c
        Services/Service.h
        Services/Service.c
        UI/UI.h
        Undo_Redo/Undo_Redo.h
        Undo_Redo/UndoRedo.c
        main.c UI/UI.h UI/UI.c Undo_Redo/Undo_Redo.h Undo_Redo/UndoRedo.c Tests/tests.c)
