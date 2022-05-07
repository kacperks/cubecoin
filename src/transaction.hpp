#pragma once

#include <iostream>
#include <chrono>
#include <string>
#include <unordered_set>
#include <vector>

class transaction{
public:
    transaction(std::string from, std::string to, int amount);
    ~transaction();
    std::string get_from();
    std::string get_to();
    int get_amount();
    std::string get_hash();
    std::string get_previous_hash();
    void set_hash(std::string h);
    void set_previous_hash(std::string h);
    void print_transaction();
private:
    std::string from_;
    std::string to_;
    int amount_;
    std::string hash;
    std::string previous_hash;
};