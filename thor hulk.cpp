#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>
using namespace std;

class Warrior{
private:
  int attkMax;
  int blockMax;

  public:
    string name;
    int health;
    Warrior(string name,int health, int attkMax, int blockMax){
      this -> name = name;
      this->health = health;
      this->attkMax = attkMax;
      this->blockMax = blockMax;
    }
    int Attack(){
        return rand() % this->attkMax;
    }
    int Block(){
      return rand() % this->blockMax;
    }
};

class Battle{

  public:

  //pass by reference why?so we will be able to change the values and the values will stay the same.

    static void startFight(Warrior& warrior1, Warrior& warrior2){
      while(true){
        if(Battle::GetAttackResult(warrior1, warrior2).compare("Game Over") == 0){
        cout << "Game Over\n";
        break;
      }
       if(Battle::GetAttackResult(warrior2, warrior1).compare("Game Over") == 0){
        cout << "Game Over\n";
        break;
       }
      }
    };

    static string GetAttackResult(Warrior& warriorA, Warrior& warriorB){
        int warriorAAttkAmt = warriorA.Attack();
        int warriorBBlockAmt = warriorA.Block();
        int damage2WarriorB = ceil(warriorAAttkAmt - warriorBBlockAmt);
        damage2WarriorB = (damage2WarriorB <= 0) ? 0 : damage2WarriorB;
        warriorB.health = warriorB.health - damage2WarriorB;

        printf("%s attacks %s and deals %d damage\n",warriorA.name.c_str(),warriorB.name.c_str(),damage2WarriorB);

        printf("%s is down to %d health\n",warriorB.name.c_str(),warriorB.health);
      if(warriorB.health <= 0){
        printf("%s has Died %s is Victorious\n",warriorB.name.c_str(),warriorA.name.c_str());
        return "Game Over";
      } else {
        return "Fight again";
      }
    }
};

int main() {


  srand(time(NULL));
  Warrior thor("Thor", 100, 30, 15);
  Warrior hulk("Hulk", 135, 25, 10);

  Battle::startFight(thor, hulk);
  
}