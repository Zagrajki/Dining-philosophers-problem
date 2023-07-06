#ifndef COMMON_HPP
#define COMMON_HPP
#include <mutex>
#include <atomic>
using namespace std;

int n_philosophs;
mutex* mtxa;
atomic<bool> ending = false;
int food, sleeping, btw_forks;
int food_min, food_max;
int sleeping_min, sleeping_max;
int btw_forks_min, btw_forks_max;
#endif
