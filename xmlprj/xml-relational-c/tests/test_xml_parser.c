#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xml_parser.h"

void test_parse_valid_xml() {
    // Test parsing a valid XML file
    const char *filename = "../data/sample.xml";
    XMLDocument *doc = parse_xml_file(filename);
    if (doc == NULL) {
        printf("Failed to parse valid XML file: %s\n", filename);
        return;
    }
    // Add assertions to check the structure of the parsed XML
    // Example: assert(doc->root != NULL);
    // Clean up
    free_xml_document(doc);
}

void test_parse_invalid_xml() {
    // Test parsing an invalid XML file
    const char *filename = "../data/invalid.xml";
    XMLDocument *doc = parse_xml_file(filename);
    if (doc != NULL) {
        printf("Parsed an invalid XML file: %s\n", filename);
        free_xml_document(doc);
    } else {
        printf("Correctly failed to parse invalid XML file: %s\n", filename);
    }
}

int main() {
    test_parse_valid_xml();
    test_parse_invalid_xml();
    return 0;
}