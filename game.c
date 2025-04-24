#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "game.h"


void printHelloMessage(void)
{
  printf("Welcome to SyntaxSakura (2 players are playing)!\n\n");
}


void printChoosingPhase(void)
{
  printf("-------------------\n");
  printf("CARD CHOOSING PHASE\n");
  printf("-------------------\n");
}


void printPlayerStatus(int player_number, Card* hand_cards, Card* chosen_cards, Card* rows[3])
{
  printf("\nPlayer %d:\n", player_number);

  if(hand_cards != NULL)
  {

  printf("  hand cards: ");
  printCards(hand_cards);
  printf("\n");
  }
  else
  {
    printf("  hand cards:\n");
  }


  if (chosen_cards != NULL)
  {

    printf("  chosen cards: ");
    printCards(chosen_cards);
    printf("\n");
  }
  else
  {
    printf("  chosen cards:\n");
  }

  for (int i = 0; i < 3; i++)
  {
    if (rows[i] != NULL)
    {
      printf("  row_%d: ", i + 1);
      printCards(rows[i]);
      printf("\n");
    }
  }

  printf("\n");
}



int cardChoosingPhase(Card** player_hand, Card** chosen_cards, int player_number, Card* rows[3])
{
  printPlayerStatus(player_number, *player_hand, *chosen_cards, rows);

  char* user_input = malloc(sizeof(char));
  if (user_input == NULL)
  {
    printf("Error: Out of memory\n");
    return NO_MEMORY;
  }

  bool isCard = false;

  for (int i = 0; i < 2; i++)
  {
    int chosen_card_number;
    char chosen_card_color;

    if(isCard == false)
    {
      printf("Please choose a ");
      if (i == 0)
      {
        printf("first");
      }
      else
      {
        printf("second");
      }
      printf(" card to keep:\nP%d > ", player_number);
    }

    char c;
    int counter = 0;


    while ((c = getchar()) != '\n' && c != EOF)
    {
      char* tpr = realloc(user_input, (counter + 2) * sizeof(char));
      if (tpr == NULL)
      {
        printf("Error: Out of memory\n");
        free(user_input);
        return NO_MEMORY;
      }
        user_input = tpr;
        tpr = NULL;
        user_input[counter] = c;
        counter++;
    }
    user_input[counter] = '\0';

    if (strcmp(user_input, "quit") == 0)
    {
      free(user_input);
      return QUIT;
    }

    if (sscanf(user_input, "%d", &chosen_card_number) != 1)
    {
      printf("Please enter the correct number of parameters!\nP%d > ",player_number);
      isCard = true;
      --i;
      continue;
    }

    Card* temp = *player_hand;
    int card_found = 0;

    while (temp != NULL)
    {
      if (temp->number_card_ == chosen_card_number)
      {
        card_found = 1;
        chosen_card_color = temp->color_card_;
        break;
      }
      temp = temp->next_;
    }

    if (!card_found)
    {
      printf("Please enter the number of a card in your hand cards!\nP%d > ",player_number);
      isCard = true;
      --i;
    }
    else
    {
      removeCard(player_hand, chosen_card_number, chosen_card_color);

      insertSorted(chosen_cards, chosen_card_number, chosen_card_color);

      isCard = false;
    }

    counter = 0;

  }
  free(user_input);

  return PROGRAM_SUCCESS;
}


void printActionPhase(void)
{
  printf("------------\n");
  printf("ACTION PHASE\n");
  printf("------------\n");
}


void printHelpCommand(void)
{
  printf("\nAvailable commands:\n\n");
  printf("- help\n  Display this help message.\n\n");
  printf("- place <row number> <card number>\n");
  printf("  Append a card to the chosen row or if the chosen row does not exist create it.\n\n");
  printf("- discard <card number>\n  Discard a card from the chosen cards.\n\n");
  printf("- quit\n  Terminate the program.\n\n");
}


int* placeCard(int row_number, int card_number, Card** chosen_cards, Card* rows[3], int* row_valid)
{
    /* 1) Row number must be 1–3 */
    if (row_number < 1 || row_number > 3) {
        printf("Please enter a valid row number!\n");
        *row_valid = 1;
        return row_valid;
    }

    /* 2) Find the card in chosen_cards (and remember its color) */
    Card *curr = *chosen_cards, *prev = NULL;
    int found = 0;
    char color = '\0';
    while (curr) {
        if (curr->number_card_ == card_number) {
            found = 1;
            color = curr->color_card_;
            break;
        }
        prev = curr;
        curr = curr->next_;
    }
    if (!found) {
        printf("Please enter the number of a card in your chosen cards!\n");
        *row_valid = 1;
        return row_valid;
    }

    /* 3) Attempt to extend or create the row */
    Card **row_head = &rows[row_number - 1];
    if (*row_head == NULL) {
        /* create new row with this card */
        Card *n = malloc(sizeof(Card));
        if (!n) { perror("malloc"); exit(NO_MEMORY); }
        n->number_card_ = card_number;
        n->color_card_  = color;
        n->next_        = NULL;
        *row_head       = n;
    } 
    else {
        /* determine first and last value */
        Card *first = *row_head;
        Card *last  = first;
        while (last->next_) last = last->next_;

        if (card_number < first->number_card_) {
            /* prepend */
            Card *n = malloc(sizeof(Card));
            if (!n) { perror("malloc"); exit(NO_MEMORY); }
            n->number_card_ = card_number;
            n->color_card_  = color;
            n->next_        = first;
            *row_head       = n;
        }
        else if (card_number > last->number_card_) {
            /* append */
            Card *n = malloc(sizeof(Card));
            if (!n) { perror("malloc"); exit(NO_MEMORY); }
            n->number_card_ = card_number;
            n->color_card_  = color;
            n->next_        = NULL;
            last->next_     = n;
        }
        else {
            /* cannot insert in middle */
            printf("This card cannot extend the chosen row!\n");
            *row_valid = 1;
            return row_valid;
        }
    }

    /* 4) Remove from chosen_cards list */
    if (prev == NULL) {
        /* at head */
        *chosen_cards = curr->next_;
    } else {
        prev->next_ = curr->next_;
    }
    free(curr);

    *row_valid = 0;
    return (int*)PROGRAM_SUCCESS;
}




int cardActionPhase(Card** player_hand, Card** chosen_cards, Card* rows[3], int player_number)
{
  int discard_card_valid = 0;
  int row_valid = 0;

  printPlayerStatus(player_number, *player_hand, *chosen_cards, rows);


  while (*chosen_cards != NULL)
  {
    if(row_valid == 0 && discard_card_valid == 0)
    {
      printf("What do you want to do?\n");
    }

    printf("P%d > ", player_number);

    char* user_input = malloc(sizeof(char));
    if (user_input == NULL)
    {
      printf("Error: Out of memory\n");
      return NO_MEMORY;
    }

    int c;
    int counter = 0;


    while ((c = getchar()) != '\n' && c != EOF)
    {
      char* tpr = realloc(user_input, (counter + 2) * sizeof(char));
      if (tpr == NULL)
      {
        printf("Error: Out of memory\n");
        free(user_input);
        return NO_MEMORY;
      }
      user_input = tpr;
      tpr = NULL;
      user_input[counter] = c;
      counter++;
    }
    user_input[counter] = '\0';


    char* command = strtok(user_input, " \n");
    char* parameter1 = strtok(NULL, " \n");
    char* parameter2 = strtok(NULL, " \n");



    if (command != NULL)
    {
      if (strcmp(command, "help") == 0 && parameter1 == NULL && parameter2 == NULL)
      {
        printHelpCommand();
        printPlayerStatus(player_number, *player_hand, *chosen_cards, rows);
      }


      else if (strcmp(command, "place") == 0 && parameter1 != NULL && parameter2 != NULL)
      {
        int rowNumber, cardNumber;
        if (sscanf(parameter1, "%d", &rowNumber) == 1 && sscanf(parameter2, "%d", &cardNumber) == 1)
        {
          placeCard(rowNumber, cardNumber, chosen_cards, rows, &row_valid);

          if(row_valid == 0)
          {
            printPlayerStatus(player_number, *player_hand, *chosen_cards, rows);
          }
        }
      }
	  else if(strcmp(command, "quit") == 0 && parameter1 == NULL && parameter2 == NULL )
      {
        free(user_input);
        return QUIT;
      }


      else if (strcmp(command, "discard") == 0 && parameter1 != NULL && parameter2 == NULL)
      {
        int cardNumber;
        if (sscanf(parameter1, "%d", &cardNumber) == 1)
        {
          int* discardResult = removeCard2(chosen_cards, cardNumber, &discard_card_valid, *chosen_cards);

          if(discardResult == 0)
          {
            printPlayerStatus(player_number, *player_hand, *chosen_cards, rows);
          }
        }
      }
	  else
      {
        printf("Please enter the correct number of parameters!\n");
        row_valid = 1;
      }
    }
    free(user_input);
  }
  return PROGRAM_SUCCESS;
}



void swapHandCards(Card** player_1Hand, Card** player_2Hand)
{
  Card* temp = *player_1Hand;
  *player_1Hand = *player_2Hand;
  *player_2Hand = temp;
}



void deallocateMemory1(Card** card_player1, Card** card_player2)
{
  deallocate(card_player1);
  deallocate(card_player2);
}


void deallocateMemory2(Card** chosen_cards_player1, Card** chosen_cards_player2)
{
  deallocate(chosen_cards_player1);
  deallocate(chosen_cards_player2);
}



void compareAndDoublePoints(int row_Length1, int rowLength_2, int row_Length3, int* points1, int* points2, int* points3)
{
  if (row_Length1 >= rowLength_2 && row_Length1 >= row_Length3)
  {
    *points1 *= 2;
  }
  else if (rowLength_2 >= row_Length1 && rowLength_2 >= row_Length3)
  {
    *points2 *= 2;
  }
  else
  {
  *points3 *= 2;
  }
}


int calculateRowPoints(Card* row, int* row_length)
{
  int points = 0;
  int blue = 0;
  int green = 0;
  int white = 0;
  int red = 0;
  *row_length = 0;

  while (row != NULL)
  {
    if (row->color_card_ == 'b')
    {
      blue++;
    }
    else if (row->color_card_ == 'g')
    {
      green++;
    }
    else if (row->color_card_ == 'w')
    {
      white++;
    }
    else if (row->color_card_ == 'r')
    {
      red++;
    }

    (*row_length)++;
    row = row->next_;
  }

  points = (blue * 3 + green * 4 + white * 7 + red * 10);

  return points;
}


int calculateTotalPoints(Card* rows[3]) 
{
  int len1, len2, len3;
  int p1 = calculateRowPoints(rows[0], &len1);
  int p2 = calculateRowPoints(rows[1], &len2);
  int p3 = calculateRowPoints(rows[2], &len3);

  compareAndDoublePoints(len1, len2, len3, &p1, &p2, &p3);

  return p1 + p2 + p3;
}


void cleanupAll(Card** hand1, Card** hand2, Card** chosen1, Card** chosen2, Card* rows1[3], Card* rows2[3]) 
{
  deallocateMemory1(hand1, hand2);
  deallocateMemory2(chosen1, chosen2);

  for (int i = 0; i < 3; i++) 
  {
    deallocateRow(&rows1[i]);
    deallocateRow(&rows2[i]);
  }
}


void printGameResults(const char* config_file_path, int total1, int total2) 
{
  if (total1 > total2)
  {
    printf("\nPlayer 1: %d points\n", total1);
    printf("Player 2: %d points\n", total2);
  }
  else 
  {
    printf("\nPlayer 2: %d points\n", total2);
    printf("Player 1: %d points\n", total1);
  }

  if (total1 > total2) 
  {
    printf("\nCongratulations! Player 1 wins the game!\n");
  } 
  else if (total2 > total1) 
  {
    printf("\nCongratulations! Player 2 wins the game!\n");
  } 
  else 
  {
    printf("\nCongratulations! Player 1 wins the game!\n");
    printf("Congratulations! Player 2 wins the game!\n");
  }

  printResultFile(config_file_path, total1, total2);
}

