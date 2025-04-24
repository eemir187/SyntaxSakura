#ifndef CONFIG_H
#define CONFIG_H

#include <string.h>

#include "card.h"
#include "game.h"


//---------------------------------------------------------------------------------------------------------------------
///
/// This function checks if the file is opened correctly or if it is empty
///
/// @param config_file_path Path to the file
///
//
int configFunction(const char *config_file_path);



//---------------------------------------------------------------------------------------------------------------------
///
/// This function distributes the cards to the players
///
/// @param card_player1 Player 1 cards
/// @param card_player2 Player 2 cards
/// @param number Number of the card
/// @param color Color of the card
///
//
int distributeCards(Card** card_player1, Card** card_player2, const char* config_file_path);


//---------------------------------------------------------------------------------------------------------------------
///
/// This function prints the result in the config file
///
/// @param config_file_path Config file
/// @param total_Points_Player1 total points of the first player
/// @param total_Points_Player2 total points of the second player
///
///
///
//
void printResultFile(const char *config_file_path, int total_Points_Player1, int total_Points_Player2);

#endif /* CONFIG_H */
