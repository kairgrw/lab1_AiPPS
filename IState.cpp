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
	// ������ ���������� ��� ������������� ���������
	throw exception(ENGINE_ALREADY_STOPPED);
}

void MotorStoppedState::Speed(ICar* iCar, int speed)
{
	// ������ �������� �������� ������ � ������������ ����������
	throw exception(UNABLE_TO_CHANGE_SPEED);
}

MotorStoppedState* MotorStoppedState::GetInstance() 
{
	// ������� Singleton
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
	// ������ ��������� ��� ���������� ���������
	throw exception(ENGINE_ALREADY_STARTED);
}

void MotorWorksState::Stop(ICar* iCar)
{
	// ���� ������ �� ����, ������ �����
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
	// ���� �������� �������� ��������� (>=0), ������������� ���
	if (speed >= 0)
		iCar->SetSpeed(speed);
	else
	{
		throw exception(SPEED_IS_NEGATIVE);
	}	
}

MotorWorksState* MotorWorksState::GetInstance() 
{
	// ������� Singleton
	if (!_Instance)
	{
		_Instance = new MotorWorksState();
		_Destroyer.Init(_Instance);
	}
	return _Instance;
}