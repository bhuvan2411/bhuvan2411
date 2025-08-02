#ifndef XML_PARSER_H
#define XML_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

typedef struct {
    char **elements;
    int count;
} ParsedData;

ParsedData* parse_xml(const char *filename);
void free_parsed_data(ParsedData *data);
void process_element(xmlNode *node, ParsedData *data);

#endif // XML_PARSER_H