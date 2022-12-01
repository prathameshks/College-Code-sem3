/*Write C++ program using STL for sorting and searching user defined records
 * such as Item records (Item code, name, cost, quantity etc) using vector
 * container.*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct item {
    int code;
    string name;
    double cost;
    int quantity;
    bool operator==(const item &i2) { return code == i2.code; }
};

// global record list
vector<item> product_rec;
int sort_basis;

bool compare(item obj1, item obj2) {
    bool result;
    switch (sort_basis) {
        case 1:
            result = obj1.code < obj2.code;
            break;
        case 2:
            result = obj1.name < obj2.name;
            break;
        case 3:
            result = obj1.cost < obj2.cost;
            break;
        case 4:
            result = obj1.quantity < obj2.quantity;
            break;
        default:
            result = obj1.code < obj2.code;
            break;
    }
    return result;
}

void insert_record() {
    struct item i1;
    cout << "Enter Product Code:";
    cin >> i1.code;
    cout << "Enter Product Name:";
    cin.ignore();
    getline(cin, i1.name);
    cout << "Enter Product cost:";
    cin >> i1.cost;
    cout << "Enter Product quantity:";
    cin >> i1.quantity;
    product_rec.push_back(i1);
    cout << "Record Inserted sucessfully" << endl;
}

void print_item(item i) {
    cout << "Product Code is " << i.code << endl;
    cout << "Product Name is " << i.name << endl;
    cout << "Product cost is " << i.cost << endl;
    cout << "Product quantity is " << i.quantity << endl;
}

void display() {
    cout << setw(5) << "Code "
         << " " << setw(15) << "Name "
         << " " << setw(7) << "Cost "
         << " " << setw(5) << "Quantity " << endl;
    for (int i = 0; i < product_rec.size(); i++) {
        cout << setw(5) << left << product_rec[i].code << " ";
        cout << setw(15) << product_rec[i].name.substr(0, 15) << " ";
        cout << setw(7) << product_rec[i].cost << " ";
        cout << setw(5) << product_rec[i].quantity << endl;
    }
}

void sort_product() {
    cout << "Sort by 1. Code 2. Name 3.Cost 4.Quantity" << endl;
    cout << "Enter your choice:";
    cin >> sort_basis;
    sort(product_rec.begin(), product_rec.end(), compare);
    cout << "\nSorted Products are:" << endl;
    display();
    cout << endl;
}

void search_product() {
    item i1;
    cout << "Enter Product Code to search:";
    cin >> i1.code;

    vector<item>::iterator ans =
        find(product_rec.begin(), product_rec.end(), i1);
    if (ans == product_rec.end() && !(i1 == *ans)) {
        cout << "Product Not Found" << endl;
    } else {
        cout << "Product details are" << endl;
        print_item(*ans);
    }
}

int main() {
    int ch;

    do {
        cout << "--: MENU :--" << endl;
        cout << "1. Insert Record" << endl;
        cout << "2. Sort Records" << endl;
        cout << "3. Search Record" << endl;
        cout << "4. Display All Records" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Your choice:";
        cin >> ch;
        switch (ch) {
            case 1:
                insert_record();
                break;
            case 2:
                sort_product();
                break;
            case 3:
                search_product();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Thank you for using App" << endl;
                break;
            default:
                cout << "Enter a valid choice" << endl;
                break;
        }
    } while (ch != 5);
    return 0;
}
