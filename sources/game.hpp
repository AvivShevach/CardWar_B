//using namespace ariel;
#ifndef GAME_INCLUDED
#define GAME_INCLUDED
//using namespace std;
#include <algorithm>
#include <random>
#include <vector>
#include "card.hpp"
#include "player.hpp"

class Game {
  public:
  Player &p1, &p2;
  vector<Card *> cards;
  unsigned int turni = 0;
  unsigned int turnCount = 0;
  int draw = 0;
  int last_win;
    Game(Player &player1, Player &player2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
  };
  
  #endif