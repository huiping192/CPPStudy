//
// Created by Huiping Guo on 2020/03/29.
//

#include <iostream>
#include <fstream>


void write_file();
void read_file();

int main() {
//    write_file();


    read_file();
    return 1;
}

void read_file() {
    std::string line;
    std::ifstream file ("sample.txt");
    if (!file.is_open())
    {
        std::cout << "Unable to open file";
    }

    while ( getline (file, line) )
    {
        std::cout << line << '\n';
    }
    file.close();
}

void write_file() {
    std::ofstream file ("sample.txt");

    if(!file.is_open()) {
        std::cout << "Unable to open file";
        return;
    }

    file << "This is a line.\n";
    file << "This is another line.\n";
    file.close();
}