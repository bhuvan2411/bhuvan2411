#ifndef XML_PARSER_H
#define XML_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

// Data structure to hold parsed XML data
typedef struct {
    char **table_names;
    int table_count;
    // Additional fields to store relevant data
} ParsedXMLData;

// Function declarations
ParsedXMLData* parse_xml(const char *filename);
void free_parsed_data(ParsedXMLData *data);
void print_parsed_data(const ParsedXMLData *data);

#endif // XML_PARSER_H