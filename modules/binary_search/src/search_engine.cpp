// Copyright 2021 Zoreev Mikhail

#include "include/search_engine.h"

std::string SearchEngine::operator()(int argc, const char* argv[],
                       int* retcode) const {
    if (argc < 3)
        return help(argv[0]);
    int desired_value;
    std::string desired_value_string;
    try {
        desired_value_string = std::string(argv[1]);
        desired_value = std::stoi(desired_value_string);
    } catch (std::out_of_range& e) {
        return "[ERROR] " + desired_value_string + " out of range.";
    }

    std::vector<int> values;
    for (int i = 2; i < 5; i++) { // TODO: remove const
        std::string value_string;
        try {
            value_string = std::string(argv[i]);
            int value = std::stoi(value_string);
            values.push_back(value);
        } catch (std::out_of_range& e) {
            return "[ERROR] " + value_string + " out of range.";
        }
    }
    if (!std::is_sorted(values.begin(), values.end())) {
        return "[ERROR] row is not sorted";
    }
    int result;
    try {
        result = BinarySearch::Search<int>(desired_value,values,0,
                                           static_cast<int>(
                                                   values.size()) - 1);
    } catch (std::runtime_error& e) {
        return "[ERROR] " + std::string(e.what());
    }
    std::ostringstream str;
    str << "Index: " << result;
    return str.str();
}

std::string SearchEngine::help(const std::string& filename) const {
    return "Usage: " + filename + " DESIRED VALUES...\n" +
    "Example: " + filename + " 5 3 2 4 5\n" +
    "Will search \"5\" element in \"3 2 4 5\" row";
}