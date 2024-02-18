//
// Created by Ale on 3/27/2023.
//

#include "Movie.h"
#include <iostream>
#include <windows.h>
#include <shellapi.h>



Movie :: Movie() : Title(""),Genre(""),number_likes(0),year_release(0),Link(""){}

Movie :: Movie(const std :: string& ti,const std :: string& gen, const int& likes, const int& year, const std::string& lin)
{
    this->Title = ti;
    this->Genre = gen;
    this->number_likes = likes;
    this->year_release = year;
    this->Link =lin;
}

void Movie::PlayTrailer()
{
    ShellExecuteA(NULL,NULL,"chrome.exe",this->getTrailer().c_str(),NULL,SW_SHOWMAXIMIZED);
}

bool Movie::operator==(Movie movie_2)
{
    if(this->Title == movie_2.getTitle() && this->Genre == movie_2.getGenre() && this->number_likes == movie_2.getLikes() && this->year_release == movie_2.year_release && this->Link == movie_2.getTrailer())
        return true;
    return false;
}

void Movie::incLikes()
{
    this->number_likes++;
}

std::ostream& operator<<(std::ostream& os, const Movie& m)
{
    os<<m.getTitle()<<","<<m.getGenre()<<","<<m.getLikes()<<","<<m.getYear()<<","<<m.getTrailer();
    return os;
}