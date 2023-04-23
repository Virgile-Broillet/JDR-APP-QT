#include "musicwindow.h"
#include "ui_musicwindow.h"

MusicWindow::MusicWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MusicWindow)
{
    ui->setupUi(this);
}

MusicWindow::~MusicWindow()
{
    delete ui;
}
