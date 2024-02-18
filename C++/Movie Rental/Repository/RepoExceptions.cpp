//
// Created by Ale on 5/3/2023.
//
#include "RepoExceptions.h"

FileException::FileException(const std::string &mesg) : message(mesg)
{

}

const char * FileException::what()
{
    return message.c_str();
}

RepositoryExceptions::RepositoryExceptions() : exception{}, message{" "}
{
}

RepositoryExceptions::RepositoryExceptions(const std::string & mesg) : message(mesg)
{
}

const char * RepositoryExceptions::what()
{
    return this->message.c_str();
}

const char * DuplicateMovieException::what()
{
    return "    There is another movie with the same title and genre in the repository!";
}