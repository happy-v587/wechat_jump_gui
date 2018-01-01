#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QRect>
#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QVector>
#include <QtMath>
#include <QThread>
#include <QComboBox>
#include <QScrollArea>
#include <QDesktopServices>


#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showImage();
    void paintEvent(QPaintEvent *);

private slots:
    void on_runBtn_clicked(bool checked);
    void on_scaleCombox_currentIndexChanged(int index);
    void on_zhihu_clicked(bool checked);

protected:
    virtual bool eventFilter(QObject *watched, QEvent *e);
    void paintOnWidget(QWidget *w);

private:
    Ui::MainWindow *ui;
    Game  game;
    float scale = 0.50;
    QPixmap* img = nullptr;
};

#endif // MAINWINDOW_H
