#ifndef USERSDISPATCHER_H
#define USERSDISPATCHER_H

#include <QObject>
#include "UsersEnum.h"

class CUsersDispatcher : public QObject
{
	Q_OBJECT
public:
	CUsersDispatcher();
	~CUsersDispatcher();

public slots:
	void slotLogIn(QString pass);

signals:
	void signalChangeUser(EUserType);

private:
	EUserType _currentUser;
};

#endif //USERSDISPATCHER_H