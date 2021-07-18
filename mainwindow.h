#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void updatetimeanddisplay();

    void on_pushButton_start_clicked();

    void on_pushButton_end_clicked();

    void on_pushButton_PAUSE_clicked();

    void on_pushButton_split_clicked();

private:
    Ui::MainWindow *ui;
    QTime basetime;
    QTimer *ptimer;
    QString showStr;
};
#endif // MAINWINDOW_H
