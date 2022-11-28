/* This file defines the server application functions (SAFs). */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "api.h"

void files_get_one(HTTPReqMessage *req, HTTPResMessage *res) {
}

struct UrlComponents *new_url_components(const char *method, const char *route, const char *command, const char *querystring) {
	struct UrlComponents *c;

	if (!(c = (struct UrlComponents *)malloc(sizeof(struct UrlComponents)))) {
		return NULL;
	};

	if (!(c->method = (char *)malloc(sizeof(strlen(method)+1)))) {
		free(c);
		return NULL;
	}

	if (!(c->route = (char *)malloc(sizeof(strlen(route)+1)))) {
		free(c->method);
		free(c);
		return NULL;
	}

	if (!(c->command = (char *)malloc(sizeof(strlen(route)+1)))) {
		free(c->route);
		free(c->method);
		free(c);
		return NULL;
	}

	if (!(c->querystring = (char *)malloc(sizeof(strlen(route)+1)))) {
		free(c->command);
		free(c->route);
		free(c->method);
		free(c);
		return NULL;
	}

	strncpy(c->method, method, MAX_STR_LEN);
	strncpy(c->route, route, MAX_STR_LEN);
	strncpy(c->command, command, MAX_STR_LEN);
	strncpy(c->querystring, querystring, MAX_STR_LEN);

	printf("Created url components %x, %x, %x, %x, %x\n", c, c->method, c->command, c->route, c->querystring);
	return c;
}

void delete_url_components(struct UrlComponents *components) {
	printf("Deleting url components %x, %x, %x, %x, %x\n", components, components->method, components->command, components->route, components->querystring);
	printf("free command ");
	free(components->command);
	printf("Freed command at %x\n", components->command);
	components->command = NULL;
	printf("route ");
	free(components->route);
	components->route = NULL;
	printf("method ");
	free(components->method);
	components->method = NULL;
	printf("querystring ");
	free(components->querystring);
	components->querystring = NULL;
	printf("components ");
	free(components);
	printf("Freed components at %x\n", components);
	components = NULL;
	printf("\n");
}

struct UrlComponents *parse_url(const char *url) {
	struct UrlComponents *components;
	components = new_url_components("method", "route", "command", "querystring");
	return components;
}
