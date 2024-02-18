//
// Created by Ale on 5/16/2023.
//

#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QDialog>
#include <QtWidgets>
#include <QTableWidget>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include "Interface.h"

GUI::GUI()
{
    this->title = new QLabel(this);
    this->adminbutton = new QPushButton(this);
    this->userbutton = new QPushButton(this);
    this->init();
}


void GUI::init()
{
    auto* layout = new QVBoxLayout(this);
    QFont titleFont = this->title->font();
    this->title->setText("<p style='text-align:center'><font color=#4D2D52> Welcome to the Movie Repository! </font></p>");
    titleFont.setItalic(true);
    titleFont.setPointSize(10);
    titleFont.setStyleHint(QFont::System);
//    titleFont.setWeight(63);
    this->title->setFont(titleFont);
    layout->addWidget(this->title);
    this->adminbutton->setText("Admin Mode");
    layout->addWidget(this->adminbutton);
    this->userbutton->setText("User Mode");
    layout->addWidget(this->userbutton);
    this->setLayout(layout);
    this->setStyleSheet("background-color:#D9DBF1");

}

GUI::~GUI()  = default;

void GUI::showAdmin()
{
    MmeoryRepository* admin_repo = new FileRepository("../CSVWatchList/movie.csv");
    Service* admin_serv = new Service{admin_repo};
    auto* admin = new AdminGUI(*admin_serv);
    admin->populateList();
    //admin->display();
    admin->show();
}

AdminGUI::AdminGUI(Service serv): service(serv)
{
    this->title = new QLabel(this);
    this->MovieListWidget = new QListWidget{};

    this->titleLineEdit = new QLineEdit{};
    this->genreLineEdit = new QLineEdit{};
    this->yearLineEdit = new QLineEdit{};
    this->likesLineEdit = new QLineEdit{};
    this->linkLineEdit = new QLineEdit{};

    this->addButton = new QPushButton("Add");
    this->deleteButton = new QPushButton("Delete");
    this->updateButton = new QPushButton("Update");
    this->showButton = new QPushButton("Show");

    setWindowFlag(Qt::Window);
    this->initAdmin();

}

void AdminGUI::initAdmin()
{
    auto* layout = new QVBoxLayout(this);
    QFont titleFont = this->title->font();
    this->title->setText("<p style='text-align:center'><font color=#4D2D52>Administrator Mode</font></p>");
    titleFont.setItalic(true);
    titleFont.setPointSize(10);
    titleFont.setStyleHint(QFont::System);
    //titleFont.setWeight(63);
    this->title->setFont(titleFont);
    layout->addWidget(this->title);

    layout->addWidget(this->MovieListWidget);

    auto* movieDetailsLayout = new QFormLayout{};
    movieDetailsLayout->addRow("Title",this->titleLineEdit);
    movieDetailsLayout->addRow("Genre",this->genreLineEdit);
    movieDetailsLayout->addRow("Likes",this->likesLineEdit);
    movieDetailsLayout->addRow("Year of release",this->yearLineEdit);
    movieDetailsLayout->addRow("Link",this->linkLineEdit);
    layout->addLayout(movieDetailsLayout);

    auto* buttonsLayout = new QGridLayout{};

    buttonsLayout->addWidget(this->addButton, 0, 0);
    buttonsLayout->addWidget(this->deleteButton, 0, 1);
    buttonsLayout->addWidget(this->updateButton, 1, 0);
    buttonsLayout->addWidget(this->showButton, 1, 1);
    layout->addLayout(buttonsLayout);

}

void AdminGUI::populateList()
{
    this->MovieListWidget->clear();
    std::vector<Movie> allMovies = this->service.get_All_Movies_Service();
//    auto* table = new QTableWidget(allMovies.size()+1,5);
//    table->insertRow(0);
//    auto* item = new QStandardItem(QString("index"));
//    table->setItem(0, 0, reinterpret_cast<QTableWidgetItem *>(item));

    for(auto &mov: allMovies)
    {
        std::string film;
        film = "   Title: " + mov.getTitle() + "   Genre: " + mov.getGenre() + "   Number of likes: " + std::to_string(mov.getLikes()) + "   Year of release: " + std::to_string(mov.getYear());
        this->MovieListWidget->addItem(QString::fromStdString(film));
    }

}

AdminGUI::~AdminGUI() = default;

void GUI::showUser()
{
    auto* user = new UserGUI();
    //user->initUser();
    user->show();
}

UserGUI::UserGUI()
{
    this->title = new QLabel(this);
    this->movieList = new QListWidget{};
    this->watchList = new QListWidget{};

    this->titleLineEdit = new QLineEdit{};
    this->genreLineEdit = new QLineEdit{};
    this->likesLineEdit = new QLineEdit{};
    this->yearLineEdit = new QLineEdit{};
    this->linkLineEdit = new QLineEdit{};

    this->genrefilter = new QLineEdit{};

    this->watchMovies = new QPushButton("Watch Movies");
    this->deleteButton = new QPushButton("Delete form watchlist");
    this->showButton = new QPushButton("Show watchlist");
    this->openFileButton = new QPushButton("Open file");
    this->saveFileButton = new QPushButton("Save file");
    this->addMovie = new QPushButton("Add to watchlist");
    this->filterButton = new QPushButton("Filter");
    this->HTML = new QRadioButton("HTML");
    this->CSV = new QRadioButton("CSV");
    initUser();
}

void UserGUI::initUser()
{
    auto* layout = new QVBoxLayout(this);
    QFont titleFont = this->title->font();
    this->title->setText("<p style='text-align:center'><font color=#4D2D52>User Mode <br> Select the type of file you want for saving your movies!</font></p>");
    titleFont.setItalic(true);
    titleFont.setPointSize(10);
    titleFont.setStyleHint(QFont::System);
    this->title->setFont(titleFont);
    layout->addWidget(this->title);

    auto* radioButtonsLayout = new QGridLayout(this);
    radioButtonsLayout->addWidget(this->CSV, 0, 0);
    radioButtonsLayout->addWidget(this->HTML, 1, 0);
    layout->addLayout(radioButtonsLayout);

    auto* listLayout = new QGridLayout(this);
    listLayout->addWidget(this->movieList, 0, 0);
    listLayout->addWidget(this->watchList, 0, 1);
    layout->addLayout(listLayout);

    auto * movielayout = new QFormLayout{};
    movielayout->addRow("Title", this->titleLineEdit);
    movielayout->addRow("Genre", this->genreLineEdit);
    movielayout->addRow("Likes", this->likesLineEdit);
    movielayout->addRow("Year of release", this->yearLineEdit);
    movielayout->addRow("Trailer link", this->linkLineEdit);
    movielayout->addRow(this->addMovie);
    layout->addLayout(movielayout);

    auto *filter = new QLabel("<p style='text-align:center'><font color=#4D2D52><br>Filter the available movies by genre</font></p>");
    QFont filterFont = filter->font();
    filterFont.setPointSize(10);
    filterFont.setStyleHint(QFont::System);
    //filterFont.setWeight(63);
    filter->setFont(filterFont);
    layout->addWidget(filter);

    auto *  filterDetailsLayout = new QFormLayout{};
    filterDetailsLayout->addRow("Genre", this->genrefilter);
    filterDetailsLayout->addRow(this->filterButton);
    layout->addLayout(filterDetailsLayout);

}

UserGUI::~UserGUI() = default;