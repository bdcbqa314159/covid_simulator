#pragma once
#include <vector>

class Person;
typedef int (*sim_func_t)();

int start_ui(sim_func_t simfunc);
void ui_redraw(std::vector<Person> &, std::vector<int> &);
