#ifndef CSORTTEST_H
#define CSORTTEST_H

#include <QtWidgets/QMainWindow>
#include "ui_CSortTest.h"
#include "CUsersDispatcher.h"

class CSortTest : public QMainWindow
{
    Q_OBJECT

public:
    CSortTest(QWidget *parent = nullptr);
    ~CSortTest();

private slots:
    void slotNewWindow();
    void slotSetUser(EUserType);

signals:
    void signalChangeUser(EUserType);
    void signalLogIn(QString);
    void signalCloseMainWindow();

private:
    Ui::CSortTestClass ui;
    EUserType _currentUser;

protected:
    void closeEvent(QCloseEvent* event);
};

#endif //CSORTTEST_H