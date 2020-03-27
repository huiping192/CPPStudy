//
// Created by Huiping Guo on 2020/02/21.
//

#include <iostream>
#include <string>

int parse(std::string url);

void test00();
void test01();

int main() {

    test00();

    return 1;
}

// normal case
void test00() {
    std::string url = "rtmps://huiping.com:8080";
    parse(url);
}

// url dont contain ://
void test01() {
    std::string url = "www.huiping.com:8080";
    parse(url);
}

void log_error(std::string msg)
{
    std::cout << "ERROR: " << msg << std::endl;
}

void log_info(std::string msg)
{
    std::cout << "INFO: " << msg << std::endl;
}

int parse(std::string urlStr) {
    log_info("Start parsing url:" + urlStr);
    char* url = &urlStr[0];

    char* p = strstr(url,"://");

    if(p == nullptr) {
        log_error(" No :// in url!");
        return 0;
    }


    // get protocol
    int protocolLen = p - url;

    char protocol[4];
    strncpy(protocol, url, protocolLen);

    auto protocolString = std::string(protocol);
    log_info("Parsed protocol: " + protocolString);



    // get host
    p += 3; // skip ://
    if (*p == 0) {
        log_error("No hostname in URL!");
        return 0;
    }

    char* end = p + strlen(p);
    char* col = strchr(p, ':');
    char* ques = strchr(p, '?');
    char* slash = strchr(p, '/');

    int hostLen = col - p;
    char host[hostLen];

    strncpy(host,p,hostLen);

    auto hostString = std::string(host);
    log_info("Parsed host: " + hostString);

    // get port
    p +=  hostLen;
    if(*p == ':') { // has port
        p++;
        unsigned int p2;
        p2 = atoi(p);

        log_info("Parsed port: " + std::to_string(p2));
    }



}


