#include <stdio.h>

#define BUFF_SIZE 100
char buff[BUFF_SIZE];

double get_distance();
int get_time();

int main()
{
    double kilometers = get_distance();
    int seconds = get_time();
    
    double hours = (double) seconds / 3600;
    double meters = 1000*kilometers;
    double miles = kilometers / 1.609344;

    double time_km = seconds / kilometers;
    int minute_km = (int) (time_km / 60);
    int second_km = (int) time_km % 60;

    double time_mi = seconds / miles;
    int minute_mi = (int) (time_mi / 60);
    int second_mi = (int) time_mi % 60;

    double speed_kph = kilometers / hours;
    double speed_mps = meters / seconds;
    double speed_mph = miles / hours;

    printf("pace (km): %d minutes %d seconds\n", minute_km, second_km);
    printf("pace (mi): %d minutes %d seconds\n", minute_mi, second_mi);
    printf("speed: %.1lf km/h\n", speed_kph);
    printf("speed: %.1lf mph\n", speed_mph);
    printf("speed: %.1lf m/s\n", speed_mps);

    return 0;
}

double get_distance()
{
    double kilometers;
    int is_valid = 0;
    
    printf("Enter distance (km): ");
    while (!is_valid)
    {
        fgets(buff, BUFF_SIZE, stdin);
        if (sscanf(buff, "%lf", &kilometers) != 1)
        {
            printf("Distance (km) needs to be a number: ");
            continue;
        }
        else if (kilometers <= 0)
        {
            printf("Distance (km) cannot be zero or negative: ");
            continue;
        }

        is_valid = 1;
    }

    return kilometers;
}

int get_time()
{
    int minutes;
    int seconds;
    int is_valid = 0;

    printf("Enter time (min sec): ");
    while (!is_valid)
    {
        fgets(buff, BUFF_SIZE, stdin);

        if (sscanf(buff, "%d %d", &minutes, &seconds) != 2)
        {
            printf("Minutes and seconds must be integers (min sec): ");
            continue;
        }
        else if (minutes < 0 || seconds < 0)
        {
            printf("Minutes and seconds cannot be negative: ");
            continue;
        }
        else if (minutes == 0 && seconds == 0)
        {
            printf("Time cannot be zero: ");
            continue;
        }

        is_valid = 1;
    }

    return 60*minutes + seconds;
}