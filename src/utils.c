#include <string.h>

#include "utils.h"

typedef struct {
    const char *keyword_text;
    ResponseType type;
} KeywordMapping;

static const KeywordMapping RESPONSE_DICTIONARY[] = {
    // Утвердительные ответы
    {"да",   RESPONSE_AFFIRMATIVE},
    {"Да",   RESPONSE_AFFIRMATIVE},
    {"дА",   RESPONSE_AFFIRMATIVE},
    {"ДА",   RESPONSE_AFFIRMATIVE},

    // Отрицательные ответы
    {"нет",  RESPONSE_NEGATIVE},
    {"Нет",  RESPONSE_NEGATIVE},
    {"нЕт",  RESPONSE_NEGATIVE},
    {"неТ",  RESPONSE_NEGATIVE},
    {"НЕт",  RESPONSE_NEGATIVE},
    {"нЕТ",  RESPONSE_NEGATIVE},
    {"НЕТ",  RESPONSE_NEGATIVE}
};

static const int DICTIONARY_SIZE = sizeof(RESPONSE_DICTIONARY) / sizeof(RESPONSE_DICTIONARY[0]);

ResponseType parse_user_response(const char *input) {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(input, RESPONSE_DICTIONARY[i].keyword_text) == 0) {
            return RESPONSE_DICTIONARY[i].type;
        }
    }
    return RESPONSE_UNKNOWN;
}
