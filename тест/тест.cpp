#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

class Player {
public:
    int posX, posY;
    int hp, maxHp;
    int mana, maxMana;
    int damage;
    int experience;
    int level;
    int skillPoints;

    Player(int startX, int startY) : posX(startX), posY(startY), maxHp(100), hp(100),
        maxMana(50), mana(50), damage(10), experience(0),
        level(1), skillPoints(0) {}
    void levelUp() {
        setlocale(LC_ALL, "Russian");
        while (experience >= 100) {
            experience -= 100;
            level++;
            skillPoints++;
            maxHp += 10;
            maxMana += 5;
            hp = maxHp;
            mana = maxMana;
            cout << "ты поднял уровень твой уровень в данный момент -  " << level << "\n";
        }
    }
    void useAbility(const string& abilityName) {
        setlocale(LC_ALL, "Ru");
        if (abilityName == "Фаэрболл") {
            if (mana >= 10) {
                mana -= 10;
                cout << "ты использовал фаэрбол\n";
            }
            else {
                cout << "нехватает маны\n";
            }
        }
        else if (abilityName == "Хилл") {
            if (mana >= 15) {
                mana -= 15;
                hp = min(hp + 25, maxHp);
                cout << "ты использовал хилл на 25\n";
            }
            else {
                cout << "нехватает маны\n";
            }
        }
        else if (abilityName == "Фиолетовый") {
            if (mana >= 25) {
                mana -= 26;
                cout << "ты использовал фиолетовый\n";
            }
            else {
                cout << "нехватает маны\n";
            }
        }
        else {
            cout << "такой способности нет\n";
        }
    }
};
class Enemy {
public:
    int hp;
    int damage;

    Enemy() : hp(50), damage(8) {}

    bool isDead() const {
        return hp <= 0;
    }
};

class Game {
public:
    const int mapWidth = 30;
    const int mapHeight = 15;
    vector<vector<int>> map;
    Player player;
    bool inBattle = false;

    Game() : player(mapWidth / 2, mapHeight / 2) {
        generateMap();
    }

    void generateMap() {
        srand(time(0));
        map.resize(mapHeight, vector<int>(mapWidth, 46));

        for (int i = 0; i < mapHeight; i++) {
            for (int j = 0; j < mapWidth; j++) {
                if (rand() % 10 == 0) {
                    map[i][j] = 35;
                }
                else if (rand() % 50 == 0) {
                    map[i][j] = 69;
                }
            }
        }
        map[mapHeight - 1][mapWidth - 1] = 42;
    }

    void displayMap() {
        for (int y = 0; y < mapHeight; y++) {
            for (int x = 0; x < mapWidth; x++) {
                if (x == player.posX && y == player.posY) {
                    cout << "[]";
                }
                else if (map[y][x] == 42) {
                    cout << "(***)";
                }
                else if (map[y][x] == 21) {
                    cout << "X";
                }
                else if (map[y][x] == 69) {
                    cout << "E ";
                }
                else {
                    cout << (char)map[y][x];
                    //Char это тип данных который используется для представления символов он может быть объявлен как самостоятельная переменная или быть частью массива а также его можно использовать для работы со строками
                    // я пытался без char но без него перс просто бесконечно идёт
                }
            }
            cout << "\n";
        }
    }
    void start() {
        (LC_ALL, "Russian");
        char input;
        cout << "для передвижения w a s d\n";
        cout << "на x выход из игры\n";
        while (true) {
            displayMap();
            cout << "хп " << player.hp << "/" << player.maxHp << " | мана " << player.mana << "/" << player.maxMana
                << " | EXP: " << player.experience << "/100 | уровень " << player.level << "\n";
            cout << "куда хочешь сходить ";
            cin >> input;

            if (input == 'x') {
                cout << "покинул игру\n";
                break;
            }

            if (!inBattle) {
                movePlayer(input);
            }

            if (map[player.posY][player.posX] == 'X') {
                cout << "Вы вошли в магазин\n";
                nextLocation();
            }

            if (map[player.posY][player.posX] == '*') {
                cout << "Вы вошли в портал\n";
                nextLocation();
            }
            else if (map[player.posY][player.posX] == 'E') {
                cout << "ты встретился взглядом с противником\n";
                startBattle();
            }
        }
    }

    void movePlayer(int input) {
        (LC_ALL, "Russian");
        int newX = player.posX;
        int newY = player.posY;

        switch (input) {
        case 'w':
            newY--;
            break;
        case 's':
            newY++;
            break;
        case 'a':
            newX--;
            break;
        case 'd':
            newX++;
            break;
        default:
            cout << "Так ходить нельзя\n";
            return;
        }

        if ((newX >= 0 && newX < mapWidth) && (newY >= 0 && newY < mapHeight)) {
            if (map[newY][newX] != 35) {
                player.posX = newX;
                player.posY = newY;
            }
            else {
                cout << "Вы не можете туда пойти\n";
            }
        }
        else {
            cout << "Вы не можете выйти за границы карты\n";
        }
    }

    void startBattle() {
        (LC_ALL, "Russian");
        inBattle = true;
        Enemy enemy;
        while (player.hp > 0 && !enemy.isDead()) {
            cout << "HP врага " << enemy.hp << " | Ваше HP " << player.hp << "\n";
            cout << "Выберите способность: 1 - простой удар 2 - фаэрболл 3 - хилл 4 - фиолетовый";
            int choice;
            cin >> choice;

            if (choice == 1) {
                cout << "Вы атаковали врага\n";
                enemy.hp -= player.damage;
            }
            else if (choice == 2) {
                player.useAbility("Фаэрболл");
                if (player.mana >= 10) {
                    enemy.hp -= 20;
                }
            }
            else if (choice == 3) {
                player.useAbility("Хилл");
            }
            else {
                cout << "Такой способности нет\n";
            }

            if (!enemy.isDead()) {
                cout << "Вас атакуют\n";
                player.hp -= enemy.damage;
            }
        }

        if (player.hp <= 0) {
            cout << "Вы погибли\n";
            exit(0);
        }
        else {
            cout << "Вы победили врага\n";
            player.experience += 50;
            player.levelUp();
            map[player.posY][player.posX] = 46;
        }

        inBattle = false;
    }

    void nextLocation() {
        (LC_ALL, "Russian");
        cout << "Телепортация на следующий этаж\n";
        generateMap();
        player.posX = 0;
        player.posY = 0;
    }
    void Shop() {
        (LC_ALL, "Russian");
        cout << "1Меч души - 200 душ 2ожерелье подовления - 2500 душ\n";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Game game;
    game.start();
    return 0;
}
