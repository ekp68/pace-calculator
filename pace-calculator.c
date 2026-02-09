#include <stdio.h>

int main()
{
    char buff[100];
    int n = 100;

    double kilometers;
    int minutes;
    int seconds;
    
    printf("Enter distance (km): ");
    fgets(buff, n, stdin);
    sscanf(buff, "%lf", &kilometers);

    printf("Enter time (min sec): ");
    fgets(buff, n, stdin);
    sscanf(buff, "%d %d", &minutes, &seconds);
    
    int total_seconds = 60*minutes + seconds;
    double hours = (double) total_seconds / 3600;
    double meters = 1000*kilometers;
    double miles = kilometers / 1.609344;

    int time_km = total_seconds / kilometers;
    int minute_km = time_km / 60;
    int second_km = time_km % 60;

    int time_mi = total_seconds / miles;
    int minute_mi = time_mi / 60;
    int second_mi = time_mi % 60;

    double speed_kph = kilometers / hours;
    double speed_mps = meters / total_seconds;
    double speed_mph = miles / hours;

    printf("pace (km): %d minutes %d seconds\n", minute_km, second_km);
    printf("pace (mi): %d minutes %d seconds\n", minute_mi, second_mi);
    printf("speed: %.1lf km/h\n", speed_kph);
    printf("speed: %.1lf mph\n", speed_mph);
    printf("speed: %.1lf m/s\n", speed_mps);

    return 0;
}
