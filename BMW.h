#pragma once

#include "ICar.h"
#include "IState.h"

// Класс Автомобиль "BMW"
class BMW : public ICar
{
public:
	BMW();
	~BMW();
public:
	const int GetSpeed(){ return _speed; }
	void StartMotor();
	void StopMotor();
	void ChangeSpeed(int speed);
	void SetSpeed(int speed);
	void ChangeState(IState* instance);
	void SwitchMotor();
};

