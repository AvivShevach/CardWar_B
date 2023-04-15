namespace ariel{};
#ifndef PLATER_INCLUDED
#define PLATER_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "card.hpp"
using namespace std;
class Player {
  public:
  string name;
  int n_win;
  unsigned int n_left;
  vector<Card *> p_cards;
//  vector<Card *> pwon_cards;

  
//   Card hand[52];
//   int stack;

  Player();
  Player(string n);
  int stacksize();
  int cardesTaken();
  void get_cards( vector<Card *> c, int start, int end);
};
 #endif