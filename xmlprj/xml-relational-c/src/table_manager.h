#ifndef TABLE_MANAGER_H
#define TABLE_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a table
typedef struct Table {
    char *name;
    char **columns;
    int column_count;
    void **rows;
    int row_count;
} Table;

// Function to create a new table
Table* create_table(const char *name, const char **columns, int column_count);

// Function to insert a row into a table
int insert_row(Table *table, void **row_data);

// Function to free the memory allocated for a table
void free_table(Table *table);

// Function to display the contents of a table
void display_table(const Table *table);

#endif // TABLE_MANAGER_H