#include <iostream>
#include <string>
#include <stdio.h>

#include "../api.h"

void test1() {
    struct UrlComponents *components;
    components = new_url_components("GET", "/files/foo/", "create", "one=1&two=2");

    std::string method = components->method;
    std::string route = components->route;
    std::string command = components->command;
    std::string querystring = components->querystring;

    delete_url_components(components);
}

void test2() {
    struct UrlComponents *components;

    components = parse_url("files/some/path/to/disk.d64:createDiskImage?type=d64&format=json");

    //std::string method = "GET";
    //std::string route = "files";
    //std::string path = "/some/path/to/disk.d64";
    //std::string command = "createDiskImage";
    //std::string querystring = "type=d64&format=json";

    delete_url_components(components);
}

int main(void) {
    test1();
    test2();
    test1();
    test2();
    test1();
    test2();
    test1();
    test2();
    test1();
    test2();
    test1();
    test2();
    test1();
    test2();
    test1();
    test2();
    test1();
    test2();
    test1();
    test2();
    test1();
    test2();
}
