#include <QCoreApplication>
#include <QtPrintSupport/QPrinter>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSize size(200,200); //指定图片大小;
    QImage image(size,QImage::Format_ARGB32); //以ARGB32格式构造一个QImage,
    //image.fill(qRgba(0,0,0,100));//填充图片背景,120/250为透明度
    QPainter painter(&image); //为这个QImage构造一个QPainter
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    //设置画刷的组合模式CompositionMode_SourceOut这个模式为目标图像在上。
    //改变组合模式和上面的填充方式可以画出透明的图片。
    //改变画笔和字体
    QPen pen = painter.pen();
    pen.setColor(Qt::red);
    QFont font = painter.font();
    font.setBold(true);//加粗
    font.setPixelSize(50);//改变字体大小
    painter.setPen(pen);
    painter.setFont(font);
    painter.drawText(image.rect(),Qt::AlignCenter,"Hello");
    //将Hello写在Image的中心
    int n = 100;//这个为图片的压缩度。0/100
    image.save("image.bmp","bmp",n);
    return a.exec();
}
