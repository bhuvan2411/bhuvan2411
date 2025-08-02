#include <stdio.h>
#include "xml_parser.h"
#include "table_manager.h"
#include "referential_integrity.h"

int main() {
    const char *xml_file_path = "data/sample.xml";

    // Initialize XML parser
    if (!initialize_xml_parser(xml_file_path)) {
        fprintf(stderr, "Failed to initialize XML parser.\n");
        return 1;
    }

    // Parse XML and load data into tables
    if (!parse_xml_and_load_tables()) {
        fprintf(stderr, "Failed to parse XML and load tables.\n");
        return 1;
    }

    // Check referential integrity
    if (!check_referential_integrity()) {
        fprintf(stderr, "Referential integrity check failed.\n");
        return 1;
    }

    printf("XML data successfully loaded into relational tables with referential integrity maintained.\n");
    return 0;
}