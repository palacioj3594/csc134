
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Define a struct for characters
struct Character {
    string name;
    int health;
    int attack;
    int defense;

    Character(string n, int h, int a, int d) : name(n), health(h), attack(a), defense(d) {}
};

// Define a struct for Goblin
struct Goblin {
    string name;
    int health;
    int attack;
    int defense;

    Goblin() : name("Goblin"), health(30), attack(5), defense(2) {}
};

// Define a struct for Orc
struct Orc {
    string name;
    int health;
    int attack;
    int defense;

    Orc() : name("Orc"), health(50), attack(7), defense(3) {}
};

// Define a struct for Dragon
struct Dragon {
    string name;
    int health;
    int attack;
    int defense;

    Dragon() : name("Dragon"), health(100), attack(10), defense(5) {}
};


void attack(Character &attacker, Goblin &defender) {
    int damage = attacker.attack - defender.defense;
    if (damage < 0) damage = 0;
    defender.health -= damage;
    cout << attacker.name << " attacks " << defender.name << " for " << damage << " damage!" << endl;
}

void attack(Character &attacker, Orc &defender) {
    int damage = attacker.attack - defender.defense;
    if (damage < 0) damage = 0;
    defender.health -= damage;
    cout << attacker.name << " attacks " << defender.name << " for " << damage << " damage!" << endl;
}

void attack(Character &attacker, Dragon &defender) {
    int damage = attacker.attack - defender.defense;
    if (damage < 0) damage = 0;
    defender.health -= damage;
    cout << attacker.name << " attacks " << defender.name << " for " << damage << " damage!" << endl;
}

void monsterAttack(Goblin &attacker, Character &defender) {
    int damage = attacker.attack - defender.defense;
    if (damage < 0) damage = 0;
    defender.health -= damage;
    cout << attacker.name << " attacks " << defender.name << " for " << damage << " damage!" << endl;
}

void monsterAttack(Orc &attacker, Character &defender) {
    int damage = attacker.attack - defender.defense;
    if (damage < 0) damage = 0;
    defender.health -= damage;
    cout << attacker.name << " attacks " << defender.name << " for " << damage << " damage!" << endl;
}

void monsterAttack(Dragon &attacker, Character &defender) {
    int damage = attacker.attack - defender.defense;
    if (damage < 0) damage = 0;
    defender.health -= damage;
    cout << attacker.name << " attacks " << defender.name << " for " << damage << " damage!" << endl;
}

Goblin createGoblin() {
    return Goblin();
}

Orc createOrc() {
    return Orc();
}

Dragon createDragon() {
    return Dragon();
}

void initializeRandomMonsters(void *monsters[], int count) {
    srand(time(0));
    for (int i = 0; i < count; i++) {
        int randomType = rand() % 3;
        if (randomType == 0) {
            monsters[i] = new Goblin();
        } else if (randomType == 1) {
            monsters[i] = new Orc();
        } else {
            monsters[i] = new Dragon();
        }
    }
}

int main() {
    Character hero("Hero", 100, 15, 5);

    int monsterCount = 3;
    void *monsters[monsterCount];
    initializeRandomMonsters(monsters, monsterCount);

    cout << "A group of monsters appears!" << endl;
    for (int i = 0; i < monsterCount; i++) {
        if (Goblin *g = static_cast<Goblin*>(monsters[i])) {
            cout << g->name << " (Health: " << g->health << ")" << endl;
        } else if (Orc *o = static_cast<Orc*>(monsters[i])) {
            cout << o->name << " (Health: " << o->health << ")" << endl;
        } else if (Dragon *d = static_cast<Dragon*>(monsters[i])) {
            cout << d->name << " (Health: " << d->health << ")" << endl;
        }
    }

    while (hero.health > 0) {
        for (int i = 0; i < monsterCount; i++) {
            if (Goblin *g = static_cast<Goblin*>(monsters[i])) {
                if (g->health > 0) {
                    attack(hero, *g);
                    if (g->health > 0) {
                        monsterAttack(*g, hero);
                    }
                }
            } else if (Orc *o = static_cast<Orc*>(monsters[i])) {
                if (o->health > 0) {
                    attack(hero, *o);
                    if (o->health > 0) {
                        monsterAttack(*o, hero);
                    }
                }
            } else if (Dragon *d = static_cast<Dragon*>(monsters[i])) {
                if (d->health > 0) {
                    attack(hero, *d);
                    if (d->health > 0) {
                        monsterAttack(*d, hero);
                    }
                }
            }
        }

        bool allMonstersDefeated = true;
        for (int i = 0; i < monsterCount; i++) {
            if (Goblin *g = static_cast<Goblin*>(monsters[i])) {
                if (g->health > 0) {
                    allMonstersDefeated = false;
                    break;
                }
            } else if (Orc *o = static_cast<Orc*>(monsters[i])) {
                if (o->health > 0) {
                    allMonstersDefeated = false;
                    break;
                }
            } else if (Dragon *d = static_cast<Dragon*>(monsters[i])) {
                if (d->health > 0) {
                    allMonstersDefeated = false;
                    break;
                }
            }
        }

        if (allMonstersDefeated) {
            cout << "The hero has defeated all the monsters!" << endl;
            break;
        }
    }

    if (hero.health <= 0) {
        cout << "The hero has been defeated by the monsters..." << endl;
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < monsterCount; i++) {
        delete static_cast<Goblin*>(monsters[i]);
    }

    return 0;
}
