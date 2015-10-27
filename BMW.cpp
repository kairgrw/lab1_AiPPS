#include "BMW.h"

BMW::BMW()
{
	_speed = 0;
	_motorWorks = false;
	_motorEnableSpeed = 1000;
	_changeSpeed = 500;
	ChangeState(MotorStoppedState::GetInstance());
}

BMW::~BMW()
{
}

void BMW::StartMotor()
{
	_state->Start(this);
	Sleep(_motorEnableSpeed);
}

void BMW::StopMotor()
{
	_state->Stop(this);
}

void BMW::ChangeSpeed(int speed)
{
	_state->Speed(this, speed);
	Sleep(_changeSpeed);
}

void BMW::SetSpeed(int speed)
{
	_speed = speed;
}

void BMW::ChangeState(IState* instance)
{
	_state = instance;
}

void BMW::SwitchMotor()
{
	_motorWorks = !_motorWorks;
}
