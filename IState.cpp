#include "IState.h"

SingletonDestroyer::~SingletonDestroyer() 
{
	if (ms_p_Instance != nullptr)
		delete ms_p_Instance;
	if (mv_p_Instance != nullptr)
		delete mv_p_Instance;
	
}
void SingletonDestroyer::Init(MotorStoppedState* p) 
{
	ms_p_Instance = p;
}

void SingletonDestroyer::Init(MotorWorksState* p)
{
	mv_p_Instance = p;
}

MotorStoppedState* MotorStoppedState::_Instance = nullptr;
SingletonDestroyer MotorStoppedState::_Destroyer;

void MotorStoppedState::Start(ICar* iCar)
{
	iCar->SwitchMotor();
	iCar->ChangeState(MotorWorksState::GetInstance());
}

void MotorStoppedState::Stop(ICar* iCar)
{
	// нельзя остановить уже остановленный двигатель
	throw exception(ENGINE_ALREADY_STOPPED);
}

void MotorStoppedState::Speed(ICar* iCar, int speed)
{
	// нельзя изменить скорость машины с незаведенным двигателем
	throw exception(UNABLE_TO_CHANGE_SPEED);
}

MotorStoppedState* MotorStoppedState::GetInstance() 
{
	// создаем Singleton
	if (!_Instance)     
	{
		_Instance = new MotorStoppedState();
		_Destroyer.Init(_Instance);
	}
	return _Instance;
}

MotorWorksState* MotorWorksState::_Instance = nullptr;
SingletonDestroyer MotorWorksState::_Destroyer;

void MotorWorksState::Start(ICar* iCar)
{
	// нельзя запустить уже запущенный двигатель
	throw exception(ENGINE_ALREADY_STARTED);
}

void MotorWorksState::Stop(ICar* iCar)
{
	// если машина не едет, глушим мотор
	if (iCar->GetSpeed() == 0)
	{
		iCar->SwitchMotor();
		iCar->ChangeState(MotorStoppedState::GetInstance());
	}
	else
	{
		throw exception(SET_SPEED_TO_ZERO);
	}
}

void MotorWorksState::Speed(ICar* iCar, int speed)
{
	// если значение скорости корректно (>=0), устанавливаем его
	if (speed >= 0)
		iCar->SetSpeed(speed);
	else
	{
		throw exception(SPEED_IS_NEGATIVE);
	}	
}

MotorWorksState* MotorWorksState::GetInstance() 
{
	// создаем Singleton
	if (!_Instance)
	{
		_Instance = new MotorWorksState();
		_Destroyer.Init(_Instance);
	}
	return _Instance;
}