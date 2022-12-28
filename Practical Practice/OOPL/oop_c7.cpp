/*
Write a program in C++ to use map associative container. The keys will be the
names of states and the values will be the populations of the states. When the
program runs, the user is prompted to type the name of a state. The program then
looks in the map, using the state name as an index and returns the population of
the state.
*/

#include <iostream>
#include <map>
using namespace std;

class state {
    map<string, long int> state_list;

   public:
    state() {
        state_list["maharashtra"] = 120000000;
        state_list["up"] = 130000000;
        state_list["gujarat"] = 20000000;
        state_list["goa"] = 4000000;
        state_list["delhi"] = 9000000;
    }
    long int get(string s) { return state_list[s]; }
};

int main() {
    state st;
    string str;
    cout << "Enter state:";
    cin >> str;
    long int pop = st.get(str);
    if (pop) {
        cout << pop << endl;
    } else {
        cout << "State record not found" << endl;
    }

    return 0;
}