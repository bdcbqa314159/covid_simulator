#pragma once

#include "location.hpp"
#include "mobility_model.hpp"
#include "simulator.hpp"

class MobilityModel;

class Person {
public:
  Person();
  bool infect();
  bool try_infect(Person other_persone);
  void progress_disease();
  bool is_alive();

  Location location;
  MobilityModel *mobility_model;
  disease_status status;
  int disease_counter;
};
