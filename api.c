/* This file defines the server application functions (SAFs). */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "api.h"

void files_get_one(HTTPReqMessage *req, HTTPResMessage *res) {
}

struct UrlComponents *new_url_components(const char *method, const char *route, const char *command, const char *querystring) {
	struct UrlComponents *c;

	if (!(c = malloc(sizeof(*c)))) {
		return NULL;
	};

    const size_t method_len = strlen(method)+1;
	if (!(c->method = malloc(method_len))) {
		free(c);
		return NULL;
	}

    const size_t route_len = strlen(route)+1;
	if (!(c->route = malloc(route_len))) {
		free(c->method);
		free(c);
		return NULL;
	}

    const size_t command_len = strlen(command)+1;
	if (!(c->command = malloc(command_len))) {
		free(c->route);
		free(c->method);
		free(c);
		return NULL;
	}

    const size_t querystring_len = strlen(querystring)+1;
	if (!(c->querystring = malloc(querystring_len))) {
		free(c->command);
		free(c->route);
		free(c->method);
		free(c);
		return NULL;
	}

	strncpy(c->method, method, method_len);
	strncpy(c->route, route, route_len);
	strncpy(c->command, command, command_len);
	strncpy(c->querystring, querystring, querystring_len);

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
