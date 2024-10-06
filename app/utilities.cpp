#include "utilities.hpp"
#include <cassert>

u_int32_t arc4random_uniform(u_int32_t upper_bound);

bool try_event(double probability)
{
    assert(probability >= 0.0 && probability <= 1.0);
    const int resolution = 100000;

    double rnum = arc4random_uniform(resolution);
    rnum = rnum / static_cast<double>(resolution);
    return rnum <= probability;
}