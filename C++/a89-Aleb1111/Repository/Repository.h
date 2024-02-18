//
// Created by Ale on 3/28/2023.
//

#ifndef A45_REPOSITORY_H
#define A45_REPOSITORY_H

#endif //A45_REPOSITORY_H
#pragma once
#include <iostream>
#include "../Domain/Movie.h"
#include <vector>

class Repository
{
private:
    std::vector<Movie> movies;
    std::string filename;
public:

    Repository();
    ~Repository();

    virtual std::vector<Movie> get_All_Movies_Repo() = 0;
    virtual int does_the_movie_exist(Movie movie) = 0;
    virtual int add_Movie_repo(Movie movie) = 0;
    virtual int delete_Movie_repo(const Movie movie) = 0;
    virtual int update_Movie_repo(const Movie movie) = 0;

    virtual void incLikes(const Movie movie) = 0;

    virtual void saveToFile() = 0;

    void Initialize();




};


