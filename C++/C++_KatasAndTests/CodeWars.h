//
// Created by John Perry on 2020-06-24.
//

#ifndef CODEWARS_CODEWARS_H
#define CODEWARS_CODEWARS_H
#include <string>
#include <vector>
#include <tuple>

class CodeWars {
public:
    std::string mumbling(const std::string &input_string) const;
    std::string encrypt_alternating_split(const std::string &text, int n) const;
    std::string decrypt_alternating_split(const std::string &encrypted_text, int n) const;
    bool is_valid_walk(const std::vector<char> &walk) const;
    unsigned int count_bits(const unsigned long long &n) const;
    std::string longest_consec(const std::vector<std::string> &str_arr, const int &k) const;
    std::pair<std::string, std::string> capitalize(const std::string &s) const;
    std::vector<unsigned long long> parts_sum(const std::vector<unsigned long long> &ls);
    bool validate(long long int n) const;
    std::string stock_summary(const std::vector<std::string> &lst, const std::vector<std::string> &categories) const;
    int count_deaf_rats(const std::string &town) const;
    std::string solution(int number) const;
    unsigned long long num_primorial(const unsigned short int &number) const;
    std::string change_case(const std::string &identifier, const std::string &target_case) const;
    bool valid_solution(const unsigned int board[9][9]) const;
    unsigned long long exp_sum(const unsigned int &n) const;
    double money_value(const std::string &s) const;
    std::vector<int> shortest_arrang(const int &n) const;
    std::string alphabet_war(const std::string &fight) const;
    std::string pattern(const int &n) const;
    std::string mix(const std::string &s1, const std::string &s2) const;
    std::string hist(const std::string &s);
    std::string play_OX_3D(const std::vector<std::vector<int>> &moves) const;
    std::string who_is_winner(const std::vector<std::string> &pieces_position_list) const;
    bool validate_battlefield(const std::vector<std::vector<int>> &field) const;
    std::vector<int> sort(const std::vector<int> &array) const;
    std::string multiply(std::string &a, std::string &b) const;
    std::vector<std::pair<long long, long long>> list_squared(const long long &m, const long long &n) const;
    int choose_best_sum(const int &t, const int &k, std::vector<int> &ls) const;
    std::string get_middle(const std::string &input) const;
    long queue_time(std::vector<int> customers, int n) const;
    std::vector<std::string> permutations (std::string &s) const;
    std::string format_duration(int seconds) const;
    std::string to_postfix(const std::string &infix) const;
    int other_angle(const int &a, const int &b) const;
    int solve(const long &n) const;
    std::vector<int> count_by(const int &x, const int &n) const;
    int epidemic(int tm, int n, int s0, int i0, double b, double a) const;
    std::string is_sorted_and_how(const std::vector<int> array) const;
    long int find_next_square(long int sq) const;
    std::tuple<double, double, double, double> fcfs(const std::vector<std::pair<int, int>> &processes) const;
    int solve2(const std::string &s) const;
    int values(const int &n) const;
    std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) const;
    int round_robin(std::vector<int> jobs, const int &slice, const int &index) const;
    int SJF(std::vector<int> jobs, int index) const;
    std::string crack(const std::string &hash) const;
    std::string alphabetWar(const std::string &fight) const;
};


#endif //CODEWARS_CODEWARS_H
