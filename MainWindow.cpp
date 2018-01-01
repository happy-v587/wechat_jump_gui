#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->imageLabel->installEventFilter(this);

    connect(ui->zhihu, SIGNAL(triggered(bool)), this, SLOT(on_zhihu_clicked(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showImage()
{
    if( img == nullptr)
        img = new QPixmap();

    img->load("1.png");
    ui->imageLabel->setPixmap(img->scaled(img->size()*scale));
}

bool MainWindow::eventFilter(QObject *watched, QEvent *e)
{
    if (watched == ui->imageLabel && e->type() == QEvent::MouseButtonPress)
    {
        qDebug() << "pos = " << ((QMouseEvent *)e)->pos();
        game.cord.append(((QMouseEvent *)e)->pos());
        game.run(double(ui->ratio->value() / 1000.0 / scale));
        showImage();
    }

    return QWidget::eventFilter(watched, e);
}

void MainWindow::paintOnWidget(QWidget *w)
{
    if ( img == nullptr) img = new QPixmap();
    img->load("1.png");

    QPainter painter(w);
    painter.drawPixmap(0, 0, img->scaled(img->width() * scale, img->height() * scale));
    painter.setPen(QPen(Qt::blue, 4));//设置画笔形式
    //painter.drawEllipse(ev->pos(), 5, 5);
    painter.end();
}

void MainWindow::paintEvent(QPaintEvent *ev)
{
    qDebug() << "paintEvent" ;
}

void MainWindow::on_runBtn_clicked(bool checked)
{
    game.cord.clear();
    game.getPic();
    showImage();
}

void MainWindow::on_scaleCombox_currentIndexChanged(int index)
{
    int id = ui->scaleCombox->currentIndex();
    switch (id) {
    case 0:
        scale = 0.25;
        break;
    case 1:
        scale = 0.50;
        break;
    case 2:
        scale = 0.75;
        break;
    case 3:
        scale = 1.00;
        break;
    default:
        break;
    }

    showImage();

}

void MainWindow::on_zhihu_clicked(bool checked)
{
    QDesktopServices::openUrl(QUrl("https://zhuanlan.zhihu.com/p/32525962"));
}
