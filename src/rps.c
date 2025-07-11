#include "rps.h"

const char* choice_names[] = {
    [ROCK]    = "Камень",
    [SCISSOR] = "Ножницы",
    [PAPER]   = "Бумага"
};

const char* get_choice_name(Choice option) {
    if (option >= 1 && option < CHOICE_COUNT) {
        return choice_names[option];
    }
    return "Неизвестное имя";
}
