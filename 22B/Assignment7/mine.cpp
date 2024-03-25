#include <iostream>
#include <cstdlib>
using namespace std;


class Creature
{
protected:
    int m_strength;
    int m_hitpoints;
    virtual string getSpecies()
    {
        return "Unknown";
    }
public:
    Creature(int strength = 10, int hitpoints = 10) : 
    m_strength(strength), m_hitpoints(hitpoints) {}
    int getStrength() const
    {
        return m_strength;
    }
    void setStrength(int strength)
    {
        m_strength = strength;
    }
    int getHitpoints() const
    {
        return m_hitpoints;
    }
    void setHitpoints(int hitpoints)
    {
        m_hitpoints = hitpoints;
    }
    virtual ~Creature() {}  //virtual func which will be overriden in derived classes
    virtual int getDamage() //virtual func which will be overriden in derived classes
    {
        int damage;
        damage = (rand() % m_strength) + 1;
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }
};

class Human : public Creature
{
public:
    Human(int strength = 10, int hitpoints = 10) : Creature(strength, hitpoints) {}
    virtual ~Human() {}
    virtual string getSpecies()
    {
        return "Human";
    }
};

class Elf : public Creature
{
public:
    Elf(int strength = 10, int hitpoints = 10) : Creature(strength, hitpoints) {}
    virtual ~Elf() {}
    virtual string getSpecies()
    {
        return "Elf";
    }
    virtual int getDamage()
    {
        int damage = Creature::getDamage();
        if ((rand() % 10) == 0)
        {
            cout << "Magical attack inflicts " << damage << 
            " additional damage points!" << endl;
            damage = damage * 2;
        }
        return damage;
    }
};

class Demon : public Creature
{
public:
    Demon(int strength = 10, int hitpoints = 10) : Creature(strength, hitpoints) {}
    virtual ~Demon() {}
    virtual string getSpecies()
    {
        return "Demon";
    }
    virtual int getDamage()
    {
        int damage = Creature::getDamage(); //Demonic attack inflicts extra dmg 
        if ((rand() % 100) < 5)
        {
            damage = damage + 50;
            cout << "Demonic attack inflicts 50 "
                 << " additional damage points!" << endl;
        }
        return damage;
    }
};

class Balrog : public Demon
{
public:
    Balrog(int strength = 10, int hitpoints = 10) : Demon(strength, hitpoints) {}
    virtual ~Balrog() {}
    virtual string getSpecies()
    {
        return "Balrog";
    }
    virtual int getDamage()
    {
        int damage = Demon::getDamage();    //Base class Demon
        int damage2= (rand() % m_strength) + 1; //Extra damge calculate 
        cout << "Balrog speed attack inflicts " << damage2 <<
        " additional damage points!" << endl;
        damage = damage + damage2;
        return damage;
    }
};

class Cyberdemon : public Demon
{
public:
    Cyberdemon(int strength = 10, int hitpoints = 10) : Demon(strength, hitpoints) {}
    virtual ~Cyberdemon() {}
    virtual string getSpecies()
    {
        return "Cyberdemon";
    }
    virtual int getDamage()
    {
        int damage = Demon::getDamage();
        return damage;
    }
};

//Function declaration comes after class
void battleArena(Creature &creature1, Creature &creature2);


int main()
{
    srand(static_cast<int>(time(NULL)));
    Human human1(30, 10);
    human1.getDamage();
    cout << endl;
    Elf elf1;
    elf1.getDamage();
    cout << endl;
    Balrog balrog1(50, 50);
    
    balrog1.getDamage();
    cout << endl;
    Cyberdemon cdemon(30, 40);
    cdemon.getDamage();
    cout << endl;
    Elf elf2(50, 50);
    Balrog balrog2(50, 50);
    cout << endl;
    battleArena(elf2, balrog2);
}

//Accepts two parameter of object Creature(by reference)
//Loop until one of the Creatures has < 0
//Output appropriate message according to condition
void battleArena(Creature &creature1, Creature &creature2)
{
    while(creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0)
    {
        cout << "Creature 1 has " << creature1.getHitpoints() << 
        " hitpoints." << endl;  //show initial hp
        cout << "Creature 2 has " << creature2.getHitpoints() << 
        " hitpoints." << endl;  //show initial hp
        creature1.setHitpoints(creature1.getHitpoints() - creature2.getDamage());
        cout << "Creature 1 has " << creature1.getHitpoints() << 
        " hitpoints." << endl;  //show hp after taking a hit
        creature2.setHitpoints(creature2.getHitpoints() - creature1.getDamage());
        cout << "Creature 2 has " << creature2.getHitpoints() << 
        " hitpoints." << endl;  //show hp after taking a hit
    }
    if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() <= 0)
        cout << "The battle is a tie!" << endl;
    else if (creature1.getHitpoints() <= 0)
        cout << "Creature 2" << " wins!" << endl;
    else
        cout << "Creature 1" << " wins!" << endl;
}



//Sample Run 1
/* Human attacks for 5 points!

Elf attacks for 1 points!

Balrog attacks for 9 points!
Balrog speed attack inflicts 16 additional damage points!

Cyberdemon attacks for 2 points!


Creature 1 has 50 hitpoints.
Creature 2 has 50 hitpoints.
Balrog attacks for 10 points!
Balrog speed attack inflicts 18 additional damage points!
Creature 1 has 22 hitpoints.
Elf attacks for 16 points!
Creature 2 has 34 hitpoints.
Creature 1 has 22 hitpoints.
Creature 2 has 34 hitpoints.
Balrog attacks for 16 points!
Balrog speed attack inflicts 47 additional damage points!
Creature 1 has -41 hitpoints.
Elf attacks for 19 points!
Creature 2 has 15 hitpoints.
Creature 2 wins! */


//Sample Run 2
/* Human attacks for 13 points!

Elf attacks for 8 points!

Balrog attacks for 7 points!
Balrog speed attack inflicts 48 additional damage points!

Cyberdemon attacks for 27 points!
Demonic attack inflicts 50  additional damage points!


Creature 1 has 50 hitpoints.
Creature 2 has 50 hitpoints.
Balrog attacks for 40 points!
Balrog speed attack inflicts 10 additional damage points!
Creature 1 has 0 hitpoints.
Elf attacks for 19 points!
Creature 2 has 31 hitpoints.
Creature 2 wins! */