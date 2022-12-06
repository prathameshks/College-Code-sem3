#include <iomanip>
#include <iostream>
using namespace std;

class item;
class orderQueue;

// Global menu items list
int total_count = 0;
int order_number = 0;
item *product_list[20];

class item {
   public:
    int id;
    string name;
    double price;
    int stock;

    item() {}

    item(string name, double price, int stock);
    ~item();
    bool buyProduct(int quantity) {
        if (quantity > stock) {
            return false;
        }
        stock -= quantity;
        return true;
    }
    void addStock(int addCount) { stock += addCount; }
};

item::item(string name, double price, int stock) {
    product_list[total_count] = this;
    total_count++;
    id = total_count;
    this->name = name;
    this->price = price;
    this->stock = stock;
}
item::~item() {
    product_list[id - 1] = product_list[total_count - 1];
    total_count--;
}

class order {
   public:
    int orderId;
    item *data[5];
    order *next = NULL;
    order() { orderId = ++order_number; }
};

class orderQueue {
   public:
    order *start = NULL;
    order *end = NULL;

    void addOrder(order *data) {
        if (end == NULL) {
            start = data;
            end = start;
        } else {
            end->next = data;
            end = data;
        }
    }

    order *pop() {
        order *process_order = start;
        start = start->next;
        return process_order;
    }

    bool deleteOrder(int orderid) {
        if (start->orderId == orderid) {
            pop();
            return true;
        } else {
            order *temp = start;
            order *prev = start;
            temp = temp->next;
            while (temp != NULL) {
                if (temp->orderId == orderid) {
                    prev->next = temp->next;
                    delete temp;
                    return true;
                }
                temp = temp->next;
                prev = prev->next;
            }
        }
        return false;
    }
};

//global manager
orderQueue manager;

void print_center(string str, int width = 50, char end = '\n',
                  char fill = ' ') {
    int len = str.size();
    cout << setfill(fill);
    if (len >= width) {
        cout << str << end;
    } else {
        int fact = width - len;
        if (fact % 2) {
            cout << setw(fact / 2) << fill << str << setw(fact / 2 + 1) << fill
                 << end;
        } else {
            cout << setw(fact / 2) << fill << str << setw(fact / 2) << fill
                 << end;
        }
    }
}

template <class i = int, class s = string, class d = double>
void row_print(i id, s name, d price, i stock, char sep = '|',
               char fillChar = ' ') {
    cout << setfill(fillChar);
    cout << sep << setw(7) << right << id << sep;
    cout << setw(25) << left << name << sep;
    cout << setw(7) << left << setprecision(2) << price << sep;
    cout << setw(6) << stock << sep << endl;
}

void page_title(string str) {
    system("cls");
    print_center("CAFE MANAGEMENT SYSTEM");
    cout << endl;
    print_center(str);
    cout << endl << endl;
}

// display all data
void show_menu() {
    row_print<char, char, char>('-', '-', '-', '-', '+', '-');
    row_print<string, string, string>("ID", "Product", "Price", "Stock");
    row_print<char, char, char>('-', '-', '-', '-', '+', '-');

    for (int i = 0; i < total_count; i++) {
        row_print(product_list[i]->id, product_list[i]->name,
                  product_list[i]->price, product_list[i]->stock);
    }

    row_print<char, char, char>('-', '-', '-', '-', '+', '-');
}

int findProduct(int item_id) {
    for (int i = 0; i < total_count; i++) {
        if (product_list[i]->id == item_id) {
            return i;
        }
    }
    return -1;
}
int getProductQuantity(int item_id) {
    for (int i = 0; i < total_count; i++) {
        if (product_list[i]->id == item_id) {
            return product_list[i]->stock;
        }
    }
    return 0;
}

void takeOrder() {
    show_menu();
    int num_of_items, item_id, item_quantity, stock, item_index;
    cout << "Enter number of items you want to add(max 5):";
    cin >> num_of_items;
    order custm_order;
    for (int i = 0; i < num_of_items && i < 5; i++) {
    retry_take_order:
        cout << "enter id";
        cin >> item_id;
        item_index = findProduct(item_id);
        if (item_index == -1) {
            cout << "Enter a valid Item ID" << endl;
            goto retry_take_order;
        }
        stock = getProductQuantity(item_id);
    retry_item_quantity:
        cout << "enter quantity";
        cin >> item_quantity;
        if (stock < item_quantity) {
            cout << "Stock not Available" << endl;
            cout << "Available stock " << stock << endl;
            goto retry_item_quantity;
        }
        if (product_list[item_index]->buyProduct(item_quantity)) {
            custm_order.data[i] = product_list[item_index];
        } else {
            cout << "Failed to add item";
        }
    }
    manager.addOrder(&custm_order);
    cout << "Order sucessfull" << endl;
    cout << "Order number is " << custm_order.orderId << endl;
}

void manage_stock() {
    char choice;
    string p_name;
    int p_stock,p_id;
    double p_price;
    int p_index;
    do {
        page_title("STOCK MANAGEMENT");
        show_menu();
        cout << setw(15) << " "
             << "(1) Add Product" << endl;
        cout << setw(15) << " "
             << "(2) Add stock" << endl;
        cout << setw(15) << " "
             << "(3) Delete Product" << endl;
        cout << setw(15) << " "
             << "(4) Exit Management" << endl;

        cout << endl;
        cout << setw(30) << "Enter Your Choice :";
        cin >> choice;

        switch (choice) {
            case '1':
                if (total_count == 20) {
                    cout << "Not enough space in store" << endl;
                } else {
                    cout << "Enter product name:";
                    cin >> p_name;

                    cout << "Enter product price:";
                    cin >> p_price;
                    cout << "Enter product stock:";
                    cin >> p_stock;

                    item *newProduct = new item(p_name, p_price, p_stock);
                    cout << "Product added sucessfully" << endl;
                }

                system("pause");
                break;

            case '2':
                cin>>p_id;
                p_index = findProduct(p_id);

                if (p_index != -1)
                {
                    cout<<"How much new stock has arrived?:";
                    cin>>p_stock;
                    product_list[p_index]->addStock(p_stock);
                    cout<<"Stock updated sucessfully"<<endl;
                }
                else
                {
                    cout<<"No such product present"<<endl;
                }
                
                system("pause");
                break;

            case '3':
                cin>>p_id;
                p_index = findProduct(p_id);

                if (p_index != -1)
                {
                    delete product_list[p_index];
                    cout<<"Stock Deleted sucessfully"<<endl;
                }
                else
                {
                    cout<<"No such product present"<<endl;
                }
                
                system("pause");
                break;

            case '4':

                // system("pause");
                break;

            default:

                break;
        }
    } while (choice != '4');
}

// Main Program
int main() {
    char choice;
    do {
        page_title("MANAGEMENT MENU");
        cout << setw(15) << " "
             << "(1) Show Menu" << endl;
        cout << setw(15) << " "
             << "(2) Take Order" << endl;
        cout << setw(15) << " "
             << "(3) Process Order" << endl;
        cout << setw(15) << " "
             << "(4) Cancel an Order" << endl;
        cout << setw(15) << " "
             << "(5) Manage Stock" << endl;
        cout << setw(15) << " "
             << "(6) Exit App" << endl;

        cout << endl;
        cout << setw(30) << "Enter Your Choice :";
        cin >> choice;

        switch (choice) {
            case '1':
                page_title("PRODUCT MENU");
                show_menu();
                system("pause");
                break;

            case '2':
                takeOrder();
                system("pause");
                break;

            case '3':

                system("pause");
                break;

            case '4':

                system("pause");
                break;

            case '5':
                manage_stock();
                system("pause");
                break;

            case '6':

                system("pause");
                break;

            default:

                break;
        }
    } while (choice != '6');
    return 0;
}
