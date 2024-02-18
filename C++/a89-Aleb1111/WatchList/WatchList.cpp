#include "WatchList.h"

WatchList::WatchList()
{
    /*
     * the initialization
     */
    this->movies = std::vector<Movie>();
    this->suggestions = std::vector<Movie>();
    this->current_movie = 0;
}

WatchList::~WatchList()
{}

int WatchList::findMovie(Movie movie)
{
    /*
     * returns -1 if the movie is not in the watch list or returns its position in the watch list
     */
    for(int i=0;i<=this->movies.size()-1;i++)
        if(this->movies[i].getGenre() == movie.getGenre() && this->movies[i].getTitle()==movie.getTitle())
            return i;
    return -1;
}

void WatchList::add(Movie movie)
{
    /*
     * adds a new movie in the watch list
     */
    this->movies.push_back(movie);

}

int WatchList::deleteMovie(Movie movie)
{
    /*
     * deletes a movie from watch list
     */
    int pos = findMovie(movie);
    if(pos != -1)
    {
        this->movies.erase(this->movies.begin()+pos);
        return 1;
    }
    else
    {
        return 0;
    }
}

Movie WatchList::getCurrentMovie()
{
    /*
     * returns the movie from the current index
     */
    return this->suggestions[this->current_movie];
}

Movie WatchList::findMovieByInfo(std::string title, std::string genre, int year)
{
    /*
     * finds the movie with a given title, genre and year of releaase
     */
    for(int i=0;i<=this->movies.size();i++)
        if(this->movies[i].getGenre() == genre && this->movies[i].getTitle() == title && this->movies[i].getYear() == year)
            return this->movies[i];
    Movie m;
    return m;
}

int WatchList::play()
{
    /*
     * starts the playing of trailers
     */
    if(this->movies.size() == 0)
        return 0;
    Movie currentMovie = this->getCurrentMovie();
    currentMovie.PlayTrailer();
    return  1;
}

void WatchList::next()
{
    /*
     * trece la urmatorul film
     */
    if(this->current_movie + 1 == this->movies.size()-1)
    {
        this->current_movie=0;
        return;
    }
    this->current_movie++;
}

bool WatchList::isEmpty()
{
    /*
     * returns true if the watch list is empty, false otherwise
     */
    return this->movies.size() == 0;
}

std::vector<Movie> WatchList::getSuggestions(std::vector<Movie> repo, std::string genre)
{
    if(genre == "''")
        return repo;
    else
    {
        std::vector<Movie> s = std::vector<Movie>();
        for (auto &i : repo)
        {
            if(i.getGenre() == genre)
                s.push_back(i);
        }
        return s;
    }

    this->current_movie = 0;

}