#include <stdio.h>
#include <assert.h>
#include "referential_integrity.h"
#include "table_manager.h"

void test_referential_integrity() {
    // Setup: Create tables and insert data
    create_table("Parent");
    create_table("Child");

    // Insert data into Parent table
    int parent_id = insert_into_table("Parent", "ParentName");
    
    // Insert data into Child table with a valid foreign key reference
    int child_id = insert_into_table("Child", "ChildName", parent_id);
    
    // Test: Check referential integrity
    assert(check_foreign_key("Child", "Parent", child_id, parent_id) == 1);
    
    // Test: Attempt to insert a child with an invalid foreign key
    int invalid_child_id = insert_into_table("Child", "InvalidChildName", -1);
    assert(check_foreign_key("Child", "Parent", invalid_child_id, -1) == 0);
    
    // Cleanup: Drop tables
    drop_table("Child");
    drop_table("Parent");
}

int main() {
    test_referential_integrity();
    printf("All referential integrity tests passed!\n");
    return 0;
}