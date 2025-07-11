#include <stdio.h>

#include <string.h>

#include "ui.h"
#include "utils.h"

#define ANSI_BOLD  "\x1b[1m"
#define ANSI_RESET "\x1b[0m"

#define INPUT_SIZE 10

void print_welcome_message(void) {
    printf(ANSI_BOLD "Добро пожаловать в игру 'Камень, ножницы, бумага'!" ANSI_RESET "\n\n");
    print_rules();
}

void print_rules(void) {
    printf(ANSI_BOLD "Правила игры 'Камень, ножницы, бумага'" ANSI_RESET "\n\n");
    printf("Цель игры — выбрать фигуру, которая победит фигуру противника (компьютера).\n\n");
    printf("В игре есть три фигуры:\n\n");
    printf("* " ANSI_BOLD "Камень" ANSI_RESET "\n");
    printf("* " ANSI_BOLD "Ножницы" ANSI_RESET "\n");
    printf("* " ANSI_BOLD "Бумага" ANSI_RESET "\n\n");
    printf("Правила победы очень простые:\n\n");
    printf("* " ANSI_BOLD "Камень" ANSI_RESET " побеждает " ANSI_BOLD "Ножницы" ANSI_RESET " (камень ломает ножницы).\n");
    printf("* " ANSI_BOLD "Ножницы" ANSI_RESET " побеждают " ANSI_BOLD "Бумагу" ANSI_RESET " (ножницы режут бумагу).\n");
    printf("* " ANSI_BOLD "Бумага" ANSI_RESET " побеждает " ANSI_BOLD "Камень" ANSI_RESET " (бумага накрывает камень).\n\n");
    printf("Если вы и компьютер выбрали одну и ту же фигуру (например, Камень против Камня), объявляется " ANSI_BOLD "ничья" ANSI_RESET ", и раунд переигрывается или не засчитывается.\n\n");
    printf("Ваша задача — предугадать ход компьютера и выбрать выигрышную фигуру!\n\n");
}

Choice get_player_choice(void) {
    int input = -1;

    while (1) {
        printf("Сделайте ваш выбор: \n");
        printf("1 - Камень\n");
        printf("2 - Ножницы\n");
        printf("3 - Бумага\n");
        printf("0 - Выход\n");
        printf("\nВаш ход: ");

        int scanf_result = scanf(" %d", &input);

        if (scanf_result != 1) {
            printf("Ошибка ввода. Пожалуйста, введите корректное число.\n");
            
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        int c = getchar();
        if (c != '\n' && c != EOF) {
            printf("Ошибка ввода. Введите только одно число.\n");
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        switch (input) {
            case 1: return ROCK;
            case 2: return SCISSOR;
            case 3: return PAPER;
            case 0: return (Choice)0;
            default: printf("Некорректный выбор. Пожалуйста, выберите от 1 до 3, или 0 для выхода.\n\n");
        }
    }
}

bool ask_user_continue(void) {
    char input[INPUT_SIZE];

    while (1) {
        printf("\nХотите сыграть ещё раз (да/нет)? ");

        if (scanf("%9s", input) != 1) {
            while (getchar() != '\n');
            continue;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        ResponseType result = parse_user_response(input);

        switch (result) {
            case RESPONSE_AFFIRMATIVE:
                return true;
            case RESPONSE_NEGATIVE:
                return false;
            case RESPONSE_UNKNOWN:
                printf("Некорректный ввод. Пожалуйста, введите 'да' или 'нет'.\n");
                break;
        }
    }
}

static const char* explanation_matrix[3][3] = {
    {NULL, "Камень бьёт ножницы", "Бумага накрывает камень"},
    {"Камень бьёт ножницы", NULL, "Ножницы режут бумагу"},
    {"Бумага накрывает камень", "Ножницы режут бумагу", NULL}
};

void print_round_results(Choice player_choice, Choice ai_choice, GameResult result) {
    const char* explanation = explanation_matrix[player_choice - 1][ai_choice - 1];

    switch (result) {
        case RESULT_WIN:
            printf("%s\n", explanation);
            printf("Вы победили!\n");
            break;
        case RESULT_LOSE:
            printf("%s\n", explanation);
            printf("Вы проиграли!\n");
            break;
        case RESULT_DRAW:
            printf("Ничья!\n");
            break;
        case ERROR:
            printf("Произошла внутренняя ошибка при определении победителя.\n");
            break;
    }
}

void print_scores(int users_score, int ai_score) {
    printf("\n--- Текущий счёт ---\n");
    printf("Вы: %d\n", users_score);
    printf("Компьютер: %d\n", ai_score);
    printf("--------------------\n");
}
