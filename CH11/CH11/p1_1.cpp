#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;    	// 장전된 총알의 수
public:
	Gun(int bnum) : bullet(bnum)
	{ }
	void Shut()
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;    // 소유한 수갑의 수
	Gun * pistol;     // 소유하고 있는 권총
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if (bnum>0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	void PutHandcuff()
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shut()
	{
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->Shut();
	}
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}

	Police(const Police &pol)
		:handcuffs(pol.handcuffs) {
		if (pol.pistol != NULL) {
			pistol = new Gun(*(pol.pistol));
		}
		else {
			pistol = NULL;
		}
	}

	Police& operator=(Police &pol) {
		if (pistol != NULL) {
			delete pistol;
		}
		if (pol.pistol != NULL) {
			pistol = new Gun(*(pol.pistol));
		}
		else {
			pistol = NULL;
		}
		handcuffs = pol.handcuffs;
		return *this;
	}
};

int main(void)
{
	Police pman1(5, 3);
	Police pman2 = pman1;
	pman2.Shut();
	pman2.PutHandcuff();

	Police pman3(0, 3);     // 권총소유하지 않은 경찰
	Police pman4(1, 2);
	pman4 = pman3;
	pman4.Shut();
	pman4.PutHandcuff();
	return 0;
}