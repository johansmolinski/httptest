#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <stdio.h>

extern "C" {
#include "../api.h"
}

// The fixture for testing class Foo.
class RouteTest : public ::testing::Test {
protected:
    // SetUp and TearDown executes for each test case.
    
    void SetUp() override {
    }

    void TearDown() override {
    }

    // Class members are accessible from test cases. Reinitiated before each test.
};

TEST(RouteTest, UrlComponents) {
    struct UrlComponents *c;
    c = new_url_components("GET", "/files/foo/", "create", "one=1&two=2");
	printf("Got url components %x, %x, %x, %x, %x\n", c, c->method, c->command, c->route, c->querystring);

    //std::string method = components->method;
    //std::string route = components->route;
    //std::string command = components->command;
    //std::string querystring = components->querystring;

    //EXPECT_EQ("GET", method);
    //EXPECT_EQ("/files/foo/", route);
    //EXPECT_EQ("create", command);
    //EXPECT_EQ("one=1&two=2", querystring);

    delete_url_components(c);
}

//TEST_F(RouteTest, ParseUrl) {
//    struct UrlComponents *components;
//
//    components = parse_url("files/some/path/to/disk.d64:createDiskImage?type=d64&format=json");
//
//    //std::string method = "GET";
//    //std::string route = "files";
//    //std::string path = "/some/path/to/disk.d64";
//    //std::string command = "createDiskImage";
//    //std::string querystring = "type=d64&format=json";
//
//    //delete_url_components(components);
//}
