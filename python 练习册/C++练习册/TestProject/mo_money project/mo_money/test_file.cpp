#include <cassert>
#include <iomanip>
#include <iostream>

#include "History.hpp"
#include "Transaction.hpp"
#include <iostream>

#ifndef MARMOSET_TESTING
unsigned int Transaction::assigned_trans_id = 0;
int main() {
  History trans_history{};
  trans_history.read_history();
  std::cout << "[Starting history]:" << std::endl;
  trans_history.print();
  trans_history.sort_by_date();

  std::cout << "[Sorted          ]:" << std::endl;
  trans_history.print();

  trans_history.update_acb_cgl();
  trans_history.print();
  std::cout << "[CGL for 2018    ]: " << trans_history.compute_cgl(2018) << std::endl;
  std::cout << "[CGL for 2019    ]: " << trans_history.compute_cgl(2019) << std::endl;

  Transaction* trans = new Transaction("NULL",0,0,0,0,0,0);
  trans_history.insert(trans);
  delete trans;
  trans = nullptr;
  return 0;
}
#endif
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


namespace ece150 {
// File and string parsing
std::ifstream file{};
std::string content{};
std::istringstream input{};
std::string current_entry{};

// Ticker symbol.
std::string symbol{};

// Date fields.
unsigned int day{};
unsigned int month{};
unsigned int year{};

// Transaction type, shares and amount.
std::string buysell{};
unsigned int shares{};
double amount{};


////////////////////
// File functions //
////////////////////

// Open the file for reading
void open_file() {
  // If the file is already open, close it
  //  - this is just in case the file changed since the last opening
  if (file.is_open()) {
    file.close();
  }

  // Open the file and set the character position to zero
  file.open("transaction_history.txt");

  // If the file did not open, indicate an error occurred.
  if (!file.is_open()) {
    std::cerr << "[ERROR]: transaction_history.txt not found" << std::endl;
  }

  // Assign to the string the 'content' the contents of the file
  content = std::string(std::istreambuf_iterator<char>(file),
                        std::istreambuf_iterator<char>());

  input.str(content);
}

void close_file() { file.close(); }

// Moves to the next transaction entry.
bool next_trans_entry() {
  std::getline(input, current_entry);
  std::stringstream ss(current_entry);
  ss.precision(2);

  if (!ss.str().empty()) {
    ss >> symbol >> day >> month >> year >> buysell >> shares >> amount;
    return true;
  } else {
    return false;
  }
}

// Functions to access the parsed fields.
std::string get_trans_symbol() { return symbol; }

unsigned int get_trans_day() { return day; }

unsigned int get_trans_month() { return month; }

unsigned int get_trans_year() { return year; }

unsigned int get_trans_shares() { return shares; }

double get_trans_amount() { return amount; }

bool get_trans_type() { return (buysell == "Buy") ? true : false; }

};  // namespace ece150





//---------------------------------------------------------------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////
// Definitions for Transaction class
////////////////////////////////////////////////////////////////////////////////
//
//

// Constructor
// TASK 1
//
Transaction::Transaction( std::string ticker_symbol,unsigned int day_date,
                         unsigned int month_date,unsigned year_date,
                         bool buy_sell_trans,unsigned int number_shares,
                         double trans_amount ){
this->symbol = ticker_symbol;
this->day = day_date;
this->month = month_date;
this->year = year_date;
this->trans_type = buy_sell_trans ? "Buy" : "Sell";
this->shares = number_shares;
this->amount = trans_amount;
this->p_next = nullptr;
this->acb = 0;
this->cgl = 0;
this->acb_per_share = 0;
this->share_balance = 0;
this->trans_id = this->assigned_trans_id;
assigned_trans_id ++;
}
// Destructor
// TASK 1
//
Transaction::~Transaction(){
    p_next = nullptr;
}

// Overloaded < operator.
// TASK 2
//

bool Transaction::operator<(Transaction const &right){
    if (get_year() != right.get_year()){
        return get_year()<right.get_year()?1:0;
    }
    if (get_month() != right.get_month()){
        return get_month()<right.get_month()?1:0;
    }
    if (get_day() != right.get_day()){
        return get_day()<right.get_day()?1:0;
    }
    return get_trans_id() < right.get_trans_id() ? true :false;
}

// GIVEN
// Member functions to get values.
//
std::string Transaction::get_symbol() const { return symbol; }
unsigned int Transaction::get_day() const { return day; }
unsigned int Transaction::get_month() const { return month; }
unsigned int Transaction::get_year() const { return year; }
unsigned int Transaction::get_shares() const { return shares; }
double Transaction::get_amount() const { return amount; }
double Transaction::get_acb() const { return acb; }
double Transaction::get_acb_per_share() const { return acb_per_share; }
unsigned int Transaction::get_share_balance() const { return share_balance; }
double Transaction::get_cgl() const { return cgl; }
bool Transaction::get_trans_type() const { return (trans_type == "Buy") ? true: false ; }
unsigned int Transaction::get_trans_id() const { return trans_id; }
Transaction *Transaction::get_next() { return p_next; }

// GIVEN
// Member functions to set values.
//
void Transaction::set_acb( double acb_value ) { acb = acb_value; }
void Transaction::set_acb_per_share( double acb_share_value ) { acb_per_share = acb_share_value; }
void Transaction::set_share_balance( unsigned int bal ) { share_balance = bal ; }
void Transaction::set_cgl( double value ) { cgl = value; }
void Transaction::set_next( Transaction *p_new_next ) { p_next = p_new_next; }

// GIVEN
// Print the transaction.
//
void Transaction::print() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << std::setw(4) << get_trans_id() << " "
    << std::setw(4) << get_symbol() << " "
    << std::setw(4) << get_day() << " "
    << std::setw(4) << get_month() << " "
    << std::setw(4) << get_year() << " ";


  if ( get_trans_type() ) {
    std::cout << "  Buy  ";
  } else { std::cout << "  Sell "; }

  std::cout << std::setw(4) << get_shares() << " "
    << std::setw(10) << get_amount() << " "
    << std::setw(10) << get_acb() << " " << std::setw(4) << get_share_balance() << " "
    << std::setw(10) << std::setprecision(3) << get_acb_per_share() << " "
    << std::setw(10) << std::setprecision(3) << get_cgl()
    << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// Definitions for the History class
////////////////////////////////////////////////////////////////////////////////
//
//


// Constructor
// TASK 3
//
History::History(){
    p_head = nullptr;
}


// Destructor
// TASK 3
//

History::~History(){

    if (p_head == NULL){
        return;
    }

    Transaction* head = p_head;

    Transaction* next = p_head->get_next();

    while (head != nullptr){
        delete head;
        head = next;
        if (head != nullptr){
            next = head->get_next();
        }else{
            break;
        }
    }
    p_head = nullptr;
    head = nullptr;
    next = nullptr;
}

// read_history(...): Read the transaction history from file.
// TASK 4
//
void History::read_history(){
    p_head = nullptr;
    ece150::open_file();
    if (ece150::next_trans_entry()){
        p_head = new Transaction{ece150::get_trans_symbol(),ece150::get_trans_day(),
                         ece150::get_trans_month(),ece150::get_trans_year(),
                         ece150::get_trans_type(),ece150::get_trans_shares(),
                         ece150::get_trans_amount()};

    }
    Transaction *p = p_head;
    int c = 0;

    while (ece150::next_trans_entry()){
        p->set_next(new Transaction(ece150::get_trans_symbol(),ece150::get_trans_day(),
                         ece150::get_trans_month(),ece150::get_trans_year(),
                         ece150::get_trans_type(),ece150::get_trans_shares(),
                         ece150::get_trans_amount()));
        p = p->get_next();
        c++;
    }
}

// insert(...): Insert transaction into linked list.
// TASK 5
//
void History::insert(Transaction *p_new_trans){


    if (p_head == nullptr){
        p_head = p_new_trans;
        return;
    }

    Transaction *node = p_head;
    while (node->get_next() != nullptr){
        node = node->get_next();
    }
    node->set_next(p_new_trans);
    node = nullptr;
}

// sort_by_date(): Sort the linked list by trade date.
// TASK 6
//

void History::sort_by_date(){

    if (p_head == nullptr){
        return;
    }
    Transaction* dummy = new Transaction("NONE",0,0,0,0,0,0);
    dummy->set_next(p_head);
    Transaction* prev= p_head;
    Transaction* cur = p_head->get_next();
    Transaction* temp= nullptr;
    while (cur != nullptr){
        if (*prev < *cur){
            prev = cur;
            cur = cur->get_next();
            continue;
        }
        temp = dummy;
        while (*(temp->get_next())<*cur){
            temp= temp->get_next();
        }

        prev->set_next(cur->get_next());
        cur->set_next(temp->get_next());
        temp->set_next(cur);
        cur = prev->get_next();
    }

    p_head = dummy->get_next();

    if (dummy != nullptr){
        delete dummy;
    }
    prev = nullptr;
    cur = nullptr;
    temp = nullptr;
}

// update_acb_cgl(): Updates the ACB and CGL values.
// TASK 7
//
void History::update_acb_cgl(){

    if (p_head == nullptr){
        return;
    }
    if (p_head->get_next() == nullptr){
        return;
    }
    Transaction* ptr = p_head->get_next();
    Transaction* prev = p_head;
    prev->set_acb(prev->get_amount());
    prev->set_acb_per_share((prev->get_amount()) /(prev->get_shares()));
    prev->set_share_balance(prev->get_shares());


    while (ptr != nullptr){
        double acb = prev->get_acb();
        if (ptr->get_trans_type()){
            acb += ptr->get_amount();
            ptr->set_acb(acb);

            ptr->set_share_balance(prev->get_share_balance() + ptr->get_shares());
            ptr->set_acb_per_share(acb/ptr->get_share_balance());
        }else{
            ptr->set_acb(prev->get_acb() - ptr->get_shares() * prev->get_acb_per_share());
            ptr->set_share_balance(prev->get_share_balance() - ptr->get_shares());
            ptr->set_acb_per_share(prev->get_acb_per_share());

            ptr->set_cgl(ptr->get_amount() - ptr->get_shares() * prev->get_acb_per_share());

        }


        prev = ptr;
        ptr = ptr->get_next();
    }
    ptr = nullptr;
    prev = nullptr;

}


// compute_cgl(): )Compute the ACB, and CGL.
// TASK 8

double History::compute_cgl(unsigned int year){
    if (p_head == nullptr){
        return 0;
    }


    Transaction* head = p_head;
    double cglyear = 0;
    while (head != nullptr){

        if (head->get_year() == year){
            cglyear += head->get_cgl();
        }
        head = head->get_next();
    }
    head = nullptr;
    return cglyear;
}


// print() Print the transaction history.
//TASK 9
//
void History::print(){
    std::cout<<"========== BEGIN TRANSACTION HISTORY ============"<<std::endl;

    if(p_head != nullptr){
        Transaction *h = p_head;
    while (h != nullptr){
        h->print();
        h = h->get_next();
    }
    }

    std::cout<<"========== END TRANSACTION HISTORY ============"<<std::endl;
}


// GIVEN
// get_p_head(): Full access to the linked list.
//
Transaction *History::get_p_head() { return p_head; }
