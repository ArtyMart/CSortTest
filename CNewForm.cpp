#include "CNewForm.h"
#include "ui_NewForm.h"

CNewForm::CNewForm(QThread* th, EUserType userType, Qt::WindowFlags f /*= 0*/)
	:_thread(th), _myThread(nullptr), ui(new Ui::NewForm())
{
	// gui
	setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
	ui->setupUi(this);

	connect(this, &QDialog::rejected, this, &CNewForm::slotCloseWindow);
	connect(ui->pushButton, &QPushButton::clicked, this, &CNewForm::slotPushButtonPressed);

	slotSetUser(userType);

	// поток в котором происходят вычисления, управляемые из этой формы
	_myThread = new CFormThread(this);
	connect(_myThread, &CFormThread::workStarted, this, &CNewForm::slotWorkStarted);
	connect(_myThread, &CFormThread::workEnded, this, &CNewForm::slotWorkEnded);
}

CNewForm::~CNewForm()
{
	if (ui)
		delete ui;
	if (_myThread)
		delete _myThread;
}

void CNewForm::slotPushButtonPressed()
{
	_myThread->start();
}

void CNewForm::slotWorkStarted()
{
	ui->pushButton->setEnabled(false);
	ui->labelWork->setText("work in progress...");
}

void CNewForm::slotWorkEnded()
{
	ui->pushButton->setEnabled(true);
	ui->labelWork->setText("Done");
	//_myThread->quit();
}

void CNewForm::slotCloseWindow()
{
	_thread->quit();
	_thread->deleteLater();
	_myThread->wait();
	delete this;
}

void CNewForm::slotSetUser(EUserType userType)
{
	ui->label_1->setVisible(userType >= EUserType::eOperator);
	ui->label_2->setVisible(userType >= EUserType::eOperator);
	ui->label_3->setVisible(userType >= EUserType::eTechnician);
	ui->label_4->setVisible(userType >= EUserType::eTechnician);
	ui->label_5->setVisible(userType >= EUserType::eEngineer);
	ui->label_6->setVisible(userType >= EUserType::eEngineer);
}