#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

class QMenuBar;
class QMenu;
class QLabel;
class Board;
class QAction;
class StatusAndControl;
class About;
class SimpleGame;
class Settingsdialog;

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();



private:
    void createMenus();
    void createActions();
    void createConnections();
    void writeSettings(/*bool write_default = 0*/);
    void readSettings();

    //vrchne menu
    QMenu *gameMenu;
    QMenu *settingsMenu;
    QMenu *helpMenu;

    //akcie
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *exitAct;

    QAction *settingsAct;
    QAction *aboutAct;

public:
    SimpleGame *game;
    Board *board;
    StatusAndControl *sac;
    About *about;
    Settingsdialog *preferences;

public slots:
   void createAbout();
   void createPreferences();

protected:
    void closeEvent(QCloseEvent *event);

};

#endif // MAINWINDOW_H
