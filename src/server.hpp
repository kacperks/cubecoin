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
    void set_nonce(int n);
    void set_transactions(std::vector<transaction> t);
    void print_chain();
    void print_transactions();
    std::string calculate_hash(std::string previous_hash, int nonce);
    void set_url(std::string url);
    void set_port(std::string port);
    void set_path(std::string path);
    void set_method(std::string method);
    void set_data(std::string data);
    void set_response(std::string response);
    void set_error(std::string error);
    void set_curl_error(std::string curl_error);
    std::string get_url();
    std::string get_port();
    std::string get_path();
    std::string get_method();
    std::string get_data();
    std::string get_response();
    std::string get_error();
    std::string get_curl_error();
private:
    blockchain blockchain_;
    std::string previous_hash_;
    std::string hash_;
    int difficulty_;
    int nonce_;
    std::vector<transaction> transactions_;
    std::vector<block> chain_;
    std::string url_;
    std::string port_;
    std::string path_;
    std::string method_;
    std::string data_;
    std::string response_;
    std::string error_;
    std::string curl_error_;
    CURL *curl_;
    CURLcode curl_code_;
    boost::property_tree::ptree json_;
    boost::optional<boost::property_tree::ptree> json_error_;
    boost::optional<boost::property_tree::ptree> json_response_;
    boost::optional<boost::property_tree::ptree> json_chain_;
    boost::optional<boost::property_tree::ptree> json_transactions_;
    boost::optional<boost::property_tree::ptree> json_previous_hash_;
    boost::optional<boost::property_tree::ptree> json_hash_;
    boost::optional<boost::property_tree::ptree> json_difficulty_;
    boost::optional<boost::property_tree::ptree> json_nonce_;
    boost::optional<boost::property_tree::ptree> json_curl_error_;
    boost::optional<boost::property_tree::ptree> json_curl_code_;
    boost::optional<boost::property_tree::ptree> json_curl_;
};
