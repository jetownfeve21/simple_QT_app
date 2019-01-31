#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include<QFileDialog>
#include<QFile>
#include<QMessageBox>
#include<QIODevice>
#include<QTextStream>


namespace Ui {
class mainWindow;
}

class mainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::mainWindow *ui;
    void displayTruncatedText(QFile &file);
};

#endif // MAINWINDOW_H
