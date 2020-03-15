#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_displayString = "";
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::loadText()
{
    QFile file("C:\\Users\\hc\\Desktop\\Test\\DailyTask.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        qDebug()<< str;
        m_displayString.append(str);
    }
}

void MainWindow::exportPic()
{
    QImage image; //以ARGB32格式构造一个QImage,
    image.load("C:\\Users\\hc\\Desktop\\Test\\img7.jpg");
    //image.fill(qRgba(0,0,0,100));//填充图片背景,120/250为透明度
    QPainter painter(&image); //为这个QImage构造一个QPainter
//    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    //设置画刷的组合模式CompositionMode_SourceOut这个模式为目标图像在上。
    //改变组合模式和上面的填充方式可以画出透明的图片。
    //改变画笔和字体
    QPen pen = painter.pen();
    pen.setColor(QColor(220,240,236));
    QFont font = painter.font();
    font.setBold(true);//加粗
    font.setPixelSize(30);//改变字体大小
    painter.setPen(pen);
    painter.setFont(font);
    painter.drawText(QRectF(image.width()-700,50,600,800),Qt::AlignLeft,m_displayString);
    //将Hello写在Image的中心
    int n = 100;//这个为图片的压缩度。0/100
    image.save("C:\\Users\\hc\\Desktop\\Test\\text.png","PNG",n);
}
