#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_manager.h"

void test_create_table() {
    // Test creating a table
    Table *table = create_table("TestTable");
    if (table == NULL) {
        printf("Failed to create table.\n");
        return;
    }
    printf("Table '%s' created successfully.\n", table->name);
    free_table(table);
}

void test_insert_data() {
    // Test inserting data into a table
    Table *table = create_table("TestTable");
    if (table == NULL) {
        printf("Failed to create table for insertion test.\n");
        return;
    }

    Row *row = create_row();
    add_column(row, "Column1", "Value1");
    add_column(row, "Column2", "Value2");

    if (insert_row(table, row) == 0) {
        printf("Row inserted successfully into table '%s'.\n", table->name);
    } else {
        printf("Failed to insert row into table '%s'.\n", table->name);
    }

    free_row(row);
    free_table(table);
}

void test_referential_integrity() {
    // Test referential integrity
    Table *parent = create_table("ParentTable");
    Table *child = create_table("ChildTable");

    add_foreign_key(child, "ParentID", parent->name);

    Row *parent_row = create_row();
    add_column(parent_row, "ID", "1");
    insert_row(parent, parent_row);

    Row *child_row = create_row();
    add_column(child_row, "ChildID", "1");
    add_column(child_row, "ParentID", "1");

    if (insert_row(child, child_row) == 0) {
        printf("Child row inserted successfully with referential integrity.\n");
    } else {
        printf("Failed to insert child row due to referential integrity violation.\n");
    }

    free_row(parent_row);
    free_row(child_row);
    free_table(parent);
    free_table(child);
}

int main() {
    test_create_table();
    test_insert_data();
    test_referential_integrity();
    return 0;
}