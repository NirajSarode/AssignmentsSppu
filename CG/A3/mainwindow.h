#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    void dda(float,float,float,float);
    int sign(float);
    void translate(float,float,float,float,float,float);
    void scale(float,float,float,float,float,float);
    void rotate(float,float,float,float,float);
    void mulmat(float [][3],float [][3]);
};

#endif // MAINWINDOW_H
