#include "Cars.h"

Cars::Cars(ECarType carType)
{
	_BMW = 0;
	_VAZ2115 = 0;

	if (carType == ECarType::C_BMW)
	{
		_BMW = new BMW();
		_ICar = _BMW;

		cout << MACHINE_BMW << endl;
	}
	else if (carType == ECarType::C_VAZ2115)
	{
		_VAZ2115 = new VAZ2115();
		_ICar = _VAZ2115;

		cout << MACHINE_VAZ2115 << endl;
	}
}

Cars::~Cars()
{
	if (_BMW)
		delete _BMW;
	if (_VAZ2115)
		delete _VAZ2115;
}

void Cars::SetCar(ECarType carType)
{
	if (carType == ECarType::C_BMW)
	{
		if (_BMW)
			delete _BMW;
		_BMW = new BMW();
		_ICar = _BMW;

		cout << MACHINE_BMW << endl;
	}
	else if (carType == ECarType::C_VAZ2115)
	{
		if (_VAZ2115)
			delete _VAZ2115;
		_VAZ2115 = new VAZ2115();
		_ICar = _VAZ2115;

		cout << MACHINE_VAZ2115 << endl;
	}
}

void Cars::StartMotor()
{
	cout << MOTOR_STARTING << endl;
	_ICar->StartMotor();
	cout << MOTOR_STARTED << endl;
}

void Cars::StopMotor()
{
	_ICar->StopMotor();
	cout << MOTOR_STOPPED << endl;
}

void Cars::SetSpeed(int speed)
{
	cout << CHANGING_SPEED << endl;
	_ICar->ChangeSpeed(speed);
	cout << NEW_SPEED_SET << speed << SPEED_MEASURE << endl;
}

void Cars::ChangeState(IState* iState)
{
	_ICar->ChangeState(iState);
}

void Cars::SwitchMotor()
{
	_ICar->SwitchMotor();
}
