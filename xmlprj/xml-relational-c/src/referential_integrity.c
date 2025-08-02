#include <stdio.h>
#include <stdlib.h>
#include "referential_integrity.h"
#include "table_manager.h"

// Function to check referential integrity for a given table
int check_referential_integrity(Table *table, int row_index) {
    // Iterate through foreign keys in the table
    for (int i = 0; i < table->foreign_key_count; i++) {
        ForeignKey fk = table->foreign_keys[i];
        int referenced_row_index = find_row_by_id(fk.referenced_table, table->rows[row_index].data[fk.column_index]);
        
        // If the referenced row does not exist, return an error
        if (referenced_row_index == -1) {
            fprintf(stderr, "Referential integrity violation: Row %d in table %s references non-existent row in table %s\n",
                    row_index, table->name, fk.referenced_table->name);
            return -1; // Integrity violation
        }
    }
    return 0; // No violation
}

// Function to enforce referential integrity across all tables
int enforce_referential_integrity(Database *db) {
    for (int i = 0; i < db->table_count; i++) {
        Table *table = &db->tables[i];
        for (int j = 0; j < table->row_count; j++) {
            if (check_referential_integrity(table, j) != 0) {
                return -1; // Integrity violation found
            }
        }
    }
    return 0; // All referential integrity checks passed
}