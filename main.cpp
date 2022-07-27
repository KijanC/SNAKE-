//
//  main.cpp
//
//
//  Created by Kijan Cassel on 25.07.22.
//

#include <iostream>
#include <string>
#include <cstdlib>
//#include "Tail.h"

using namespace std;

// entity standert festlegen
class entity
{       
    private:
        int posX_;
        int posY_;
    public:
        void setXY(int posX, int posY){posX_ = posX; posY_ = posY;}

        // Parameter festlegen
        void setX(int posX){posX_ = posX;}
        void setY(int posY){posY_ = posY;}

        // Varibalen der Klasse abfragen
        int get_posX(void){return posX_;}
        int get_posY(void){return posY_;}
};

int main()
{   
    // Setup
    // Player Setup
    entity Player;
    Player.setXY(0,0);
    string input;

    // Item Setup
    entity Fruit;
    Fruit.setX(rand() % 7);
    Fruit.setY(rand() % 4);
    
    // Startscreen
    int start[5][7] = {
         {1,8,8,8,8,8,8},
         {0,8,8,8,8,8,8},
         {8,8,8,8,8,8,8},
         {8,8,8,8,8,8,8},
         {8,8,8,8,8,8,8}
        };

    for (int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 7; j++)
            {
                cout << start[i][j];
            }
            cout << endl;
        }
        cout << endl;


    // Game
    while (true)
    {    
        // Map setup
        int field[5][7] = {
            {8,8,8,8,8,8,8}, 
            {8,8,8,8,8,8,8},
            {8,8,8,8,8,8,8},
            {8,8,8,8,8,8,8},
            {8,8,8,8,8,8,8}
        };
        

        // Player interaction

        int PlayerPosX = Player.get_posX();
        int PlayerPosY = Player.get_posY();

        // User Input
        cin >> input;
        cout << endl;
        if (input == "w") {Player.setY(PlayerPosY -= 1);}
        if (input == "s") {Player.setY(PlayerPosY += 1);}
        if (input == "a") {Player.setX(PlayerPosX -= 1);}
        if (input == "d") {Player.setX(PlayerPosX += 1);}

        field[Player.get_posY()][Player.get_posX()] = 1;


        // Map begerenzung
        // 4 & 6 da bei 0 angefangen wird zu zählen
        if (Player.get_posY() < 0 || Player.get_posY() > 4) 
        {
            cout << "du bist gegen die Wand gelaufen" << endl;
            break;
        }
        if (Player.get_posX() < 0 || Player.get_posX() > 6)
        {
            cout << "du bist gegen die Wand gelaufen" << endl;
            break;
        }


        // Fruit Item
        // actiom
        if (Fruit.get_posX() == Player.get_posX() && Fruit.get_posY() == Player.get_posY())
        {
            Fruit.setX(rand() % 7);
            Fruit.setY(rand() % 4);
            cout << "✨ du hast das Item bekommen ✨" << endl;
            cout << endl;
        }
        
        // Spawn
        field[Fruit.get_posY()][Fruit.get_posX()] = 0;



        // Gameoutput
        for (int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 7; j++)
            {
                cout << field[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
