#include "VAZ2115.h"


VAZ2115::VAZ2115()
{
	_speed = 0;
	_motorWorks = false;
	_motorEnableSpeed = 2000;
	_changeSpeed = 1500;
	ChangeState(MotorStoppedState::GetInstance());
}

VAZ2115::~VAZ2115()
{
}

void VAZ2115::StartMotor()
{
	_state->Start(this);
	Sleep(_motorEnableSpeed);
}

void VAZ2115::StopMotor()
{
	_state->Stop(this);
}

void VAZ2115::ChangeSpeed(int speed)
{
	_state->Speed(this, speed);
	Sleep(_changeSpeed);
}

void VAZ2115::SetSpeed(int speed)
{
	_speed = speed;
}

void VAZ2115::ChangeState(IState* instance)
{
	_state = instance;
}

void VAZ2115::SwitchMotor()
{
	_motorWorks = !_motorWorks;
}
