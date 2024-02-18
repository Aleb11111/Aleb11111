//
// Created by Ale on 3/29/2023.
//

#include "Service.h"

Service::Service()
{

}

Service::~Service()
{

}

void Service::add_Movie_service(const std::string& title, const std::string& genre, const int& year, const int& likes, std::string trailer)
{
    Movie m{title,genre,likes,year,trailer};
    this->repository->add_Movie_repo(m);
}

int Service::update_Movie_service(std::basic_string<char> title, std::basic_string<char> genre, const int likes, const int year, std::basic_string<char> link)
{
    return this->repository->update_Movie_repo(Movie(title,genre,likes,year,link));
}