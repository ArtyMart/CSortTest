#ifndef FORMNEWFORM_H
#define FORMNEWFORM_H
#include <qdialog.h>
#include <QThread>
#include "UsersEnum.h"

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

private:
	NewForm* ui;
	QThread* _thread;
};

#endif //FORMNEWFORM_H