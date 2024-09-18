#include "mobility_model.hpp"
#include "person.hpp"
#include <cassert>

MobilityModel::MobilityModel() { person = nullptr; }

void MobilityModel::setPerson(Person *p) {
  assert(p != nullptr);
  person = p;
}
