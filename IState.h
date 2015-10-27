#pragma once

#include "ICar.h"

// Базовый класс
class IState
{
public:
	IState(){};
	virtual ~IState() {};
	virtual void Start(ICar* iCar) = 0;
	virtual void Stop(ICar* iCar) = 0;
	virtual void Speed(ICar* iCar, int speed) = 0;
protected:
	const char* ENGINE_ALREADY_STOPPED = "Двигатель уже остановлен!";
	const char* UNABLE_TO_CHANGE_SPEED = "Нельзя изменить скорость, когда двигатель остановлен!";
	const char* ENGINE_ALREADY_STARTED = "Двигатель уже запущен!";
	const char* SET_SPEED_TO_ZERO = "Прежде чем остановить двигатель уменьшите скорость до 0!";
	const char* SPEED_IS_NEGATIVE = "Значение скорости не может быть отрицательным!";
};

// опережающие объявления
class MotorStoppedState; 
class MotorWorksState;

// Класс для автоматического разрушения одиночек
class SingletonDestroyer
{
public:
	~SingletonDestroyer();
	void Init(MotorStoppedState* p);
	void Init(MotorWorksState* p);
private:
	// одиночки (классы, наследующие IState)
	MotorStoppedState* ms_p_Instance;
	MotorWorksState* mv_p_Instance;
};

// Класс состояния "Мотор заглушен"
class MotorStoppedState : public IState
{
public:
	void Start(ICar* iCar);
	void Stop(ICar* iCar);
	void Speed(ICar* iCar, int speed);
public:
	static MotorStoppedState* GetInstance();
protected:
	MotorStoppedState() { }
	MotorStoppedState(const MotorStoppedState&);
	MotorStoppedState& operator=(MotorStoppedState&);
	~MotorStoppedState() { };
	friend class SingletonDestroyer;
private:
	static MotorStoppedState* _Instance;
	static SingletonDestroyer _Destroyer;
};

// Класс состояния "Мотор заведен"
class MotorWorksState : public IState
{
public:
	void Start(ICar* iCar);
	void Stop(ICar* iCar);
	void Speed(ICar* iCar, int speed);
public:
	static MotorWorksState* GetInstance();
protected:
	MotorWorksState() { }
	MotorWorksState(const MotorWorksState&);
	MotorWorksState& operator=(MotorWorksState&);
	~MotorWorksState() { };
	friend class SingletonDestroyer;
private:
	static MotorWorksState* _Instance;
	static SingletonDestroyer _Destroyer;
};



