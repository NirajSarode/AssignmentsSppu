#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QColorDialog"
#include "math.h"
QColor col,col2;
QImage image(400,400,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap::fromImage(image));
    dda(200,0,200,400);
    dda(0,200,400,200);


}
void MainWindow::dda(float x1, float y1, float x2, float y2)
{
    QRgb value=qRgb(250,0,0);
    float dx=abs(x2-x1);
    float dy=abs(y2-y1);
    float step;
    if(dx>dy)
        step=dx;
    else
        step=dy;
    dx=dx/step;
    dy=dy/step;
    float x=x1;
    float y=y1;
    float i=1;
    while(i<=step)
    {
        image.setPixel(x,y,value);
        x=x+dx*sign(x2-x1);
        y=y+dy*sign(y2-y1);
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}
void MainWindow::mulmat(float a[2][3],float b[2][3]){
    float mat[2][3];
    int i,j,k;
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            mat[i][j]=0;
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
          {
            for(k=0;k<3;k++)
            {
                mat[i][j]=mat[i][j]+a[i][k]*b[k][j];
            }
        }
    dda(mat[0][0]+200,-mat[0][1]+200,mat[1][0]+200,-mat[1][1]+200);
}

int MainWindow::sign(float t){
    if(t<0)
        return -1;
    return 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::translate(float x1, float y1, float x2, float y2, float tx, float ty)
{
    int i,j;
    float a[2][3];
    float b[3][3];
    //float c[2][3];
    a[0][0]=x1;
    a[0][1]=y1;
    a[0][2]=1;
    a[1][0]=x2;
    a[1][1]=y2;
    a[1][2]=1;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            if(i==j)
                b[i][j]=1;
            else
                b[i][j]=0;
        }
    b[2][0]=tx;
    b[2][1]=ty;
    mulmat(a,b);
}
/*void MainWindow::mousePressEvent(QMouseEvent* eve)
{
    if(start==true)
    {
        int p=eve->pos().x();
        int q=eve->pos().y();
        z[h]=p;
        v[h]=q;
        if(eve->button()==Qt::RightButton)
        {
            dda(z[0],v[0],z[h-1],v[h-1]);
                    start=false;
        }
        else
        {
            if(h>0)
            {
                dda(z[h-1],v[h-1],z[h],v[h]);
            }

        }
        h++;

    }
}*/
void MainWindow::scale(float x1, float y1, float x2, float y2, float sx,float sy){
    int i,j;
    float a[2][3];
    float b[3][3];
    //float c[2][3];
    a[0][0]=x1;
    a[0][1]=y1;
    a[0][2]=1;
    a[1][0]=x2;
    a[1][1]=y2;
    a[1][2]=1;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            b[i][j]=0;
        }
    b[0][0]=sx;
    b[1][1]=sy;
    b[2][2]=1;
    mulmat(a,b);
}
void MainWindow::rotate(float x1, float y1, float x2, float y2, float theta)
{
    int i,j;
    float a[2][3];
    float b[3][3];

    a[0][0]=x1;
    a[0][1]=y1;
    a[0][2]=1;
    a[1][0]=x2;
    a[1][1]=y2;
    a[1][2]=1;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            b[i][j]=0;
        }
    b[0][0]=cos(theta);
    b[0][1]=-sin(theta);
    b[1][0]=sin(theta);
    b[1][1]=cos(theta);
    b[2][2]=1;
    mulmat(a,b);
}

void MainWindow::on_pushButton_clicked()
{

    float x1=ui->textEdit->toPlainText().toFloat();
    float y1=ui->textEdit_2->toPlainText().toFloat();
    float x2=ui->textEdit_3->toPlainText().toFloat();
    float y2=ui->textEdit_4->toPlainText().toFloat();
    float tx=ui->textEdit_5->toPlainText().toFloat();
    float ty=ui->textEdit_6->toPlainText().toFloat();
    translate(x1,y1,x2,y2,tx,ty);

}

void MainWindow::on_pushButton_3_clicked()
{
    float x1=ui->textEdit->toPlainText().toFloat();
    float y1=ui->textEdit_2->toPlainText().toFloat();
    float x2=ui->textEdit_3->toPlainText().toFloat();
    float y2=ui->textEdit_4->toPlainText().toFloat();
    float tx=ui->textEdit_5->toPlainText().toFloat();
    float ty=ui->textEdit_6->toPlainText().toFloat();
    scale(x1,y1,x2,y2,tx,ty);
}

void MainWindow::on_pushButton_2_clicked()
{
    float x1=ui->textEdit->toPlainText().toFloat();
    float y1=ui->textEdit_2->toPlainText().toFloat();
    float x2=ui->textEdit_3->toPlainText().toFloat();
    float y2=ui->textEdit_4->toPlainText().toFloat();
    float theta=ui->textEdit_7->toPlainText().toFloat();
            theta=(3.14*theta)/180;
    rotate(x1,y1,x2,y2,theta);
}

void MainWindow::on_pushButton_4_clicked()
{
    float x1=ui->textEdit->toPlainText().toFloat();
    float y1=ui->textEdit_2->toPlainText().toFloat();
    float x2=ui->textEdit_3->toPlainText().toFloat();
    float y2=ui->textEdit_4->toPlainText().toFloat();
    dda(x1+200,-y1+200,x2+200,-y2+200);
}
