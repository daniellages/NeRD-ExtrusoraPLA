#include "extrud.h"

object_state_t Coil;
object_state_t Hopper;
fil_diameter_state_t Filament;

int timeElapsed = 0;

void change_motor_speed_extrude(int speed) {
    printf("- Extrude Motor Speed changed to: %d\n", speed);
}

void change_motor_speed_coil(int speed) {
    printf("- Coil Motor Speed changed to: %d\n", speed);
}

void change_hopper(bool open) {
    if(open) {
        printf("- Hopper open\n");
    } else {
        printf("- Hopper close\n");
    }
}

void change_temp(int temp) {
    printf("- Temp changed to %d", temp);
}


bool check_coil_full(object_state_t command) {
    Coil = command;
    if(Coil == ObjectFull) {
        return true;
    } else {
        return false;
    }
}

bool check_hopper_empty(object_state_t command) {
    Hopper = command;
    if(Hopper == ObjectEmpty) {
        return true;
    } else {
        return false;
    }
}

// Isto tá mal
// Eu sei que sabes disso
// Mas vais arranjar
// Porque és fixe
// Os argumentos destas funçoes sao inputs "virtuais"
bool finish(bool finish) {
    return finish;
}


int get_temp(int temp) {
    return temp;
}

int get_current_time() {
    return timeElapsed;
}

int get_diameter(fil_diameter_state_t command) {
    Filament = command;
    if(Filament == FilDiameterLow) {
        return -1;
    } else if(Filament == FilDiameterMedium) {
        return 0;
    } else {
        return 1;
    }
}

void timeTick() {
    timeElapsed++;
}