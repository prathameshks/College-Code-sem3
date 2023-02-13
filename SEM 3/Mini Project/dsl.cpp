#include <iomanip>
#include <iostream>
using namespace std;

// for using terminal claer and pause
#ifdef _WIN32
bool windows = true;
#else
bool windows = false;
#endif  // _WIN32

void clear() {
    if (windows)
        system("cls");
    else
        system("clear");
}
void wait() {
    char s;
    if (windows) {
        system("pause");
    } else {
        s = getchar();
        cin.ignore();
    }
}

class item;
class orderQueue;
template <class i = int, class s = string, class d = double>
void row_print(i id, s name, d price, i stock, char sep = '|',
               char fillChar = ' ') {
    cout << setfill(fillChar);
    cout << sep << setw(7) << right << id << sep;
    cout << setw(25) << left << name << sep;
    cout << setw(7) << left << setprecision(2) << price << sep;
    cout << setw(6) << stock << sep << endl;
    cout << right << setfill(' ');
}

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
    item *data[5]{NULL, NULL, NULL, NULL, NULL};
    int quantity[5] = {0};
    order *next = NULL;
    string cust_name;
    double total;
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

    bool isEmpty() { return (start == NULL) ? true : false; }

    order *pop() {
        if (start == NULL) {
            return NULL;
        }
        order *process_order = start;
        if (start == end) {
            start = end = NULL;
            return process_order;
        }

        start = start->next;
        return process_order;
    }

    bool deleteOrder(int orderid) {
        if (start == NULL) {
            return false;
        }

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

    order *getOrder(int orderid) {
        order *temp = start;
        while (temp != NULL) {
            if (temp->orderId == orderid) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void showAllOrders() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        order *temp = start;
        int sum = 0;
        row_print<char, char, char>('-', '-', '-', '-', '+', '-');
        row_print<string, string, string>("ID", "Name", "Total", "Itm Cnt");
        row_print<char, char, char>('-', '-', '-', '-', '+', '-');
        while (temp != NULL) {
            sum = 0;
            for (int i = 0; i < 5; i++) {
                sum += temp->quantity[i];
            }
            row_print<int, string, double>(temp->orderId, temp->cust_name,
                                           temp->total, sum);
            temp = temp->next;
        }
        row_print<char, char, char>('-', '-', '-', '-', '+', '-');
        cout << endl;
    }
};

// global manager
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

void page_title(string str) {
    clear();
    print_center("CAFE MANAGEMENT SYSTEM");
    cout << endl;
    print_center(str);
    cout << endl << endl;
}

// display all data
void show_menu() {
    if (total_count == 0) {
        cout << "Menu Is Empty" << endl;
        return;
    }

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
void showBill(order *ord) {
    cout << setfill('-') << setw(50) << '-' << endl << endl;
    print_center("BILL");
    cout << "Order Number: " << ord->orderId << endl;
    cout << "Customer Name : " << ord->cust_name << endl;
    int i = 0;
    row_print<char, char, char>('-', '-', '-', '-', '+', '-');
    row_print<string, string, string>("ID", "Product", "Price", "Qty");
    row_print<char, char, char>('-', '-', '-', '-', '+', '-');
    while (ord->data[i] != NULL && i < 5) {
        row_print(ord->data[i]->id, ord->data[i]->name, ord->data[i]->price,
                  ord->quantity[i]);
        i++;
    }
    row_print<char, char, char>('-', '-', '-', '-', '+', '-');
    cout << "Total Bill is :" << fixed << ord->total << endl;
    print_center("END");
    cout << setfill('-') << setw(50) << '-' << endl;
}

void generateBill(int order_id) {
    // page_title("BILL GENERATOR");
    order *order_details = manager.getOrder(order_id);
    if (order_details == NULL) {
        cout << "No Such Order present" << endl;
        return;
    }

    int i = 0;
    double totalAmt = 0;
    while (order_details->data[i] != NULL && i < 5) {
        totalAmt += order_details->quantity[i] * order_details->data[i]->price;
        i++;
    }

    order_details->total = totalAmt;
    showBill(order_details);
}

void takeOrder() {
    if (total_count == 0) {
        cout << "Menu Is Empty" << endl;
        return;
    }

    string c_name;
    show_menu();
    int num_of_items, item_id, item_quantity, stock, item_index;
    cout << "Enter name of Customer:";
    cin >> c_name;
    order *custm_order = new order;
    custm_order->cust_name = c_name;
    cout << "Enter number of items you want to add(max 5):";
    cin >> num_of_items;
    for (int i = 0; i < num_of_items && i < 5; i++) {
    retry_take_order:
        cout << "Enter item id to buy";
        cin >> item_id;
        item_index = findProduct(item_id);
        if (item_index == -1) {
            cout << "Enter a valid Item ID" << endl;
            goto retry_take_order;
        }
        stock = getProductQuantity(item_id);
    retry_item_quantity:
        cout << "Enter Quantity you Want to buy:";
        cin >> item_quantity;
        if (stock < item_quantity) {
            cout << "Sorry, Stock not Available" << endl;
            cout << "Available stock is " << stock << endl;
            goto retry_item_quantity;
        }
        if (product_list[item_index]->buyProduct(item_quantity)) {
            custm_order->data[i] = product_list[item_index];
            custm_order->quantity[i] = item_quantity;
        } else {
            cout << "Failed to add item";
        }
        cout << endl;
    }
    manager.addOrder(custm_order);
    cout << "Order sucessfull" << endl;
    cout << "Order number is " << custm_order->orderId << endl;
    generateBill(custm_order->orderId);
}

void manage_stock() {
    char choice;
    string p_name;
    int p_stock, p_id;
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

                wait();
                break;

            case '2':
                cout << "Enter Product Id:" << endl;
                cin >> p_id;
                p_index = findProduct(p_id);

                if (p_index != -1) {
                    cout << "How much new stock has arrived?:";
                    cin >> p_stock;
                    product_list[p_index]->addStock(p_stock);
                    cout << "Stock updated sucessfully" << endl;
                } else {
                    cout << "No such product present" << endl;
                }

                wait();
                break;

            case '3':
                cout << "Enter Product Id:" << endl;
                cin >> p_id;
                p_index = findProduct(p_id);

                if (p_index != -1) {
                    delete product_list[p_index];
                    cout << "Stock Deleted sucessfully" << endl;
                } else {
                    cout << "No such product present" << endl;
                }

                wait();
                break;
        }
    } while (choice != '4');
}

void processOrder() {
    order *processed = manager.pop();
    if (processed == NULL) {
        cout << "Order queue is Empty" << endl;
        return;
    }

    cout << "Order Processed with ID " << processed->orderId << endl;
    showBill(processed);
}

void deleteOrder() {
    page_title("DELETE AN ORDER");
    int order_id;
    manager.showAllOrders();
    if (manager.isEmpty()) {
        return;
    }
    cout << "-- Enter 0 to cancel --" << endl;
    cout << "Enter order id:";
    cin >> order_id;
    if (order_id == 0) {
        cout << "Operation Cancled" << endl;
        return;
    }

    bool status = manager.deleteOrder(order_id);
    if (status) {
        cout << "Order deleted Sucessfully" << endl;
    } else {
        cout << "Order Not Found" << endl;
    }
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
             << "(4) Show All Orders" << endl;
        cout << setw(15) << " "
             << "(5) Delete an Order" << endl;
        cout << setw(15) << " "
             << "(6) Manage Stock" << endl;
        cout << setw(15) << " "
             << "(7) Exit App" << endl;

        cout << endl;
        cout << setw(30) << "Enter Your Choice :";
        cin >> choice;

        switch (choice) {
            case '1':
                page_title("PRODUCT MENU");
                show_menu();
                wait();
                break;

            case '2':
                takeOrder();
                wait();
                break;

            case '3':
                processOrder();
                wait();
                break;

            case '4':
                manager.showAllOrders();
                wait();
                break;

            case '5':
                deleteOrder();
                wait();
                break;

            case '6':
                manage_stock();
                wait();
                break;
        }
    } while (choice != '7');
    page_title("Thank You For Using App");
    return 0;
}

/*
5 1 coffee 25 60


*/