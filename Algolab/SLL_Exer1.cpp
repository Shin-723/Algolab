#include<iostream>
#include<iomanip>

using namespace std;

class Node{
    private:
        int data;
        Node*next;
        Node(int value){
            data=value;
            next=0;
        }
        friend class List;
};
class List{
    private:
        Node*head;
    public:
    List(){
        head =0;
    }
    void insert(int);
    void append(int);
    void display();
};
void List::insert(int data){
    Node*temp=new Node(data);
    if(head!=0){
        temp->next=head;
        head=temp;
    }
    else head=temp;
}
void List::append(int data){
    Node*temp=new Node(data);
    temp->data=data;
    temp->next=0;
    if(head==0) head=temp;
    else{
        Node*ptr=head;
        while(ptr->next !=0){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void List::display(){
    Node*ptr;
    ptr=head;
    while(ptr){
        cout <<" "<<ptr->data;
        ptr=ptr->next;
    }
    cout<<endl;
}
int main(){
    List l1;
    l1.insert(30);
    l1.insert(40);
    l1.display();
    l1.append(11);
    l1.display();
    return 0;
}