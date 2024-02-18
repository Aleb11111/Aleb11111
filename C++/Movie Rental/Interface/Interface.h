//
// Created by Ale on 5/16/2023.
//

#ifndef UNTITLED1_INTERFACE_H
#define UNTITLED1_INTERFACE_H

#endif //UNTITLED1_INTERFACE_H
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QDialog>
#include <QTableWidget>
#include <QMainWindow>
#include <QComboBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QRadioButton>
#include "../Service/Service.h"

class GUI: public QWidget
{
private:

    void init();
    QLabel* title;
    QPushButton* adminbutton;
    QPushButton* userbutton;


public:

    GUI();
    ~GUI();
    void showAdmin();
    void showUser();
};

class AdminGUI: public QWidget
{
private:
    QLabel* title;
    QListWidget* MovieListWidget;
    //QTableWidget* MovieListWidget;
    QLineEdit *titleLineEdit, *genreLineEdit, *yearLineEdit, *likesLineEdit, *linkLineEdit;
    QPushButton* addButton, *deleteButton, *updateButton, *showButton;

    void addMovie();
    void deleteMovie();
    void updateMovie();
    void showMovies();

    void initAdmin();

    Service service;


public:
    AdminGUI(Service serv);
    ~AdminGUI();
    void display();
    void populateList();
};

class UserGUI: public QWidget
{
private:

    QLabel* title;
    QListWidget* movieList, *watchList;
    QLineEdit* genrefilter;
    QRadioButton* HTML, *CSV;
    QLineEdit* titleLineEdit, *genreLineEdit, *yearLineEdit, *likesLineEdit, *linkLineEdit;
    QPushButton* watchMovies, *deleteButton, *openFileButton, *showButton, *saveFileButton, *addMovie, *filterButton;
    void initUser();

public:

    UserGUI();
    ~UserGUI();

};