#include <iostream>

using namespace std;


class Node{
public:
    Node(int val, Node* next);
    ~Node();
    int getVal();
    Node* getNext();
    void setNext(Node* next);
    void setVal(int val);
private:
    Node* next=nullptr;
    int val=0;
};
Node::Node(int val, Node* next){
    this->val = val;
    this->next = next;
}
Node::~Node(){
    next = nullptr;
}
int Node::getVal(){
    return val;
}
Node* Node::getNext(){
    return next;
}
void Node::setNext(Node* next){
    this->next = next;
}
void Node::setVal(int val){
    this->val = val;
}

class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    //LinkedList(int* input);
    void addEnd(Node* node);
    void addFront(Node* node);
    void print();
    int getLen();
    Node* getHead();
    Node* getTail();

private:
    Node* p_head = nullptr;
    int len = 0 ;
    Node* p_tail = nullptr;
};
LinkedList::LinkedList(){
    p_head = nullptr;
}
LinkedList::~LinkedList(){
    if (p_head == nullptr){
        return;
    }

    Node* cur = p_head;
    Node* next = p_head->getNext();
    if (cur != nullptr){
        delete cur;
    }
    while (next != nullptr){
        cur = next;
        next = next->getNext();
        delete cur;
        cur = nullptr;
    }
    if (cur != nullptr){
        delete cur;
    }
    cur = nullptr;
    next = nullptr;
}
void LinkedList::addEnd(Node* node){
    if (p_tail == nullptr){
        addFront(node);
        return;
    }

    p_tail->setNext(node);
    p_tail = p_tail->getNext();
    len ++;
}
void LinkedList::addFront(Node* node){
    p_head = new Node(node->getVal(), p_head);
    if (p_head->getNext() == nullptr){
        p_tail = p_head;
    }
    len ++;
}
void LinkedList::print(){
    Node* ptr = p_head;
    std::cout<<"[";
    while(ptr != nullptr){
        std::cout<<(ptr->getVal())<<" ";
        ptr = ptr->getNext();
    }
    std::cout<<"] with length "<< len <<std::endl;
    ptr = nullptr;
}
int LinkedList::getLen(){
    return len;
}
Node* LinkedList::getHead(){
    return p_head;
}
Node* LinkedList::getTail(){
    return p_tail;
}

int main(){
    LinkedList* ll = new LinkedList();
    for (int i = 1; i < 10; i ++){

        ll->addEnd(new Node(i, nullptr));
    }
    ll->print();
    ll->addFront(new Node(0, nullptr));
    ll->print();
    delete ll;
    return 0;
}
