#pragma once

#include "transaction.hpp"

#include <vector>
#include <iostream>

// make a simple blockchain

struct block{
    std::vector<transaction> transactions;
    std::string previous_hash;
    std::string hash;
    int difficulty;
    int nonce;
};

class blockchain{
public:
    blockchain();
    ~blockchain();
    void add_transaction(transaction t);
    bool mine_block();
    std::vector<block> get_chain();
    std::vector<transaction> get_transactions();
    std::string get_previous_hash();
    std::string get_hash();
    int get_difficulty();
    void set_difficulty(int d);
    void set_previous_hash(std::string h);
    void set_hash(std::string h);
    void set_chain(std::vector<block> c);
    void set_transactions(std::vector<transaction> t);
    void print_chain();
    void print_transactions();
    std::string calculate_hash(std::string previous_hash, int nonce);
private:
    std::vector<block> chain;
    std::vector<transaction> transactions;
    std::string previous_hash;
    std::string hash;
    int difficulty;
    int nonce;
};