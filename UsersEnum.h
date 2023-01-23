#ifndef USERSENUM_H
#define USERSENUM_H

enum class EUserType
{
	eUndefined = -1,	// неопределенный
	eOperator = 0,		// оператор (по умолчанию)
	eTechnician = 1,	// техник
	eEngineer = 2		// инженер
};

#endif //USERSENUM_H