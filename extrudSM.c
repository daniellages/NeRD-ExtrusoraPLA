#include "extrudSM.h"

int st_start_time;

void sm_execute(extrudSM_t *SM) {

    st_start_time = get_current_time();

    switch (SM->current_state) {

        case st_Init:

            init_temp();
            
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
                break;
            }

            printf("ERROR! State Init can't progress.");

            break;

        case st_Extrude:

            get_temp();
            get_diameter();
            change_motor_speed("extrude");
            change_motor_speed("coil");
            change_hopper();
            change_temp();

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

            change_temp();
            get_temp();
            change_hopper();
            change_motor_speed("extrude");
            change_motor_speed("coil");

            SM->current_state = st_Stop;

            break;
        
        case st_Stop:

            get_temp();
            change_temp();
            change_motor_speed("extrude");
            change_motor_speed("coil");
            change_hopper();

            // Check if can extrude
            if(!check_coil_full() && !check_hopper_empty()) {
                SM->current_state = st_Extrude;
                break;
            }

            SM->current_state = st_Stop;

            break;

        default:
            printf("ERROR! Invalid state.");
            break;

    }

}

void sm_init(extrudSM_t *SM){
    SM->initial_state = st_Init;
    SM->current_state = SM->current_state;
}