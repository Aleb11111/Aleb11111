//
// Created by Ale on 5/3/2023.
//

#ifndef A45_CSVWATCHLIST_H
#define A45_CSVWATCHLIST_H

#endif //A45_CSVWATCHLIST_H

#pragma once
#include "../WatchList/WatchList.h"

class CSVWatchList :
        public WatchList
{
public:

    CSVWatchList();
    ~CSVWatchList();

    void saveToFile();
    void openInFile();
};