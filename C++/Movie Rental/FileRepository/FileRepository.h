//
// Created by Ale on 4/12/2023.
//

#ifndef A45_FILEREPOSITORY_H
#define A45_FILEREPOSITORY_H

#endif //A45_FILEREPOSITORY_H


#pragma once
#include "../MemoryRepository/MemoryRepository.h"
#include "fstream"


class FileRepository :
        public MmeoryRepository
{
private:
    std::string filename;
    void loadFromFile();

public:
    FileRepository();
    FileRepository(const std::string& filename) {this->filename = filename; loadFromFile();}
    FileRepository(const FileRepository& otherRepo);
    ~FileRepository();

    void saveToFile();
};