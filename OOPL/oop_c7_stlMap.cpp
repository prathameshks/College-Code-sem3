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
        list["andaman nicobar"] = 400000;
        list["andhra pradesh"] = 52787000;
        list["arunachal pradesh"] = 1533000;
        list["assam"] = 35043000;
        list["bihar"] = 123083000;
        list["chandigarh"] = 1208000;
        list["chhatisgarh"] = 29493000;
        list["dadra nagar haveli and daman & diu"] = 1078000;
        list["delhi"] = 20571000;
        list["goa"] = 1559000;
        list["gujarat"] = 69788000;
        list["haryana"] = 29483000;
        list["himachal pradesh"] = 7394000;
        list["jammu kashmir"] = 13408000;
        list["jharkhand"] = 38471000;
        list["karnataka"] = 66845000;
        list["kerala"] = 35489000;
        list["ladakh"] = 297000;
        list["lakshadweep"] = 68000;
        list["madhya pradesh"] = 84516000;
        list["maharashtra"] = 124437000;
        list["manipur"] = 3165000;
        list["meghalaya"] = 3288000;
        list["mizoram"] = 1216000;
        list["nagaland"] = 2192000;
        list["odisha"] = 44033000;
        list["puducherry"] = 1572000;
        list["punjab"] = 30339000;
        list["rajasthan"] = 79281000;
        list["sikkim"] = 677000;
        list["tamil nadu"] = 76402000;
        list["telangana"] = 37725000;
        list["tripura"] = 4071000;
        list["uttar pradesh"] = 230907000;
        list["uttarakhand"] = 11399000;
        list["west bengal"] = 98125000;
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
