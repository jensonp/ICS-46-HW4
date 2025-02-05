#pragma once
#include <vector> 
#include <unordered_map>
#include <utility>
#include <iterator>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

inline std::vector<double> ASI, ASR, LSI, LSR, AQI, AQR, LQI, LQR;
inline unordered_map
    <
    string, 
    pair<vector<double>*, vector<double>*>
    >
    times = 
    {
    {"ArrayStack", {&ASI, &ASR}},
    {"LinkedStack", {&LSI, &LSR}},
    {"ArrayQueue",  {&AQI, &AQR}},
    {"LinkedQueue", {&LQI, &LQR}}
    };

template<typename Iter, typename PairType>
inline void csv_lines_helper_2(
    Iter &it, 
    const PairType &value,
    Iter it_end
){
    for(int i=1; i<=10; ++i){
        if(it + i < it_end){
            *(it+i) =
            to_string(i)+","+
            to_string((*value.first)[i-1])+","+
            to_string((*value.second)[i-1])+",";
        }
    }
    advance(it, 10);
}
inline void csv_lines_helper(vector<string> &lines){
    for(auto it=lines.begin(); it!=lines.end(); ++it){
        for(const auto&[key, value]:times){
            if(it->find(key) != string::npos){ csv_lines_helper_2(it, value, lines.end()); break;} }
    }
}
inline void csv(const string& file_name){
    ifstream in(file_name);
    vector<string>lines; string line;
    while(getline(in, line)){ lines.push_back(line); } 
    in.close();
    csv_lines_helper(lines);
    ofstream out(file_name, ofstream::trunc);
    for(const auto &mod_line : lines){ out<<mod_line<<"\n";}
    out.close();
}
inline void all_words(const string &name, const double &time, const char &mode){
    auto it = times.find(name);
    if(it != times.end()) {mode=='i'?it->second.first->push_back(time):it->second.second->push_back(time);}
}