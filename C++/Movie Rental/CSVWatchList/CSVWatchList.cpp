//
// Created by Ale on 5/3/2023.
//

#include <fstream>
#include <windows.h>
#include "CSVWatchlist.h"

CSVWatchList::CSVWatchList()
{

}

CSVWatchList::~CSVWatchList()
{

}

void CSVWatchList::saveToFile()
{
    std::ofstream f("../CSVWatchList/watchlist.csv");
    for(auto &i : this->movies)
        f << i << "\n";
    f.close();
}

void CSVWatchList::openInFile()
{
    ShellExecuteA(NULL,
                  "open",
                  "C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE",
                  "../CSVWatchList/watchlist.csv",
                  NULL,
                  SW_SHOWMAXIMIZED);
}