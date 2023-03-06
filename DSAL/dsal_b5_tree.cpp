/*A book consists of chapters, chapters consist of sections and sections consist
of subsections. Construct a tree and print the nodes. Find the time and space
requirements of your method. */
#include <iostream>
#include <string>

#define MAX_NUM_OF_CHILD 5

using namespace std;

class node {
   public:
    string data;
    node* child[MAX_NUM_OF_CHILD];
    int size;

    node() {
    	size = 0;
        for (int i = 0; i < MAX_NUM_OF_CHILD; i++) {
            child[i] = NULL;
        }
    }
};

class BookTree {
    node* root = NULL;

    void printTree(node*& curnode, int tab = 0) {
        if (curnode == NULL) return;

        for (int i = 0; i < tab; i++) cout << '\t';
        switch (tab) {
            case 0:
                cout << "Book:";
                break;

            case 1:
                cout << "Chapter:";
                break;

            case 2:
                cout << "Section:";
                break;

            case 3:
                cout << "Subsection:";
                break;
        }
        cout << curnode->data << endl;
        for (int i = 0; i < MAX_NUM_OF_CHILD; i++) {
            printTree(curnode->child[i], tab + 1);
        }
    }

   public:
    BookTree() {
        root = new node;
        cout << "Enter Name of the book:";
        // cin.ignore();
        getline(cin, root->data);
    }

    void insertChap(string chName) {
        if (root->size >= MAX_NUM_OF_CHILD) {
            cout << "Chapter Limit reached can not Add chapter" << endl;
            return;
        } else {
            for (int i = 0; i < root->size; i++) {
                if (chName == root->child[i]->data) {
                    cout << "Chapter Already Exists." << endl;
                    return;
                }
            }
            root->child[root->size] = new node;
            root->child[root->size]->data = chName;
            cout << "Chapter Added Sucessfully" << endl;
            (root->size)++;
        }
    }

    void insertSec(string secName, int chIndex) {
        node* chapter = root->child[chIndex];
        if ((chapter->size) >= MAX_NUM_OF_CHILD) {
            cout << "Section Limit reached for this chapter can not Add section"
                 << endl;
            return;
        } else {
            for (int i = 0; i < chapter->size; i++) {
                if (secName == chapter->child[i]->data) {
                    cout << "Section Already Exists." << endl;
                    return;
                }
            }
            chapter->child[chapter->size] = new node;
            chapter->child[chapter->size]->data = secName;
            cout << "Section Added Sucessfully" << endl;
            (chapter->size)++;
        }
    }

    void insertSubSec(string subSecName, int chIndex, int secIndex) {
        node* chapter = root->child[chIndex];
        if (secIndex >= (chapter->size) || secIndex < 0) {
            cout << "Section not Found, Enter a valid Section index" << endl;
        }
        node* section = chapter->child[secIndex];
        if ((section->size) >= MAX_NUM_OF_CHILD) {
            cout << "Sub Section Limit reached for this Section can not Add "
                    "subsection"
                 << endl;
            return;
        } else {
            for (int i = 0; i < section->size; i++) {
                if (subSecName == section->child[i]->data) {
                    cout << "SubSection Already Exists." << endl;
                    return;
                }
            }
            section->child[section->size] = new node;
            section->child[section->size]->data = subSecName;
            cout << "SubSection Added Sucessfully" << endl;
            (section->size)++;
        }
    }

    int getChapIndex() {
        int chIndex;
        if (root->size <= 0) {
            cout << "No chapters found" << endl;
            return -1;
        }
    retryChindex:
        cout << "Chapters" << endl;
        for (int i = 0; i < root->size; i++) {
            cout << i + 1 << "." << root->child[i]->data << endl;
        }
        cout << "Enter chapter index:";
        cin >> chIndex;
        chIndex--;
        if (chIndex >= (root->size) || chIndex < 0) {
            cout << "Chapter not Found, Enter a valid chapter index" << endl;
            goto retryChindex;
        }
        return chIndex;
    }

    int getSecIndex(int chIndex) {
        int secIndex;
        node* chapter = root->child[chIndex];
        if (chapter->size <= 0) {
            cout << "No Sections found" << endl;
            return -1;
        }
    retrySecindex:
        cout << "Sections" << endl;
        for (int i = 0; i < chapter->size; i++) {
            cout << i + 1 << "." << chapter->child[i]->data << endl;
        }
        cout << "Enter Section index:";
        cin >> secIndex;
        secIndex--;

        if (secIndex >= (chapter->size) || secIndex < 0) {
            cout << "Section not Found, Enter a valid Section index" << endl;
            goto retrySecindex;
        }

        return secIndex;
    }

    void disaply_tree() { printTree(root); }
};

int main() {
    BookTree tree;
    int choice;
    string ChName, secname, subsecname;
    int chindex, secindex;
    do {
        cout << "--: MENU :--" << endl;
        cout << "1. Insert Chapter" << endl;
        cout << "2. Insert Section" << endl;
        cout << "3. Insert Subsection" << endl;
        cout << "4. Display Tree" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter choice:";
        cin >> choice;

        switch (choice) {
            case (1):
                cout << "Enter name of the new chapter:";
                cin.ignore();
                getline(cin, ChName);

                tree.insertChap(ChName);
                break;
            case (2):
                chindex = tree.getChapIndex();
                if (chindex == -1) {
                    break;
                }
                cout << "Enter name of the new Section:";
                cin.ignore();
                getline(cin, secname);
                tree.insertSec(secname, chindex);
                break;
            case (3):
                chindex = tree.getChapIndex();
                if (chindex == -1) {
                    break;
                }
                secindex = tree.getSecIndex(chindex);
                if (secindex == -1) {
                    break;
                }
                cout << "Enter name of the new SubSection:";
                cin.ignore();
                getline(cin, subsecname);
                tree.insertSubSec(subsecname, chindex, secindex);

                break;
            case (4):
                tree.disaply_tree();
                break;
            case (5):
                cout << "Thank you" << endl;
                break;
            default:
                cout << "Enter a valid choice" << endl;
                break;
        }

    } while (choice != 5);

    return 0;
}
