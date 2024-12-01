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
}