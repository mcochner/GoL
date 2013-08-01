#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class Settingsdialog;
}

class Settingsdialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Settingsdialog(QWidget *parent = 0);
    ~Settingsdialog();
    
private slots:
    void on_cancelButton_clicked();
    void on_okButton_clicked();

    void on_restoreButton_clicked();

private:
    Ui::Settingsdialog *ui;
    void createConnections();
    void readSettingsToEdit();
};

#endif // SETTINGSDIALOG_H
