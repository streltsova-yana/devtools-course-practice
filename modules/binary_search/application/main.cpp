// Copyright 2021 Zoreev Mikhail

#include <iostream>
#include <string>

#include "include/search_engine.h"

int main(int argc, const char* argv[]) {
    SearchEngine::Search app;
    int retcode = 0;
    std::cout << app(argc, argv, &retcode);
    return retcode;
}
