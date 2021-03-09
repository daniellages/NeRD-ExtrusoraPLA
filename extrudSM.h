#pragma once

#include <stdio.h>
#include <stdbool.h>

// Timeout duration in seconds
#define TIMEOUT 60
// Tarege temperature (ºC)
#define TARGET 250

// States
typedef enum {
    st_Init,
    st_Extrude,
    st_Clean,
    st_Stop
} extrudState_t;

// Data structure for the state machine
typedef struct {
    extrudState_t initial_state;
    extrudState_t current_state;
} extrudSM_t;

// State machine execution
void sm_execute(extrudSM_t *SM);

// Set inital state
void sm_init(extrudSM_t *SM);