#include "server.hpp"

// Not finished yet

server::server(){
    port = 8080;
    address = "";
    chain = std::vector<block>();
    transactions = std::vector<transaction>();
    difficulty = 0;
    previous_hash = "";
    hash = "";
}
server::~server(){}
void server::start(){
    run();
}
void server::stop(){}
void server::set_port(int p){
    port = p;
}
void server::set_address(std::string a){
    address = a;
}
void server::set_chain(std::vector<block> c){
    chain = c;
}
void server::set_transactions(std::vector<transaction> t){
    transactions = t;
}
void server::set_difficulty(int d){
    difficulty = d;
}
void server::set_previous_hash(std::string h){
    previous_hash = h;
}
void server::set_hash(std::string h){
    hash = h;
}
std::vector<block> server::get_chain(){
    return chain;
}
std::vector<transaction> server::get_transactions(){
    return transactions;
}
std::string server::get_previous_hash(){
    return previous_hash;
}
std::string server::get_hash(){
    return hash;
}
int server::get_difficulty(){
    return difficulty;
}
void server::print_chain(){
    for(int i = 0; i < chain.size(); i++){
        std::cout << "Block " << i << ":" << std::endl;
        std::cout << "Previous Hash: " << chain[i].previous_hash << std::endl;
        std::cout << "Hash: " << chain[i].hash << std::endl;
        std::cout << "Difficulty: " << chain[i].difficulty << std::endl;
        std::cout << "Nonce: " << chain[i].nonce << std::endl;
        std::cout << "Transactions: " << std::endl;
        for(int j = 0; j < chain[i].transactions.size(); j++){
            chain[i].transactions[j].print_transaction();
        }
    }
}
void server::print_transactions(){
    for(int i = 0; i < transactions.size(); i++){
        transactions[i].print_transaction();
    }
}
void server::run(){
    std::cout << "Server running on port " << port << std::endl;
    std::cout << "Waiting for connections..." << std::endl;
    while(true){
        std::string message = "";
        std::string response = "";
        std::string client_address = "";
        int client_port = 0;
        int client_socket = 0;
        //client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_port);
        std::cout << "Client connected from " << client_address << ":" << client_port << std::endl;
        std::cout << "Waiting for message..." << std::endl;
    }
}
