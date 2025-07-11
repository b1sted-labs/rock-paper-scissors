#include "game_logic.h"

#include <stdlib.h>
#include <time.h>

Choice get_random_choice(void) {
    int num_choices = CHOICE_COUNT - ROCK;
    int random_index = rand() % num_choices;
    return (Choice)(random_index + ROCK);
}

static const GameResult winner_matrix[3][3] = {
    {RESULT_DRAW, RESULT_WIN, RESULT_LOSE},
    {RESULT_LOSE, RESULT_DRAW, RESULT_WIN},
    {RESULT_WIN, RESULT_LOSE, RESULT_DRAW}
};

int determine_winner(Choice player, Choice ai) {
    if (player < ROCK || player > PAPER || ai < ROCK || ai > PAPER) {
        return ERROR;
    }
    return winner_matrix[player - 1][ai - 1];
}
