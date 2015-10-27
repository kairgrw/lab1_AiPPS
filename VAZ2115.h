#pragma once

#include "ICar.h"
#include "IState.h"

// Класс Автомобиль "VAZ 2115"
class VAZ2115 : public ICar
{
public:
	VAZ2115();
	~VAZ2115();
public:
	const int GetSpeed(){ return _speed; }
	void StartMotor();
	void StopMotor();
	void ChangeSpeed(int speed);
	void SetSpeed(int speed);
	void ChangeState(IState* instance);
	void SwitchMotor();
};

