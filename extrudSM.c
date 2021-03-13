#include "extrudSM.h"

int st_start_time;

void sm_execute(extrudSM_t *SM) {

    switch (SM->current_state) {

        case st_Init:

            change_temp(TARGET);
            
            // Check if we can't extrude
            if(check_coil_full() || check_hopper_empty()) {
                SM->current_state = st_Stop;
                break;
            }

            // TODO: Take in consideration thresholds
            if(get_temp() == TARGET) {
                SM->current_state = st_Extrude;
                break;
            }

            // Timout handler
            if(get_current_time() - st_start_time >= TIMEOUT) {
                SM->current_state = st_Init;
                st_start_time = get_current_time();
                break;
            }

            printf("ERROR! State Init can't progress.");

            break;

        case st_Extrude:

            get_diameter();
            change_motor_speed_extrude(15);
            change_motor_speed_coil(15);
            change_hopper(true);

            if(get_temp() != TARGET) {
                change_temp(TARGET);
            }

            // Check if can extrude
            if(!check_coil_full() && !check_hopper_empty()) {
                SM->current_state = st_Extrude;
                break;
            }

            // Check if we can't extrude
            if(check_coil_full() || check_hopper_empty()) {
                SM->current_state = st_Stop;
                break;
            }

            // Check if the process is completed
            if(finish()) {
                SM->current_state = st_Clean;
                break;
            }

            break;

        case st_Clean:

            if(get_temp() != TARGET) {
                change_temp(TARGET);
            }

            change_hopper(false);
            change_motor_speed_extrude(9001);
            change_motor_speed_coil(42069);

            SM->current_state = st_Stop;

            break;
        
        case st_Stop:

            change_temp(0);
            change_motor_speed_extrude(0);
            change_motor_speed_coil(0);
            change_hopper(false);

            // Check if can extrude
            if(!check_coil_full() && !check_hopper_empty()) {
                SM->current_state = st_Extrude;
                break;
            } else {
                SM->current_state = st_Stop;
            }

            break;

        default:
            printf("ERROR! Invalid state.");
            break;

    }

}

void sm_init(extrudSM_t *SM){
    SM->initial_state = st_Init;
    SM->current_state = SM->initial_state;
    st_start_time = get_current_time();
}