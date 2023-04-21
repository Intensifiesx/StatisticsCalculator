# Statistics Calculator

A C++ program that reads data from a file and calculates various statistics such as mean, variance, mode, quartiles, range, and standard deviation.

## Requirements

- C++11 or later

## Usage

Compile the program using your preferred C++ compiler and run the executable file. When prompted, enter the name of the file containing the data.

## Example

Suppose we have a file named `data.txt` containing the following data:

```
10.2
13.5
12.7
14.3
11.9
```

To run the program on this data, we would do the following:

```
$ g++ main.cpp -o stats
$ ./stats.exe
------------------------------------
------- Statistics Calculator ------
------------------------------------
------- Finds Mean, Variance, ------
------ Range, Mode, Quartiles, -----
----- and Standard Deviation -------
------------------------------------
Enter file: data.txt
Sorted: 
     10.20      11.90      12.70      13.50      14.30 
Q1: 11.90
Q2: 12.70
Q3: 13.50
Sum: 62.60
Mode: No mode
Mean: 12.52
Count: 5
Range: 3.10
Median: 12.70
Variance: 1.16
Standard deviation: 1.08
Interquartile range: 1.60
```
