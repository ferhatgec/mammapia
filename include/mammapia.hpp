// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//

#ifndef MAMMAPIA_MAMMAPIA_HPP
#define MAMMAPIA_MAMMAPIA_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
#include "../libs/piacli/include/piacli.hpp"

class pia {
public:
    using pc = piacli::chords;

    std::string file;

    const std::unordered_map<std::string, piacli::chords> chord_match = {
        {"c7", pc::C7 }, {"b6", pc::B6 },
        {"a6", pc::A6 }, {"g6", pc::G6 },
        {"f6", pc::F6 }, {"e6", pc::E6 },
        {"d6", pc::D6 }, {"c6", pc::C6 },
        {"b5", pc::B5 }, {"a5", pc::A5 },
        {"g5", pc::G5 }, {"f5", pc::F5 },
        {"e5", pc::E5 }, {"d5", pc::D5 },
        {"c5", pc::E5 }, {"b4", pc::B4 },
        {"a4", pc::A4 }, {"g4", pc::G4 },
        {"f4", pc::F4 }, {"e4", pc::E4 },
        {"d4", pc::D4 }, {"c4", pc::C4 },
        {"b3", pc::B3 }, {"a3", pc::A3 },
        {"g3", pc::G3 }, {"f3", pc::F3 },
        {"e3", pc::E3 }, {"d3", pc::D3 },
        {"c3", pc::C3 }, {"b2", pc::B2 },
        {"a2", pc::A2 }, {"g2", pc::G2 },
        {"f2", pc::F2 }, {"e2", pc::E2 },
        {"d2", pc::D2 }, {"c2", pc::C2 },
        {"rest", pc::Rest }
    };

    std::vector<piacli::chords> chords;
public:
    pia() = default; ~pia() = default;
};

class mamma {
    std::string file_data;
    std::vector<std::string> data;
    pia seq;
public:
    mamma() = default; ~mamma() = default;

    void init(std::string file_data) noexcept;
    void read() noexcept;
    std::vector<std::string> split(std::string data) noexcept;
};

#endif // MAMMAPIA_MAMMAPIA_HPP
