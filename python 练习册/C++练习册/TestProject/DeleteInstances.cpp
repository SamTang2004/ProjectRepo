#include "LinkedList.hpp" // This imports the linkedlist
#ifndef MARMOSET_TESTING
int main();
#endif
void LinkedList::delete_insts(int num)
{
// Your Code Here
    if (p_head == nullptr){
        return;
    }


    Node* head = get_head();

    Node* cur = head;
    Node* next = head->get_next();

    if (next == nullptr){
        if (cur->get_value() == num){
            delete cur;
            return;
        }
        return;
    }

    while(next != nullptr){
        if (next->get_value() == num){
            Node* tmp = next;
            cur->set_next(next->get_next());
            next = next->get_next();
            delete tmp;
        }else{
        cur = cur->get_next();
        next = next->get_next();
        }

    }


    if (p_head->get_value()== num){
        Node* tmp = p_head;
        p_head = p_head->get_next();
        delete tmp;
    }


}
#ifndef MARMOSET_TESTING
int main()
{
// Test your code here
return 0;
}
#endif
