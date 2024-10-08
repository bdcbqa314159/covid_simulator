#pragma once

#define X_LIMIT 5000
#define Y_LIMIT 5000

#define SIM_HOURS 1000
#define NUM_PEOPLE 1000

enum disease_status
{
    VULNERABLE,
    INFECTED,
    IMMUNE,
    DEAD
};

#define INFECTION_TIME 480

#define INFECTION_PROBABILITY 0.01

#define NORMAL_FATALITY_RATE 0.01
#define SATURED_FATALITY_RATE 0.06
#define INFECTION_PROXIMITY 5.0
#define INITIAL_INFECTIONS 30

#define SATURATION_THRESHOLD (NUM_PEOPLE / 5)

extern bool saturated;
int sim_main();
