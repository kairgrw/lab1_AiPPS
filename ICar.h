#pragma once

#include <iostream>
#include <exception>
#include <Windows.h>

using namespace std;

class IState; // объявление вместо include

// Базовый класс "Автомобиль"
class ICar
{
public:
	ICar();
	virtual ~ICar(){};
public:
	virtual const int GetSpeed(){ return 0; } // возвращает значение скорости
	virtual void StartMotor() = 0; // запускает двигатель
	virtual void StopMotor() = 0; // останавливает двигатель
	virtual void ChangeSpeed(int speed) = 0; // устанавливает новое значение скорости (для IState)
	virtual void SetSpeed(int speed) = 0; // setter для скорости
	virtual void ChangeState(IState* instance) = 0; // изменяет состояние автомобиля
	virtual void SwitchMotor() = 0; // изменяет состояние мотора (заведен/заглушен)
protected:
	int _speed; // значение скорости
	bool _motorWorks; // состояние мотора (заведен/заглушен)
	// индивидуальные характеристики автомобиля
	int _motorEnableSpeed; // время запуска двигателя
	int _changeSpeed; // время разгона до нужной скорости
	IState* _state; // состояние автомобиля
};

