#include <stdio.h>

#include <string.h>

#include "ui.h"
#include "utils.h"

#define INPUT_SIZE 10

void print_welcome_message(void) {
    printf("\u001b[1mДобро пожаловать в игру 'Камень, ножницы, бумага'!\u001b[0m\n\n");
    print_rules();
}

void print_rules(void) {
    printf("\u001b[1mПравила игры 'Камень, ножницы, бумага'\u001b[0m\n\n");
    printf("Цель игры — выбрать фигуру, которая победит фигуру противника (компьютера).\n\n");
    printf("В игре есть три фигуры:\n\n");
    printf("* \u001b[1mКамень\u001b[0m\n");
    printf("* \u001b[1mНожницы\u001b[0m\n");
    printf("* \u001b[1mБумага\u001b[0m\n\n");
    printf("Правила победы очень простые:\n\n");
    printf("* \u001b[1mКамень\u001b[0m побеждает \u001b[1mНожницы\u001b[0m (камень ломает ножницы).\n");
    printf("* \u001b[1mНожницы\u001b[0m побеждают \u001b[1mБумагу\u001b[0m (ножницы режут бумагу).\n");
    printf("* \u001b[1mБумага\u001b[0m побеждает \u001b[1mКамень\u001b[0m (бумага накрывает камень).\n\n");
    printf("Если вы и компьютер выбрали одну и ту же фигуру (например, Камень против Камня), объявляется \u001b[1mничья\u001b[0m, и раунд переигрывается или не засчитывается.\n\n");
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

static const char* a_explanation_matrix[3][3] = {
    {NULL, "Камень бьёт ножницы", "Бумага накрывает камень"},
    {"Камень бьёт ножницы", NULL, "Ножницы режут бумагу"},
    {"Бумага накрывает камень", "Ножницы режут бумагу", NULL}
};

void print_round_results(Choice player_choice, Choice ai_choice, GameResult result) {
    const char* explanation = a_explanation_matrix[player_choice - 1][ai_choice - 1];

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
