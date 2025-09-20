// comsc-210 | lab6 | Christian Molina 

#include <cstddef>
#include <iostream>
using namespace std;
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric> // I found this one online for accumulation

//the code simulates or tries to simulate a month of daily temperatures, 30 days

constexpr size_t DAYS = 30;

void display(const array<double, DAYS>& temps) {
    cout << "Temperatures: ";

    for (const auto& t : temps) cout << t << " ";
    cout << endl;

}

int main(){
    vector<double> temps; // dynamic array

    array<double, DAYS> temperatures{}; // initialize all to 0.0

    ifstream fin("temp.txt");
    if(!fin){
        cerr << "Error opening file" << endl;
        return 1;
    }
    double value;
    while(fin >> value){
        temps.push_back(value);
        //dynamically add to the vector
    }

    fin.close();

    // demonstrate std array members and algorithms
    cout << "the Vector's size: " << temperatures.size() << endl;
    display(temperatures);

    if (!temps.empty()) {
        cout << "First day's temperature: " << temperatures.front() << endl;
        cout << "Last day's temperature: " << temperatures.back() << endl;
        
        if (temps.size() >= 15)
            cout << "15th day's temperature: " << temps[14] << endl; // direct access to 15th day


        // finding the min and max temperature
        auto minmax = minmax_element(temperatures.begin(), temperatures.end());
        cout << "Minimum temperature: " << *minmax.first << endl;
        cout << "Maximum temperature: " << *minmax.second << endl;

        double avge = accumulate(temperatures.begin(), temperatures.end(), 0.0) / DAYS;
        cout << "The average monthly temperature is: " << avge << endl;

        //sort n display the sorted array
        array<double, DAYS> sorted_temps = temperatures; // copy original array
        sort(sorted_temps.begin(), sorted_temps.end());
        cout << "Sorted temperatures: ";
        for (const auto& t : sorted_temps) cout << t << " ";
        cout << endl;

        array<double, DAYS> cdsnap;// cold snap simulation
        cdsnap.fill(-10.0); // fill with -10.0
        cout << "cold's snap simulation array: ";
        for(const auto& t : cdsnap) cout << t << " ";
        cout << endl;

        //swap the arrays given they are the same size
        cout << "swapping the two arrays now..." << endl;
        sorted_temps.swap(cdsnap);
        cout << "sorted temps after swap: ";
        for (const auto& t : sorted_temps) cout << t << " ";
        cout << endl;

        // check if the array is empty
        cout << "is the array for temperatures empty? " << (temperatures.empty() ? " yes" : " no") << endl;
        cout << "Now a direct access to array data: ";    //pointer directly to the array data
        double* dataPtr = temperatures.data();
        for(size_t i = 0; i < temperatures.size(); ++i)
            cout << *(dataPtr + i) << " ";
        cout << endl;
        }

    return 0;
}