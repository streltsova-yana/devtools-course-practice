// Copyright 2021 Zoreev Mikhail

#include "include/search_engine.h"

std::string SearchEngine::operator()(int argc, const char* argv[],
                       int* retcode) const {
    if (argc < 3)
        return help(argv[0]);
    std::string desired_value = argv[1];
    std::vector<std::string> values;
    for (int i = 2; i < argc; i++) {
        values.push_back(argv[i]);
    }
    int result = 0;
    try {
        result = BinarySearch::Search<std::string>(desired_value, values,0,
                                          static_cast<int>(values.size()) - 1);
    } catch (std::runtime_error& e) {
        return "[ERROR] " + std::string(e.what());
    }
    std::ostringstream str;
    str << "Index: " << result;
    return str.str();
}

std::string SearchEngine::help(const std::string& filename) const {
    return "Usage: " + filename + "DESIRED VALUES...\n" +
    "Example:" + filename + " 5 3 2 4 5\n" +
    "Will search \"5\" element in \"3 2 4 5\" row";
}