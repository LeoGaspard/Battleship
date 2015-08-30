  /**
 * ========================
 * 
 * Filename: map_gen.h
 * 
 * Author: NehZio <leo.gaspard@outlook.fr>
 * 
 * Description: The map generator
 * 
 * Created: 01/07/15
 * =========================
 **/ 

#ifndef MAP_GEN_H_INCLUDED
#define MAP_GEN_H_INCLUDED

class Map
{
public :
  
  Map();
  ~Map();
  
  void random();
  void diy(int player);
  char getMap(int x, int y);
  void setMap(int x, int y, char set);
  
private :
  
  char map[10][10];
  
};

#endif