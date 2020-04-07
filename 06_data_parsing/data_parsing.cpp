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
#define MAX_LEN  100


// does not work yet
int handle01(const char* data) {
    int i, len;
    char *words[MAX_LEN], *cp;
    const char *delim = "\n";

    cp = const_cast<char *>(data);
    for (len = 0; len < MAX_LEN; len++) {
        if ((words[len] = strtok(cp, delim)) == nullptr)
            break;
        cp = nullptr;
    }
    for (i=0; i<len; i++) {
        std::string str(words[i]);
        std::cout << "data:" << str << std::endl;
    }
}

int main() {
    const  char *data = "12345\nabcde\nfsdf\n";
    handle01(data);

    return 1;
}