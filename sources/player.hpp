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
  Player();
  Player(string n);
  int stacksize();
  int cardesTaken();
  void get_cards( vector<Card *> card, int start, int end);
};
 #endif