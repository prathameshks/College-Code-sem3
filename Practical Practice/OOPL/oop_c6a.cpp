/*
Write C++ program using STL for sorting and searching user defined records such
as personal records (Name, DOB, Telephone number etc) using vector container.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class personal {
   public:
    string name;
    string dob;
    string tel_no;

    personal(){};
    personal(string name, string dob, string tel_no) {
        this->name = name;
        this->dob = dob;
        this->tel_no = tel_no;
    }
    void create() {
        cout << "Enter name:";
        cin >> name;
        cout << "Enter dob:";
        cin >> dob;
        cout << "Enter tel_no:";
        cin >> tel_no;
    }
    void display() {
        cout << "Name:" << name;
        cout << "Dob:" << dob;
        cout << "Tel_no:" << tel_no << endl;
    }

    bool operator==(string name) {
        if (name == this->name) {
            return true;
        }
        return false;
    }
};

bool compare_personal(personal obj1, personal obj2) {
    if (obj1.name < obj2.name) {
        return true;
    }
    return false;
}

int main() {
    // personal recs[10];
    vector<personal> recs;
    personal rec;
    int ind = 0;
    string name;
    int ch;
    vector<personal>::iterator iter;
    do {
        cout << "MENU" << endl;
        cout << "1. Add rec" << endl;
        cout << "2. Sort recs" << endl;
        cout << "3. Search recs" << endl;
        cout << "4. Display recs" << endl;
        cout << "0 to exit" << endl;
        cout << "Enter your choice";
        cin >> ch;
        switch (ch) {
            case 1:
                rec.create();
                recs.push_back(rec);
                ind++;
                break;

            case 2:
                sort(recs.begin(), recs.end(), compare_personal);
                break;

            case 3:
                cout << "Enter name to find:";
                cin >> name;
                iter = find(recs.begin(), recs.end(), name);
                if (iter == recs.end() && (recs.end()->name != name)) {
                    cout << "Not found" << endl;
                } else {
                    iter->display();
                }
                break;

            case 4:
                for (int i = 0; i < ind; i++) {
                    recs[i].display();
                }
                break;

            case 0:
                cout << "thanks" << endl;
                break;

            default:
                cout << "Enter a valid Choice" << endl;
                break;
        }

    } while (ch != 0);

    return 0;
}
