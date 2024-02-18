#pragma once
#include "../Domain/Movie.h"
#include <vector>
class WatchList
{
protected:
    std::vector<Movie> movies;

    int current_movie;

public:
    WatchList();
    ~WatchList();
    std::vector<Movie> suggestions;

    void add(Movie movie);
    int deleteMovie(Movie movie);

    std::vector<Movie> getSuggestions(std::vector<Movie> repo, std::string genre);

    int getSize() const {return this->movies.size();}



    int findMovie(Movie movie);
    Movie getCurrentMovie();
    std::vector<Movie> getList() {return this->movies;}

    Movie findMovieByInfo(std::string title, std::string genre, int year);
    int play();
    void next();
    bool isEmpty();

    virtual void saveToFile() = 0;
    virtual void openInFile() = 0;

};

