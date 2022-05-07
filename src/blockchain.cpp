#include "blockchain.hpp"

blockchain::blockchain(){
    chain.push_back(block());
    chain[0].previous_hash = "";
    chain[0].hash = "";
    chain[0].difficulty = 1;
    chain[0].nonce = 0;
    chain[0].transactions.push_back(transaction("","",0));
}
blockchain::~blockchain(){}
void blockchain::add_transaction(transaction t){
    chain[0].transactions.push_back(t);
}
bool blockchain::mine_block(){
    int difficulty = chain[0].difficulty;
    int nonce = chain[0].nonce;
    std::string previous_hash = chain[0].hash;
    std::string hash = "";
    std::string target = "";
    for(int i = 0; i < difficulty; i++){
        target += "0";
    }
    while(hash.substr(0, difficulty) != target){
        nonce++;
        hash = calculate_hash(previous_hash, nonce);
    }
    chain[0].nonce = nonce;
    chain[0].hash = hash;
    return true;
}
std::vector<block> blockchain::get_chain(){
    return chain;
}
std::vector<transaction> blockchain::get_transactions(){
    return chain[0].transactions;
}
std::string blockchain::get_previous_hash(){
    return chain[0].previous_hash;
}
std::string blockchain::get_hash(){
    return chain[0].hash;
}
int blockchain::get_difficulty(){
    return chain[0].difficulty;
}
void blockchain::set_difficulty(int d){
    chain[0].difficulty = d;
}
void blockchain::set_previous_hash(std::string h){
    chain[0].previous_hash = h;
}
void blockchain::set_hash(std::string h){
    chain[0].hash = h;
}
void blockchain::set_chain(std::vector<block> c){
    chain = c;
}
void blockchain::set_transactions(std::vector<transaction> t){
    chain[0].transactions = t;
}
void blockchain::print_chain(){
    for(int i = 0; i < chain.size(); i++){
        std::cout << "Block " << i << ": " << std::endl;
        std::cout << "Previous hash: " << chain[i].previous_hash << std::endl;
        std::cout << "Hash: " << chain[i].hash << std::endl;
        std::cout << "Difficulty: " << chain[i].difficulty << std::endl;
        std::cout << "Nonce: " << chain[i].nonce << std::endl;
        std::cout << "Transactions: " << std::endl;
        for(int j = 0; j < chain[i].transactions.size(); j++){
            chain[i].transactions[j].print_transaction();
        }  
    }
}
void blockchain::print_transactions(){
    for(int i = 0; i < chain[0].transactions.size(); i++){
        chain[0].transactions[i].print_transaction();
    }
}
std::string blockchain::calculate_hash(std::string previous_hash, int nonce){
    std::string hash = previous_hash + std::to_string(nonce);
    return hash;
}
