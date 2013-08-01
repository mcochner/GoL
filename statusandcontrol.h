#ifndef STATUSANDCONTROL_H
#define STATUSANDCONTROL_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QPushButton>

class StatusAndControl : public QWidget
{
    Q_OBJECT
public:
    explicit StatusAndControl(QWidget *parent = 0);
    QLabel *aliveCells;
    QLabel *deadCells;
    void createConnections();
signals:

public slots:
    void changeAliveLabel(int alive);
    void do5Steps();
private:


    int numOfAliveCells;
    int numOfDeadCells;

    QPushButton *playButton;
    QPushButton *play5Button;
    QString labelCaption(int);
    
};

#endif // STATUSANDCONTROL_H
