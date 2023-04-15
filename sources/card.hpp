//using namespace ariel;
#ifndef CARD_INCLUDED
#define CARD_INCLUDED
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
const string CardName[] = {
    "", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" 
};

class Card {
 public:
  int value;
  string suit;
public:
  Card( int, string);
  ~Card();
};

#endif
