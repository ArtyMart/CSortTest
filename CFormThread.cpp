#include "CFormThread.h"

CFormThread::CFormThread(QObject *parent): QThread(parent)
{}

void CFormThread::run()
{
    emit workStarted();
    QThread::sleep(3); // ��������� ������ ����������
    emit workEnded();
}