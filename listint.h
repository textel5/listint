/*
    listint is my implementation of linked list of int
    Copyright (C) 2021  Sergey Tokarev
....
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

struct listint {
  struct listint *next;
  int data;
};
void
listintAllocP(struct listint **item);
void
listintFreeP(struct listint **item);
void
listintResetP(struct listint **item);
void
listintCreateP(struct listint **item);
void
listintDeleteP(struct listint **item);
void
listintLinkP(struct listint *itemP, struct listint *itemT);
void
listintInsertP(struct listint *itemP, struct listint *itemT);
void
listintExtructP(struct listint *itemP);
void
listintSliderPP(struct listint *itemB, unsigned long int order,
  struct listint **itemS);
void
listintAddP(struct listint **itemB, unsigned long int order,
  struct listint **itemAdded);
void
listintRemoveP(struct listint **itemB, unsigned long int order,
  struct listint **itemPN);
void
listintAddListP(struct listint **itemB, unsigned long int order,
  unsigned long int quantity, struct listint **itemAdded);
void
listintRemoveListP(struct listint **itemB, unsigned long int order,
  unsigned long int quantity, struct listint **itemPN);
void
listintEditP(struct listint *item, int data);
void
listintEditByOrderP(struct listint *item, int data, unsigned long int order);
void
listintDeleteListP(struct listint *itemB);
unsigned long int
listintList_sizeF(struct listint *itemB);
char
listintIsLoopBF(struct listint *itemB);
void
listintPrintListP(struct listint *itemB);
void
listintPrintListReverse(struct listint *itemB);
void
listintMgrP();










