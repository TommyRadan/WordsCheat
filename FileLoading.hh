#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <cctype>

const std::vector<std::string> LoadFile(const std::string& filename)
{
    std::vector<std::string> returnVector;

    std::ifstream file;
    file.open(filename);

    if(!file.is_open()) {
        throw std::runtime_error("Could not load the dictionary");
    }

    std::string line;
    while(std::getline(file, line)) {
        if(line.size() > 10 || line.size() < 3) continue;
        std::transform(line.begin(), line.end(), line.begin(), ::toupper);
        returnVector.push_back(line);
    }

    file.close();

    return returnVector;
}
