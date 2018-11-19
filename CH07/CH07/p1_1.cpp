#include<iostream>
using namespace std;

class Car {	//기본연료 자동차
private:
	int gasolineGauge;
public:

	Car()
		:gasolineGauge(0)
	{
		cout << "Car Constructor!" << endl;
	}

	Car(int n)
		:gasolineGauge(n)
	{
		cout << "Car Constructor(int n)!" << endl;
	}

	int getGasGauge() {
		return gasolineGauge;
	}

	~Car() {
		cout << "Car Distructor!" << endl;
	}
};

class HybridCar : public Car //하이브리드 자동차
{
private:
	int electricGauge;
public:

	HybridCar()
		:Car(0), electricGauge(0)
	{
		cout << "HybridCar Constructor!" << endl;
	}

	HybridCar(int n)
		:Car(0), electricGauge(n)
	{
		cout << "HybridCar Constructor(int n)!" << endl;
	}

	HybridCar(int n1, int n2)
		:Car(n1), electricGauge(n2)
	{
		cout << "HybridCar Constructor(int n1, int n2)!" << endl;
	}

	int getElecGauge() {
		return electricGauge;
	}

	~HybridCar() {
		cout << "HybridCar Distructor!" << endl;
	}

};

class HybridWaterCar : public HybridCar //하이브리드 워터카
{
private:
	int waterGauge;
public:

	HybridWaterCar()
		:HybridCar(0), waterGauge(0)
	{
		cout << "HybridWaterCar Constructor!" << endl;
	}

	HybridWaterCar(int n)
		:HybridCar(0), waterGauge(n)
	{
		cout << "HybridWaterCar Constructor(int n)!" << endl;
	}

	HybridWaterCar(int n1, int n2)
		:HybridCar(n1), waterGauge(n2)
	{
		cout << "HybridWaterCar Constructor(int n1, int n2)!" << endl;
	}

	HybridWaterCar(int n1, int n2, int n3)
		:HybridCar(n1, n2), waterGauge(n3)
	{
		cout << "HybridWaterCar Constructor(int n1, int n2, int n3)!" << endl;
	}

	void showCurrentGauge() {
		cout << "잔여 가솔린 : " << getGasGauge() << endl;
		cout << "잔여 전기량 : " << getElecGauge() << endl;
		cout << "잔여 워터량 : " << waterGauge << endl;
	}

	~HybridWaterCar() {
		cout << "HybridWaterCar Distructor!" << endl;
	}
};


int main(void) {

	HybridWaterCar HWCar1;
	HWCar1.showCurrentGauge();

	cout << "=============================" << endl << endl;

	HybridWaterCar HWCar2(30);
	HWCar2.showCurrentGauge();

	cout << "=============================" << endl << endl;

	HybridWaterCar HWCar3(20, 30);
	HWCar3.showCurrentGauge();

	cout << "=============================" << endl << endl;

	HybridWaterCar HWCar4(10, 20, 30);
	HWCar4.showCurrentGauge();

	cout << "=============================" << endl << endl;

	return 0;
}