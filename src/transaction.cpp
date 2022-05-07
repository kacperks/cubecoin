#include "transaction.hpp"

transaction::transaction(std::string from, std::string to, int amount){
    from_ = from;
    to_ = to;
    amount_ = amount;
    previous_hash = "";
    hash = "";
}
transaction::~transaction(){}
int transaction::get_amount(){
    return amount_;
}
std::string transaction::get_from(){
    return from_;
}
std::string transaction::get_to(){
    return to_;
}
std::string transaction::get_hash(){
    return hash;
}
std::string transaction::get_previous_hash(){
    return previous_hash;
}
void transaction::set_hash(std::string h){
    hash = h;
}
void transaction::set_previous_hash(std::string h){
    previous_hash = h;
}
void transaction::print_transaction(){
    std::cout << "From: " << from_ << std::endl;
    std::cout << "To: " << to_ << std::endl;
    std::cout << "Amount: " << amount_ << std::endl;
    std::cout << "Previous hash: " << previous_hash << std::endl;
    std::cout << "Hash: " << hash << std::endl;
}
