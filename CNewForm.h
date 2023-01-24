#ifndef FORMNEWFORM_H
#define FORMNEWFORM_H
#include <qdialog.h>
#include <QThread>
#include "UsersEnum.h"
#include "CFormThread.h"

namespace Ui {
	class NewForm;
}

using namespace Ui;

class CNewForm : public QDialog
{
	Q_OBJECT

public:
	CNewForm(QThread* th, EUserType userType, Qt::WindowFlags f = 0);
	~CNewForm();

	void slotSetUser(EUserType);
	void slotCloseWindow();
	void slotPushButtonPressed();
	void slotWorkStarted();
	void slotWorkEnded();

private:
	NewForm* ui;
	QThread* _thread;		// поток в котором работает данная форма
	CFormThread* _myThread; // поток в котором происходят вычисления, управляемые из этой формы

signals:
	void signalStartWork();
};

#endif //FORMNEWFORM_H