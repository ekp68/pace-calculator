def main():
    kilometers = float(input("Enter distance (km): "))
    minutes, seconds = map(int, input("Enter time (min sec): ").split())

    print(f"Distance {kilometers}")
    print(f"Time {minutes} min {seconds} sec")

if __name__ == "__main__":
    main()