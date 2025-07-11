#ifndef UTILS_H
#define UTILS_H

typedef enum {
    RESPONSE_UNKNOWN,
    RESPONSE_AFFIRMATIVE,
    RESPONSE_NEGATIVE
} ResponseType;

ResponseType parse_user_response(const char *input);

#endif // UTILS_H