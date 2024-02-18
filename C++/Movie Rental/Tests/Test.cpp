////
//// Created by Ale on 3/27/2023.
////
//
//#include "Movie.h"
//#include "Test.h"
//#include <cassert>
//#include "DynamicArray.h"
//#include "Repository.h"
//#include "UI.h"
//void tests::Test_Movie()
//{
//    Movie movie{"Jurassic World","Action",212312,2019,"https://www.youtube.com/watch?v=7L72L9qHpyc&ab_channel=MSApreviouslyMyStoryAnimated"};
//    Movie mov_2{"Jurassic World","Action",212312,2019,"https://www.youtube.com/watch?v=7L72L9qHpyc&ab_channel=MSApreviouslyMyStoryAnimated"};
//    Movie mov_3{"Jurassic World","Action",212312,2019,"df"};
//    assert(movie.getTitle() == "Jurassic World");
//    assert(movie.getGenre() == "Action");
//    assert(movie.getLikes() == 212312);
//    assert(movie.getYear() == 2019);
//    assert(movie.getTrailer() == "https://www.youtube.com/watch?v=7L72L9qHpyc&ab_channel=MSApreviouslyMyStoryAnimated");
//
//    assert(movie == mov_2);
//    assert((movie==mov_3)==false);
//    Movie m;
//    assert(m.getLikes()==0);
//    assert(m.getTrailer()=="");
//    assert(m.getYear()==0);
//
//    movie.PlayTrailer();
//
//}
//
//void tests::Test_DynamicArray()
//{
//    DynamicArray<int> arr{5};
//
//    arr.addElem(3);
//    assert(arr.getIndex()==1);
//    assert(arr.getSpecificElement(0) == 3);
//    arr.addElem(9);
//    arr.addElem(12);
//    arr.addElem(5);
//    arr.addElem(8);
//    assert(arr.getSpecificElement(2) ==12);
//    assert(arr.getIndex()==5);
//
//    arr.deleteElem(0);
//    assert(arr.getSpecificElement(0)==9);
//
//    arr.updateElem(0,7);
//    arr.updateElem(0,10);
//    assert(arr.getSpecificElement(0) == 10);
//    arr.addElem(5);
//    arr.addElem(8);
//    assert(arr.getCapacity() == 10);
//
//}
//
//void tests::Test_Repository()
//{
//    Repository repo = Repository();
//    Movie m{"Jurassic World","Action",212312,2019,"dsf"};
//    //assert(repo.add_Movie_repo(m)==1);
//    //assert(repo.add_Movie_repo(m)==0);
//    int pox = repo.does_the_movie_exist(m);
//    Movie m2{"Jurassic Park","Action",21312,1999,"dweewsf"};
//
//    pox=repo.does_the_movie_exist(m2);
//    assert(repo.add_Movie_repo(m2)==1);
//    assert(pox==-1);
//    /*
//    repo.delete_Movie_repo(m);
//    pox=repo.does_the_movie_exist(m);
//    assert(pox == -1); */
//
//    assert(repo.delete_Movie_repo(m) == 1);
//    assert(repo.delete_Movie_repo(m) == 0);
//
//    //Movie m3{"Jurassic World","Action",1,1,"dsfds"};
//    Movie m3{"Jurassic World","Action",22,2019,"dsf"};
//    assert(repo.does_the_movie_exist(m3)==-1);
//    assert(repo.add_Movie_repo(m3)==1);
//    assert(repo.update_Movie_repo(m3) == 1);
//    assert(repo.does_the_movie_exist(m3)!=-1);
//    assert(repo.delete_Movie_repo(m3) == 1);
//    assert(repo.update_Movie_repo(m3) == 0);
//
//    Repository r2 = Repository();
//
//    r2.Initialize();
//    Movie mov{"Jurassic World","action",123213,2019,"https://www.youtube.com/watch?v=RFinNxS5KN4&ab_channel=UniversalPictures"};
//    assert(r2.does_the_movie_exist(mov)!=-1);
//
//    Movie mov2{"Jurassic Park","action",193820,1993,"https://www.youtube.com/watch?v=_jKEqDKpJLw&ab_channel=Amblin"};
//    assert(r2.does_the_movie_exist(mov2)!=-1);
//    Movie mov3{"How to train your dragon","animation",439321,2010,"https://www.youtube.com/watch?v=2AKsAxrhqgM&ab_channel=RottenTomatoesClassicTrailers"};
//    assert(r2.does_the_movie_exist(mov3)!=-1);
//    Movie m4{"Star Wars: The Rise of Skywalker","action",94638,2019,"https://www.youtube.com/watch?v=8Qn_spdM5Zg&ab_channel=StarWars"};
//    assert(r2.does_the_movie_exist(m4)!=-1);
//    Movie m5{"Lord of the Rings","adventure",982373,2003,"https://www.youtube.com/watch?v=r5X-hFf6Bwo&ab_channel=Movieclips"};
//    assert(r2.does_the_movie_exist(m5)!=-1);
//    Movie m6{"The Nun","horror",128700,2018,"https://www.youtube.com/watch?v=zwAM5UnGd2s&ab_channel=FilmSelectTrailer"};
//    assert(r2.does_the_movie_exist(m6)!=-1);
//    Movie m7{"The conjuring 2","horror",129879,2016,"https://www.youtube.com/watch?v=VFsmuRPClr4&ab_channel=WarnerBros.Pictures"};
//    assert(r2.does_the_movie_exist(m7)!=-1);
//    Movie m8{"After","drama",123003,2019,"https://www.youtube.com/watch?v=u0zhw8Ilb6g&ab_channel=FilmSiChannel"};
//    assert(r2.does_the_movie_exist(m8)!=-1);
//    Movie m9{"Me before you","drama",449713,2016,"https://www.youtube.com/watch?v=Eh993__rOxA&ab_channel=RottenTomatoesTrailers"};
//    assert(r2.does_the_movie_exist(m9)!=-1);
//    Movie m10{"Puss in boots the last wish","animation",991309,2022,"https://www.youtube.com/watch?v=RqrXhwS33yc&ab_channel=UniversalPictures"};
//    assert(r2.does_the_movie_exist(m10)!=-1);
//
//
//
//
//}
//void tests::Test_Service()
//{
//    Repository repository = Repository();
//    Movie m{"HTTYD","Animation",122,2010,"dsf"};
//    Service serv = Service(repository=repository);
//    serv.add_Movie_service("HTTYD","Animation",122,2010,"dsf");
//    assert(serv.getRepo(serv).does_the_movie_exist(m) !=-1);
//    serv.update_Movie_service("HTTYD","Animation",1,201,"dsf");
//    serv.delete_Movie_service("HTTYD","Animation",122,2010,"dsf");
//    assert(serv.getRepo(serv).does_the_movie_exist(m)==-1);
//
//    Repository repo2=Repository();
//    Service serv2 = Service(repository=repo2);
//    serv2.add_Movie_service("HTTYD","Animation",122,2010,"dsf");
//
//    DynamicArray<Movie> movie(20);
//    Movie mm{"HTTYD","Animation",122,2010,"dsf"};
//    movie.addElem(mm);
//    assert(serv.getWatchList().play()==0);
//    /*assert(movie.getCapacity() == serv2.get_All_Movies_Service().);
//    assert(movie.getIndex() == serv2.get_All_Movies_Service().getIndex());
//    for(int i=0;i<=movie.getIndex();i++)
//        assert(movie.getSpecificElement(i) == serv2.get_All_Movies_Service().getSpecificElement(i));*/
//
//    serv.addMovietoWatchList(mm);
//    assert(serv.getWatchList().getCurrentMovie()==mm);
//    std::string title=mm.getTitle();
//    serv.deleteMovieWatchList(title,mm.getGenre());
//    assert(serv.getWatchList().isEmpty()==true);
//    assert(serv.getWatchList().deleteMovie(mm)==0);
//
//    serv.addMovietoWatchList(mm);
//    assert(serv.LikeVideo(mm)==1);
//
//    assert(serv.filterbyGenre("''").isEmpty()==false);
//    assert(serv.filterbyGenre("animation").isEmpty()==true);
//    //assert(serv.filterbyGenre("animation"));
//    assert(serv.startWatchList()==1);
//    serv.nextWatchList();
//    serv.addMovietoWatchList(mm);
//    serv.nextWatchList();
//
//    serv.getWatchList().findMovieByInfo(mm.getTitle(),mm.getGenre(),mm.getYear());
//    Movie mmmmm;
//    mmmmm=serv.getWatchList().findMovieByInfo("asda","adsad",3);
//    assert(mmmmm.getTitle()=="");
//
//    WatchList wl;
//    assert(wl.getSize()==0);
//
//}
