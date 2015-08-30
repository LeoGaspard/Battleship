  /**
 * ========================
 * 
 * Filename: map_gen.cpp
 * 
 * Author: NehZio <leo.gaspard@outlook.fr>
 * 
 * Description: The map generator
 * 
 * Created: 01/07/15
 * =========================
 **/ 
 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "map_gen.h"

/********************
 *   CONSTRUCTOR    *
 * ******************/

Map::Map()
{
  for(int i = 0; i < 10; i++)
  {
    for(int j = 0; j < 10; j++)
      map[i][j] = '*';
  }
  
  srand(time(0));
}

/********************
 *    DESTRUCTOR    *
 ********************/

Map::~Map()
{
  //nothing
}

/*******************
 *     RANDOM      *
 *******************/

void Map::random()
{
      int face = 0;
      int i = 0, j = 0;
      
      face = rand()%4 + 1; // 1 up  2 down  3 left  4 right
      
      switch(face)
      {
	case 1:
	    i = rand()%9 + 1;
	    j = rand()%10 + 0;
	  map[i][j] = '2';
	  map[i-1][j] = '2';
	  break;
	  
	case 2:
	    i = rand()%9 + 0;
	    j = rand()%10 + 0;
	  map[i][j] = '2';
	  map[i+1][j] = '2';
	  break;
	  
	case 3:
	    i = rand()%10 + 0;
	    j = rand()%9 + 1;
	  map[i][j] = '2';
	  map[i][j-1] = '2';
	  break;
	  
	case 4:
	    i = rand()%10 + 0;
	    j = rand()%9 + 0;
	  map[i][j] = '2';
	  map[i][j+1] = '2';
	  break;
      }   

      
      face = rand()%4 + 1; // 1 up  2 down  3 left  4 right
      
      switch(face)
      {
	case 1:
	  do
	  {
	    i = rand()%8 + 2;
	    j = rand()%10 + 0;
	  }while(map[i][j] != '*' || map[i-1][j] != '*' || map[i-2][j] != '*');
	  map[i][j] = '3';
	  map[i-1][j] = '3';
	  map[i-2][j] = '3';
	  break;
	  
	case 2:
	  do
	  {
	    i = rand()%8 + 0;
	    j = rand()%10 + 0;
	  }while(map[i][j] != '*' || map[i+1][j] != '*' || map[i+2][j] != '*');
	  map[i][j] = '3';
	  map[i+1][j] = '3';
	  map[i+2][j] = '3';
	  break;
	  
	case 3:
	  do
	  {
	    i = rand()%10 + 0;
	    j = rand()%8 + 2;
	  }while(map[i][j] != '*' || map[i][j-1] != '*' || map[i][j-2] != '*');
	  map[i][j] = '3';
	  map[i][j-1] = '3';
	  map[i][j-2] = '3';
	  break;
	  
	case 4:
	  do
	  {
	    i = rand()%10 + 0;
	    j = rand()%8 + 0;
	  }while(map[i][j] != '*' || map[i][j+1] != '*' || map[i][j+2] != '*');
	  map[i][j] = '3';
	  map[i][j+1] = '3';
	  map[i][j+2] = '3';
	  break;
      }   
	
	face = rand()%4 + 1; // 1 up  2 down  3 left  4 right
      
      switch(face)
      {
	case 1:
	  do
	  {
	    i = rand()%7 + 3;
	    j = rand()%10 + 0;
	  }while(map[i][j] != '*' || map[i-1][j] != '*' || map[i-2][j] != '*' || map[i-3][j] != '*');
	  map[i][j] = '4';
	  map[i-1][j] = '4';
	  map[i-2][j] = '4';
	  map[i-3][j] = '4';
	  break;
	  
	case 2:
	  do
	  {
	    i = rand()%7 + 0;
	    j = rand()%10 + 0;
	  }while(map[i][j] != '*' || map[i+1][j] != '*' || map[i+2][j] != '*' || map[i+3][j] != '*');
	  map[i][j] = '4';
	  map[i+1][j] = '4';
	  map[i+2][j] = '4';
	  map[i+3][j] = '4';
	  break;
	  
	case 3:
	  do
	  {
	    i = rand()%10 + 0;
	    j = rand()%7 + 3;
	  }while(map[i][j] != '*' || map[i][j-1] != '*' || map[i][j-2] != '*' || map[i][j-3] != '*');
	  map[i][j] = '4';
	  map[i][j-1] = '4';
	  map[i][j-2] = '4';
	  map[i][j-3] = '4';
	  break;
	  
	case 4:
	  do
	  {
	    i = rand()%10 + 0;
	    j = rand()%7 + 0;
	  }while(map[i][j] != '*' || map[i][j+1] != '*' || map[i][j+2] != '*' || map[i][j+3] != '*');
	  map[i][j] = '4';
	  map[i][j+1] = '4';
	  map[i][j+2] = '4';
	  map[i][j+3] = '4';
	  break;
      }   
      
	face = rand()%4 + 1; // 1 up  2 down  3 left  4 right
      
      switch(face)
      {
	case 1:
	  do
	  {
	    i = rand()%6 + 4;
	    j = rand()%10 + 0;
	  }while(map[i][j] != '*' || map[i-1][j] != '*' || map[i-2][j] != '*' || map[i-3][j] != '*' || map[i-4][j] != '*');
	  map[i][j] = '5';
	  map[i-1][j] = '5';
	  map[i-2][j] = '5';
	  map[i-3][j] = '5';
	  map[i-4][j] = '5';
	  break;
	  
	case 2:
	  do
	  {
	    i = rand()%6 + 0;
	    j = rand()%10 + 0;
	  }while(map[i][j] != '*' || map[i+1][j] != '*' || map[i+2][j] != '*' || map[i+3][j] != '*' || map[i+4][j] != '*');
	  map[i][j] = '5';
	  map[i+1][j] = '5';
	  map[i+2][j] = '5';
	  map[i+3][j] = '5';
	  map[i+4][j] = '5';
	  break;
	  
	case 3:
	  do
	  {
	    i = rand()%10 + 0;
	    j = rand()%6 + 4;
	  }while(map[i][j] != '*' || map[i][j-1] != '*' || map[i][j-2] != '*' || map[i][j-3] != '*' || map[i][j-4] != '*');
	  map[i][j] = '5';
	  map[i][j-1] = '5';
	  map[i][j-2] = '5';
	  map[i][j-3] = '5';
	  map[i][j-4] = '5';
	  break;
	  
	case 4:
	  do
	  {
	    i = rand()%10 + 0;
	    j = rand()%6 + 0;
	  }while(map[i][j] != '*' || map[i][j+1] != '*' || map[i][j+2] != '*' || map[i][j+3] != '*' || map[i][j+4] != '*');
	  map[i][j] = '5';
	  map[i][j+1] = '5';
	  map[i][j+2] = '5';
	  map[i][j+3] = '5';
	  map[i][j+4] = '5';
	  break;
      } 
}

/********************
 *        DIY       *
 ********************/

void Map::diy(int player)
{
   TTF_Font *police = 0;
   police = TTF_OpenFont("Marcsc.ttf", 40);
  
   SDL_Surface *screen = 0, *background = 0, *grid = 0, *littleBoat = 0, *mediumBoat = 0, *largeBoat = 0, *hugeBoat = 0, *playerScreen = 0, *place = 0;
   SDL_Rect backgroundPos, gridPos, littleBoatPos, mediumBoatPos, largeBoatPos, hugeBoatPos, playerPos, placePos;
   SDL_Color black = {0, 0, 0};
   SDL_Event event;
	    
   screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	    
   background = IMG_Load("pictures/background_1.png");
   grid = IMG_Load("pictures/grid.png");
   littleBoat = IMG_Load("pictures/little_ship_horizontal.png");
   mediumBoat = IMG_Load("pictures/medium_ship_horizontal.png");
   largeBoat = IMG_Load("pictures/large_ship_horizontal.png");
   hugeBoat = IMG_Load("pictures/huge_ship_horizontal.png");
   
   backgroundPos.x = 0;
   backgroundPos.y = 0;
   SDL_BlitSurface(background, 0, screen, &backgroundPos);   
	    
   gridPos.x = 355;
   gridPos.y = 144;
   SDL_BlitSurface(grid, 0, screen, &gridPos);
	    
   littleBoatPos.x = 990;
   littleBoatPos.y = 226;
   SDL_BlitSurface(littleBoat, 0, screen, &littleBoatPos);
	    
   mediumBoatPos.x = 965;
   mediumBoatPos.y = 299;
   SDL_BlitSurface(mediumBoat, 0, screen, &mediumBoatPos);
	    
   largeBoatPos.x = 940;
   largeBoatPos.y = 369;
   SDL_BlitSurface(largeBoat, 0, screen, &largeBoatPos);
	    
   hugeBoatPos.x = 915;
   hugeBoatPos.y = 439;
   SDL_BlitSurface(hugeBoat, 0, screen, &hugeBoatPos);
   
   if(player == 1)
     playerScreen = TTF_RenderText_Blended(police, "Player 1", black);
   if(player == 2)
     playerScreen = TTF_RenderText_Blended(police, "Player 2", black);
   playerPos.x = 570;
   playerPos.y = 30;
   SDL_BlitSurface(playerScreen, 0, screen, &playerPos);
	    
   SDL_Flip(screen);
   
   int xB = 0, yB = 0, xE = 0, yE = 0;
   bool placed = false; 							// To know if the boat is succesfully placed or not
   
   
      for(int k = 2 ; k <= 5 ; k++)
    {
      do
      {
	do
	{              
	  placePos.x = 300;
	  placePos.y = 80;
	  place = TTF_RenderText_Blended(police, "Choose the the first point of your boat", black);
		  
	  SDL_BlitSurface(background, 0, screen, &backgroundPos); 
	  SDL_BlitSurface(grid, 0, screen, &gridPos);
	  SDL_BlitSurface(littleBoat, 0, screen, &littleBoatPos);
	  SDL_BlitSurface(mediumBoat, 0, screen, &mediumBoatPos);
	  SDL_BlitSurface(largeBoat, 0, screen, &largeBoatPos);
	  SDL_BlitSurface(hugeBoat, 0, screen, &hugeBoatPos);
	  SDL_BlitSurface(playerScreen, 0, screen, &playerPos);
	  SDL_BlitSurface(place, 0, screen, &placePos);
		  
	  SDL_Flip(screen);
		
	  do
	  {
	    SDL_WaitEvent(&event);	 
	  }while(event.type != SDL_MOUSEBUTTONUP && event.type != SDL_QUIT);
		  
	  if(event.type == SDL_MOUSEBUTTONUP)
	  {
	    if(event.button.button == SDL_BUTTON_LEFT)
	    {
	      xB = (event.button.x-355)/50;
	      yB = (event.button.y-144)/50;	  
	    }
	    
	  }
	  if(event.type == SDL_QUIT)
	    exit(0);
	  
	  cout << endl << map[yB][xB] << " " << xB << " " << yB;
	  
	}while(xB >= 10 || xB < 0 || yB >= 10 || yB < 0 || map[yB][xB] != '*');
	
	do
	{
	  placePos.x = 200;
	  placePos.y = 80;
	  place = TTF_RenderText_Blended(police, "Choose the last point of your boat", black);
		      
	  SDL_BlitSurface(background, 0, screen, &backgroundPos); 
	  SDL_BlitSurface(grid, 0, screen, &gridPos);
	  SDL_BlitSurface(littleBoat, 0, screen, &littleBoatPos);
	  SDL_BlitSurface(mediumBoat, 0, screen, &mediumBoatPos);
	  SDL_BlitSurface(largeBoat, 0, screen, &largeBoatPos);
	  SDL_BlitSurface(hugeBoat, 0, screen, &hugeBoatPos);
	  SDL_BlitSurface(playerScreen, 0, screen, &playerPos);
	  SDL_BlitSurface(place, 0, screen, &placePos);
		      
	  SDL_Flip(screen);
		      
	  do
	    {
	      SDL_WaitEvent(&event);	 
	    }while(event.type != SDL_MOUSEBUTTONUP && event.type != SDL_QUIT);
		    
	    if(event.type == SDL_MOUSEBUTTONUP)
	    {
	      if(event.button.button == SDL_BUTTON_LEFT)
	      {
		xE = (event.button.x-355)/50;
		yE = (event.button.y-144)/50;	  
	      }
	      
	    }
	    if(event.type == SDL_QUIT)
	      exit(0);	   
	    
	    cout << endl << map[yE][xE] << " " << xE << " " << yE;
	    
	}while(xE >= 10 || xE < 0 || yE >= 10 || yE < 0 || map[yE][xE] != '*');
	
	if(k == 2)
	  {
	    if((xE == xB + 1 && yE == yB) || (xE == xB - 1 && yE == yB) || (yE == yB + 1 && xE == xB) || (yE == yB - 1 && xE == xB))
	    {
	      map[yB][xB] = '2';
	      map[yE][xE] = '2';
	      
	      if(yE == yB)
	      {
		littleBoat = IMG_Load("pictures/little_ship_horizontal.png");
		
		if(xE == xB + 1)
		{
		  littleBoatPos.x = xB*50 + 358;
		  littleBoatPos.y = yB*50 + 148;	    
		}
		if(xE == xB - 1)
		{
		  littleBoatPos.x = xE*50 + 358;
		  littleBoatPos.y = yE*50 + 148;
		}	  
	      }
	      
	      if(xE == xB)
	      {
		littleBoat = IMG_Load("pictures/little_ship_vertical.png");
		
		if(yE == yB + 1)
		{
		  littleBoatPos.x = xB*50 + 358;
		  littleBoatPos.y = yB*50 + 148;	    
		}
		if(yE == yB - 1)
		{
		  littleBoatPos.x = xE*50 + 358;
		  littleBoatPos.y = yE*50 + 148;	    
		}	  
	      }
	      
	      placed = true;

	    }
	  }
	  
	if(k == 3)
	{
	  placed = false;
	  
	  if((xE == xB + 2 && yE == yB) || (xE == xB - 2 && yE == yB) || (xE == xB && yE == yB + 2) || (xE == xB && yE == yB - 2))
	  {
	    
	    if(yE == yB)
	    {
	      mediumBoat = IMG_Load("pictures/medium_ship_horizontal.png");
	    
	      if(xE == xB + 2)
	      {	
		if(map[yB][xB+1] == '*')
		{
		  map[yB][xB] = '3';
		  map[yB][xB+1] = '3';
		  map[yB][xB+2] = '3';
		  placed = true;
		  mediumBoatPos.x = xB*50 + 358;
		  mediumBoatPos.y = yB*50 + 148;
		}			      
	      }
	      if(xE == xB - 2)
	      {
		if(map[yB][xB-1] == '*')
		{
		  map[yB][xB] = '3';
		  map[yB][xB-1] = '3';
		  map[yB][xB-2] = '3';
		  placed = true;
		  mediumBoatPos.x = xE*50 + 358;
		  mediumBoatPos.y = yE*50 + 148;	
		}	      
	      }	    
	    }
	    
	  if(xE == xB)
	      {
		mediumBoat = IMG_Load("pictures/medium_ship_vertical.png");
		
		if(yE == yB + 2)
		{
		  if(map[yB+1][xB] == '*')
		  {
		    map[yB][xB] = '3';
		    map[yB+1][xB] = '3';
		    map[yB+1][xB] = '3';
		    placed = true;
		    mediumBoatPos.x = xB*50 + 358;
		    mediumBoatPos.y = yB*50 + 148;
		  }		  	    
		}
		if(yE == yB - 2)
		{
		  if(map[yB-1][xB] == '*')
		  {
		    map[yB][xB] = '3';
		    map[yB-1][xB] = '3';
		    map[yB-2][xB] = '3';
		    placed = true;
		    mediumBoatPos.x = xE*50 + 358;
		    mediumBoatPos.y = yE*50 + 148;
		  }		  	    
		}	  
	      }
	    }
	}
	
	if(k == 4)
	{
	  placed = false;
	  
	  if((xE == xB + 3 && yE == yB) || (xE == xB - 3 && yE == yB) || (xE == xB && yE == yB + 3) || (xE == xB && yE == yB - 3))
	  {
	    
	    if(yE == yB)
	    {
	    
	      largeBoat = IMG_Load("pictures/large_ship_horizontal.png");
	    
	      if(xE == xB + 3)
	      {
		if(map[yB][xB+1] == '*' && map[yB][xB+2] == '*')
		{
		  map[yB][xB] = '4';
		  map[yB][xB+1] = '4';
		  map[yB][xB+2] = '4';
		  map[yB][xB+3] = '4';
		  placed = true;
		  largeBoatPos.x = xB*50 + 358;
		  largeBoatPos.y = yB*50 + 148;	
		}		      
	      }
	      if(xE == xB - 3)
	      {
		if(map[yB][xB-1] == '*' && map[yB][xB-2] == '*')
		{
		  map[yB][xB] = '4';
		  map[yB][xB-1] = '4';
		  map[yB][xB-2] = '4';
		  map[yB][xB-3] = '4';
		  placed = true;
		  largeBoatPos.x = xE*50 + 358;
		  largeBoatPos.y = yE*50 + 148;	 
		}	     
	      }
	     }	    
	  if(xE == xB)
	      {
		largeBoat = IMG_Load("pictures/large_ship_vertical.png");
		
		if(yE == yB + 3)
		{
		  if(map[yB+1][xB] == '*' && map[yB+2][xB] == '*')
		  {
		    map[yB][xB] = '4';
		    map[yB+1][xB] = '4';
		    map[yB+2][xB] = '4';
		    map[yB+3][xB] = '4';
		    placed = true;
		    largeBoatPos.x = xB*50 + 358;
		    largeBoatPos.y = yB*50 + 148;	 
		  }	     
		}
		if(yE == yB - 3)
		{
		  if(map[yB-1][xB] == '*' && map[yB-2][xB] == '*')
		  {
		    map[yB][xB] = '4';
		    map[yB-1][xB] = '4';
		    map[yB-2][xB] = '4';
		    map[yB-3][xB] = '4';
		    placed = true;
		    largeBoatPos.x = xE*50 + 358;
		    largeBoatPos.y = yE*50 + 148;	
		  }		      
		}	  
	      }
	    }
	}
	
	
	if(k == 5)
	{
	  placed = false;
	  
	  if((xE == xB + 4 && yE == yB) || (xE == xB - 4 && yE == yB) || (xE == xB && yE == yB + 4) || (xE == xB && yE == yB - 4))
	  {
	    
	    if(yE == yB)
	    {
	      hugeBoat = IMG_Load("pictures/huge_ship_horizontal.png");
	    
	      if(xE == xB + 4)
	      {
		if(map[yB][xB+1] == '*' && map[yB][xB+2] == '*' && map[yB][xB+3] == '*')
		{
		  map[yB][xB] = '5';
		  map[yB][xB+1] = '5';
		  map[yB][xB+2] = '5';
		  map[yB][xB+3] = '5';
		  map[yB][xB+4] = '5';
		  placed = true;
		  hugeBoatPos.x = xB*50 + 358;
		  hugeBoatPos.y = yB*50 + 148;
		}			      
	      }
	      if(xE == xB - 4)
	      {
		if(map[yB][xB-1] == '*' && map[yB][xB-2] == '*' && map[yB][xB-3] == '*')
		{
		  map[yB][xB] = '5';
		  map[yB][xB-1] = '5';
		  map[yB][xB-2] = '5';
		  map[yB][xB-3] = '5';
		  map[yB][xB-4] = '5';
		  placed = true;
		  hugeBoatPos.x = xE*50 + 358;
		  hugeBoatPos.y = yE*50 + 148;
		}			      
	      }	    
	    }
	    
	  if(xE == xB)
	      {
		hugeBoat = IMG_Load("pictures/huge_ship_vertical.png");
		
		if(yE == yB + 4)
		{
		  if(map[yB+1][xB] == '*' && map[yB+2][xB] == '*' && map[yB+3][xB] == '*')
		  {
		    map[yB][xB] = '5';
		    map[yB+1][xB] = '5';
		    map[yB+2][xB] = '5';
		    map[yB+3][xB] = '5';
		    map[yB+4][xB] = '5';
		    placed = true;
		    hugeBoatPos.x = xB*50 + 358;
		    hugeBoatPos.y = yB*50 + 148;
		  }	  	    
		}
		if(yE == yB - 4)
		{
		  if(map[yB-1][xB] == '*' && map[yB-2][xB] == '*' && map[yB-3][xB] == '*')
		  {
		    map[yB][xB] = '5';
		    map[yB-1][xB] = '5';
		    map[yB-2][xB] = '5';
		    map[yB-3][xB] = '5';
		    map[yB-4][xB] = '5';
		    placed = true;
		    hugeBoatPos.x = xE*50 + 358;
		    hugeBoatPos.y = yE*50 + 148;	
		  }		      
		}	  
	      }
	    }
	}
      }while(!placed);
      
      for(int x = 0; x < 10; x++)
      {
	cout << endl;
	for(int y = 0; y < 10; y++)
	  cout << map[x][y] << " ";
      }
    }  
  
}  


/********************
 *     GET MAP      *
 ********************/

char Map::getMap(int x, int y)
{
  return map[x][y];
}

/********************
 *     SET MAP      *
 ********************/

void Map::setMap(int x, int y, char set)
{
  map[x][y] = set;
}