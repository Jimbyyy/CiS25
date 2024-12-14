# CIS Assignment 31-HW2: Class Inheritance

## Features

- Class inheritance between Date, Time, and DateTime.

- The program implements Date and Time Arithmetic:

    1. Program contains methods to both the Date and Time classes for adding and subtracting days, months, and years for Date and seconds, minutes, and hours for Time. Program can handle changes that cross month or year boundaries (e.g., adding 30 days to January 15) and day boundary for Time (e.g., adding 90 minutes to 23:30).

    2. Program has a method in DateTime that computes the difference between two DateTime objects in terms of total days, hours, minutes, and seconds.

- Program has an additional format method in DateTime class called `format(std::string formatString)` where `formatString` specifies how the date and time should be displayed (e.g., "YYYY-MM-DD", "HH:MM", "MM/DD/YYYY HH:MM:SS").
    - Program allows the format string to include text, which must be echoed exactly, such as "Today is YYYY-MM-DD, and the time is HH:MM".
    - **NOTE**: The format function is currently incomplete!

## Contributing

1. Fork the repository
2. Create a new branch (`git checkout -b feature/YourFeature`)
3. Make your changes
4. Commit your changes (`git commit -m 'Add some feature'`)
5. Push to the branch (`git push origin feature/YourFeature`)
6. Open a pull request

## License

This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/Jimbyyy/CiS25/blob/main/LICENSE) file for details.

## Acknowledgments

This code was written as part of the Berkeley City College CIS 25 course
