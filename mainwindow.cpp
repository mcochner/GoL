#include <QtGui>
#include "simplegame.h"
#include "mainwindow.h"
#include "board.h"
#include "defaultsettings.h"
#include "statusandcontrol.h"
#include "about.h"
#include "settingsdialog.h"
#include "globalpointers.h"

MainWindow::MainWindow()
{
    GlobalPointers *global = GlobalPointers::getInstance();

    sac = new StatusAndControl(this);
    global->sac = sac;

    board = new Board(this);
    global->board = board;


    game = new SimpleGame(this);
    global->game = game;


    sac->createConnections();

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(board);
    mainLayout->addWidget(sac);


    //setLayout(mainLayout); //nemozem priamo pridat na mainwindow, musim obklukou
    QWidget *mainArea = new QWidget;
    setCentralWidget(mainArea);
    mainArea->setLayout(mainLayout);


    // MENU
    createActions();
    createMenus();
    createConnections();

    //nastavim spravnu velkost spravnu velkost:
    this->setFixedSize(this->sizeHint().width() , this->sizeHint().height());
    readSettings();

}

void MainWindow::readSettings(){

    QSettings settings("config.ini", QSettings::IniFormat);
    move(settings.value("pos", QPoint(50, 50)).toPoint());
}


void MainWindow::writeSettings()
{
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.setValue("pos", pos());
}


void MainWindow::closeEvent(QCloseEvent *event) {
    writeSettings();
    QMainWindow::closeEvent(event);
}

void MainWindow::createMenus()
{
    gameMenu = menuBar()->addMenu(tr("&Game"));
    gameMenu->addAction(newAct);
    gameMenu->addSeparator();
    gameMenu->addAction(exitAct);

    settingsMenu = menuBar()->addMenu(tr("&Settings"));
    settingsMenu->addAction(settingsAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}

void MainWindow::createActions() // action is an item that can be added to any number
// of menus and toolbars
{
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));


    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Erase the board"));
    connect(newAct, SIGNAL(triggered()), game, SLOT(clearGame()));


    settingsAct = new QAction(tr("&Preferences"), this);
    settingsAct->setShortcuts(QKeySequence::Preferences);
    settingsAct->setStatusTip(tr("Configure the application"));
    connect(settingsAct, SIGNAL(triggered()), this, SLOT(createPreferences()));

    aboutAct = new QAction(tr("&About"),this);
    aboutAct->setStatusTip(tr("Exit the application"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(createAbout()));


}

MainWindow::~MainWindow(){
    delete(gameMenu);
    delete(settingsMenu);
    delete(board);
}

void MainWindow::createConnections(){
    connect(board, SIGNAL(labelChanged(int)), sac, SLOT(changeAliveLabel(int)));
    connect(board, SIGNAL(cellChanged(int,int,bool)), game, SLOT(setCell(int,int,bool)));
    connect(game, SIGNAL(squaresChanged()), board, SIGNAL(squaresChangedfromGame()));
}

void MainWindow::createAbout(){
    //qDebug() << "createAbout";
    about = new About(this);
    about->setModal(true);
    about->show();
}

void MainWindow::createPreferences(){
    //qDebug() << "createAbout";
    preferences = new Settingsdialog(this);
    preferences->setModal(true);
    preferences->show();
}
