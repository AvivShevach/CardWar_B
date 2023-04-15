#include "player.hpp"

int Player::stacksize() {
    return (int)n_left;
}

int Player::cardesTaken() {

    return n_win;
}

Player::Player() {
    n_left = 0;
}

Player::Player(string n) {
    name = n;
    n_win = 0;
    n_left = 0;
}

void Player::get_cards( vector<Card *> c, int start, int end)
{
    std::vector<Card *> help_cards(c.begin()+start, c.begin()+end);
    p_cards = help_cards;
    for (auto& element : p_cards)
    {
        // std::cout << std::setw(2) << element->value << " ";
        printf("%2d ", element->value);
    }
    std::cout << std::endl;
    n_left = (unsigned int)52-p_cards.size();
}
