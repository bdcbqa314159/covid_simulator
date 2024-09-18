#include "mobility_model.hpp"
#include "person.hpp"
#include <cassert>

MobilityModel::MobilityModel() { person = NULL; }

void MobilityModel::setPerson(Person *p) {
  assert(p != NULL);
  person = p;
}
