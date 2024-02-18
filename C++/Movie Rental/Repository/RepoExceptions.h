//
// Created by Ale on 5/3/2023.
//

#ifndef A45_REPOEXCEPTIONS_H
#define A45_REPOEXCEPTIONS_H

#endif //A45_REPOEXCEPTIONS_H

#pragma once
#include <exception>
#include <string>

class RepositoryExceptions: public std::exception
{
protected:
    std::string message;

public:

    RepositoryExceptions();
    RepositoryExceptions(const std::string& mesg);

    virtual  ~RepositoryExceptions() {}
    virtual const char* what();
};

class DuplicateMovieException : public RepositoryExceptions
{
public:
    const char* what();
};

class FileException : public std::exception
{
protected:
    std::string message;
public:
    FileException(const std::string& mesg);
    virtual const char* what();
};