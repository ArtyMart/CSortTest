#include "CSortTest.h"
#include <QThread>
#include <QDialog>
#include "CNewForm.h"

CSortTest::CSortTest(QWidget *parent): _currentUser(EUserType::eUndefined), QMainWindow(parent)
{
    // диспетчер пользователей
    QThread* userDispatcherThread = new QThread();
    CUsersDispatcher* usersDispatcher = new CUsersDispatcher();
    usersDispatcher->moveToThread(userDispatcherThread);

    connect(this, &CSortTest::signalLogIn, usersDispatcher, &CUsersDispatcher::slotLogIn);
    connect(usersDispatcher, &CUsersDispatcher::signalChangeUser, this, &CSortTest::slotSetUser, Qt::BlockingQueuedConnection);
    connect(usersDispatcher, &CUsersDispatcher::signalChangeUser, this, &CSortTest::signalChangeUser, Qt::BlockingQueuedConnection);

    userDispatcherThread->start();

    // интерфейс
    ui.setupUi(this);
    ui.newWindowButton->setVisible(false);
    ui.pushButton_1->setVisible(false);
    ui.pushButton_2->setVisible(false);
    ui.pushButton_3->setVisible(false);
    ui.pushButton_4->setVisible(false);
    ui.pushButton_5->setVisible(false);
    ui.pushButton_6->setVisible(false);
    connect(ui.LogInButton, &QPushButton::clicked, [this]() { emit signalLogIn(ui.lineEditPass->text()); }); // отправить сигнал для userDispatcher
    connect(ui.newWindowButton, &QPushButton::clicked, this, &CSortTest::slotNewWindow); 
}

void CSortTest::slotNewWindow()
{
    QThread* thread = new QThread();
    CNewForm* form = new CNewForm(thread, _currentUser);

    form->moveToThread(thread);

    connect(this, &CSortTest::signalChangeUser, form, &CNewForm::slotSetUser);
    connect(this, &CSortTest::signalCloseMainWindow, form, &CNewForm::slotCloseWindow);

    thread->start();
    form->show();
}

void CSortTest::slotSetUser(EUserType userType)
{
    _currentUser = userType;
    ui.newWindowButton->setVisible(userType >= EUserType::eOperator);
    ui.pushButton_1->setVisible(userType >= EUserType::eOperator);
    ui.pushButton_2->setVisible(userType >= EUserType::eOperator);
    ui.pushButton_3->setVisible(userType >= EUserType::eTechnician);
    ui.pushButton_4->setVisible(userType >= EUserType::eTechnician);
    ui.pushButton_5->setVisible(userType >= EUserType::eEngineer);
    ui.pushButton_6->setVisible(userType >= EUserType::eEngineer);
}

void CSortTest::closeEvent(QCloseEvent* e)
{
    emit signalCloseMainWindow();
}

CSortTest::~CSortTest()
{}
