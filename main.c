#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main(int argc, char* argv[])
{
  if (argc < 2 || argc > 2)
  {
    printf("Usage: ./a3 <config file>\n");
    return FILE_ERROR;
  }

  const char* config_file_path = argv[1];
  Card* card_player1 = NULL;
  Card* card_player2 = NULL;
  Card* chosen_cards_player1 = NULL;
  Card* chosen_cards_player2 = NULL;
  Card* rows_player1[3] = {NULL, NULL, NULL};
  Card* rows_player2[3] = {NULL, NULL, NULL};

  int configResult = configFunction(config_file_path);
  if (configResult == NULL_FILE)
  {
    return NULL_FILE;
  }
  else if (configResult == INVALID_FILE)
  {
    return INVALID_FILE;
  }


  printHelloMessage();


  int distributeCardsResult = distributeCards(&card_player1, &card_player2, config_file_path);
  if (distributeCardsResult == NO_MEMORY)
  {
    return NO_MEMORY;
  }

  while (card_player1 != NULL || card_player2 != NULL)
  {
    printChoosingPhase();

    int choosingCards1 = cardChoosingPhase(&card_player1, &chosen_cards_player1, 1, rows_player1);
    if (choosingCards1 == QUIT)
    {
      deallocateMemory1(&card_player1, &card_player2);
      deallocateMemory2(&chosen_cards_player1, &chosen_cards_player2);
      for (int i = 0; i < 3; i++)
      {
        deallocateRow(&rows_player1[i]);
        deallocateRow(&rows_player2[i]);
      }
      return PROGRAM_SUCCESS;
    }
    else if(choosingCards1 == NO_MEMORY)
    {
      return NO_MEMORY;
    }


    int choosingCards2 = cardChoosingPhase(&card_player2, &chosen_cards_player2, 2, rows_player2);
    if (choosingCards2 == QUIT)
    {
      deallocateMemory1(&card_player1, &card_player2);
      deallocateMemory2(&chosen_cards_player1, &chosen_cards_player2);
      for (int i = 0; i < 3; i++)
      {
      deallocateRow(&rows_player1[i]);
      deallocateRow(&rows_player2[i]);
      }
      return PROGRAM_SUCCESS;
    }
    else if(choosingCards2 == NO_MEMORY)
    {
      return NO_MEMORY;
    }

    printf("\nCard choosing phase is over - passing remaining hand cards to the next player!\n\n");

    swapHandCards(&card_player1, &card_player2);

    printActionPhase();

    int actionPhase1 = cardActionPhase(&card_player1, &chosen_cards_player1, rows_player1, 1);
    if (actionPhase1 == QUIT)
    {
      deallocateMemory1(&card_player1, &card_player2);
      deallocateMemory2(&chosen_cards_player1, &chosen_cards_player2);
    for (int i = 0; i < 3; i++)
    {
      deallocateRow(&rows_player1[i]);
      deallocateRow(&rows_player2[i]);
    }
    return PROGRAM_SUCCESS;
    }

    else if (actionPhase1 == NO_MEMORY)
    {
      return NO_MEMORY;
    }

    int actionPhase2 = cardActionPhase(&card_player2, &chosen_cards_player2, rows_player2, 2);
    if (actionPhase2 == QUIT)
    {
      deallocateMemory1(&card_player1, &card_player2);
      deallocateMemory2(&chosen_cards_player1, &chosen_cards_player2);
      for (int i = 0; i < 3; i++)
      {
        deallocateRow(&rows_player1[i]);
        deallocateRow(&rows_player2[i]);
      }
      return PROGRAM_SUCCESS;
    }

    else if (actionPhase2 == NO_MEMORY)
    {
      return NO_MEMORY;
    }

    printf("\nAction phase is over - starting next game round!\n\n");
  }


  int total_points_player1 = calculateTotalPoints(rows_player1);
  int total_points_player2 = calculateTotalPoints(rows_player2);

  printGameResults(config_file_path, total_points_player1, total_points_player2);

  cleanupAll(&card_player1, &card_player2, &chosen_cards_player1, &chosen_cards_player2, rows_player1, rows_player2);


  return PROGRAM_SUCCESS;
}
