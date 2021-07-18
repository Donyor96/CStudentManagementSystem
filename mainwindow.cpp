#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ptimer = new QTimer;
    connect(this->ptimer, SIGNAL(timeout()), this, SLOT(updatetimeanddisplay()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updatetimeanddisplay()
{
    QTime curr = QTime::currentTime();
    int nt = this->basetime.msecsTo(curr);
    QTime showtime;
    showtime.setHMS(0,0,0,0);
    showtime = showtime.addMSecs(nt);
    //this->basetime = this->basetime.addMSecs(1);
    showStr = showtime.toString("hh:mm:ss:zzz");
    this->ui->lcdNumber->display(showStr);
}

void MainWindow::on_pushButton_start_clicked()
{
    //this->basetime.setHMS(0,0,0,0);
    this->basetime = QTime::currentTime();
    this->ptimer->start(1);
    this->ui->pushButton_start->setEnabled(false);
}

void MainWindow::on_pushButton_end_clicked()
{
    //this->ptimer->stop();
    if(this->ui->pushButton_end->text()=="end")
    {
        this->ui->pushButton_end->setText("clear");
        this->ptimer->stop();
    }
    else
    {
        this->ui->lcdNumber->display("00:00:00:000");
        this->ui->textBrowser->clear();
        this->ui->pushButton_end->setText("end");
        this->ui->pushButton_start->setEnabled(true);
    }
}

void MainWindow::on_pushButton_PAUSE_clicked()
{
    //this->ptimer->stop();
    static QTime pausetim;

    if(this->ui->pushButton_PAUSE->text()=="pause")
    {
        pausetim = QTime::currentTime();
        this->ptimer->stop();
        this->ui->pushButton_PAUSE->setText("continue");
    }
    else
    {
        QTime cut = QTime::currentTime();
        int ntt = pausetim.msecsTo(cut);
        this->basetime = this->basetime.addMSecs(ntt);
        this->ptimer->start();
        this->ui->pushButton_PAUSE->setText("pause");
    }
}

void MainWindow::on_pushButton_split_clicked()
{
    this->ui->textBrowser->append(showStr);
}
