#include <iostream>

using namespace  std;

class Node {
public:
    double value_;
    Node *p_next_node_;
};

class Linked_list {
public:
    bool delete_last_instance( double value );
// Other public member functions,
// constructors, destructors, etc.
    Node *p_list_head_;
};
// Enter your function here

bool Linked_list::delete_last_instance(double value){
    int number = 0;

    Node* ptr = nullptr;

    if (p_list_head_ == nullptr){
        return false;
    }

    ptr = p_list_head_;


    while (ptr != nullptr){
        if (ptr->value_ == value){
            number ++;
        }
        ptr = ptr->p_next_node_;
    }

    if (number == 0){
        return false;
    }
    if (number == 1 && p_list_head_->value_ == value){

        Node* temp = p_list_head_;
        p_list_head_= p_list_head_->p_next_node_;
        temp->p_next_node_ = nullptr;
        delete temp;
        temp = nullptr;
        return true;
    }

    Node* prevptr = p_list_head_;
    ptr = p_list_head_->p_next_node_;
    int cur = 0;
    if (prevptr->value_ == value){
        cur ++;
    }


    while (cur < number){
        ptr = ptr->p_next_node_;
        prevptr = prevptr->p_next_node_;
        if (ptr->value_== value){
            cur ++;
        }

    }


    Node* temp = ptr;
    cout<<(prevptr->value_)<<endl;
    prevptr->p_next_node_ = prevptr->p_next_node_->p_next_node_;
    cout<<(temp->value_)<<endl;

    delete temp;
    temp = nullptr;


    return true;
}

int main(){
    Node* p_head = new Node{4,nullptr};
    double val[9]{5,2,4,4,3,0,4,1,2};

    Node* ptr = p_head;
    for (int i = 0; i <9; i++){
        ptr->p_next_node_ = new Node{val[i], nullptr};
        ptr = ptr->p_next_node_;
    }

    Linked_list* ll = new Linked_list{p_head};

    Node* cur = ll->p_list_head_;

    while ( cur != nullptr){
        cout<<cur->value_<<" ";
        cur = cur->p_next_node_;
    }
    cout<<endl;
    ll->delete_last_instance(4);

    cur = ll->p_list_head_;

    for(int  i= 0; i < 9; i ++){
        cout<<cur->value_<<" ";
        cur = cur->p_next_node_;

    }

    return 0;
}
