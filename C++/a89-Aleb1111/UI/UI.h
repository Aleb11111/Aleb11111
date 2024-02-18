//
// Created by Ale on 3/29/2023.
//

#ifndef A45_UI_H
#define A45_UI_H

#endif //A45_UI_H
#pragma once
#include "../Service/Service.h"

class UI
{
private:
    Service service;
    WatchList* watchList;

public:

    UI();
    UI(Service serv, WatchList* wl);
    ~UI();

    void runApp();

private:

    void runAdmin();
    void runUser();

    void printMenuApp();
    void printMenuAdmin();
    void printMenuUser();
    void printWatchMenu(Movie& m);

    void consoleADD();
    void consoleDELETE();
    void consoleUPDATE();
    void consoleSHOW();


    void userWATCH();
    void userShow();
    void userDELETE();
    void userSave();
    void userOpen();

//
//public:
//
//    UI(const Service serv);
//
//    Service getService();
//
//    void add_Movie_ui();
//    void delete_Movie_ui();
//    void update_Movie_ui();
//    void Initialize();
//    void PrintMovies();
//    static void PrintMenu();
//    static void PrintMenuAdmin();
//    void Start();
//
//    void PrintMenuUser();
//    void watchStart();
//    void user_delete_watchlist_ui();
//    void printWatchList(WatchList* wl);
//
//    void savePlaylistToFile();

};


