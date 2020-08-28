#include "timerthread.h"

TimerThread::TimerThread(QObject *parent) : QThread(parent)
{
    timer = new QTimer(this);
    timer->setInterval(1000);
    qDebug() << "init timer thread";
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
}

void TimerThread::run(){
    qDebug() << "run timer thread";
    startTimer();
}

void TimerThread::stop(){
    qDebug() << "stop timer thread";
    stopTimer();
}

void TimerThread::setSecs(int sec){
    qDebug() << "set secs to "+QString::number(sec);
    secc = sec;
}

void TimerThread::startTimer(){
    qDebug() << "start timer";
    if (!timerStarted){
        timer->start();
        timerStarted = !timerStarted;
    }
}

void TimerThread::stopTimer(){
    qDebug() << "stop timer";
    if (timerStarted){
        timer->stop();
        timerStarted = !timerStarted;
    }
}

void TimerThread::timerTimeout(){
    qDebug() << "timer timeout";
    if (secc >= 0){
        qDebug() << "lebih dari 0 atau = 0";
        secc--;
        formatToTime();

        if (secc == 0){
            qDebug() << "sama dengan 0";
            stop();
        }
    } else {
        qDebug() << "dah habis";
        stopTimer();
    }
}

void TimerThread::formatToTime(){
    qDebug() << "format to time and emit updateSec";
    emit updateSec(QDateTime::fromTime_t(secc).toUTC().toString("hh:mm:ss"));
}

