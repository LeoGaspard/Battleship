 /**
 * ========================
 * 
 * Filename: Battleship.cpp
 * 
 * Author: NehZio <leo.gaspard@outlook.fr>
 * 
 * Description: Battleship class
 * 
 * Created: 27/06/15
 * =========================
 **/
 
#ifndef BATTLESHIP_H_INCLUDED
#define BATTLESHIP_H_INCLUDED

#include "map_gen.h"

class Battleship
{
  public :
    
    Battleship();
    ~Battleship();
    
    void play();
    void turn();
    bool multi();
    void AI();
    int win();
    void print(int playerTurn);
    
  private :
    
    char mapAI[10][10];
    
    Map mapJ1;
    Map mapJ2;
    
    
    int playerTurn;
    int player;
};

#endif