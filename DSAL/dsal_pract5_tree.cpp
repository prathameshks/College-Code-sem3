#include<iostream>
#include<string>

#define MAX_NUM_OF_CHILD 5

using namespace std;

class node{
    public:
    string data;
    node* child[MAX_NUM_OF_CHILD];

    node(){
        for(node* i:child){
            i=NULL;
        }
    } 
};


class BookTree{
    node* root= NULL;
    public:
        BookTree(){
            root = new node;
            cout<<"Enter Name of the book:";
            cin>>root->data;
        }
        
        void insert_section(){
            string sec;
            int i = 0;
            cout<<"Enter name of the section:";
            cin>>sec;
            int insert = 0;
            for(i = 0;i < MAX_NUM_OF_CHILD; i++){
                if (root->child[i] == NULL){
                    insert = 1;
                    break;
                }else if(root->child[i]->data == sec){
                    insert = 0;
                    break;
                }else if(i == (MAX_NUM_OF_CHILD-1)){
                    insert = 2;
                }
            }
            if(insert == 0){
                cout<<"Section "<<sec<<" Already Exists"<<endl;
            }else if(insert == 1){
                root->child[i] = new node();
                root->child[i]->data = sec;
                cout<<"Section "<<sec<<" Added"<<endl;
            }else{
                cout<<"Section Limit Reached"<<endl;
            }
        }
        
        void insert_subsection(){
            string subsec;
            int sec_no = 0;
            while(sec_no < MAX_NUM_OF_CHILD){
                if(root->child[sec_no] == NULL){
                    break;
                }else{
                    cout<<"\tSection "<<sec_no+1<<":"<< root->child[sec_no]->data <<endl;
                }
                sec_no++;
            }
            cout<<"In which section you want to add subsection:";
            cin>>sec_no;
            sec_no--;
            
            int insert = 0;
            for(i = 0;i < MAX_NUM_OF_CHILD; i++){
                if (root->child[i] == NULL){
                    insert = 1;
                    break;
                }else if(root->child[i]->data == sec){
                    insert = 0;
                    break;
                }else if(i == (MAX_NUM_OF_CHILD-1)){
                    insert = 2;
                }
            }
            if(insert == 0){
                cout<<"Section "<<sec<<" Already Exists"<<endl;
            }else if(insert == 1){
                root->child[i] = new node();
                root->child[i]->data = sec;
                cout<<"Section "<<sec<<" Added"<<endl;
            }else{
                cout<<"Section Limit Reached"<<endl;
            }
        }
        
        void disaply_tree(){
            cout << "Book:" << root->data << endl;
            int sec_no = 0;
            while(sec_no < MAX_NUM_OF_CHILD){
                if(root->child[sec_no] == NULL){
                    break;
                }else{
                    cout<<"\tSection "<<sec_no+1<<":"<< root->child[sec_no]->data <<endl;
                    int subsec_no = 0;
                    while(sec_no < MAX_NUM_OF_CHILD){
                        if(root->child[sec_no]->child[subsec_no] == NULL){
                            break;
                        }else{
                            cout<<"\t\tSubsection "<<subsec_no+1<<":"<< root->child[sec_no]->child[subsec_no]->data <<endl;
                        }
                        subsec_no++;
                    }
                }
                sec_no++;
            }
        }
};




int main(){
    BookTree tree;
    int choice;
    do{
        cout<<"--: MENU :--"<<endl;
        cout<<"1. Insert Section"<<endl;
        cout<<"2. Insert Subsection"<<endl;
        cout<<"3. Display Tree"<<endl;
        cout<<"4. Quit"<<endl;
        cout<<"Enter choice:";
        cin>>choice;
        
        switch(choice){
            case(1):
                tree.insert_section();
                break;
            case(2):
                break;
            case(3):
                tree.disaply_tree();
                break;
            case(4):
                cout<<"Thank you"<<endl;
                break;
            default:
                cout<<"Enter a valid choice"<<endl;
                break;            
        }
        
    }while(choice != 4);
    
    return 0;
}






