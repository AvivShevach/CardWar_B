//using namespace ariel;
#ifndef CARD_INCLUDED
#define CARD_INCLUDED
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
const vector<string> CardName = {
    "", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" 
};

class Card {
 public:
  unsigned int value;
  string suit;
  Card( unsigned int, string);
};

#endif
