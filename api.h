#ifndef __API_H__
#define __API_H__

#include "lib/server.h"

#define MAX_STR_LEN 512

struct Parameter {
    char *name;
    char *value;
};

struct UrlComponents {
    char *method;
    char *route;
    char *command;
    char *querystring;
};

struct UrlComponents *new_url_components(const char *method, const char *route, const char *command, const char *querystring);
void delete_url_components(struct UrlComponents *components);

struct UrlComponents *parse_url(const char *url);

void files_get_one(HTTPReqMessage *, HTTPResMessage *);

#endif

