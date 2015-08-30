/**
 * ========================
 * 
 * Filename: Battleship.cpp
 * 
 * Author: NehZio <leo.gaspard@outlook.fr>
 * 
 * Description: Battleship class and function
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
#include "Battleship.h"

using namespace std;

/********************
 *   CONSTRUCTOR    *
 ********************/

Battleship::Battleship()
{
  for(int k=0 ; k<10 ; k++)
    {
      for (int l=0 ; l<10 ; l++)
	{
	  mapAI[k][l] = '*';
	}
    } 
 
 srand(time(0));
 playerTurn = rand()%2 + 1; // Random selection of the player who will begin 
 
}

/********************
 *    DESCTUCTOR    *
 * ******************/

Battleship::~Battleship()
{
		  //Nothing
}

/*******************
 *      PLAY       *
 *******************/
	
void Battleship::play()
{
	bool twoPlayers = multi();
	
	while(win()== 0)
	{
		if(twoPlayers)
		{
			turn();
			
			if(playerTurn == 1)                	// If player 1 has played, it's player 2's turn
			{
			  playerTurn = 2;
			}  
			else if(playerTurn == 2)                // If player 2 has played, it's player 1's turn
			  playerTurn = 1;
			
		}
		else
		{
			if(playerTurn == 1)
			{
				turn();
				playerTurn = 2;
				
			}
			else
			{
				AI();
				playerTurn = 1;
			}
		}
	}
	
	if(win() == 1)
	{
	  TTF_Font *police = 0;
	  police = TTF_OpenFont("Marcsc.ttf", 40);
	  
	  SDL_Surface *winner, *background, *screen;
	  SDL_Rect backgroundPos, winnerPos;
	  SDL_Color white = {255, 255, 255};
	      
	  screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	      
	  background = IMG_Load("pictures/win.png");
	  
	  backgroundPos.x = 0;
	  backgroundPos.y = 0;
	  SDL_BlitSurface(background, 0, screen, &backgroundPos);
	  
	  winner = TTF_RenderText_Blended(police, "The winner is Player 1", white);
	  winnerPos.x = 800;
	  winnerPos.y = 75;
	  SDL_BlitSurface(winner, 0, screen, &winnerPos);
	  
	  SDL_Flip(screen);
	}
	else if(win() == 2)
	{
		if(twoPlayers)
		{
                  TTF_Font *police = 0;
		  police = TTF_OpenFont("Marcsc.ttf", 40);
		  
		  SDL_Surface *winner, *background, *screen;
		  SDL_Rect backgroundPos, winnerPos;
		  SDL_Color white = {255, 255, 255};
		      
		  screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
		      
		  background = IMG_Load("pictures/win.png");
		  
		  backgroundPos.x = 0;
		  backgroundPos.y = 0;
		  SDL_BlitSurface(background, 0, screen, &backgroundPos);
		  
		  winner = TTF_RenderText_Blended(police, "The winner is Player 2", white);
		  winnerPos.x = 800;
		  winnerPos.y = 75;
		  SDL_BlitSurface(winner, 0, screen, &winnerPos);
		  
		  SDL_Flip(screen);
		}
		else
		{
		  TTF_Font *police = 0;
	          police = TTF_OpenFont("Marcsc.ttf", 40);
	  
		  SDL_Surface *winner, *background, *screen;
		  SDL_Rect backgroundPos, winnerPos;
		  SDL_Color white = {255, 255, 255};
		      
		  screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
		      
		  background = IMG_Load("pictures/win.png");
		  
		  backgroundPos.x = 0;
		  backgroundPos.y = 0;
		  SDL_BlitSurface(background, 0, screen, &backgroundPos);
		  
		  winner = TTF_RenderText_Blended(police, "The winner is AI", white);
		  winnerPos.x = 800;
		  winnerPos.y = 75;
		  SDL_BlitSurface(winner, 0, screen, &winnerPos);
		  
		  SDL_Flip(screen);
		}
	}
	SDL_Delay(2000);
	
}

/********************
 *       TURN       *
 * ******************/

void Battleship::turn()
{
  int x = 0, y = 0;
  
  SDL_Event event;
    
    
  if(playerTurn == 1)
  {    
    print(1);
    
    do
    {
      do
      {
	SDL_WaitEvent(&event);      
      }while(event.type != SDL_MOUSEBUTTONUP && event.type != SDL_QUIT);
      
      if(event.type == SDL_QUIT)
	    exit(0);
      
      x = (event.button.x-700)/50 ;
      y = (event.button.y-150)/50 ;
      
    }while(x >= 10 || x < 0  || y >= 10 || y < 0);
    
   if((mapJ2.getMap(y, x) == '*' || mapJ2.getMap(y, x) == 'M') && mapJ2.getMap(y, x) != 'T')
   {
     mapJ2.setMap(y, x, 'M');
   }
   else
   {
     mapJ2.setMap(y, x, 'T');
   }	  
  }
   
  if(playerTurn == 2)
  { 
    print(2);
       
    do
      {
	do
	{
	  SDL_WaitEvent(&event);      
	}while(event.type != SDL_MOUSEBUTTONUP && event.type != SDL_QUIT);
	
	x = (event.button.x-55)/50 ;
	y = (event.button.y-150)/50 ;
	
	if(event.type == SDL_QUIT)
	    exit(0);
	
      }while(x >= 10 || x < 0  || y >= 10 || y < 0);
    
    if((mapJ1.getMap(y, x) == '*' || mapJ1.getMap(y, x) == 'M') && mapJ1.getMap(y, x) != 'T')
    {
      mapJ1.setMap(y, x, 'M');
    }
    else
    {
      mapJ1.setMap(y, x, 'T');
    }	  
  }    
}

/********************
 *      MULTI       *
 * ******************/

bool Battleship::multi()
{
	char choice = '*';
	bool chosen = false;
	
	TTF_Font *police = 0;
	police = TTF_OpenFont("Marcsc.ttf", 40);
	
	SDL_Surface *screen = 0, *background = 0, *question = 0, *answer1 = 0, *answer2 = 0;
	SDL_Rect backgroundPos, questionPos, answer1Pos, answer2Pos;
	SDL_Color black = {0, 0, 0};
        SDL_Event event;
	    
        screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	    
	background = IMG_Load("pictures/background_3.png");
	
	backgroundPos.x = 0;
        backgroundPos.y = 0;
        SDL_BlitSurface(background, 0, screen, &backgroundPos);	
	
	question = TTF_RenderText_Blended(police, "Do you want to play against a Player or against AI ?", black);
	answer1 = TTF_RenderText_Blended(police, "Player", black);
	answer2 = TTF_RenderText_Blended(police, "AI", black);
	
	questionPos.x = 230;
	questionPos.y = 90;
	SDL_BlitSurface(question, 0, screen, &questionPos);
	
	answer1Pos.x = 120;
	answer1Pos.y = 450;
	SDL_BlitSurface(answer1, 0, screen, &answer1Pos);
	
	answer2Pos.x = 1080;
	answer2Pos.y = 450;
	SDL_BlitSurface(answer2, 0, screen, &answer2Pos);
	
	SDL_Flip(screen);
	
	do
	{
	  do
	  {
	    SDL_WaitEvent(&event);
	  }while(event.type != SDL_MOUSEBUTTONUP && event.type != SDL_QUIT);
	  
	  if(event.type == SDL_MOUSEBUTTONUP)
	    {
	      if(event.button.button == SDL_BUTTON_LEFT)
	      {
		if(event.button.x <= 250 && event.button.x >= 100 && event.button.y <= 500 && event.button.y >= 450)
		  choice = 'p';
		if(event.button.x <= 1180  && event.button.x >= 1030 && event.button.y <= 500 && event.button.y >= 450)
		  choice = 'a';
	      }
	    }
	    if(event.type == SDL_QUIT)
	    exit(0);
	}while(choice != 'a' && choice != 'p');
	
	
	question = TTF_RenderText_Blended(police, "Player 1, do you want a random map or do you want to build your own ?", black);
	answer1 = TTF_RenderText_Blended(police, "Random", black);
	answer2 = TTF_RenderText_Blended(police, "I build", black);
	
	questionPos.x = 45;
	answer1Pos.x = 105;
	answer2Pos.x = 1045;
	
	SDL_BlitSurface(background, 0, screen, &backgroundPos);	
	SDL_BlitSurface(question, 0, screen, &questionPos);
	SDL_BlitSurface(answer1, 0, screen, &answer1Pos);
	SDL_BlitSurface(answer2, 0, screen, &answer2Pos);
	
	SDL_Flip(screen);
	do
	{
		do
		{
		  SDL_WaitEvent(&event);	  
		}while(event.type != SDL_MOUSEBUTTONUP && event.type != SDL_QUIT);
		  
		if(event.type == SDL_MOUSEBUTTONUP)
		{
		  if(event.button.button == SDL_BUTTON_LEFT)
		  {
		    if(event.button.x <= 250 && event.button.x >= 100 && event.button.y <= 500 && event.button.y >= 450)
		    {
			  mapJ1.random();
			  chosen = true;
		    }
		    if(event.button.x <= 1180  && event.button.x >= 1030 && event.button.y <= 500 && event.button.y >= 450)
		    {
		      mapJ1.diy(1);
		      chosen = true;
		    }
		  }	  
		}
		if(event.type == SDL_QUIT)
		    exit(0);
	}while(!chosen);

	
	if(choice == 'p')
	{
	  question = TTF_RenderText_Blended(police, "Player 2, do you want a random map or do you want to build your own ?", black);
	  answer1 = TTF_RenderText_Blended(police, "Random", black);
	  answer2 = TTF_RenderText_Blended(police, "I build", black);
	  
	  SDL_BlitSurface(background, 0, screen, &backgroundPos);	
	  SDL_BlitSurface(question, 0, screen, &questionPos);
	  SDL_BlitSurface(answer1, 0, screen, &answer1Pos);
	  SDL_BlitSurface(answer2, 0, screen, &answer2Pos);
	  
	  SDL_Flip(screen);

	  do
	  {
	    SDL_WaitEvent(&event);	  
	  }while(event.type != SDL_MOUSEBUTTONUP && event.type != SDL_QUIT);
	    
	  if(event.type == SDL_MOUSEBUTTONUP)
	  {
	    if(event.button.button == SDL_BUTTON_LEFT)
	    {
	      if(event.button.x <= 250 && event.button.x >= 100 && event.button.y <= 500 && event.button.y >= 450)
		    mapJ2.random();
	      if(event.button.x <= 1180  && event.button.x >= 1030 && event.button.y <= 500 && event.button.y >= 450)
		    mapJ2.diy(2);	    
	    }	  
	  }
	  if(event.type == SDL_QUIT)
	    exit(0);
	  return true;
	}
	
        else
	{
	  mapJ2.random();
	  return false;
	}  
}

/********************
 *       AI         *
 * ******************/

void Battleship::AI()
{
  int x = 0, y = 0, T = 0;
  bool random = true;
  
    
 for(int k=0 ; k<10 ; k++)
  {
    for(int l=0 ; l<10 ; l++)
    {
      if(mapAI[k][l] == 'T')
      {
	random = false;
	
	if(mapAI[k+1][l] == '*')
	{
	  x = k+1;
	  y = l;
	  T++;
	}
	
	else if(mapAI[k-1][l] == '*')
	{
	  x = k-1;
	  y = l;
	  T++;
	}
	
	else if(mapAI[k][l+1] == '*')
	{
	  x = k;
	  y = l+1;
	  T++;
	}
	
	else if(mapAI[k][l-1] == '*')
	{
	  x = k;
	  y = l-1;
	  T++;
	}
	
      }
      else if(T == 0)
	random = true;      
    }
  }
    
      if(random)
      {
	do
	{
	  x = rand()%10 + 0;
	  y = rand()%10 + 0;
	}while(mapAI[x][y] != '*');
      }

  
  if((mapJ1.getMap(y,x) == '*'|| mapJ1.getMap(y,x) == 'M') && mapJ1.getMap(y,x) != 'T')
  {
      mapJ1.setMap(y, x, 'M');                                                // If there isn't any boat, missed
      mapAI[x][y] = 'M';
      
      x++;
      y++;
  }
  else
  {
      mapJ1.setMap(y, x, 'T');						// If there is a boat, touched
      mapAI[x][y] = 'T'; 
  }
}

/********************
 *      WIN         *
 * ******************/

int Battleship::win()
{
  bool boatJ1 = false;
  bool boatJ2 = false;
  
  for(int i = 0 ; i < 10 ; i++)
  {
    for(int j = 0 ; j < 10 ; j++)
    {
      if(mapJ1.getMap(i,j) == '2' || mapJ1.getMap(i,j) == '3' || mapJ1.getMap(i,j) == '4' || mapJ1.getMap(i,j) == '5')
	boatJ1 = true;                                                                            // If there is a boat, true
      if(mapJ2.getMap(i,j) == '2' ||  mapJ2.getMap(i,j)== '3' || mapJ2.getMap(i,j) == '4' || mapJ2.getMap(i,j) == '5')
	boatJ2 = true;										  // If there is a boat, false
    }
  }
  
  if(!boatJ1)
    return 2; // If J1 has no boat left, J2 win
  if(!boatJ2)
    return 1; // If J2 has no boat left, J1 win
  
  return 0;
}

/*******************
 *      PRINT      *
 *******************/

void Battleship::print(int playerTurn)
{
  
  char J1 = ' ', J2 = ' ';
  
  TTF_Font *police = 0;
  police = TTF_OpenFont("Marcsc.ttf", 40);
  SDL_Color black = {0, 0, 0};
  
  SDL_Surface *screen = 0, *background = 0, *grid = 0, *touched = 0, *missed = 0, *player1 = 0, *player2 = 0, *turn = 0;
  SDL_Rect backgroundPos, gridPos, touchedPos, missedPos, player1Pos, player2Pos, turnPos;
  
  	    
  screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  
  player1 = TTF_RenderText_Blended(police, "Player 1", black);
  player2 = TTF_RenderText_Blended(police, "Player 2", black);
	    
  background = IMG_Load("pictures/background_2.png");
  grid = IMG_Load("pictures/grid.png");
  touched = IMG_Load("pictures/touched.png");
  missed = IMG_Load("pictures/missed.png");
  turn = IMG_Load("pictures/turn.png");
  
  if(playerTurn == 1)
  {
    turnPos.x = 485;
    turnPos.y = 35;
  }
  
  if(playerTurn == 2)
  {
    turnPos.x = 700;
    turnPos.y = 35;
  }
  
 
  
  backgroundPos.x = 0;
  backgroundPos.y = 0;
  SDL_BlitSurface(background, 0, screen, &backgroundPos);
  
  SDL_BlitSurface(turn, 0, screen, &turnPos);
  
  player1Pos.x = 230;
  player1Pos.y = 35;
  SDL_BlitSurface(player1, 0, screen, &player1Pos);
  
  player2Pos.x = 855;
  player2Pos.y = 35;
  SDL_BlitSurface(player2, 0, screen, &player2Pos);
  
  gridPos.x = 55;
  gridPos.y = 150;
  SDL_BlitSurface(grid, 0, screen, &gridPos);
  
  gridPos.x = 700;
  gridPos.y = 150;
  SDL_BlitSurface(grid, 0, screen, &gridPos);
  
  for(int i = 0; i<10; i++)
  {
    for(int j = 0; j<10; j++)
    {
      J1 = mapJ1.getMap(i,j);
      J2 = mapJ2.getMap(i,j);
      
      if(J1 == 'T')
      {
	touchedPos.x = 55 + 50*j;
	touchedPos.y = 150 + 50*i;
	SDL_BlitSurface(touched, 0, screen, &touchedPos);
      }
      
      if(J1 == 'M')
      {
	missedPos.x = 55 + 50*j;
	missedPos.y = 150 + 50*i;
	SDL_BlitSurface(missed, 0, screen, &missedPos);
      }
      
      if(J2 == 'T')
      {
	touchedPos.x = 700 + 50*j;
	touchedPos.y = 150 + 50*i;
	SDL_BlitSurface(touched, 0, screen, &touchedPos);
      }
      
      if(J2 == 'M')
      {
	missedPos.x = 700 + 50*j;
	missedPos.y = 150 + 50*i;
	SDL_BlitSurface(missed, 0, screen, &missedPos);
      }
    }
  }
  SDL_Flip(screen);
}