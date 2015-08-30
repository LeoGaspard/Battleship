 /**
 * ========================
 * 
 * Filename: main.cpp
 * 
 * Author: NehZio <leo.gaspard@outlook.fr> ;
 * 
 * Description: Battleship main
 * 
 * Created: 27/06/15
 * =========================
 **/
 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Battleship.cpp"
#include "functions.cpp"
#include "map_gen.cpp"

using namespace std;

int main()
{
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
  do
  {
    Battleship game;
    game.play();
  }while(playAgain());
 
 return 0; 
}