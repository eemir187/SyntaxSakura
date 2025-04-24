#include <stdio.h>
#include <stdlib.h>

#include "card.h"
#include "game.h"

int insertBeginning(Card** card_player, int number, char color)
{
  Card* new_card = malloc(sizeof(Card));
  if (new_card == NULL)
  {
    printf("Error: Out of memory\n");
    return NO_MEMORY;
  }
  new_card->number_card_ = number;
  new_card->color_card_ = color;

  new_card->next_ = *card_player;
  *card_player = new_card;

  return PROGRAM_SUCCESS;
}


int insertAfter(Card* card, int number, char color)
{
  Card* new_card = malloc(sizeof(Card));
  if (new_card == NULL)
  {
    printf("Error: Out of memory\n");
    return NO_MEMORY;
  }
  new_card->number_card_ = number;
  new_card->color_card_ = color;

  new_card->next_ = card->next_;
  card->next_ = new_card;

  return PROGRAM_SUCCESS;
}


int insertSorted(Card** card_player, int number, char color)
{
  if (*card_player == NULL || (*card_player)->number_card_ >= number)
  {
    if (insertBeginning(card_player, number, color) == NO_MEMORY)
    {
      return NO_MEMORY;
    }
    return PROGRAM_SUCCESS;
  }

  Card* curr = *card_player;
  while (curr->next_ != NULL)
  {
    if (curr->next_->number_card_ >= number)
    {
      break;
    }
    curr = curr->next_;
  }
  if (insertAfter(curr, number, color) == NO_MEMORY)
  {
    return NO_MEMORY;
  }
  return PROGRAM_SUCCESS;
}


void printCards(Card* card_player)
{
  for (Card* curr = card_player; curr != NULL; curr = curr->next_)
  {
    printf("%d_%c", curr->number_card_, curr->color_card_);
	if (curr->next_ != NULL)
    {
      printf(" ");
    }
  }
}


void deallocate(Card** card_player)
{
  Card* curr = *card_player;
  while (curr != NULL)
  {
    Card* aux = curr;
    curr = curr->next_;
    free(aux);
  }
  *card_player = NULL;
}



void removeCard(Card** card, int number, char color)
{
  if (*card == NULL)
  {
    return;
  }

  if ((*card)->number_card_ == number && (*card)->color_card_ == color)
  {
    Card* to_remove = *card;
    *card = (*card)->next_;
    free(to_remove);
    return;
  }

  Card* curr = *card;
  while (curr->next_ != NULL)
  {
    if (curr->next_->number_card_ == number && curr->next_->color_card_ == color)
    {
      Card* to_remove = curr->next_;
      curr->next_ = curr->next_->next_;
      free(to_remove);
      return;
    }
    curr = curr->next_;
  }
}




int* removeCard2(Card** card, int number, int* discard_card_valid, Card* chosen_cards)
{
  Card* temp = chosen_cards;
  int card_found = 0;

  while (temp != NULL)
  {
    if (temp->number_card_ == number)
    {
      card_found = 1;
      break;
    }
    temp = temp->next_;
  }

    if (card_found)
    {
      if (*card == NULL)
      {
        return (int*)PROGRAM_SUCCESS;
      }

      if ((*card)->number_card_ == number)
      {
        Card* to_remove = *card;
        *card = (*card)->next_;
        free(to_remove);
        return (int*)PROGRAM_SUCCESS;
      }

      Card* curr = *card;
      while (curr->next_ != NULL)
      {
        if (curr->next_->number_card_ == number)
        {
          Card* to_remove = curr->next_;
          curr->next_ = curr->next_->next_;
          free(to_remove);
          return (int*)PROGRAM_SUCCESS;
        }
        curr = curr->next_;
      }
      *discard_card_valid = 0;
      return discard_card_valid;
  }

  else
  {
    printf("Please enter the number of a card in your chosen cards!\n");
    *discard_card_valid = 1;
    return discard_card_valid;
  }

  return (int*)PROGRAM_SUCCESS;
}


void deallocateRow(Card** row)
{
  Card* curr = *row;
  while (curr != NULL)
  {
    Card* aux = curr;
    curr = curr->next_;
    free(aux);
  }
  *row = NULL;
}

