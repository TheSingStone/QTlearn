#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QAction>
#include <QTextEdit>

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

private:
    Ui::MainWindow *ui;
    QAction *openAction;
    QAction *saveAction;
    QTextEdit *textEdit;
    void openFile();
    void saveFile();
};

#endif // MAINWINDOW_H
