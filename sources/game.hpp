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
  // int p1wons = 0;
// int p2wons = 0;
  int draw = 0;
  int last_win;
    Game(Player &player1, Player &player2);
  //   Card deck[52];
  //   Card playedCards[52];
  //  int turnCount;
  //  Player winner;
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
    void print_draw_turn(const char *cardName, string s1, string s2); 
  };
  
  #endif