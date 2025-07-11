#ifndef UI_H
#define UI_H

#include <stdbool.h>

#include "rps.h"
#include "game_logic.h"

void print_welcome_message(void);
void print_rules(void);

Choice get_player_choice(void);
bool ask_user_continue(void);

void print_round_results(Choice player_choice, Choice ai_choice, GameResult result);
void print_scores(int users_score, int ai_score);

#endif // UI_H