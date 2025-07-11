#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "rps.h"

typedef enum {
    RESULT_DRAW,
    RESULT_WIN,
    RESULT_LOSE,
    ERROR
} GameResult;

Choice get_random_choice(void);
int determine_winner(Choice player, Choice ai);

#endif // GAME_LOGIC_H