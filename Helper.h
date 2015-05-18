#pragma once

#include "Board.h"

#include <Windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

char wait_for_char(int milis);
void display_help();
void display_score(Board* b1, Board* b2);