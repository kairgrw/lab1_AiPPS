/* Реализация возможностей паттернов State, Facade, Singleton
   Выполнено Дианой Белик*/
#include "Cars.h"

#include <locale>

int main()
{
	setlocale(LC_ALL, "Rus");

	Cars* cars = new Cars(ECarType::C_BMW);
	try
	{
		cars->StartMotor();
		cars->SetSpeed(150);
		cars->SetSpeed(0);
		cars->StopMotor();

		cars->SetCar(ECarType::C_VAZ2115);

		cars->StartMotor();
		cars->SetSpeed(80);
		cars->SetSpeed(0);
		cars->StopMotor();
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}

	delete cars;

	system("pause");
	return 0;
}