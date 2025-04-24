#ifndef GAME_H
#define GAME_H

#include "card.h"
#include "config.h"

#define MAGIC_NUMBER "ESP"
#define numberPlayer 2


enum return_values {QUIT = -1, PROGRAM_SUCCESS = 0, FILE_ERROR = 1, NULL_FILE = 2, INVALID_FILE = 3, NO_MEMORY = 4};

//---------------------------------------------------------------------------------------------------------------------
///
/// This function prints hello message
///
//
void printHelloMessage(void);

//---------------------------------------------------------------------------------------------------------------------
///
/// This function prints choosing phase message
///
//
void printChoosingPhase(void);


//---------------------------------------------------------------------------------------------------------------------
///
/// This function prints the final game results to the console and writes them to the config file.
///
/// @param config_file_path Path to the config file where the results should be written
/// @param total1 Total points of player 1
/// @param total2 Total points of player 2
///
///
//
void printGameResults(const char* config_file_path, int total1, int total2);


//---------------------------------------------------------------------------------------------------------------------
///
/// This function prints the player status and the cards he has
///
/// @param player_number Number of the player
/// @param hand_cards Cards in the hand cards deck
/// @param chosen_cards Cards in the chosen cards deck
/// @param rows Rows of the cards
///
///
//
void printPlayerStatus(int player_number, Card* hand_cards, Card* chosen_cards, Card* rows[3]);


//---------------------------------------------------------------------------------------------------------------------
///
/// This function prints action phase message
///
//
void printActionPhase(void);


//---------------------------------------------------------------------------------------------------------------------
///
/// This function prints the help command message
///
//
void printHelpCommand(void);

//---------------------------------------------------------------------------------------------------------------------
///
/// This function simulates the card choosing phase
///
/// @param player_hand Cards in the player hand cards deck
/// @param chosen_cards Player´s choosen cards
/// @param player_number Number of player
/// @param rows Rows of the cards
///
///
//
int cardChoosingPhase(Card** player_hand, Card** chosen_cards, int player_number, Card* rows[3]);


//---------------------------------------------------------------------------------------------------------------------
///
/// This function simulates the card action phase
///
/// @param player_hand Cards in the player hand cards deck
/// @param chosen_cards Player´s choosen cards
/// @param rows Rows of the cards
/// @param player_number Number of player
///
///
//
int cardActionPhase(Card** player_hand, Card** chosen_cards, Card* rows[3], int player_number);




//---------------------------------------------------------------------------------------------------------------------
///
/// This function places the card in the rows
///
/// @param row_number Number of the row
/// @param card_number Number of the card
/// @param chosen_cards Player´s chosen cards
/// @param rows Rows of the cards
/// @param row_valid Checks if the row is valid or not
///
///
//
int* placeCard(int row_number, int card_number, Card** chosen_cards, Card* rows[3], int* row_valid);



//---------------------------------------------------------------------------------------------------------------------
///
/// This function calculates the points based on the color in the rows
///
/// @param row Row of the cards
/// @param row_Length Length of the row
///
/// @return points Returns the points
///
//
int calculateRowPoints(Card* row, int* row_length);


//---------------------------------------------------------------------------------------------------------------------
///
/// This function calculates the total points for a player by evaluating all three of their rows.
///
/// @param rows Array of 3 rows containing the player's placed cards
///
/// @return Total calculated points for the player
///
///
//
int calculateTotalPoints(Card* rows[3]);

//---------------------------------------------------------------------------------------------------------------------
///
/// This function swaps the player's cards
///
/// @param player_1Hand Cards in the player1 hand cards deck
/// @param player_2Hand Cards in the player2 hand cards deck
///
///
//
void swapHandCards(Card **player_1Hand, Card **player_2Hand);



//---------------------------------------------------------------------------------------------------------------------
///
/// This function compares the points and doubles the row that has the most cards
///
/// @param row_Length1 Length of row 1
/// @param rowLength_2 Length of row 2
/// @param row_Length3 Length of row 3
/// @param points1 Points of the first row
/// @param points2 Points of the second row
/// @param points3 Points of the third row
///
///
//
void compareAndDoublePoints(int row_Length1, int rowLength_2, int row_Length3, int* points1, int* points2, int* points3);


//---------------------------------------------------------------------------------------------------------------------
///
/// This function deallocates the player's cards
///
/// @param card_player1 Player's 1 cards
/// @param card_player2 Player's 2 cards
///
///
//
void deallocateMemory1(Card **card_player1, Card **card_player2);


//---------------------------------------------------------------------------------------------------------------------
///
/// This function deallocates the player's chosen cards
///
/// @param chosen_cards_player1 Player's 1 chosen cards
/// @param chosen_cards_player2 Player's 2 chosen cards
///
///
//
void deallocateMemory2(Card **chosen_cards_player1, Card **chosen_cards_player2);



//---------------------------------------------------------------------------------------------------------------------
///
/// This function deallocates all dynamically allocated memory for both players and their rows.
///
/// @param hand1 Hand cards of player 1
/// @param hand2 Hand cards of player 2
/// @param chosen1 Chosen cards of player 1
/// @param chosen2 Chosen cards of player 2
/// @param rows1 Array of 3 rows for player 1
/// @param rows2 Array of 3 rows for player 2
///
///
//
void cleanupAll(Card** hand1, Card** hand2, Card** chosen1, Card** chosen2, Card* rows1[3], Card* rows2[3]);

#endif /* GAME_H */
