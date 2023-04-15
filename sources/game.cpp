#include "game.hpp"
Game::Game(Player &player1, Player &player2) : p1(player1), p2(player2)
{
    for (int i = 1; i < 14; i++)
    {
        cards.push_back(new Card(i,"Hearts"));
        cards.push_back(new Card(i,"Diamonds"));
        cards.push_back(new Card(i,"Spades"));
        cards.push_back(new Card(i,"Clubs"));
    }
    
  // create a random number generator
  std::random_device rd;
  std::mt19937 g(rd());

  // shuffle the elements of the vector
  std::shuffle(cards.begin(), cards.end(), g); 
  p1.get_cards(cards, 0,26);
  p2.get_cards(cards, 26,52);
}
// void Game::playTurn()
// {
//     Card *cp1 = p1.p_cards.back();
//     p1.p_cards.pop_back();
//     Card *cp2 = p2.p_cards.back();
//     p2.p_cards.pop_back();
//     vector<Card *> draws;
//     int i = 0;
//   //  std::cout << cp1->value << " ";
//     while(cp1->value == cp2->value)
//     {
//         draws.push_back(cp1);
//         draws.push_back(cp2);

//         cp1 = p1.p_cards.back();
//         p1.p_cards.pop_back();
//         cp2 = p2.p_cards.back();
//         p2.p_cards.pop_back();

//         draws.push_back(cp1);
//         draws.push_back(cp2);

//         cp1 = p1.p_cards.back();
//         p1.p_cards.pop_back();
//         cp2 = p2.p_cards.back();
//         p2.p_cards.pop_back();
//         i = i+4;
//     }
//     if(cp1->value > cp2->value)
//     {
//         if(i != 0)
//             game.p1.pwon_cards(draws.begin(), draws.begin() + i);
//         game.p1.pwon_cards.push_back(cp1);
//         game.p1.pwon_cards.push_back(cp2);
//         std::cout << cp1->value << " > " <<  cp2->value << endl;
//     //    last_win = 1;
//     }
//     else if(cp1->value <= cp2->value)
//     {
//         if(i != 0)
//              game.p2.pwon_cards(draws.begin(), draws.begin() + i);
//         game.p2.pwon_cards.push_back(cp1);
//         game.   p2.pwon_cards.push_back(cp2);
//         std::cout << cp1->value << " < " <<  cp2->value << endl;
//     //    last_win = 2;
//     }
//     // else
//     // {

//     // }
// }
 void Game::printLastTurn() 
 {
    int i = 0;
    unsigned int d = turni-1;
    while( d>=2 && p1.p_cards[d-2]->value == p2.p_cards[d-2]->value)
    {
        d = d-2;
    }
       while( p1.p_cards[d]->value == p2.p_cards[d]->value)
            {
                int v = p1.p_cards[d]->value;
                printf("%s played %s of %s %s played %d of %s. draw. ", p1.name.c_str(), CardName[v].c_str(),  p1.p_cards[d]->suit.c_str(), p2.name.c_str(), v, p2.p_cards[d]->suit.c_str());
                d += 2;
            }
        int a1 = p1.p_cards[d]->value;
        int a2 = p2.p_cards[d]->value;
        const char *v1 = CardName[a1].c_str();
        const char *v2 = CardName[a2].c_str();
        printf("%s played %s of %s %s played %s of %s. ", p1.name.c_str(), v1,  p1.p_cards[d]->suit.c_str(), p2.name.c_str(), v2, p2.p_cards[d]->suit.c_str());
        if((a1>a2 && a2 != 1) || (a1 == 2 && a2 == 1) || (a1 == 1 && a2 != 2 ))
            printf("%s wins.\n", p1.name.c_str());
        else
            printf("%s wins.\n", p2.name.c_str());
        // int v1 = p1.p_cards[d]->value;
        // int v2 = p2.p_cards[d]->value;
        // printf("%s played %d of %s %s played %d of %s. ", p1.name.c_str(), v1,  p1.p_cards[d]->suit.c_str(), p2.name.c_str(), v2, p2.p_cards[d]->suit.c_str());
        // if(v1>v2)
        //     printf("%s wins.\n", p1.name.c_str());
        // else
        //     printf("%s wins.\n", p2.name.c_str());
            
}
 

 
void Game::playTurn()
{
    int d =0;
    if(turni>25) {
        throw "Game over";
    }
    if( &p1 == &p2)
        throw "Same player not allowed";

    while(p1.p_cards[turni]->value == p2.p_cards[turni]->value)
    {
        d += 4;
        draw++;
        if(turni==24)
        {
            p1.n_win += 2;
            p2.n_win += 2;
            turni += 2;
            p1.n_left = 26 - turni;
            p2.n_left = 26 - turni;
            return;
        }

         if(turni==25)
        {
            p1.n_win++;
            p2.n_win++;
            turni++;
            p1.n_left = 26 - turni;
            p2.n_left = 26 - turni;
            return;
        }
    turni += 2;
    }
    int a1 = p1.p_cards[turni]->value;
    int a2 = p2.p_cards[turni]->value;
        if((a1>a2 && a2 != 1) || (a1 == 2 && a2 == 1) || (a1 == 1 && a2 != 2 ))
            p1.n_win += 2 +d;
        else
            p2.n_win += 2 +d;
    
    turnCount++;
    turni++;

    p1.n_left = 26 - turni;
    p2.n_left = 26 - turni;
}
void Game::playAll() 
{
    while (turni < 26)
        playTurn();
}
void Game::printWiner() 
{
    // if(turni == 25 )
    // {
        if(p1.n_win > p2.n_win)
             std::cout << p1.name <<  endl; //" " << p1.n_win << ":" << p2.n_win << endl;
        else if(p1.n_win < p2.n_win)
             std::cout << p2.name <<  endl; //" " << p1.n_win << ":" << p2.n_win << endl;
        else
             std::cout << "draw" << endl;
   // }
}
void Game::printLog() 
{
    unsigned int k =0;
    while (k < turni )
    {
        if (p1.p_cards[k]->value == p2.p_cards[k]->value)
            {
                const char *cardName = CardName[p1.p_cards[k]->value].c_str();
             //   print_draw_turn(CardName,  p1.p_cards[k]->suit.c_str(),  p2.p_cards[k]->suit.c_str() );
                printf("%s played %s of %s %s played %s of %s. draw. ", p1.name.c_str(), cardName,  p1.p_cards[k]->suit.c_str(), p2.name.c_str(), cardName, p2.p_cards[k]->suit.c_str());
                k += 2;
                if (k >= turni)
                    printf("\n");
            }
        if (k >= turni)
            return;
        int a1 = p1.p_cards[k]->value;
        int a2 = p2.p_cards[k]->value;
        const char *v1 = CardName[a1].c_str();
        const char *v2 = CardName[a2].c_str();
        printf("%s played %s of %s %s played %s of %s. ", p1.name.c_str(), v1,  p1.p_cards[k]->suit.c_str(), p2.name.c_str(), v2, p2.p_cards[k]->suit.c_str());
        if((a1>a2 && a2 != 1) || (a1 == 2 && a2 == 1) || (a1 == 1 && a2 != 2 ))
            printf("%s wins.\n", p1.name.c_str());
        else
            printf("%s wins.\n", p2.name.c_str());
        k++;
    }
}
// void Game::print_draw_turn(const char *cardName, string s1, string s2) 
// {
//     printf("%s played %s of %s %s played %s of %s. draw. ", p1.name.c_str(), cardName,  s1 , p2.name.c_str(), cardName, s2);
// }
  

void Game::printStats() 
{
     if(p1.n_win > p2.n_win)
             std::cout << p1.name << " won with a score of " << p1.n_win << ":" << p2.n_win << endl;
        else if(p1.n_win < p2.n_win)
             std::cout << p2.name << " won with a score of " << p1.n_win << ":" << p2.n_win << endl;
        else
             std::cout << "The game ended in a draw" << endl;
    std::cout << "The number of times there was a draw: " << draw << endl;
}