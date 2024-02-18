//
// Created by Ale on 3/27/2023.
//

#ifndef A45_MOVIE_H
#define A45_MOVIE_H

#endif //A45_MOVIE_H

#pragma once
#include <iostream>

class Movie
{
private:
    std :: string Title;
    std :: string Genre;
    int number_likes;
    int year_release;
    std :: string Link;

public:
    Movie();
    Movie(const std :: string& title,const std :: string& genre, const int& likes, const int& year, const std::string& link);
    std::string getTitle() const { return Title;  }
    std::string getGenre() const { return Genre;  }
    int getYear() const { return year_release;  }
    int getLikes() const { return number_likes;  }
    std::string getTrailer() const { return Link;  }

    void PlayTrailer();

    bool operator==(Movie movie_2);

    friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
    void incLikes();
};

