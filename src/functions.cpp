   /**
 * ========================
 * 
 * Filename: functions.cpp
 * 
 * Author: NehZio <leo.gaspard@outlook.fr>
 * 
 * Description: Different functions
 * 
 * Created: 29/06/15
 * =========================
 **/

   
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "functions.h"

bool playAgain()
{
  bool again;
  
  SDL_Surface *screen, *background, *question, *answer1, *answer2;
  SDL_Rect backgroundPos, questionPos, answer1Pos, answer2Pos;
  SDL_Event event;
  SDL_Color black = {0, 0, 0};
  
  TTF_Font *police = 0;
  police = TTF_OpenFont("Marcsc.ttf", 40);  
  
  screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  
  background = IMG_Load("pictures/background_3.png");
  
  backgroundPos.x = 0;
  backgroundPos.y = 0;
  
  question = TTF_RenderText_Blended(police, "Do you want to replay ?", black);
  
  answer1 = TTF_RenderText_Blended(police, "Yes", black);
  answer2 = TTF_RenderText_Blended(police, "No", black);
  
  questionPos.x = 500;
  questionPos.y = 90;
  SDL_BlitSurface(question, 0, screen, &questionPos);
	
  answer1Pos.x = 130;
  answer1Pos.y = 450;
  SDL_BlitSurface(answer1, 0, screen, &answer1Pos);
	
  answer2Pos.x = 1060;
  answer2Pos.y = 450;
  SDL_BlitSurface(answer2, 0, screen, &answer2Pos);
  
  SDL_BlitSurface(background, 0, screen, &backgroundPos);
  SDL_BlitSurface(question, 0, screen, &questionPos);
  SDL_BlitSurface(answer1, 0, screen, &answer1Pos);
  SDL_BlitSurface(answer2, 0, screen, &answer2Pos);
  
  SDL_Flip(screen);

  do
  {
    SDL_WaitEvent(&event);    
  }while(event.type != SDL_MOUSEBUTTONUP && event.type != SDL_QUIT);
  
  if(event.type == SDL_QUIT)
    exit(0);
  
  if(event.type == SDL_MOUSEBUTTONUP)
  {
    if(event.button.button == SDL_BUTTON_LEFT)
    {
      if(event.button.x <= 250 && event.button.x >= 100 && event.button.y <= 500 && event.button.y >= 450)
	again = true;
      else if(event.button.x <= 1180  && event.button.x >= 1030 && event.button.y <= 500 && event.button.y >= 450)
	again = false;	       
    }   
  } 
  
  if(again)
    return true;
  else
    return false;
    
}