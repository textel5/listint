/*
    listint is my implementation of linked list of int
    Copyright (C) 2021  Sergey Tokarev
    
    This file is part of listint.

    listint is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    listint is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with listint.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define LISTINT_ITEM_MSIZE sizeof(struct listint)

struct listint {
  struct listint *next;
  int data;
};

void
listintAllocP(struct listint **item)
{
  if (item != NULL) {
    *item = malloc(LISTINT_ITEM_MSIZE);
  }
}

void
listintFreeP(struct listint **item)
{
  if (item != NULL && *item != NULL) {
    free(*item);
  }
}

void
listintResetP(struct listint **item)
{
  if (item != NULL && *item != NULL) {
    (*item)->next = NULL;
    (*item)->data = 0;
  }
}

void
listintCreateP(struct listint **item)
{
  listintAllocP(item);
  listintResetP(item);
}

void
listintDeleteP(struct listint **item)
{
  listintResetP(item);
  listintFreeP(item);
}

void
listintLinkP(struct listint *itemP, struct listint *itemT)
{
  if (itemP != NULL) {
    itemP->next = itemT;
  }
}

void
listintInsertP(struct listint *itemP, struct listint *itemT)
{
  struct listint *itemN;
  
  if (itemP != NULL && itemT != NULL) {
    itemN = itemP->next;
    listintLinkP(itemP, itemT);
    listintLinkP(itemT, itemN);
  }
}

void
listintExtructP(struct listint *itemP)
{
  struct listint *itemT, *itemN;
  
  if (itemP != NULL && itemP->next != NULL) {
    itemT = itemP->next;
    itemN = itemT->next;
    listintLinkP(itemP, itemN);
    listintLinkP(itemT, NULL);
  }
}

void
listintSliderPP(struct listint *itemB, unsigned long int order,
  struct listint **itemS)
{
  struct listint *itemP;
  unsigned long int i;
  
  *itemS = NULL;
  
  if (order == 0 || itemB == NULL) {
    return;
  }
  
  itemP = itemB;
  for (i = 0; i < order - 1 && itemP != NULL; i++) {
    itemP = itemP->next;
  }
  if (i == order - 1) {
    *itemS = itemP;
  } else {
  }
}

void
listintAddP(struct listint **itemB, unsigned long int order,
  struct listint **itemAdded)
{
  struct listint *itemNew, *itemP;
  
  if (itemB == NULL || itemAdded == NULL) {
    return;
  }
  
  /**itemAdded = NULL;*/
  listintCreateP(&itemNew);
  if (itemNew == NULL) {
    *itemAdded = NULL;
    return;
  }
  
  if (order == 0) {
    listintLinkP(itemNew, *itemB);
    *itemB = itemNew;
    *itemAdded = itemNew;
    return;
  }
  
  listintSliderPP(*itemB, order, &itemP);
  if (itemP == NULL) {
    listintDeleteP(&itemNew);
    *itemAdded = NULL;
  } else {
    listintInsertP(itemP, itemNew);
    *itemAdded = itemNew;
  }
}

void
listintRemoveP(struct listint **itemB, unsigned long int order,
  struct listint **itemPN)
{
  struct listint *itemT;
  
  if (itemB == NULL || itemPN == NULL) {
    return;
  }
  
  *itemPN = NULL;
  if (order == 0) {
    if (*itemB != NULL) {
      itemT = (*itemB)->next;
      listintDeleteP(itemB);
      *itemB = itemT;
      *itemPN = itemT;
    }
    return;
  }
  
  listintSliderPP(*itemB, order, itemPN);
  if (*itemPN == NULL) {
    return;
  }
  
  itemT = (*itemPN)->next;
  listintExtructP(*itemPN);
  listintDeleteP(&itemT);
}

void
listintAddListP(struct listint **itemB, unsigned long int order,
  unsigned long int quantity, struct listint **itemAdded)
{
  struct listint *itemP;
  unsigned long int i;
  
  if (itemB == NULL || itemAdded == NULL || quantity == 0) {
    return;
  }
  
  listintAddP(itemB, order, itemAdded);
  /* should i check *itemAdded == NULL ? */
  for (i = 1; i < quantity && *itemAdded != NULL; i++) {
    listintAddP(itemAdded, 1, itemAdded);
  }
}

void
listintRemoveListP(struct listint **itemB, unsigned long int order,
  unsigned long int quantity, struct listint **itemPN)
{
  unsigned long int i;
  
  if (itemB == NULL || itemPN == NULL || quantity == 0) {
    return;
  }
  
  listintRemoveP(itemB, order, itemPN);
  for (i = 1; i < quantity && *itemPN != NULL; i++) {
    listintRemoveP(itemPN, 1, itemPN);
  }
}

void
listintEditP(struct listint *item, int data)
{
  if (item != NULL) {
    item->data = data;
  }
}

void
listintEditByOrderP(struct listint *itemB, int data, unsigned long int order)
{
  struct listint *itemPT;
  
  listintSliderPP(itemB, order, &itemPT);
  if (itemPT != NULL) {
    /*itemPT = itemPT->next;*/
    listintEditP(itemPT, data);
  }
}

void
listintDeleteListP(struct listint **itemB)
{
  struct listint *itemPT;
  
  do {
    listintRemoveListP(itemB, 0, 1, &itemPT);
  } while (itemPT != NULL);
  /*listintRemoveListP(itemB, 0, 1, &itemP);*/
  *itemB = NULL;
}

unsigned long int
listintList_sizeF(struct listint *itemB)
{
  struct listint *itemT;
  unsigned long int i = 0;
  
  itemT = itemB;
  if (itemT == NULL) {
    return i;
  } else {
    itemT = itemT->next;
  }
  for (i++; itemT != NULL && itemT != itemB; i++) {
    itemT = itemT->next;
  }
  
  return i;
}

char
listintIsLoopBF(struct listint *itemB)
{
  struct listint *itemT = NULL;
  
  if (itemB != NULL) {
    itemT = itemB->next;
  }
  while (itemT != NULL) {
    if (itemT == itemB) {
      return 1;
    }
    itemT = itemT->next;
  }
  
  return 0;
}

void
listintPrintListP(struct listint *itemB)
{
  struct listint *itemT;
  unsigned long int i;
  
  itemT = itemB;
  for (i = 0; itemT != NULL; i++) {
    printf("%lu %d\n", i, itemT->data);
    itemT = itemT->next;
  }
  printf("----\ntotal: %lu\n", i);
}

void
listintPrintListReverseP(struct listint *itemB)
{
  struct listint *itemT;
  unsigned long int i, list_size;
  
  list_size = listintList_sizeF(itemB);
  
  listintSliderPP(itemB, list_size, &itemT);
  for (i = 0; i < list_size; i++) {
    printf("%lu %d\n", list_size - i - 1, itemT->data);
    listintSliderPP(itemB, list_size - i - 1, &itemT);
  }
  
}

void
listintMgrP()
{
  struct listint *itemB = NULL;
  struct listint *itemTmp;
  char choice[1];
  char running = 1;
  int value = 0;
  unsigned long int order, quantity;
  
  choice[0] = 0;
  while (running) {
    printf("c - create,\nd - delete,\nD - delete all,\np - print,\n");
    printf("r - print in reverse,\ne - edit,\n");
    printf("q - quit.\n");
    scanf("%s", choice);
    printf("\n");
    switch (choice[0]) {
    case ('c') :
      printf("element's number: ");
      scanf("%lu", &order);
      printf("quantity of elements: ");
      scanf("%lu", &quantity);
      listintAddListP(&itemB, order, quantity, &itemTmp);
      break;
    case ('d') :
      printf("element's number from: ");
      scanf("%lu", &order);
      printf("quantity of elements: ");
      scanf("%lu", &quantity);
      listintRemoveListP(&itemB, order, quantity, &itemTmp);
      break;
    case ('D') :
      listintDeleteListP(&itemB);
      printf("i may have deleted the list\n");
      break;
    case ('p') :
      listintPrintListP(itemB);
      break;
    case ('r') :
      listintPrintListReverseP(itemB);
      break;
    case ('e') :
      printf("item's order: ");
      scanf("%lu", &order);
      printf("enter value: ");
      scanf("%d", &value);
      listintEditByOrderP(itemB, value, order);
      break;
    case ('q') :
      listintDeleteListP(&itemB);
      running = 0;
      break;
    default:
      printf("sorry i can't understad what you want from me. if you have some");
      printf(" troubles try combination Ctr+C\n");
      break;
    }
  }
}










