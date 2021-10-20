#!/bin/sh
#
#    listint is my implementation of linked list of int
#    Copyright (C) 2021  Sergey Tokarev
#....
#    This file is part of listint.
#
#    listint is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    listint is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with listint.  If not, see <https://www.gnu.org/licenses/>.
#


gcc -std=c89 -c main.c
gcc -std=c89 -g3 -c listint.c
gcc -std=c89 -o listint main.o listint.o