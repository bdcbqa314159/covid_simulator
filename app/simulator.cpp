#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

#include "person.hpp"
#include "simulator.hpp"
#include "ui.hpp"
#include "ppmodel.hpp"
#include "utilities.hpp"

using namespace std;

bool saturated = false;

int sim_main()
{
  // setup the simuation
  Person people[NUM_PEOPLE];
  PopularPlacesModel models[NUM_PEOPLE];

  // "flattening the curve"
  // this hitory array is the curve for stores the number
  // of current infections at each hour in the simulation

  std::vector<int> infection_history(SIM_HOURS, 0);

  // initial infections
  for (int i = 0; i < INITIAL_INFECTIONS; i++)
  {
    people[i].status = INFECTED;
  }
  int max_infected_at_once = 0;

  for (int i = 0; i < SIM_HOURS; i++)
  {
    // redraw the UI, so you can see it happen
    if ((i % 2) == 0)
    {
      ui_redraw(people, NUM_PEOPLE, infection_history);
    }

    // move people
    for (int p = 0; p < NUM_PEOPLE; p++)
    {
      if (people[p].is_alive())
      {
        models[p].move(people[p]);
        // people[p].mobility_model->move();
        people[p].progress_disease();
      }
    }

    // try to infect
    for (int p = 0; p < NUM_PEOPLE; p++)
    {
      if (people[p].is_alive())
      {
        for (int p2 = 0; p2 < NUM_PEOPLE; p2++)
        {
          if (p != p2 && people[p2].is_alive())
          {
            people[p].try_infect(people[p2]);
          }
        }
      }
    }

    // report status
    int num_infected = 0;
    int num_immune = 0;
    int num_dead = 0;
    int num_vulnerable = 0;
    for (int p = 0; p < NUM_PEOPLE; p++)
    {
      if (!people[p].is_alive())
      {
        num_dead++;
      }
      if (people[p].status == INFECTED)
      {
        num_infected++;
      }
      if (people[p].status == IMMUNE)
      {
        num_immune++;
      }
      if (people[p].status == VULNERABLE)
      {
        num_vulnerable++;
      }
    }
    if (num_infected > max_infected_at_once)
    {
      max_infected_at_once = num_infected;
    }

    // set whether or not the medical system is currently saturated
    saturated = (num_infected > SATURATION_THRESHOLD);

    if ((i % 10) == 0 || num_infected == 0)
    {
      std::cout << std::fixed;
      std::cout << std::setprecision(2);
      double ratio = num_dead * 100. / NUM_PEOPLE;

      std::cout << num_vulnerable << "\t" << num_infected << "\t" << num_immune
                << "\t" << num_dead << "\t" << ratio << "%\n";
    }
    infection_history[i] = num_infected;
    if (num_infected == 0)
      break;
  }
  std::cout << "Peak infections - " << max_infected_at_once << "\n";
  return 0;
}

int main(int argc, char const *argv[])
{
  int out = start_ui(sim_main);

  assert(out == 0);

  return 0;
}
