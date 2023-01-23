#include "CNewForm.h"
#include "ui_NewForm.h"

CNewForm::CNewForm(QThread* th, EUserType userType, Qt::WindowFlags f /*= 0*/)
	:_thread(th), ui(new Ui::NewForm())
{
	setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
	ui->setupUi(this);

	connect(this, &QDialog::rejected, this, &CNewForm::slotCloseWindow);

	slotSetUser(userType);
}

CNewForm::~CNewForm()
{
	if (ui)
		delete ui;
}

void CNewForm::slotCloseWindow()
{
	_thread->quit();
	_thread->deleteLater();
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