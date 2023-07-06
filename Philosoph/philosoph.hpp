#ifndef PHILOSOPH_HPP
#define PHILOSOPH_HPP
#include "common.hpp"
#include <chrono>

class Philosoph {
public:
    volatile atomic<bool> fork1, fork2, eats, sleeps = false;
    int fed = 0;
    char place = 0;
    void set_place(char number) {
        place = number;
    }
    void f() {
        while (!ending) {
            if (mtxa[place == n_philosophs ? 0 : place - 1].try_lock()) {
                fork1 = true;
            }
            if (fork1) {
                chrono::milliseconds timespan_forks(btw_forks_min + (rand() % (btw_forks_max - btw_forks_min + 1)));
                this_thread::sleep_for(timespan_forks);
                if (mtxa[place == n_philosophs ? n_philosophs - 1 : place].try_lock()) {
                    fork2 = true;
                }
                else {
                    fork1 = false;
                    mtxa[place == n_philosophs ? 0 : place - 1].unlock();
                }
            }
            if (fork1 && fork2) {
                eats = true;
                chrono::milliseconds timespan_food(food_min + (rand() % (food_max - food_min + 1)));
                this_thread::sleep_for(timespan_food);
                fed++;
                eats = false;
                fork2 = false;
                mtxa[place == n_philosophs ? n_philosophs - 1 : place].unlock();
                fork1 = false;
                mtxa[place == n_philosophs ? 0 : place - 1].unlock();
            }
            sleeps = true;
            chrono::milliseconds timespan_sleeping(sleeping_min + (rand() % (sleeping_max - sleeping_min + 1)));
            this_thread::sleep_for(timespan_sleeping);
            sleeps = false;
        }
    }
};
#endif
