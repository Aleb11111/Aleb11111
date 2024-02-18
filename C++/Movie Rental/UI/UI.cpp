//
// Created by Ale on 3/29/2023.
//

#include "../Repository/RepoExceptions.h"
#include "UI.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <cstring>

UI::UI() {

}

UI::~UI()
{

}

UI::UI(Service serv, WatchList *wl)
{
    this->service = serv;
    this->watchList = wl;
}




void UI::printMenuApp()
{
    system("cls");
    std::cout<<"\n            Options: \n";
    std::cout<<"    admin ---> administrator mode.\n";
    std::cout<<"    user ---> user mode.\n";
    std::cout<<"    exit ---> exit the application.\n";
}

void UI::runApp() {

    this->service.save_to_file();
    this->watchList->saveToFile();

    while (true)
    {
        printMenuApp();
        std::string command;
        std::cout << "Your choice: ";
        std::getline(std::cin, command);

        if(command == "exit")
            break;
        if(command == "admin")
        {
            system("cls");
            std::cout<<"\n      Now you are in Admin mode.\n";
            Sleep(2000);
            runAdmin();
            system("cls");
            std::cout << "You are no longer in administrator mode. \n";
            Sleep(2000);
            continue;
        }

        if( command == "user")
        {
            system("cls");
            std::cout << "\n	Now you are in User mode\n";
            Sleep(2000);
            runUser();
            system("cls");
            std::cout << "\n	You are no more in User mode! ^_^\n";
            Sleep(2000);
            continue;
        }

        std::cout << "	Invalid mode!\n";
        Sleep(2000);
    }

    this->service.save_to_file();
    this->watchList->saveToFile();

}


void UI::printMenuAdmin()
{
    system("cls");
    std::cout<<"\n       ADMINISTRATOR MODE \n";
    std::cout<<"  add ---> add a movie.\n";
    std::cout<<"  delete ---> delete a movie. \n";
    std::cout<<"  update ---> update a movie. \n";
    std::cout<<"  show ---> show all the movies. \n";
    std::cout<<"  exit ---> exit administrator mode. \n";
}

void UI::runAdmin()
{

    while(true)
    {
        printMenuAdmin();
        std::string command;
        std::cout<<"Your choice: ";
        std::getline(std::cin,command);

        if(command == "exit")
            break;
        if(command == "add")
        {
            consoleADD();
            Sleep(2000);
            continue;
        }
        if(command == "delete")
        {
            consoleDELETE();
            Sleep(2000);
            continue;
        }
        if(command == "update")
        {
            consoleUPDATE();
            Sleep(2000);
            continue;
        }
        if(command == "show")
        {
            consoleSHOW();
            Sleep(2000);
            std::cout<<"\n\n";
            continue;
        }

        std::cout << "	Invalid command!\n\n";
        Sleep(2000);
    }
    }


void UI::printMenuUser()
{
    system("cls");
    std::cout<<"\n       USER MODE \n";
    std::cout<<"  watch ---> see movies by genre. \n";
    std::cout<<"  show ---> show the watchlist. \n";
    std::cout<<"  delete ---> delete a watched movie. \n";
    std::cout<<"  open ---> display the watchlist. \n";
    std::cout<<"  exit ---> exit user mode. \n";
}

void UI::runUser()
{
    while (true)
    {
        printMenuUser();
        std::string command;
        std::getline(std::cin, command);
        if (command == "exit")
            break;
        if (command == "watch")
        {
            userWATCH();
            Sleep(2000);
            continue;
        }
        if (command == "show")
        {
            userShow();
            Sleep(2000);
            continue;
        }
        if (command == "delete")
        {
            userDELETE();
            Sleep(2000);
            continue;
        }

        if (command == "save")
        {
            userSave();
            Sleep(2000);
            continue;
        }
        if (command == "open")
        {
            userOpen();
            Sleep(2000);
            continue;
        }
        std::cout << "	Invalid command!\n\n";
        Sleep(2000);
    }
}


void UI::printWatchMenu(Movie& m)
{
    system("cls");
    std::cout<<"\n\n\n        WATCHLIST MENU \n";
    std::cout<<"     Title: "<< m.getTitle()<<"\n";
    std::cout<<"  next ---> go to the next movie.\n";
    std::cout<<"  add ---> add the movie into the WatchList. \n";
    std::cout<<"  exit --> exit watch mode. \n";
}

void UI::consoleADD()
{
    std::string title, genre, year, nbLikes, trailer;
    std::cout << "	Insert title: ";
    std::getline(std::cin, title);
    std::cout << "	Insert genre: ";
    std::getline(std::cin, genre);
    std::cout << "	Insert year: ";
    std::getline(std::cin, year);
    std::cout << "	Insert number of likes: ";
    std::getline(std::cin, nbLikes);
    std::cout << "	Insert trailer link: ";
    std::getline(std::cin, trailer);

    try {
        this->service.add_Movie_service(title,genre,std::stoi(year), std::stoi(nbLikes) ,trailer);
    }
    catch (MovieException& e)
    {
        for(auto &s : e.getErrors())
            std::cout << s;
    }
    catch (RepositoryExceptions& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (FileException& e)
    {
        std::cout<< e.what() << '\n';
    }
    catch (std::invalid_argument e)
    {
        std::cout << "Insert numbers! \n";
    }
}

void UI::consoleDELETE()
{
    std::string title, genre;

    std::cout<<"Insert the title: ";
    std::getline(std::cin,title);
    std::cout<<"Insert the genre: ";
    std::getline(std::cin,genre);

    try
    {
        this->service.delete_Movie_service(title,genre,2312,2000,"http");
    }
    catch (MovieException& e)
    {
        for (auto &s : e.getErrors())
            std::cout << s;
    }
    catch (RepositoryExceptions& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (FileException& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (std::invalid_argument e)
    {
        std::cout << "Insert numbers! \n";
    }
}

void UI::consoleUPDATE()
{
    std::string title, genre, year, nbLikes, trailer;
    std::cout << "	Insert title: ";
    std::getline(std::cin, title);
    std::cout << "	Insert genre: ";
    std::getline(std::cin, genre);
    std::cout << "	Insert year: ";
    std::getline(std::cin, year);
    std::cout << "	Insert number of likes: ";
    std::getline(std::cin, nbLikes);
    std::cout << "	Insert trailer link: ";
    std::getline(std::cin, trailer);

    try {
        this->service.update_Movie_service(title,genre, std::stoi(nbLikes), std::stoi(year),trailer);
    }
    catch (MovieException& e)
    {
        for (auto s : e.getErrors())
            std::cout << s;
    }
    catch (RepositoryExceptions& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (FileException& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (std::invalid_argument e)
    {
        std::cout << "Insert numbers\n";
    }
}

void UI::consoleSHOW()
{
    for(auto &i : this->service.get_All_Movies_Service())
        std::cout<<"Title: "<<i.getTitle()<<" Genre: " << i.getGenre()
        << " Number of likes: "<< i.getLikes() << " Year of release: "
        << i.getYear() << " Trailer: " <<i.getTrailer()<<"\n\n";

}

void UI::userWATCH()
{
    std::cout<<"Please enter the genre: ";
    std::string genre;
    std::getline(std::cin,genre);

    std::vector<Movie> s;
    std::vector<Movie> movies = this->service.get_All_Movies_Service();
    s = this->watchList->getSuggestions(movies,genre);

    this->watchList->suggestions = s;

    if(this->watchList->suggestions.size() == 0)
        std::cout<<"There are 0 movies of this genre.\n";
    else
    {
        while(1)
        {
            if(this->watchList->suggestions.size() == 0)
                break;
            Movie m = this->watchList->getCurrentMovie();
            m.PlayTrailer();
            printWatchMenu(m);

            std::string command;
            std::cout<<"\nYour choice: \n";
            std::getline(std::cin,command);

            if(command == "exit")
                break;
            if(command == "add")
            {
                this->watchList->add(m);
                continue;
            }
            if(command == "next")
            {
                this->watchList->next();
                continue;
            }

            std::cout<<"   Invalid command! Try again.\n\n";
            Sleep(2000);

        }
    }

    if(s.size() == 0)
    {
        std::cout << "	That's all for now!\n";
        Sleep(3000);
    }
}

void UI::userShow()
{
    if(this->watchList->getList().size() ==0)
        std::cout << "\n	No movie in your WatchList!\n";
    else
        for(auto &m: this->watchList->getList())
            std::cout << "Movie with title: " << m.getTitle() << " genre: " << m.getGenre() << " from year: " << m.getYear() << " which has: " << m.getLikes() << " likes and has the trailer: " << m.getTrailer() << "\n";
    Sleep(5000);
}

void UI::userDELETE()
{
    std::cout << "Input title: ";
    std::string title;
    std::getline(std::cin, title);

    std::cout << "Input genre: ";
    std::string genre;
    std::getline(std::cin, genre);

    Movie m{title,genre,9,2000,"http://sfds"};

    if(this->watchList->deleteMovie(m) == 0)
    {
        std::cout << "	Inexistent movie!\n";
        Sleep(2000);
    }
    else
    {
        std::cout << "	Like the movie? (yes / no): ";
        std::string liked;

        do
        {
            std::getline(std::cin, liked);
            if (liked != "yes" && liked != "no")
                std::cout << "	Invalid option\n";
        } while (liked != "yes" && liked != "no");

        if (liked == "yes")
            this->service.LikeVideo(m);
    }
}

void UI::userSave()
{
    this->watchList->saveToFile();
}

void UI::userOpen()
{
    this->watchList->openInFile();
}


//
//UI::UI(const Service serv) : service(serv){}
//
//Service UI::getService()
//{
//    return this->service;
//}
//
//void UI::PrintMenu()
//{
//    std::cout<<"\nMenu: \n";
//    std::cout<<"1. Administrator mode.\n";
//    std::cout<<"2. User mode.\n";
//}
//
//void UI::Initialize()
//{
//    /*this->service.add_Movie_service("Jurassic World","action",123213,2019,"https://www.youtube.com/watch?v=RFinNxS5KN4&ab_channel=UniversalPictures");
//    this->service.add_Movie_service("Jurassic Park","action",193820,1993,"https://www.youtube.com/watch?v=_jKEqDKpJLw&ab_channel=Amblin");
//    this->service.add_Movie_service("How to train your dragon","animation",439321,2010,"https://www.youtube.com/watch?v=2AKsAxrhqgM&ab_channel=RottenTomatoesClassicTrailers");
//    this->service.add_Movie_service("Star Wars: The Rise of Skywalker","action",94638,2019,"https://www.youtube.com/watch?v=8Qn_spdM5Zg&ab_channel=StarWars");
//    this->service.add_Movie_service("Lord of the Rings","adventure",982373,2003,"https://www.youtube.com/watch?v=r5X-hFf6Bwo&ab_channel=Movieclips");
//    this->service.add_Movie_service("The Nun","horror",128700,2018,"https://www.youtube.com/watch?v=zwAM5UnGd2s&ab_channel=FilmSelectTrailer");
//    this->service.add_Movie_service("The conjuring 2","horror",129879,2016,"https://www.youtube.com/watch?v=VFsmuRPClr4&ab_channel=WarnerBros.Pictures");
//    this->service.add_Movie_service("After","drama",123003,2019,"https://www.youtube.com/watch?v=u0zhw8Ilb6g&ab_channel=FilmSiChannel");
//    this->service.add_Movie_service("Me before you","drama",449713,2016,"https://www.youtube.com/watch?v=Eh993__rOxA&ab_channel=RottenTomatoesTrailers");
//    this->service.add_Movie_service("Puss in boots the last wish","animation",991309,2022,"https://www.youtube.com/watch?v=RqrXhwS33yc&ab_channel=UniversalPictures");*/
//    this->service.init();
//}
//
//void UI::PrintMenuAdmin()
//{
//    std::cout<<"\nMenu administrator:\n";
//    std::cout<<"add - Add a movie.\n";
//    std::cout<<"delete - Delete a movie.\n";
//    std::cout<<"update - Update a movie.\n";
//    std::cout<<"Show all - Show movies.\n";
//}
//
//void UI::PrintMenuUser()
//{
//    std::cout<<"\nMenu User:\n";
//    std::cout<<"watch - Watch Trailers.\n";
//    std::cout<<"delete - Delete from Watch List.\n";
//    std::cout<<"show - Show movies from Watch List\n";
//}
//
//void UI::watchStart()
//{
//    std::cout<<"Please insert the genre: ";
//    char genre[20]="";
//    std::cin.getline(genre,20);
//    WatchList list = this->service.filterbyGenre(genre);
//    Movie m;
//    char command[20];
//
//    while(!list.isEmpty())
//    {
//
//        list.play();
//        m = list.getCurrentMovie();
//        std::cout<<"\nMovie with title: "<< m.getTitle() << " genre: "<<m.getGenre() <<" nr. of likes: "<<m.getLikes() <<" year of release: "<<m.getYear()<<std::endl;
//        std::cout<<"You can: \n";
//        std::cout<<"next - play the next movie trailer\n";
//        std::cout<<"add - add to the Watch list\n";
//        std::cout<<"exit\n";
//        std::cout<<"Your option: ";
//        std::cin.getline(command,20);
//        if(strcmp(command,"exit")==0)
//            return;
//        if(strcmp(command,"add")==0)
//        {
//            this->service.addMovietoWatchList(m);
//            list.deleteMovie(m);
//            list.next();
//
//        }
//        if(strcmp(command,"next")==0)
//            list.next();
//    }
//
//    if(list.isEmpty())
//        std::cout<<"There are no movies!\n";
//}
//
//void UI::printWatchList(WatchList* wl)
//{
//    if(wl->isEmpty())
//    {
//        std::cout<<"There is no movie in your watch list!\n";
//        return;
//    }
//    Movie movie;
//    int i=0;
//    std::cout<<"Movies in your Watch list: \n";
//    while(wl->isEmpty()==false)
//    {
//        movie=wl->getCurrentMovie();
//        std::cout<<"Movie :"<<movie.getTitle() <<"\n";
//        i++;
//        if(i==wl->getSize())
//            break;
//        wl->next();
//    }
//}
//
//void UI::user_delete_watchlist_ui()
//{
//    if(this->service.getWatchList()->isEmpty())
//    {
//        std::cout<<"Your watch list is empty!";
//        return;
//    }
//    char title[50],genre[20],liked[5],year[4];
//    std::cout<<"Insert title: ";
//    std::cin.getline(title,50);
//    std::cout<<"Insert genre: ";
//    std::cin.getline(genre,20);
//    std::cout<<"Did you enjoyed the movie? Yes/No.";
//    std::cin.getline(liked,5);
//    std::cout<<"Insert the year of release: ";
//    std::cin.getline(year,4);
//
//    int sem=0;
//    if(strcmp(liked,"yes")==0)
//    {
//        Movie movie;
//        movie = this->service.getWatchList()->findMovieByInfo(title,genre,atoi(year));
//        this->service.LikeVideo(movie);
//        sem=1;
//        std::cout<<"\nMovie liked and deleted from Watch List!";
//    }
//    this->service.deleteMovieWatchList(title,genre);
//    if(sem==0)
//        std::cout<<"Movie deleted from Watch List.\n";
//}
//
//void UI::Start()
//{
//    PrintMenu();
//    Initialize();
//    char choice[10];
//    std::cout<<"Your choice: ";
//    std::cin.getline(choice,10);
//    while(strcmp(choice,"exit")!=0)
//    {
//        while(strcmp(choice,"admin") !=0 && strcmp(choice,"user")!=0 && strcmp(choice,"exit")==0)
//        {
//            std::cout<<"That is not an option! Try again.\n";
//            std::cout<<"Your choice: ";
//            std::cin.getline(choice,10);
//        }
//
//        if(strcmp(choice,"admin")==0)
//        {
//            PrintMenuAdmin();
//            char choice2[10];
//            std::cout<<"Your choice: ";
//            std::cin.getline(choice2,10);
//            while(strcmp(choice2,"exit")!=0)
//            {
//                while(strcmp(choice2,"add")!=0 && strcmp(choice2,"delete")!=0 && strcmp(choice2,"update")!=0 && strcmp(choice2,"Show all")!=0 && strcmp(choice2,"exit")!=0)
//                {
//                    std::cout<<"That is not an option! Try again.\n";
//                    std::cout<<"Your choice: ";
//                    std::cin.getline(choice2,10);
//                }
//
//                if(strcmp(choice2,"add")==0)
//                    this->add_Movie_ui();
//                else
//                if(strcmp(choice2,"Show all")==0)
//                    PrintMovies();
//                else
//                if(strcmp(choice2,"delete")==0)
//                    delete_Movie_ui();
//                else
//                if(strcmp(choice2,"update")==0)
//                    update_Movie_ui();
//                PrintMenuAdmin();
//                std::cout<<"\nYour choice: ";
//                std::cin.getline(choice2,10);
//            }
//        }
//        else
//        {
//            if(strcmp(choice,"user")==0)
//            {
//                PrintMenuUser();
//                char choice2[10];
//                std::cout<<"Your choice: ";
//                std::cin.getline(choice2,10);
//                while(strcmp(choice2,"exit")!=0)
//                {
//                    if(strcmp(choice2,"watch")==0)
//                    {
//                        watchStart();
//                        PrintMenuUser();
//                        std::cout<<"Your choice: ";
//                        std::cin.getline(choice2,10);
//                    }
//                    if(strcmp(choice2,"show")==0)
//                    {
//                        std::cout<<std::endl;
//                        WatchList* list = this->service.getWatchList();
//                        printWatchList(list);
//                        PrintMenuUser();
//                        std::cout<<"Your choice: ";
//                        std::cin.getline(choice2,10);
//                    }
//                    if(strcmp(choice2,"delete")==0)
//                    {
//                        std::cout<<"\nWhat do you want to do after?\n";
//                        PrintMenuUser();
//                        std::cout<<"Your choice: ";
//                        std::cin.getline(choice2,10);
//                        std::cout<<"\nThe previous delete starts now: \n";
//                        user_delete_watchlist_ui();
//
//                    }
//
//                }
//            }
//            else
//            {
//                if(strcmp(choice,"exit")==0)
//                    return;
//            }
//        }
//
//        PrintMenu();
//        std::cout<<"Your choice: ";
//        std::cin.getline(choice,10);
//
//        while(strcmp(choice,"admin") !=0 && strcmp(choice,"user")!=0 && strcmp(choice,"exit")!=0)
//        {
//            std::cout<<"That is not an option! Try again.\n";
//            std::cout<<"Your choice: ";
//            std::cin.getline(choice,10);
//        }
//
//    }
//}
//
//
//void UI::add_Movie_ui()
//{
//    char title[100],genre[20],link[1000],year[5],nr_likes[10];
//
//    std::cout<<"Type a title: ";
//    std::cin.getline(title,100);
//
//    std::cout<<"The genre can be: action, adventure, animation, horror, drama.\n";
//    std::cout<<"Type the genre of the movie: ";
//    std::cin.getline(genre,20);
//
//    while(strcmp(genre,"action")!=0 && strcmp(genre,"adventure")!=0 && strcmp(genre,"animation")!=0 && strcmp(genre,"horror")!=0 && strcmp(genre,"drama")!=0)
//    {
//        std::cout<<"That category isn't correct.\n";
//        std::cout<<"Type the genre of the movie: ";
//        std::cin.getline(genre,20);
//    }
//
//    std::cout<<"Type the number of likes: ";
//    std::cin.getline(nr_likes,10);
//
//    while(atoi(nr_likes) <=0)
//    {
//        std::cout<<"Can't have such a number of likes!";
//        std::cout<<"Type another number of likes";
//        std::cin.getline(nr_likes,10);
//    }
//
//    std::cout<<"Type the year of release: ";
//    std::cin.getline(year,5);
//
//    while(atoi(year) <=1888)
//    {
//        std::cout<<"Movies were not invented back then!";
//        std::cout<<"Type another year of release: ";
//        std::cin.getline(year,5);
//    }
//    while(atoi(year) >2027)
//    {
//        std::cout<<"That movie isn't release yet!";
//        std::cout<<"Type another year of release: ";
//        std::cin.getline(year,5);
//    }
//
//    std::cout<<"Insert the link of the trailer: ";
//    std::cin.getline(link,100);
//
//    this->service.add_Movie_service(title,genre,atoi(nr_likes),atoi(year),link);
//
//}
//
//void UI::PrintMovies()
//{
//    std::vector<Movie> list = this->service.get_All_Movies_Service();
//
//    for(int i=0;i<list.size();i++)
//        std::cout<<std::endl<<"Title: "<<list[i].getTitle() <<" Genre: "<<list[i].getGenre() <<" Likes: "<<list[i].getLikes() <<" Release year: "<<list[i].getYear() <<" Link: "<<list[i].getTrailer();
//
//}
//
//void UI::delete_Movie_ui()
//{
//    char title[50],genre[20];
//    std::cout<<"Type a title: ";
//    std::cin.getline(title,50);
//
//    std::cout<<"The genre can be: action, adventure, animation, horror, drama.\n";
//    std::cout<<"Type the genre of the movie: ";
//    std::cin.getline(genre,20);
//
//    while(strcmp(genre,"action")!=0 && strcmp(genre,"adventure")!=0 && strcmp(genre,"animation")!=0 && strcmp(genre,"horror")!=0 && strcmp(genre,"drama")!=0)
//    {
//        std::cout<<"That category isn't correct.\n";
//        std::cout<<"Type the genre of the movie: ";
//        std::cin.getline(genre,20);
//    }
//
//    this->service.delete_Movie_service(title,genre,0,0,"ewr");
//}
//
//void UI::update_Movie_ui()
//{
//    char title[50],genre[20],nr_likes[10],year[5],link[100];
//    std::cout<<"Type a title: ";
//    std::cin.getline(title,50);
//
//    std::cout<<"The genre can be: action, adventure, animation, horror, drama.\n";
//    std::cout<<"Type the genre of the movie: ";
//    std::cin.getline(genre,20);
//
//    while(strcmp(genre,"action")!=0 && strcmp(genre,"adventure")!=0 && strcmp(genre,"animation")!=0 && strcmp(genre,"horror")!=0 && strcmp(genre,"drama")!=0)
//    {
//        std::cout<<"That category isn't correct.\n";
//        std::cout<<"Type the genre of the movie: ";
//        std::cin.getline(genre,20);
//    }
//    std::cout<<"Type the number of likes: ";
//    std::cin.getline(nr_likes,10);
//
//    while(atoi(nr_likes) <=0)
//    {
//        std::cout<<"Can't have such a number of likes!";
//        std::cout<<"Type another number of likes";
//        std::cin.getline(nr_likes,10);
//    }
//
//    std::cout<<"Type the year of release: ";
//    std::cin.getline(year,5);
//
//    while(atoi(year) <=1888)
//    {
//        std::cout<<"Movies were not invented back then!";
//        std::cout<<"Type another year of release: ";
//        std::cin.getline(year,5);
//    }
//    while(atoi(year) >2027)
//    {
//        std::cout<<"That movie isn't release yet!";
//        std::cout<<"Type another year of release: ";
//        std::cin.getline(year,5);
//    }
//
//    std::cout<<"Insert the link of the trailer: ";
//    std::cin.getline(link,100);
//    this->service.update_Movie_service(title,genre,atoi(nr_likes),atoi(year),link);
//}
//
//void UI::savePlaylistToFile()
//{
//    try {
//        this->service.save_to_file();
//        if(this->service.getWatchList() == nullptr)
//        {
//            std::cout << "Playlist cannot be displayed!" << std::endl;
//            return;
//        }
//    }
//    catch (std::exception)
//    {
//        std::cout<<"Exception";
//    }
//}