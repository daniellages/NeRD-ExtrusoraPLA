#include <stdio.h>
#include <windows.h>
#include <pthread.h>

// void getTemp();
int regTemp(double current, double target);

int main(){

    double current_temp = 100;
    double target_temp = 250;

    int x = regTemp(current_temp, target_temp);
    printf("Resultado: %d\n", x);

    return 0;
}

// void getTemp(){
//     printf("Temperatura da Extrusora:\n");

// }

int regTemp(double current, double target){
    double diff = target - current;
    int flag = 0;

    while (flag != 1){
        diff = target - current;
        if (diff != 0){
            // Central code
            current = target;
        } else {
            flag = 1;
        }
        // Wait 1 sec
        Sleep(1000);
    }

    return flag;
}