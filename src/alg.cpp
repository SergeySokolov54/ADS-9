// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> bst;
    std::ifstream file(filename);
    std::string strin;
    while (!file.eof()) {
        char ch = file.get();
        if (ch >= 65 && ch <= 90) {
            ch += 32;
            str += ch;
            continue;
        }
        if (ch >= 97 && ch <= 122) {
            str += ch;
        } else {
            if (!str.empty()) {
                bst.add(strin);
            }
            strin.clear();
        }
    }
    bst.add(strin);
    file.close();
    return bst;
}
