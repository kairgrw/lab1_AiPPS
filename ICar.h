#pragma once

#include <iostream>
#include <exception>
#include <Windows.h>

using namespace std;

class IState; // ���������� ������ include

// ������� ����� "����������"
class ICar
{
public:
	ICar();
	virtual ~ICar(){};
public:
	virtual const int GetSpeed(){ return 0; } // ���������� �������� ��������
	virtual void StartMotor() = 0; // ��������� ���������
	virtual void StopMotor() = 0; // ������������� ���������
	virtual void ChangeSpeed(int speed) = 0; // ������������� ����� �������� �������� (��� IState)
	virtual void SetSpeed(int speed) = 0; // setter ��� ��������
	virtual void ChangeState(IState* instance) = 0; // �������� ��������� ����������
	virtual void SwitchMotor() = 0; // �������� ��������� ������ (�������/��������)
protected:
	int _speed; // �������� ��������
	bool _motorWorks; // ��������� ������ (�������/��������)
	// �������������� �������������� ����������
	int _motorEnableSpeed; // ����� ������� ���������
	int _changeSpeed; // ����� ������� �� ������ ��������
	IState* _state; // ��������� ����������
};

