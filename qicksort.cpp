#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;
using namespace std::chrono;

void randomArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % n;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    fstream file;
    file.open("experiment.txt", ios_base::app);
    srand(time(0));
    int n = 10000;

    vector<int> time;

    for (int i = 0; i < 30; i++)
    {

        int count = 0;
        int *arr = new int[n];
        randomArr(arr, n);
        // printArray(arr, n);

        // Get starting timepoint
        auto start = high_resolution_clock::now();
        insertionSort(arr, n);
        // Get ending timepoint
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        // printArray(arr, n);
        // cout << "Time taken by function: "
        //      << duration.count() << " microseconds" << endl;
        // cout << count << endl;

        time.push_back(duration.count());

        file << duration.count() << " ";
    }
    file << endl;
    file.close();

    // calculate mean +- std to result.txt

    double sum = accumulate(time.begin(), time.end(), 0.0);
    double mean = sum / time.size();

    double sq_sum = inner_product(time.begin(), time.end(), time.begin(), 0.0);
    double stdev = sqrt(sq_sum / time.size() - mean * mean);

    file.open("result.txt", ios_base::app);
    file << "time = " << mean << "+-" << stdev << endl;
    return 0;
}