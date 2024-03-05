#ifndef CHECK_INPUT_H
#define CHECK_INPUT_H

struct CheckAction {
    bool keepPlaying;
    int choice;
};

int* checkAction();
int* gameTypeInput();

#endif