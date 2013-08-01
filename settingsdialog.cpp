#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include <QSettings>
#include <defaultsettings.h>

Settingsdialog::Settingsdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settingsdialog)
{
    ui->setupUi(this);
    createConnections();
    readSettingsToEdit();


}


void Settingsdialog::readSettingsToEdit(){
    QSettings settings("config.ini", QSettings::IniFormat);

    ui->heightLineEdit->setText(QString::number(DEFAULT_NUMBER_OF_HSQUARES));
    ui->widthLineEdit->setText(QString::number(DEFAULT_NUMBER_OF_WSQUARES));
    ui->sizeOfSquareLineEdit->setText(QString::number(DEFAULT_SIZE_OF_SQUARE));
}


void Settingsdialog::createConnections(){
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

Settingsdialog::~Settingsdialog()
{
    delete ui;
}

void Settingsdialog::on_cancelButton_clicked()
{
    close();
}

void Settingsdialog::on_okButton_clicked()
{
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.setValue("HSquares",ui->heightLineEdit->text());
    settings.setValue("WSquares",ui->widthLineEdit->text());
    settings.setValue("sizeOfSquare",ui->sizeOfSquareLineEdit->text());
    settings.sync();
    exit(0);
}

void Settingsdialog::on_restoreButton_clicked()
{
    ui->heightLineEdit->setText(QString::number(DEFAULT_NUMBER_OF_HSQUARES));
    ui->widthLineEdit->setText(QString::number(DEFAULT_NUMBER_OF_WSQUARES));

    ui->sizeOfSquareLineEdit->setText(QString::number(DEFAULT_SIZE_OF_SQUARE));
}
