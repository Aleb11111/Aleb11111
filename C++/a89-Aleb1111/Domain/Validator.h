//
// Created by Ale on 5/3/2023.
//

#ifndef A45_VALIDATOR_H
#define A45_VALIDATOR_H

#endif //A45_VALIDATOR_H

#pragma once
#include "Movie.h"
#include <exception>
#include <vector>

class Validator
{
public:
    Validator();
    ~Validator();

    void validate_movie(const Movie& movie);
};

class MovieException
{
private:
    std::vector<std::string> errors;

public:

    MovieException(std::vector<std::string> _errors);
    std::vector<std::string> getErrors() const;

};