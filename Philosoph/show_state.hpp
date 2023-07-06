#ifndef SHOW_STATE_HPP
#define SHOW_STATE_HPP
#include "philosoph.hpp"
#include <iostream>

void show_state(Philosoph* person) {
    while (!ending) {
        system("CLS");
        for (int i = 0; i < n_philosophs; i++) {
            if (person[i].eats) {
                printf("Fed %d times philosopher %d eats and holds forks: %d and %d.\n", person[i].fed, i + 1, person[i].place == n_philosophs ? 0 : person[i].place - 1, person[i].place == n_philosophs ? n_philosophs - 1 : person[i].place);
            }
            else if (person[i].fork1 && !person[i].sleeps) {
                printf("Fed %d times philosopher %d holds fork %d and will pick up another one in a moment.\n", person[i].fed, i + 1, person[i].place == n_philosophs ? 0 : person[i].place - 1);
            }
            else if (person[i].fork1 && person[i].sleeps) {
                printf("Fed %d times philosopher %d holds a fork %d and sleeps.\n", person[i].fed, i + 1, person[i].place == n_philosophs ? 0 : person[i].place - 1);
            }
            else if (person[i].sleeps) {
                printf("Fed %d times philosopher %d sleeps.\n", person[i].fed, i + 1);
            }
            else {
                printf("Fed %d times philosopher %d will fall asleep in a moment.\n", person[i].fed, i + 1);
            }
        }
        chrono::milliseconds timespan_break(200);
        this_thread::sleep_for(timespan_break);
    }
}
#endif
