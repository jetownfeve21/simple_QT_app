#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QFile>
#include<QMessageBox>
#include<QIODevice>
#include<QTextStream>

mainWindow::mainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "", "Text File (*.txt)");
    if (filename.length() == 0)
        return;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream out(&file);
        QString data = out.readAll();
        ui->textBrowser->setText(data);
    } else {
        QMessageBox::warning(this, "Error", file.errorString());
    }
}
