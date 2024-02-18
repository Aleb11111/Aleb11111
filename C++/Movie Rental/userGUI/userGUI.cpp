////
//// Created by Ale on 5/16/2023.
////
//
//#include "userGUI.h"
//
//int UserGUI::userInterface(int argc, char* argv[])
//{
//    QApplication a(argc,argv);
//    this->setObjectName(QStringLiteral("User UI"));
//    this->resize(544,443);
//    this->setStyleSheet(QStringLiteral("background: rgb(154, 216, 176)"));
//
//
//    QFont buttonfont("Consolas",13,true);
//    this->sh = new QPushButton("Show WatchList");
//    this->sh->setFont(buttonfont);
//
//    this->watch = new QPushButton("Watch Trailers");
//    this->watch->setFont(buttonfont);
//
//    this->del = new QPushButton("Delete Trailer");
//    this->del->setFont(buttonfont);
//
//    this->open = new QPushButton("Open WatchList");
//    this->open->setFont(buttonfont);
//
//    this->save = new QPushButton("Save WatchList");
//    this->save->setFont(buttonfont);
//
//    auto* mainLayout = new QVBoxLayout();
//
//    auto* buttonsLayout = new QGridLayout();
//    buttonsLayout->addWidget(this->sh, 0, 0);
//    buttonsLayout->addWidget(this->watch, 1, 0);
//    buttonsLayout->addWidget(this->del, 2, 0);
//    buttonsLayout->addWidget(this->open, 3, 0);
//    mainLayout->addLayout(buttonsLayout);
//    auto *mainWindow = new QWidget();
//    mainWindow->setLayout(mainLayout);
//
//    return a.exec();
//
//}
