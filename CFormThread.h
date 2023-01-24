#ifndef FORMTHREAD_H
#define FORMTHREAD_H
#include <QThread>

class CFormThread  : public QThread
{
    Q_OBJECT

public:
    CFormThread(QObject *parent);
    void run();

signals:
    void workStarted();
    void workEnded();
};

#endif// FORMTHREAD_H