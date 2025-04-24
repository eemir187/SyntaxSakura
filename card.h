#ifndef CARD_H
#define CARD_H

#include <stdlib.h>

typedef struct _Card_ {
    int number_card_;
    char color_card_;
    struct _Card_* next_;
} Card;



//---------------------------------------------------------------------------------------------------------------------
///
/// This function inserts card at the beginning
///
/// @param card_player Player cards
/// @param number Number of the card
/// @param color Color of the card
///
///
///
//
int insertBeginning(Card** card_player, int number, char color);


//---------------------------------------------------------------------------------------------------------------------
///
/// This function inserts card after another card
///
/// @param card Card
/// @param number Number of the card
/// @param color Color of the card
///
//
int insertAfter(Card* card, int number, char color);


//---------------------------------------------------------------------------------------------------------------------
///
/// This function sorts the cards
///
/// @param card_player Player cards
/// @param number Number of the card
/// @param color Color of the card
///
///
///
//
int insertSorted(Card** card_player, int number, char color);


//---------------------------------------------------------------------------------------------------------------------
///
/// This function prints the cards
///
/// @param card_player Cards of the player
///
//
void printCards(Card *card_player);

//---------------------------------------------------------------------------------------------------------------------
///
/// This function removes the card from the list based on the number and color
/// of the card
///
/// @param card Card
/// @param number Number of card
/// @param color Color of card
///
///
//
void removeCard(Card **card, int number, char color);


//---------------------------------------------------------------------------------------------------------------------
///
/// This function removes the card from the list based on the number
/// of the card
///
/// @param card Card
/// @param number Number of card
/// @param color Color of card
/// @param color Color of card
/// @param discard_card_valid Checks if the card is valid
/// @param chosen_cards Chosen cards
//
int *removeCard2(Card **card, int number, int *discard_card_valid, Card *chosen_cards);


//---------------------------------------------------------------------------------------------------------------------
///
/// This function deallocates the memory
///
/// @param card_player Cards of the player
///
///
//                 
void deallocate(Card **card_player);

//---------------------------------------------------------------------------------------------------------------------
///
/// This function deallocates the cards in the row
///
/// @param row Row of the stored cards
///
///
//
void deallocateRow(Card **row);

#endif /* CARD_H */
