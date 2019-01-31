#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void mainWindow::displayTruncatedText(QFile &file)
{
    QTextStream out(&file);
    QString dataStr = out.readAll();
    int k = 0;
    for (int i = 0; i < dataStr.length(); i++) {
        if (k == 20)
            dataStr = dataStr.insert(i, '\n');
        if (dataStr[i] == '\n')
            k = 0;
        else
            k++;
    }
    ui->textBrowser->setText(dataStr);
}

void mainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "", "Text File (*.txt)");
    if (filename.length() == 0)
        return;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        displayTruncatedText(file);
    } else {
        QMessageBox::warning(this, "Error", file.errorString());
    }
}
