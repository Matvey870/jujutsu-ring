#include <iostream>
using namespace std;

class weapon {
public:
    int dmg;
    int lvl;
    int lvlOfSkill;
    virtual void atack() = 0;
    virtual void upgrade() = 0;
    string rarity;
};
class meele_weapon : public weapon {
    string HuntingDagger;
};
class range_wepon : public weapon {
    string bow;
};
class magic_weapon : public weapon {
    string soulBlade;
};

int main()
{
    cout << "МАТВЕЙ НАТУРАЛ!\n";//dfgdfgdfg
	int lvl = 0;
	int exp = 0;
	int dexterity = 0;
	int intelligence = 0;
	int power = 0;
	int luck = 0;

	if exp = 100 {
		cout << "У вас новый уровень";
		cout << "Ветка прокачки";
		cout << "1-Прокочать силу";
		cout << "2-Прокочать интилект";
		cout << "3-Прокочать ловкость";
		cout << "4-Прокочать удача";

		int x;
		switch (x)
		{
		case 1:
			cout << "Вы прокачиваете силу";
			int power = 0 + 1;

		case 2:
			cout << "Вы прокочали интелект";
			int intelligence = 0 + 1;

		case 3:
			cout << "Вы прокочали ловкость";
			int dextrity = 0 + 1;

		case 4:
			cout << "Вы прокочали удачу";
			int luck = 0 + 1;
			break;
		}
	}
}