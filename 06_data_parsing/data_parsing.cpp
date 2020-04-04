//
// Created by Huiping Guo on 2020/04/05.
//

#include <iostream>
#include "data_parsing.h"

char* data_parsing(const char*& data, bool &hasLeft) {

    char* p = strstr(const_cast<char *>(data),"\n");

    if(p == nullptr) {
        auto subData = const_cast<char *>(data);
        data = nullptr;
        hasLeft = false;
        return subData;
    }

    int len = p - data;

    char* subData = static_cast<char *>(malloc(len));
    strncpy(subData, data, len);

    // move \n
    p++;
    if(p == nullptr) { // end
        data = nullptr;
        hasLeft = false;
        return subData;
    }

    data = p;
    hasLeft = true;
    return subData;
}

void handle(const char* data) {
    const char *leftData = data;
    while(1) {
        bool hasLeft = false;
        auto subData = data_parsing(reinterpret_cast<const char *&>(leftData),hasLeft);

        // left data doest  contain \n
        if(leftData == nullptr && !hasLeft) {
            std::string str(subData);
            std::cout << "left data: " << str << std::endl;
            break;
        }

        std::string str(subData);
        std::cout << "data: " << str << std::endl;

        // no data anymore
        if(*leftData == 0) {
            break;
        }
    }
}

int main() {
    const char *data = "12345\nabcde\nfsdf\n";

    handle(data);

    return 1;
}