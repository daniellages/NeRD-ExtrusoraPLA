#pragma once

#include <stdio.h>
#include <stdbool.h>

// Data type definitions
typedef enum {
    ObjectFull,
    ObjectEmpty
} object_state_t;

typedef enum {
    FilDiameterLow,
    FilDiameterMedium,
    FilDiameterHigh
} fil_diameter_state_t;

// Functions
void change_motor_speed_extrude(int speed);
void change_motor_speed_coil(int speed);
void change_hopper(bool open);
void change_temp(int temp);

bool check_coil_full();
bool check_hopper_empty();
bool finish();

int get_temp();
int get_current_time();
int get_diameter();

void tickTime();