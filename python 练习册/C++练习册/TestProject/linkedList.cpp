#include <iostream>

class node{
private:
    double val = 0;
    node* next = nullptr;
public:
    node(double val){
        this->val = val;
    }

    node* get_next(){
        return next;
    }
    double get_val(){
        return val;
    }
    void set_next(node* next){
        this->next = next;
    }
};
std::ostream& operator<<(std::ostream& out, node* head){


    node* p_tmp = new node(head->get_val());
    p_tmp->set_next(head->get_next());
    while (p_tmp != nullptr){
        out << p_tmp->get_val() << " -> ";
        p_tmp = p_tmp->get_next();
    }
    return out;
}


int main(){

    node* head = new node(1);
    node* cur = head;
    for (int i = 0; i < 10; i++){
        cur->set_next(new node(std::rand()));
        cur = cur->get_next();
    }
        std::cout<<head<<std::endl;

    // sorting


    std::cout<<head<<std::endl;
    return 0;
}
