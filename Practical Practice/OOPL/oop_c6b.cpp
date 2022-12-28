/*
Write C++ program using STL for sorting and searching user defined records such
as Item records (Item code, name, cost, quantity etc) using vector container.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class items {
   public:
    int code;
    string name;
    double cost;
    int quantity;

    items(){};

    void create() {
        cout << "Enter Code:";
        cin >> code;
        cout << "Enter name:";
        cin >> name;
        cout << "Enter cost:";
        cin >> cost;
        cout << "Enter quantity:";
        cin >> quantity;
    }
    void display() {
        cout << "Code:" << code;
        cout << " Name:" << name;
        cout << " Cost:" << cost;
        cout << " Quantity:" << quantity << endl;
    }

    bool operator==(int code) {
        if (code == this->code) {
            return true;
        }
        return false;
    }
};

bool compare_items(items obj1, items obj2) { return (obj1.code < obj2.code); }

int main() {
    vector<items> recs;
    items rec;
    int ind = 0;
    int ch, code;
    vector<items>::iterator iter;
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
                sort(recs.begin(), recs.end(), compare_items);
                break;

            case 3:
                cout << "Enter code to find:";
                cin >> code;
                iter = find(recs.begin(), recs.end(), code);
                if (iter == recs.end() && (recs.end()->code != code)) {
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
