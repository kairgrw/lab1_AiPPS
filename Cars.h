#pragma once

#include "BMW.h"
#include "VAZ2115.h"

// ���� (�����) �����������
typedef enum 
{ 
	C_BMW, 
	C_VAZ2115 
}ECarType;

// �������� ����� ����������
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
	// ��������� �� ����������� ������
	BMW* _BMW;
	VAZ2115* _VAZ2115;
	ICar* _ICar; // ��������� �� ������� �����
protected:
	const char* MACHINE_BMW = "��� BMW";
	const char* MACHINE_VAZ2115 = "��� VAZ-2115";
	const char* MOTOR_STARTING = "����� ���������...";
	const char* MOTOR_STARTED = "����� �������";
	const char* MOTOR_STOPPED = "����� ��������";
	const char* CHANGING_SPEED = "������ ��������...";
	const char* NEW_SPEED_SET = "����������� ����� ��������: ";
	const char* SPEED_MEASURE = " ��/�";

};

