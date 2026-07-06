#include <stdio.h>
#include "light.h"
#include <time.h>
#include <unistd.h>

 void switch_light()
 {
    light_status light= OFF;

    /* # include <time.h> library for fetching time
    time_t - data ype to store time
    time()- saves system's time from OS
    localtime()- gives human readable time
    struct tm - predefines struct, which has all time related data 
    */
    time_t current_time, new_time;
    

    struct tm *local; 
    
    
    while(1)
    {
        current_time = time(NULL);//fetches current time in computer readable form
        local = localtime(&current_time); //human readable time
        printf("Current time: %d:%d:%d\n",local->tm_hour,local->tm_min,local->tm_sec);
        if(local->tm_hour >= 18  || local->tm_hour < 6)
        {
            printf("Light switched ON..\n");
            light= ON;
        }
        else
        {
            printf("Light switched OFF...\n");
        }
        sleep(60);//1 minute; sleep(1)- 1 sec and sleep(3600)- 1 hour
    }
    
}
