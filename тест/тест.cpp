#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

class Character {
public:
    string name;
    int health;
    int atk;
    int abp;

    Character(string n, int hp, int ap, int abp)
        : name(n), health(hp), atk(ap), abp(abp) {}
    void attack(Character& target) {
        target.health -= atk;
        cout << name << " атакует " << target.name << " на " << atk << " урона\n";
    }
    void Ability(Character& target) {
        target.health -= abp;
        cout << name << " использует способность на " << target.name << " на " << abp << " урона\n";
    }
    bool Alive() {
        return health > 0;
    }
};
class opponent {
protected:
    int HP;
    string name;
    int atk;
public:
    opponent(string name, int HP, int atk) {
        this->name = name;
        this->HP = HP;
        this->atk = atk;
    }
};
class skeleton : protected opponent {
    skeleton(string name, int HP, int atk) : opponent(name, HP, atk) {}
};
class goblin : protected opponent {
    goblin(string name, int HP, int atk) : opponent(name, HP, atk) {}
};
class ork : protected opponent {
    ork(string name, int HP, int atk) : opponent(name, HP, atk) {}
};
class hunter : protected opponent {
    hunter(string name, int HP, int atk) : opponent(name, HP, atk) {}
};
class knight : protected opponent {
    knight(string name, int HP, int atk) : opponent(name, HP, atk) {}
};
class FUdog : protected opponent {
    FUdog(string name, int HP, int atk) : opponent(name, HP, atk) {}
};
class BOSS {
protected:
    int HP;
    int atk;
    string name;
    int resist;
    BOSS(string name, int HP, int atk, int resist) {
        this->name = name;
        this->HP = HP;
        this->atk = atk;
        this->resist = resist;
    }
};
class Horseman : protected BOSS {
    Horseman(string name, int HP, int atk, int resist) : BOSS(name, HP, atk, resist) {}
};
class KingGoblin : protected BOSS {
    KingGoblin(string name, int HP, int atk, int resist) : BOSS(name, HP, atk, resist) {}
};
class KingOrk : protected BOSS {
    KingOrk(string name, int HP, int atk, int resist) : BOSS(name, HP, atk, resist) {}
};
class KingSkeleton : protected BOSS {
    KingSkeleton(string name, int HP, int atk, int resist) : BOSS(name, HP, atk, resist) {}
};
class DarkKing : protected BOSS {
    DarkKing(string name, int HP, int atk, int resist) : BOSS(name, HP, atk, resist) {}
};
class Igris : protected BOSS {
    Igris(string name, int HP, int atk, int resist) : BOSS(name, HP, atk, resist) {}
};
class Xenoc : protected BOSS {
    Xenoc(string name, int HP, int atk, int resist) : BOSS(name, HP, atk, resist) {}
};
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
	string name;
	//meele_weapon knife{"demon slayer knife", 100, 20, 34}
};
class range_wepon : public weapon {
    string bow;
	string Crossbow;
	string steelBow;
	string bigBow;
};
class magic_weapon : public weapon {
    string soulBlade;
	string stick;
};

int main()
{
setlocale(LC_ALL, "RU");
    Character player("Игрок", 100, 10, 20);
    Character enemy("Противник", 100, 15, 0);
    while (player.Alive() && enemy.Alive()) {
        int choice;
        cout << "\nВаш ход\n 1 - Обычная атака\n 2 - Способность\n\n";
        cin >> choice;
        if (choice == 1) {
            player.attack(enemy);
        }
        else if (choice == 2) {
            player.Ability(enemy);
        }
        else {
            cout << "Таково выбора нет\n";
        }
        if (!enemy.Alive()) {
            cout << enemy.name << " повержен\n";
            break;
        }


        enemy.attack(player);
        if (!player.Alive()) {
            cout << player.name << " Вы погибли\n";
            break;
        }
    }
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