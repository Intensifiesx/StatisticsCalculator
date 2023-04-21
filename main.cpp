#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

// Finds the mean of the array
double findMean(vector<double> arr)
{
    double total = 0;

    for (double i : arr)
        total += i;

    return total / arr.size();
}

// Finds the variance of the array
double findVariance(vector<double> arr, double mean)
{
    double total = 0;

    for (double i : arr)
        total += pow(i - mean, 2);

    return total / (arr.size() - 1);
}

// Reads the data from the file and stores it in the array
void readData(vector<double> &arr)
{
    ifstream file;
    cout << "------------------------------------" << endl;
    cout << "------- Statistics Calculator ------" << endl;
    cout << "------------------------------------" << endl;
    cout << "------- Finds Mean, Variance, ------" << endl;
    cout << "------ Range, Mode, Quartiles, -----" << endl;
    cout << "----- and Standard Deviation -------" << endl;
    cout << "------------------------------------" << endl;
    while (!file.is_open())
    {
        cout << "Enter file: ";
        string fileName;
        cin >> fileName;
        file.open(fileName);
    }
    while (!file.eof())
    {
        double temp;
        file >> temp;
        arr.push_back(temp);
    }
}

// Finds the mode of the array
int findMode(vector<double> arr)
{
    int maxCount = 0, mode = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;

        // Count the number of times the current number appears
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[j] == arr[i])
                count++;

        // If the current number appears more than the current mode, update the mode
        if (count > maxCount)
        {
            maxCount = count;
            mode = arr[i];
        }
    }
    return mode;
}

// Find sum of array
double findSum(vector<double> arr)
{
    double sum = 0;
    for (double i : arr)
        sum += i;
    return sum;
}

int main()
{
    vector<double> arr;

    readData(arr);

    // Sort the array
    sort(arr.begin(), arr.end());
    cout << fixed << setprecision(2) << "Sorted: \n";
    int indent = 1;
    for (double i : arr)
    {
        cout << setw(10) << i << " ";
        if (indent % 5 == 0)
            cout << endl;
        indent++;
    }

    long double count = arr.size(),
                sum = findSum(arr),
                mean = findMean(arr),
                mode = findMode(arr),
                q1 = arr[arr.size() / 4],
                q2 = arr[arr.size() / 2],
                q3 = arr[arr.size() * 3 / 4],
                variance = findVariance(arr, mean),
                standardDeviation = sqrt(variance),
                range = arr[arr.size() - 1] - arr[0],
                interquartileRange = arr[q3] - arr[q1],
                median = (arr.size() % 2 == 0 ? (arr[arr.size() / 2] + arr[(arr.size() / 2) - 1]) / 2 : arr[q2]);

    cout << "\nQ1: " << q1 << "\nQ2: " << q2 << "\nQ3: " << q3 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Mode: ";
    if (mode == 0)
        cout << "No mode" << endl;
    else
        cout << mode << endl;
    cout << "Mean: " << mean << endl;
    cout << setprecision(0) << "Count: " << count << endl;
    cout << setprecision(2) << "Range: " << range << endl;
    cout << "Median: " << median << endl;
    cout << "Variance: " << variance << endl;
    cout << "Standard deviation: " << standardDeviation << endl;
    cout << "Interquartile range: " << interquartileRange << endl;

    return 0;
}