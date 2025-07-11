#ifndef RPS_H
#define RPS_H

typedef enum {
    ROCK = 1,
    SCISSOR,
    PAPER,
    CHOICE_COUNT
} Choice;

const char* get_choice_name(Choice option);

#endif // RPS_H