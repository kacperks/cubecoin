#pragma once

#include "blockchain.hpp"
#include "transaction.hpp"
#include <curl/curl.h>

#include <boost/optional.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class server{
public:
    server();
    ~server();
    void start();
    void stop();
    void set_port(int p);
    void set_address(std::string a);
    void set_chain(std::vector<block> c);
    void set_transactions(std::vector<transaction> t);
    void set_difficulty(int d);
    void set_previous_hash(std::string h);
    void set_hash(std::string h);
    std::vector<block> get_chain();
    std::vector<transaction> get_transactions();
    std::string get_previous_hash();
    std::string get_hash();
    int get_difficulty();
    void print_chain();
    void print_transactions();
private:
    int port;
    std::string address;
    std::vector<block> chain;
    std::vector<transaction> transactions;
    int difficulty;
    std::string previous_hash;
    std::string hash;
    int server_socket;
    void run();
    void handle_request(std::string request);
    void handle_get_chain();
    void handle_get_transactions();
    void handle_get_previous_hash();
    void handle_get_hash();
    void handle_get_difficulty();
    void handle_set_difficulty();
    void handle_set_previous_hash();
    void handle_set_hash();
    void handle_set_chain();
    void handle_set_transactions();
    void handle_print_chain();
    void handle_print_transactions();
    void handle_add_transaction();
    void handle_mine_block();
    void handle_get_block();
};