#include <stdio.h>
#include "config.h"

int distributeCards(Card** card_player1, Card** card_player2, const char* config_file_path)
{
  char color_card;
  int number_card;

  FILE* file = fopen(config_file_path, "r");

  char buffer[100];
  fgets(buffer, sizeof(buffer), file);
  fgets(buffer, sizeof(buffer), file);

  for(int i = 0; i < 20; i++)
  {
    fscanf(file, "%d_%c\n", &number_card, &color_card);

    if (i % 2 == 0)
    {
      if(insertSorted(card_player1, number_card, color_card) == NO_MEMORY)
      {
        return NO_MEMORY;
      }
    }
    else
    {
      if(insertSorted(card_player2, number_card, color_card) == NO_MEMORY)
      {
        return NO_MEMORY;
      }
    }
  }
  fclose(file);
  return PROGRAM_SUCCESS;
}


int configFunction(const char* config_file_path)
{
  FILE* file = fopen(config_file_path, "r");
  if (file == NULL)
  {
    printf("Error: Cannot open file: %s\n", config_file_path);
    return NULL_FILE;
  }

  char magic_number[4];
  if (fgets(magic_number, sizeof(magic_number), file) != NULL && strcmp(magic_number, MAGIC_NUMBER) != 0)
  {
    printf("Error: Invalid file: %s\n", config_file_path);
    fclose(file);
    return INVALID_FILE;
  }
  fclose(file);
  return PROGRAM_SUCCESS;
}

void printResultFile(const char* config_file_path, int total_Points_Player1, int total_Points_Player2)
{
  FILE* file = fopen(config_file_path, "a");
    if (file == NULL) 
    {
      printf("Warning: Results not written to file!\n");
      return;
    }

    fprintf(file, "\n");


    if (total_Points_Player1 > total_Points_Player2) 
    {
      fprintf(file, "Player 1: %d points\n", total_Points_Player1);
      fprintf(file, "Player 2: %d points\n", total_Points_Player2);

    }
    else if (total_Points_Player2 > total_Points_Player1) 
    {
      fprintf(file, "Player 2: %d points\n", total_Points_Player2);
      fprintf(file, "Player 1: %d points\n", total_Points_Player1);
    }
    else 
    {
      fprintf(file, "Congratulations! Player 1 wins the game!\n");
      fprintf(file, "Congratulations! Player 2 wins the game!\n");
    }

    fprintf(file, "\n");

    if (total_Points_Player1 > total_Points_Player2) 
    {
      fprintf(file, "Congratulations! Player 1 wins the game!\n");
    }
    else if (total_Points_Player2 > total_Points_Player1) 
    {
      fprintf(file, "Congratulations! Player 2 wins the game!\n");
    }
    else 
    {
      fprintf(file, "Congratulations! Player 1 wins the game!\n");
      fprintf(file, "Congratulations! Player 2 wins the game!\n");
    }

    fclose(file);
}

