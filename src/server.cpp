#include "server.hpp"

server::server(){
    curl_ = curl_easy_init();
    if(curl_ == NULL){
        std::cout << "curl_easy_init() failed" << std::endl;
    }
    curl_code_ = CURLE_OK;
    curl_error_ = "";
    json_ = boost::property_tree::ptree();
    json_error_ = boost::optional<boost::property_tree::ptree>();
    json_response_ = boost::optional<boost::property_tree::ptree>();
    json_chain_ = boost::optional<boost::property_tree::ptree>();
    json_transactions_ = boost::optional<boost::property_tree::ptree>();
    json_previous_hash_ = boost::optional<boost::property_tree::ptree>();
    json_hash_ = boost::optional<boost::property_tree::ptree>();
    json_difficulty_ = boost::optional<boost::property_tree::ptree>();
    json_nonce_ = boost::optional<boost::property_tree::ptree>();
    json_curl_error_ = boost::optional<boost::property_tree::ptree>();
    json_curl_code_ = boost::optional<boost::property_tree::ptree>();
    json_curl_ = boost::optional<boost::property_tree::ptree>();
    url_ = "http://";
    port_ = ":";
    path_ = "/";
    method_ = "";
    data_ = "";
    response_ = "";
    error_ = "";
    curl_error_ = "";
}
server::~server(){
    curl_easy_cleanup(curl_);
}
void server::add_transaction(transaction t){
    transactions_.push_back(t);
}
bool server::mine_block(){
    bool success = false;
    int nonce = 0;
    std::string previous_hash = get_previous_hash();
    std::string hash = get_hash();
    int difficulty = get_difficulty();
    while(!success){
        hash = calculate_hash(previous_hash, nonce);
        if(hash.substr(0, difficulty) == std::string(difficulty, '0')){
            success = true;
        }
        nonce++;
    }
    set_hash(hash);
    set_nonce(nonce);
    return success;
}
std::vector<block> server::get_chain(){
    return chain_;
}
std::vector<transaction> server::get_transactions(){
    return transactions_;
}
std::string server::get_previous_hash(){
    return previous_hash_;
}
std::string server::get_hash(){
    return hash_;
}
int server::get_difficulty(){
    return difficulty_;
}
void server::set_difficulty(int d){
    difficulty_ = d;
}
void server::set_previous_hash(std::string h){
    previous_hash_ = h;
}
void server::set_hash(std::string h){
    hash_ = h;
}
void server::set_chain(std::vector<block> c){
    chain_ = c;
}
void server::set_transactions(std::vector<transaction> t){
    transactions_ = t;
}
void server::print_chain(){
    for(int i = 0; i < chain_.size(); i++){
        std::cout << "Block " << i << ":" << std::endl;
        std::cout << "Previous hash: " << chain_[i].previous_hash << std::endl;
        std::cout << "Hash: " << chain_[i].hash << std::endl;
        std::cout << "Difficulty: " << chain_[i].difficulty << std::endl;
        std::cout << "Nonce: " << chain_[i].nonce << std::endl;
        std::cout << "Transactions: " << std::endl;
        for(int j = 0; j < chain_[i].transactions.size(); j++){
            std::cout << "Transaction " << j << ":" << std::endl;
            std::cout << "Sender: " << chain_[i].transactions[j].get_from() << std::endl;
            std::cout << "Recipient: " << chain_[i].transactions[j].get_to() << std::endl;
            std::cout << "Amount: " << chain_[i].transactions[j].get_amount() << std::endl;
        }
    }
}
void server::print_transactions(){
    for(int i = 0; i < transactions_.size(); i++){
        std::cout << "Transaction " << i << ":" << std::endl;
        std::cout << "Sender: " << transactions_[i].get_from() << std::endl;
        std::cout << "Recipient: " << transactions_[i].get_to() << std::endl;
        std::cout << "Amount: " << transactions_[i].get_amount() << std::endl;
    }
}
void server::set_url(std::string u){
    url_ = u;
}
void server::set_port(std::string p){
    port_ = p;
}
void server::set_path(std::string p){
    path_ = p;
}
void server::set_method(std::string m){
    method_ = m;
}
void server::set_data(std::string d){
    data_ = d;
}
void server::set_response(std::string r){
    response_ = r;
}
void server::set_error(std::string e){
    error_ = e;
}
void server::set_curl_error(std::string e){
    curl_error_ = e;
}