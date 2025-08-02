#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_manager.h"
#include "referential_integrity.h"

// Structure to represent a relational table
typedef struct Table {
    char *name;
    char **columns;
    int column_count;
    char ***data;
    int row_count;
} Table;

// Array of tables
Table *tables = NULL;
int table_count = 0;

// Function to create a new table
void create_table(const char *table_name, char **columns, int column_count) {
    tables = realloc(tables, sizeof(Table) * (table_count + 1));
    Table *new_table = &tables[table_count];
    
    new_table->name = strdup(table_name);
    new_table->columns = malloc(sizeof(char *) * column_count);
    for (int i = 0; i < column_count; i++) {
        new_table->columns[i] = strdup(columns[i]);
    }
    new_table->column_count = column_count;
    new_table->data = NULL;
    new_table->row_count = 0;
    
    table_count++;
}

// Function to insert data into a table
void insert_into_table(const char *table_name, char **row_data) {
    for (int i = 0; i < table_count; i++) {
        if (strcmp(tables[i].name, table_name) == 0) {
            tables[i].data = realloc(tables[i].data, sizeof(char **) * (tables[i].row_count + 1));
            tables[i].data[tables[i].row_count] = malloc(sizeof(char *) * tables[i].column_count);
            for (int j = 0; j < tables[i].column_count; j++) {
                tables[i].data[tables[i].row_count][j] = strdup(row_data[j]);
            }
            tables[i].row_count++;
            return;
        }
    }
}

// Function to free all allocated memory for tables
void free_tables() {
    for (int i = 0; i < table_count; i++) {
        free(tables[i].name);
        for (int j = 0; j < tables[i].column_count; j++) {
            free(tables[i].columns[j]);
        }
        free(tables[i].columns);
        for (int j = 0; j < tables[i].row_count; j++) {
            for (int k = 0; k < tables[i].column_count; k++) {
                free(tables[i].data[j][k]);
            }
            free(tables[i].data[j]);
        }
        free(tables[i].data);
    }
    free(tables);
}

// Function to print all tables (for debugging purposes)
void print_tables() {
    for (int i = 0; i < table_count; i++) {
        printf("Table: %s\n", tables[i].name);
        for (int j = 0; j < tables[i].row_count; j++) {
            for (int k = 0; k < tables[i].column_count; k++) {
                printf("%s ", tables[i].data[j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}