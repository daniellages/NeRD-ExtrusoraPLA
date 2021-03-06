#include <stdio.h>
#include <windows.h>
#include <pthread.h>

int regTemp(double target);

void changeTemp(double temperature);

double readTemp();

int main(){

    int x;
    x = regTemp(100);
    printf("RegTemp: %d\n", x);

    return 0;

}

int regTemp(double target){

    double current = readTemp();

    // Joao pensa nisto do threshold
    double threshold = 0.05;
    double diff;
    int flag = 0;

    while(flag == 0) {
        
        diff = target - current;

        if(diff == 0) {

            flag = 1;

        } 
        else {

            // Yes
            // Change Temperature
            changeTemp(target);
            Sleep(2000);    // Wait 2 sec
            // Read Temperature Value
            current = readTemp();

        }
        
    }

    return flag;

}

void changeTemp(double temperature){

    printf("Changed Temperature to: %lf\n", temperature);

}

double readTemp(){

    double temp;

    printf("Temperature?\n");
    scanf("%lf", &temp);

    return temp;

}