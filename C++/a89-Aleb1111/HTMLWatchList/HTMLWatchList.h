//
// Created by Ale on 5/3/2023.
//

#ifndef A45_HTMLWATCHLIST_H
#define A45_HTMLWATCHLIST_H

#endif //A45_HTMLWATCHLIST_H

#pragma once
#include "../WatchList/WatchList.h"

class HTMLWatchList :
        public WatchList
{
public:

    HTMLWatchList();
    ~HTMLWatchList();

    void saveToFile();
    void openInFile();

};