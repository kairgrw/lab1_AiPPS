#pragma once

#include "BMW.h"
#include "VAZ2115.h"

// Типы (марки) автомобилей
typedef enum 
{ 
	C_BMW, 
	C_VAZ2115 
}ECarType;

// Фасадный класс Автомобили
class Cars
{
public:
	Cars(ECarType carType);
	~Cars();
public:
	void SetCar(ECarType carType);
	int GetSpeed(){ return _ICar->GetSpeed(); }
	void StartMotor();
	void StopMotor();
	void SetSpeed(int speed);
private:
	void ChangeState(IState* iState);
	void SwitchMotor();
private:
	// указатели на производные классы
	BMW* _BMW;
	VAZ2115* _VAZ2115;
	ICar* _ICar; // указатель на базовый класс
protected:
	const char* MACHINE_BMW = "Это BMW";
	const char* MACHINE_VAZ2115 = "Это VAZ-2115";
	const char* MOTOR_STARTING = "Мотор заводится...";
	const char* MOTOR_STARTED = "Мотор заведен";
	const char* MOTOR_STOPPED = "Мотор заглушен";
	const char* CHANGING_SPEED = "Меняем скорость...";
	const char* NEW_SPEED_SET = "Установлена новая скорость: ";
	const char* SPEED_MEASURE = " км/ч";

};

