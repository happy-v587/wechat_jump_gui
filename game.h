#ifndef GAME_H
#define GAME_H

#include <QVector>
#include <QProcess>
#include <QPoint>
#include <QThread>

class Game : public QObject
{
Q_OBJECT

public:
    QVector<QPoint> cord;
    QProcess process;


public:
    Game(){}

    void getPic()
    {
        process.start(QString("adb shell screencap -p /sdcard/1.png"));
        process.waitForFinished();
        process.start(QString("adb pull /sdcard/1.png ."));
        process.waitForFinished();
    }

    void jump(double distance, double ratio)
    {
        int press_time = int(distance * ratio);
        QString cmd = QString("adb shell input swipe 320 410 320 410 ") + QString::number(press_time);

        process.start(cmd);
        process.waitForFinished();
        QThread::msleep(2000);
    }

    void run(double ratio)
    {
        if( cord.size() == 2)
        {
            double dis = sqrt(pow(cord[0].x() - cord[1].x(), 2) + pow(cord[0].y() - cord[1].y(), 2));
            cord.clear();
            jump(dis, ratio);
            getPic();
        }
    }

public slots:
    void slot_setCord(QPoint point)
    {
        cord.append(point);
    }

};

#endif // GAME_H
