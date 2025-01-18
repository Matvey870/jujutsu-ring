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
    vector<vector<char>> map;
    Player player;
    bool inBattle = false;

    Game() : player(mapWidth / 2, mapHeight / 2) {
        generateMap();
    }

    void generateMap() {
        srand(static_cast<unsigned int>(time(0)));

        map.resize(mapHeight, vector<char>(mapWidth, '.'));
        for (int i = 0; i < mapHeight; i++) {
            for (int j = 0; j < mapWidth; j++) {
                if (std::rand() % 10 == 0) {
                    map[i][j] = '#';
                }
                else if (std::rand() % 50 == 0) {
                    map[i][j] = 'E';
                }
            }
        }
        map[mapHeight - 1][mapWidth - 1] = '*';
    }

    void displayMap() {
        for (int y = 0; y < mapHeight; y++) {
            for (int x = 0; x < mapWidth; x++) {
                if (x == player.posX && y == player.posY) {
                    cout << "[]";
                }
                else if (map[y][x] == '*') {
                    cout << "(***)";
                }
                else if (map[y][x] == 'E') {
                    cout << "E ";
                }
                else {
                    cout << map[y][x];
                }
            }
            cout << "\n";
        }
    }

    void start() {
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

    void movePlayer(char input) {
        int newX = player.posX;
        int newY = player.posY;

        switch (input) {
        case 'w': newY--; break;
        case 's': newY++; break;
        case 'a': newX--; break;
        case 'd': newX++; break;
        default: cout << "так ходить нельзя\n"; return;
        }

        if (newX >= 0 && newX < mapWidth && newY >= 0 && newY < mapHeight && map[newY][newX] != '#') {
            player.posX = newX;
            player.posY = newY;
        }
        else {
            cout << "Ты неможешь туда пойти\n";
        }
    }

    void startBattle() {
        inBattle = true;
        Enemy enemy;
        while (player.hp > 0 && !enemy.isDead()) {
            cout << "хп врага " << enemy.hp << " | твоё хп " << player.hp << "\n";
            cout << "выбири одну из способностей";
            int choice;
            cin >> choice;

            if (choice == 1) {
                cout << "ты атоковал врага" << "\n";
                enemy.hp -= player.damage;
            }
            else if (choice == 2) {
                player.useAbility("фаэрбол");
                if (player.mana >= 10) {
                    enemy.hp -= 20;
                }
            }
            else if (choice == 3) {
                player.useAbility("хил");
            }
            else {
                cout << "таково нет" << "\n";
            }

            if (!enemy.isDead()) {
                cout << "тебя атакуют" << "\n";
                player.hp -= enemy.damage;
            }
        }

        if (player.hp <= 0) {
            cout << "Вы погибли" << "\n";
            exit(0);
        }
        else {
            cout << "Ты победил врага" << "\n";
            player.experience += 50;
            player.levelUp();
            map[player.posY][player.posX] = '.';
        }

        inBattle = false;
    }

    void nextLocation() {
        cout << "телепорт на следующий этаж" << "\n";
        generateMap();
        player.posX = 0;
        player.posY = 0;
    }
};

int main() {
    Game game;
    game.start();
    return 0;
}
