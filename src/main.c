#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// Подключаем интерфейсы наших модулей
#include "ui.h"
#include "game_logic.h"
#include "rps.h"

int main(void) {
    srand(time(NULL));
    int user_score = 0;
    int ai_score = 0;
    bool continue_game = true;

    print_welcome_message();

    while (continue_game) {
        // Получаем ход игрока (вся сложность ввода скрыта в модуле ui)
        Choice player_choice = get_player_choice();

        // Проверяем сигнал выхода
        if ((int)player_choice == 0) {
            break;
        }

        // Получаем ход компьютера (логика скрыта в game_logic)
        Choice ai_choice = get_random_choice();

        // Сообщаем о сделанных ходах
        printf("\nВы выбрали: %s\n", get_choice_name(player_choice));
        printf("Компьютер выбрал: %s\n", get_choice_name(ai_choice));

        // Определяем победителя (логика скрыта в game_logic)
        GameResult result = determine_winner(player_choice, ai_choice);

        // Обновляем счет
        if (result == RESULT_WIN) {
            user_score++;
        } else if (result == RESULT_LOSE) {
            ai_score++;
        }

        // Выводим результаты раунда и текущий счет (все printf скрыты в ui)
        print_round_results(player_choice, ai_choice, result);
        print_scores(user_score, ai_score);

        // Спрашиваем, хочет ли пользователь продолжить
        continue_game = ask_user_continue();
    }

    printf("\nСпасибо за игру! До встречи!\n");

    return 0;
}