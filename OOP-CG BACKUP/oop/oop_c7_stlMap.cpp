/*Write a program in C++ to use map associative container. The keys will be the
names of states and the values will be the populations of the states. When the
program runs, the user is prompted to type the name of a state. The program then
looks in the map, using the state name as an index and returns the population of
the state.*/

#include <iostream>
#include <map>
using namespace std;

class stateList {
    map<string, int> list;

   public:
    stateList() {
        list["maharashtra"] = 124000000;
        list["delhi"] = 20000000;
        list["goa"] = 1000000;
        list["gujarat"] = 69788000;
        list["karnataka"] = 80000000;
        list["kerala"] = 35000000;
        list["madhya pradesh"] = 84516000;
        list["punjab"] = 30339000;
        list["rajasthan"] = 8000000;
        list["tamil nadu"] = 10000000;
        list["telangana"] = 30000000;
        list["uttar pradesh"] = 230000000;
    }

    int getPopulation(string state) { return list[state]; }

    void displayAll() {
        cout << "All states data available is" << endl;
        for (pair<string, int> state : list) {
            cout << state.first << " - " << state.second << endl;
        }
    }
};

int main() {
    string str;
    int population;

    stateList database;
    retry: //retry block start point
    cout << "Enter state name(0 for all)" << endl;
    cin >> str;
    if (str == "0") {
        database.displayAll();
    } else {
        population = database.getPopulation(str);
        if (population == 0) {
            cout << "No such state is present, Please Try Again" << endl;
            goto retry;
        } else {
            cout << "Population of " << str << " is " << population << endl;
        }
    }

    cout << "Thank you" << endl;
    return 0;
}
