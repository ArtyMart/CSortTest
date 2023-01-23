#include "CUsersDispatcher.h"

CUsersDispatcher::CUsersDispatcher() :_currentUser(EUserType::eUndefined)
{
}

CUsersDispatcher::~CUsersDispatcher()
{
}

void CUsersDispatcher::slotLogIn(QString pass)
{
    EUserType type;
    if (pass == "111")
        type = EUserType::eTechnician;
    else if (pass == "222")
        type = EUserType::eEngineer;
    else
        type = EUserType::eOperator;

    if (_currentUser != type)
    {
        _currentUser = type;
        emit signalChangeUser(type);
    }
}
