//
// Created by Ale on 4/12/2023.
//
#include "../Repository/RepoExceptions.h"
#include "MemoryRepository.h"
#include <fstream>
#include <Windows.h>

MmeoryRepository::MmeoryRepository()
{
    this->items = std::vector<Movie>();
    this->validator_movies = Validator();
}

MmeoryRepository::~MmeoryRepository()
{
}

int MmeoryRepository::does_the_movie_exist(Movie movie)
{
    int ct=0;
    for(auto &m: this->items)
    {
        if(m.getTitle() == movie.getTitle() && m.getGenre() == movie.getGenre())
            return ct;
        ct++;
    }
     return -1;
}

int MmeoryRepository::add_Movie_repo(Movie movie)
{
    validator_movies.validate_movie(movie);
    int pos = does_the_movie_exist(movie);
    if(pos != -1)
    {
        throw DuplicateMovieException();
    }
    this->items.push_back(movie);
    return 1;
}

int MmeoryRepository::delete_Movie_repo(const Movie movie)
{
    int pos;
    pos = does_the_movie_exist(movie);
    if(pos == -1)
    {
        std::cout<<"No such movie!\n";
        return 0;
    }
    this->items.erase(this->items.begin()+pos);
    return 1;
}

int MmeoryRepository::update_Movie_repo(const Movie movie)
{
    int pos;
    pos = does_the_movie_exist(movie);
    if(pos == -1)
    {
        std::cout<<"No such movie!\n";
        return 0;
    }
    this->items[pos]=movie;
    return 1;
}

void MmeoryRepository::saveToFile()
{}