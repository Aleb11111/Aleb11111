//
// Created by Ale on 3/29/2023.
//

#ifndef A45_SERVICE_H
#define A45_SERVICE_H

#endif //A45_SERVICE_H

#include "../Repository/Repository.h"
#include "../WatchList/WatchList.h"
#include "../FileRepository/FileRepository.h"

class Service{

private:
    Repository *repository;

public:
    Service();
    Service(Repository* repo) {this->repository = repo; }
    ~Service();

    //Repository getRepo(Service service);
    void add_Movie_service(const std::string& title, const std::string& genre, const int& year, const int& likes, std::string trailer);
    int delete_Movie_service(std::basic_string<char> title, std::basic_string<char> genre, const int likes, const int year, const char link[])
    {
        return this->repository->delete_Movie_repo(Movie(title,genre,likes,year,link));
    }
    int update_Movie_service(std::basic_string<char> title, std::basic_string<char> genre, int likes, int year, std::basic_string<char> link);
    std::vector<Movie> get_All_Movies_Service() {return this->repository->get_All_Movies_Repo();}
    int getPosition(const Movie& movie){return this->repository->does_the_movie_exist(movie);}

    void LikeVideo(const Movie& movie) {this->repository->incLikes(movie);}
    void save_to_file(){this->repository->saveToFile();}
};