// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//

#include "../include/mammapia.hpp"
#include <fstream>

void mamma::init(std::string file_data) noexcept {
    std::ifstream stream(file_data);

    for(std::string temp; std::getline(stream, temp);) {
        if(temp.length() >= 1 && temp[0] == '#') continue;
        for(auto& data: this->split(temp)) this->data.push_back(data);
    } stream.close();
}

void mamma::read() noexcept {
    bool is_load = false, is_time = false;
    double seconds = 0.3;

    for(auto& data: this->data) {
        if(data == "(" || data == ")") continue;

        if(is_load || is_time) {
            if(is_load) this->seq.file = data;
            else seconds = std::stod(data);
            is_load = false; is_time = false; continue;
        } if(data == "load") { is_load = true; continue;
        } else if(data == "time") { is_time = true; continue; }

        if(data.length() >= 2) {
            for(auto& chord: this->seq.chord_match) {
                if(chord.first == data) {
                    this->seq.chords.push_back(chord.second);
                }
            }
        }
    } piacli init(this->seq.file);
    init.sequence.seconds = seconds;
    init.sequence.sequence = this->seq.chords;
    init.compile_sequence();
}

std::vector<std::string> mamma::split(std::string data) noexcept {
    std::string temp;
    std::vector<std::string> temp_data;

    for(auto& ch: data) {
        if((ch == ' ' || ch == '(' || ch == ')' || ch == EOF) && !temp.empty()) {
            temp_data.push_back(temp);
            temp.clear(); continue;
        } temp.push_back(ch);
    } return temp_data;
}

int main(int argc, char const* const* argv) noexcept {
    if(argc < 2) {
        std::cout << "mammapia - script to piacli data\n"
                     "--------\n" <<
                     argv[0] << " [mammapia script]\n";
        return 1;
    } mamma init;
    init.init(std::string(argv[1]));
    init.read();
}