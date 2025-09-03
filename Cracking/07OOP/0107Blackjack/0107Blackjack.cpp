#include <iostream>
#include "Deck.hpp"

// g++ -std=c++17 0107Blackjack.cpp Deck.cpp DeckHelper.cpp -o hola

//www.plantuml.com/plantuml/png/PL7DZjCm4BxdAKRbi5re8rY9IuHMcoOL59QsD3rnGLvdcbfrxCW_e6Mrxux73giMUd3d6ty_uycTTSmutyli2ch1EiDwQDoZ5AhBx4ceWL67IsPjwPmH3zxXYclLYDy8R_-bB1W_TKPxrLPQQWFteZkwXVHuHcJ6w5_f-jLD_6L7qI9WFxX7wB5_G6EpCCvI-HuDSq8hcs40i6KIuIa3sAwgiWd_rMPNVj-ibrJlTyl5vZwMzQhyMgxteNxEadBjoJPgosO6zIOSGH3EFCz3y_CClitW2_6leAAdG8q7eKHAvx5JCTD6Ypdy66YK8awK6Yeb56DKQBw1Z-WIcbx_Tq7AsAQ2SlcOoaz_Crgg2_Y9t6dpWT9letfhX794d5v7t1pzuI1nH3KoITneJiMb-IUKmxY99-kO4_oPB9d4lMvSSEwc14Xi8xmafaUyK1Cy8yS5xb2cptOKWytYaoRl9l1wFeV9-vj9McG1N2l7X1ePUNvxFc01tgBDY4fNQKqlQDpb7QhMz_8F
/*
                     ┌──────────────────────┐                            
                     │Deck                  │                            
                     ├──────────────────────┤                            
                     │- _deck : vector<Card>│                            
                     │+ PrintDeck()         │                            
                     │+ Shuffle()           │                            
                     │+ DealCard() : Card   │                            
                     └──────────────────────┘                            
                  *                        .                               
                 .                         .                               
  ┌──────────────────────┐                 v                              
  │Card                  │             ┌──────────────────────────────────────────┐
  ├──────────────────────┤             │DeckHelper                                │
  │- _pale : Pale        │             ├──────────────────────────────────────────┤
  │- _number : Number    │             │{static} + PaleToString(Pale) : string    │
  │+ GetNumber() : Number│             │{static} + NumberToString(Number) : string│
  │+ GetPale() : Pale    │             └──────────────────────────────────────────┘
  └──────────────────────┘                                               
      .              .
      v              .                                                     
┌─────────┐          v                                                    
│Pale     │  ┌──────────────────┐                                        
├─────────┤  │Number            │                                        
│PICAS    │  ├──────────────────┤                                        
│CORAZONES│  │AS, DOS, TRES, ...│                                        
│TREBOLES │  │J, Q, K           │                                        
│DIAMANTES│  └──────────────────┘                                        
└─────────┘                                      
*/

int main()
{
    Deck deck;
    deck.PrintDeck();

    return 0;
}