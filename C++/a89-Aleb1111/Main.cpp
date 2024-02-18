//
// Created by Ale on 3/27/2023.
//
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include "Domain/Movie.h"
#include "Tests/Test.h"
#include "CSVWatchList/CSVWatchlist.h"
#include "HTMLWatchList/HTMLWatchList.h"
#include "Interface/Interface.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>

#include "userGUI/userGUI.h"


int main(int argc, char *argv[])
{
//
//    std::string type = "";
//    while(1)
//    {
//        system("cls");
//        std::cout << "\n	For exit type: exit\n";
//        std::cout << "	Choose file type (csv or html): ";
//        std::getline(std::cin,type);
//        std::cout<<"\n\n";
//        if (type == "exit")
//        {
//            std::cout << "\n\n	Bye!!! :)\n";
//            Sleep(1000);
//            break;
//        }
//        if(type == "csv" || type == "html")
//        {
//            MmeoryRepository* admin_repo = new FileRepository("../CSVWatchList/movie.csv");
//            WatchList* user_repo;
//            if(type == "csv")
//                user_repo = new CSVWatchList();
//            else
//                user_repo = new HTMLWatchList();
//
//            Service* admin_serv = new Service{admin_repo};
//            UI* ui = new UI(*admin_serv,user_repo);
//
//            ui->runApp();
//
//        }
//
//    }

    QApplication a(argc,argv);
    GUI ui;

    //ui.init();
    //ui.show();

    ui.show();
    ui.showAdmin();
    ui.showUser();
    return QApplication::exec();
}
