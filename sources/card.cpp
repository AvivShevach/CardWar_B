#include "card.hpp"

Card::Card( int v, string s)
{
     value = v;
     suit = s;
}

Card::~Card()
{
    std::cout << "Card: " << suit << " number: " << value << " deleted\n";
}