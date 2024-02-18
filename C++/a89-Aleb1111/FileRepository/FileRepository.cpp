#include "FileRepository.h"
#include "../Domain/Movie.h"
#include "../util.h"

FileRepository::FileRepository()
{

}

FileRepository::FileRepository(const FileRepository &otherRepo) :MmeoryRepository(otherRepo)
{
    this->filename = otherRepo.filename;
    loadFromFile();
}

FileRepository::~FileRepository()
{

}

void FileRepository::loadFromFile()
{
    std::ifstream f(this->filename);

    if(!f.is_open())
        std::cout<<"Not opened!";

    std::string temp;
    std::string* args;

    while(!f.eof())
    {
        std::getline(f, temp);
        if(f.eof() || temp == "")
        {
            f.close();
            break;
        }

        args = splitString(temp);
        add_Movie_repo(Movie{args[0],args[1],stoi(args[2]),stoi(args[3]),args[4]});
    }
    f.close();
}

void FileRepository::saveToFile()
{
    std::ofstream f(this->filename);
    for (auto &i: this->items)
        f << i << std::endl;
    f.close();
}
