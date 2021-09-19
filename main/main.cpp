#include <iostream>
#include <unistd.h>
#include <thread>
#include <ctime>
#include <gamepad.h>
#include <drone.h>

double fall_back_throttle = 0;
double throttle = 0;
double dt = 0.01;

int main(){
    setvbuf(stdout, NULL,_IONBF,0);

    drone::init();
    gamepad::init();

    bool update = false;

    double old = 0.0;

    while(true){

        
        throttle +=  * dt;


        if(throttle < 0){throttle = 0;}
        if(throttle > 0.3) {throttle = 0.3;}
        
        double diff = throttle - old;
        if(diff > 0.01 || diff < 0.01){
            drone::set_all(throttle)
        }

        usleep(10000);
    };

    drone::destroy();
}