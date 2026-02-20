def main():
    kilometers = float(input("Enter distance (km): "))
    minutes, seconds = map(int, input("Enter time (min sec): ").split())
    seconds += 60*minutes

    hours = seconds / 3600
    meters = 1000*kilometers
    miles = kilometers / 1.609344

    time_km = seconds / kilometers
    minute_km = int(time_km / 60)
    second_km = int(time_km) % 60

    time_mi = seconds / kilometers
    minute_mi = int(time_mi / 60)
    second_mi = int(time_mi) % 60

    speed_kph = kilometers / hours
    speed_mps = meters / seconds
    speed_mph = miles / hours

    print(f"Pace (km): {minute_km} minutes {second_km} seconds")
    print(f"Pace (mi): {minute_mi} minutes {second_mi} seconds")
    print(f"Speed (kph): {speed_kph}")
    print(f"Speed (m/s): {speed_mps}")
    print(f"Speed (mph): {speed_mph}")

if __name__ == "__main__":
    main()