#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    ui->webView->load(QUrl("http://artax.karlin.mff.cuni.cz/~cochm5am/wiki/doku.php?id=qt#game_of_life"));
 }

About::~About()
{
    delete ui;
}

void About::on_okButton_clicked()
{
    close();
}

