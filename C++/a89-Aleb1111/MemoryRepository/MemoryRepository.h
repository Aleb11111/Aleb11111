//
// Created by Ale on 4/12/2023.
//

#ifndef A45_MEMORYREPOSITORY_H
#define A45_MEMORYREPOSITORY_H

#endif //A45_MEMORYREPOSITORY_H

#include <vector>
#pragma once
#include "../Domain/Validator.h"
#include "../Repository/Repository.h"

class MmeoryRepository:
        public Repository
{
protected:
    std::vector<Movie> items;
    Validator validator_movies;
public:

    MmeoryRepository();
    ~MmeoryRepository();

    MmeoryRepository(const MmeoryRepository& otherRepo) {this->items = otherRepo.items;}

    std::vector<Movie> get_All_Movies_Repo() {return this->items;}

    int add_Movie_repo(Movie movie);
    int delete_Movie_repo(const Movie movie);
    int update_Movie_repo(const Movie movie);
    int does_the_movie_exist(Movie movie);
    void incLikes(const Movie movie) {this->items[does_the_movie_exist(movie)].incLikes();}

    void saveToFile();


};