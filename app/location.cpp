#include "location.hpp"
#include "simulator.hpp"
#include <cmath>

#define CLOSE_ENOUGH 0.05

Location::Location()
    : x_(arc4random_uniform(X_LIMIT)), y_(arc4random_uniform(Y_LIMIT)) {}

Location::Location(double nx, double ny) : x_(nx), y_(ny) {}

bool Location::move_toward(Location destination, double howFar) {
  double dx = destination.x_ - x_;
  double dy = destination.y_ - y_;
  double theta = atan2(dy, dx);

  double distance = sqrt(dx * dx + dy * dy);

  if (distance < howFar) {
    x_ = destination.x_;
    y_ = destination.y_;
    return true;
  } else {
    x_ += (howFar * cos(theta));
    y_ += (howFar * sin(theta));
    return false;
  }
}

double Location::get_distance(Location destination) {
  double dx = destination.x_ - x_;
  double dy = destination.y_ - y_;

  double distance = sqrt(dx * dx + dy * dy);

  return distance;
}

bool Location::at_location(Location destination) {
  return (get_distance(destination) < CLOSE_ENOUGH);
}

double Location::get_x() { return x_; }
double Location::get_y() { return y_; }
void Location::set_x(double nx) { x_ = nx; }
void Location::set_y(double ny) { y_ = ny; }
