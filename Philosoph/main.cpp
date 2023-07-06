#include "show_state.hpp"
#include <conio.h>
#include <vector>

int main()
{
    cout << "Enter the number of philosophers:";
    cin >> n_philosophs;
    cout << "Enter the time of eating:";
    cin >> food;
    food_min = 0.8f * food;
    food_max = 1.2f * food;
    cout << "Enter the time of sleeping:";
    cin >> sleeping;
    sleeping_min = 0.8f * sleeping;
    sleeping_max = 1.2f * sleeping;
    cout << "Enter the time between picking up forks:";
    cin >> btw_forks;
    btw_forks_min = 0.8f * btw_forks;
    btw_forks_max = 1.2f * btw_forks;
    Philosoph* person = new (nothrow) Philosoph[n_philosophs];
    mtxa = new (nothrow) mutex[n_philosophs];
    vector<thread> th;
    for (int i = 0; i < n_philosophs; i++) {
        person[i].set_place(i + 1);
        th.push_back(thread(&Philosoph::f, &person[i]));
    }
    thread thp(show_state, person);
    while (!ending)
        if (_getche() == 32)
            ending = true;
    for (int i = 0; i < n_philosophs; i++) {
        th[i].join();
    }
    thp.join();
    delete[] person;
    delete[] mtxa;
    return 0;
}
