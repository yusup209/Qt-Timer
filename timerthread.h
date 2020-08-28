#ifndef TIMERTHREAD_H
#define TIMERTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QDateTime>

class TimerThread : public QThread
{
    Q_OBJECT
public:
    explicit TimerThread(QObject *parent = nullptr);
    void run() override;
    void stop();

private:
    QTimer *timer;
    bool timerStarted = false;
    int secc = 0;

public slots:
    void startTimer();
    void stopTimer();
    void setSecs(int sec);

private slots:
    void formatToTime();
    void timerTimeout();

signals:
    void updateSec(QString jam);
};

#endif // TIMERTHREAD_H
