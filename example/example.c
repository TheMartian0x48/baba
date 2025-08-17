#include <baba/baba.h>
#include <baba/memory/memory.h>
#include <stdio.h>

void test_u64_array()
{
    Arena* main_arena = arena_make(ArenaTypeProxy, 1024 * 1024);
    printf("--- Testing U64Array functionality ---\n\n");

    // 1. Create an array with initial capacity
    U64Array my_array = u64_array_make(main_arena, 4);
    printf("Created U64Array with initial capacity 4.\n");
    printf("Initial size: %llu\n", PArraySize(my_array));
    printf("Initial capacity: %llu\n\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 0);
    assert(PArrayCapacity(my_array) == 4);

    // 2. Add elements and test dynamic resizing
    printf("Adding elements...\n");
    u64_array_add(&my_array, 10);
    u64_array_add(&my_array, 20);
    u64_array_add(&my_array, 30);
    u64_array_add(&my_array, 40);
    printf("Added 4 elements.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 4);
    assert(PArrayCapacity(my_array) == 4);
    printf("Array contents: [%d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3]);

    printf("Adding one more element to trigger resize...\n");
    u64_array_add(&my_array, 50);
    printf("Added 5th element.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 5);
    assert(PArrayCapacity(my_array) > 4); // Capacity should have doubled
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);

    // 3. Insert an element
    printf("Inserting element 99 at index 2...\n");
    u64_array_insert(&my_array, 99, 2);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4], my_array.v[5]);
    assert(my_array.v[2] == 99);
    assert(PArraySize(my_array) == 6);

    // 4. Remove an element
    printf("Removing element at index 3...\n");
    u64_array_remove(&my_array, 3);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);
    assert(PArraySize(my_array) == 5);
    assert(my_array.v[2] == 99); // The element that was at index 2 should still be there
    assert(my_array.v[3] == 40); // The element at index 4 (before removal) should have shifted

    // 5. Clear the array
    printf("Clearing the array...\n");
    u64_array_clear(&my_array);
    printf("Current size: %llu\n", PArraySize(my_array));
    assert(PArraySize(my_array) == 0);
    printf("Array is now empty.\n\n");

    // 6. Kill the array
    printf("Killing the array...\n");
    u64_array_kill(&my_array);
    assert(my_array.v == NULL);
    printf("Array successfully killed.\n\n");

    free(main_arena); // Free mock arena

    printf("All tests passed!\n");
}

void test_u32_array()
{
    Arena* main_arena = arena_make(ArenaTypeProxy, 1024 * 1024);
    printf("--- Testing U32Array functionality ---\n\n");

    // 1. Create an array with initial capacity
    U32Array my_array = u32_array_make(main_arena, 4);
    printf("Created U32Array with initial capacity 4.\n");
    printf("Initial size: %llu\n", PArraySize(my_array));
    printf("Initial capacity: %llu\n\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 0);
    assert(PArrayCapacity(my_array) == 4);

    // 2. Add elements and test dynamic resizing
    printf("Adding elements...\n");
    PArrayAdd(my_array, 10);
    PArrayAdd(my_array, 20);
    PArrayAdd(my_array, 30);
    PArrayAdd(my_array, 40);
    printf("Added 4 elements.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 4);
    assert(PArrayCapacity(my_array) == 4);
    printf("Array contents: [%d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3]);

    printf("Adding one more element to trigger resize...\n");
    PArrayAdd(my_array, 50);
    printf("Added 5th element.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 5);
    assert(PArrayCapacity(my_array) > 4); // Capacity should have doubled
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);

    // 3. Insert an element
    printf("Inserting element 99 at index 2...\n");
    PArrayInsert(my_array, 99, 2);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4], my_array.v[5]);
    assert(my_array.v[2] == 99);
    assert(PArraySize(my_array) == 6);

    // 4. Remove an element
    printf("Removing element at index 3...\n");
    PArrayRemove(my_array, 3);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);
    assert(PArraySize(my_array) == 5);
    assert(my_array.v[2] == 99); // The element that was at index 2 should still be there
    assert(my_array.v[3] == 40); // The element at index 4 (before removal) should have shifted

    // 5. Clear the array
    printf("Clearing the array...\n");
    PArrayClear(my_array);
    printf("Current size: %llu\n", PArraySize(my_array));
    assert(PArraySize(my_array) == 0);
    printf("Array is now empty.\n\n");

    // 6. Kill the array
    printf("Killing the array...\n");
    PArrayKill(my_array);
    assert(my_array.v == NULL);
    printf("Array successfully killed.\n\n");

    free(main_arena); // Free mock arena

    printf("All tests passed!\n");
}

void test_u16_array()
{
    Arena* main_arena = arena_make(ArenaTypeProxy, 1024 * 1024);
    printf("--- Testing U16Array functionality ---\n\n");

    // 1. Create an array with initial capacity
    U16Array my_array = u16_array_make(main_arena, 4);
    printf("Created U16Array with initial capacity 4.\n");
    printf("Initial size: %llu\n", PArraySize(my_array));
    printf("Initial capacity: %llu\n\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 0);
    assert(PArrayCapacity(my_array) == 4);

    // 2. Add elements and test dynamic resizing
    printf("Adding elements...\n");
    u16_array_add(&my_array, 10);
    u16_array_add(&my_array, 20);
    u16_array_add(&my_array, 30);
    u16_array_add(&my_array, 40);
    printf("Added 4 elements.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 4);
    assert(PArrayCapacity(my_array) == 4);
    printf("Array contents: [%d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3]);

    printf("Adding one more element to trigger resize...\n");
    u16_array_add(&my_array, 50);
    printf("Added 5th element.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 5);
    assert(PArrayCapacity(my_array) > 4); // Capacity should have doubled
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);

    // 3. Insert an element
    printf("Inserting element 99 at index 2...\n");
    u16_array_insert(&my_array, 99, 2);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4], my_array.v[5]);
    assert(my_array.v[2] == 99);
    assert(PArraySize(my_array) == 6);

    // 4. Remove an element
    printf("Removing element at index 3...\n");
    u16_array_remove(&my_array, 3);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);
    assert(PArraySize(my_array) == 5);
    assert(my_array.v[2] == 99); // The element that was at index 2 should still be there
    assert(my_array.v[3] == 40); // The element at index 4 (before removal) should have shifted

    // 5. Clear the array
    printf("Clearing the array...\n");
    u16_array_clear(&my_array);
    printf("Current size: %llu\n", PArraySize(my_array));
    assert(PArraySize(my_array) == 0);
    printf("Array is now empty.\n\n");

    // 6. Kill the array
    printf("Killing the array...\n");
    u16_array_kill(&my_array);
    assert(my_array.v == NULL);
    printf("Array successfully killed.\n\n");

    free(main_arena); // Free mock arena

    printf("All tests passed!\n");
}

void test_u8_array()
{
    Arena* main_arena = arena_make(ArenaTypeProxy, 1024 * 1024);
    printf("--- Testing U8Array functionality ---\n\n");

    // 1. Create an array with initial capacity
    U8Array my_array = u8_array_make(main_arena, 4);
    printf("Created U8Array with initial capacity 4.\n");
    printf("Initial size: %llu\n", PArraySize(my_array));
    printf("Initial capacity: %llu\n\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 0);
    assert(PArrayCapacity(my_array) == 4);

    // 2. Add elements and test dynamic resizing
    printf("Adding elements...\n");
    u8_array_add(&my_array, 10);
    u8_array_add(&my_array, 20);
    u8_array_add(&my_array, 30);
    u8_array_add(&my_array, 40);
    printf("Added 4 elements.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 4);
    assert(PArrayCapacity(my_array) == 4);
    printf("Array contents: [%d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3]);

    printf("Adding one more element to trigger resize...\n");
    u8_array_add(&my_array, 50);
    printf("Added 5th element.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 5);
    assert(PArrayCapacity(my_array) > 4); // Capacity should have doubled
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);

    // 3. Insert an element
    printf("Inserting element 99 at index 2...\n");
    u8_array_insert(&my_array, 99, 2);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4], my_array.v[5]);
    assert(my_array.v[2] == 99);
    assert(PArraySize(my_array) == 6);

    // 4. Remove an element
    printf("Removing element at index 3...\n");
    u8_array_remove(&my_array, 3);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);
    assert(PArraySize(my_array) == 5);
    assert(my_array.v[2] == 99); // The element that was at index 2 should still be there
    assert(my_array.v[3] == 40); // The element at index 4 (before removal) should have shifted

    // 5. Clear the array
    printf("Clearing the array...\n");
    u8_array_clear(&my_array);
    printf("Current size: %llu\n", PArraySize(my_array));
    assert(PArraySize(my_array) == 0);
    printf("Array is now empty.\n\n");

    // 6. Kill the array
    printf("Killing the array...\n");
    u8_array_kill(&my_array);
    assert(my_array.v == NULL);
    printf("Array successfully killed.\n\n");

    free(main_arena); // Free mock arena

    printf("All tests passed!\n");
}

void test_i8_array()
{
    Arena* main_arena = arena_make(ArenaTypeProxy, 1024 * 1024);
    printf("--- Testing I8Array functionality ---\n\n");

    // 1. Create an array with initial capacity
    I8Array my_array = i8_array_make(main_arena, 4);
    printf("Created I8Array with initial capacity 4.\n");
    printf("Initial size: %llu\n", PArraySize(my_array));
    printf("Initial capacity: %llu\n\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 0);
    assert(PArrayCapacity(my_array) == 4);

    // 2. Add elements and test dynamic resizing
    printf("Adding elements...\n");
    i8_array_add(&my_array, 10);
    i8_array_add(&my_array, 20);
    i8_array_add(&my_array, 30);
    i8_array_add(&my_array, 40);
    printf("Added 4 elements.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 4);
    assert(PArrayCapacity(my_array) == 4);
    printf("Array contents: [%d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3]);

    printf("Adding one more element to trigger resize...\n");
    i8_array_add(&my_array, 50);
    printf("Added 5th element.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 5);
    assert(PArrayCapacity(my_array) > 4); // Capacity should have doubled
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);

    // 3. Insert an element
    printf("Inserting element 99 at index 2...\n");
    i8_array_insert(&my_array, 99, 2);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4], my_array.v[5]);
    assert(my_array.v[2] == 99);
    assert(PArraySize(my_array) == 6);

    // 4. Remove an element
    printf("Removing element at index 3...\n");
    i8_array_remove(&my_array, 3);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);
    assert(PArraySize(my_array) == 5);
    assert(my_array.v[2] == 99); // The element that was at index 2 should still be there
    assert(my_array.v[3] == 40); // The element at index 4 (before removal) should have shifted

    // 5. Clear the array
    printf("Clearing the array...\n");
    i8_array_clear(&my_array);
    printf("Current size: %llu\n", PArraySize(my_array));
    assert(PArraySize(my_array) == 0);
    printf("Array is now empty.\n\n");

    // 6. Kill the array
    printf("Killing the array...\n");
    i8_array_kill(&my_array);
    assert(my_array.v == NULL);
    printf("Array successfully killed.\n\n");

    free(main_arena); // Free mock arena

    printf("All tests passed!\n");
}

void test_i16_array()
{
    Arena* main_arena = arena_make(ArenaTypeProxy, 1024 * 1024);
    printf("--- Testing I16Array functionality ---\n\n");

    // 1. Create an array with initial capacity
    I16Array my_array = i16_array_make(main_arena, 4);
    printf("Created I16Array with initial capacity 4.\n");
    printf("Initial size: %llu\n", PArraySize(my_array));
    printf("Initial capacity: %llu\n\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 0);
    assert(PArrayCapacity(my_array) == 4);

    // 2. Add elements and test dynamic resizing
    printf("Adding elements...\n");
    i16_array_add(&my_array, 10);
    i16_array_add(&my_array, 20);
    i16_array_add(&my_array, 30);
    i16_array_add(&my_array, 40);
    printf("Added 4 elements.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 4);
    assert(PArrayCapacity(my_array) == 4);
    printf("Array contents: [%d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3]);

    printf("Adding one more element to trigger resize...\n");
    i16_array_add(&my_array, 50);
    printf("Added 5th element.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 5);
    assert(PArrayCapacity(my_array) > 4); // Capacity should have doubled
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);

    // 3. Insert an element
    printf("Inserting element 99 at index 2...\n");
    i16_array_insert(&my_array, 99, 2);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4], my_array.v[5]);
    assert(my_array.v[2] == 99);
    assert(PArraySize(my_array) == 6);

    // 4. Remove an element
    printf("Removing element at index 3...\n");
    i16_array_remove(&my_array, 3);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);
    assert(PArraySize(my_array) == 5);
    assert(my_array.v[2] == 99); // The element that was at index 2 should still be there
    assert(my_array.v[3] == 40); // The element at index 4 (before removal) should have shifted

    // 5. Clear the array
    printf("Clearing the array...\n");
    i16_array_clear(&my_array);
    printf("Current size: %llu\n", PArraySize(my_array));
    assert(PArraySize(my_array) == 0);
    printf("Array is now empty.\n\n");

    // 6. Kill the array
    printf("Killing the array...\n");
    i16_array_kill(&my_array);
    assert(my_array.v == NULL);
    printf("Array successfully killed.\n\n");

    free(main_arena); // Free mock arena

    printf("All tests passed!\n");
}

void test_i32_array()
{
    Arena* main_arena = arena_make(ArenaTypeProxy, 1024 * 1024);
    printf("--- Testing I32Array functionality ---\n\n");

    // 1. Create an array with initial capacity
    I32Array my_array = i32_array_make(main_arena, 4);
    printf("Created I32Array with initial capacity 4.\n");
    printf("Initial size: %llu\n", PArraySize(my_array));
    printf("Initial capacity: %llu\n\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 0);
    assert(PArrayCapacity(my_array) == 4);

    // 2. Add elements and test dynamic resizing
    printf("Adding elements...\n");
    i32_array_add(&my_array, 10);
    i32_array_add(&my_array, 20);
    i32_array_add(&my_array, 30);
    i32_array_add(&my_array, 40);
    printf("Added 4 elements.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 4);
    assert(PArrayCapacity(my_array) == 4);
    printf("Array contents: [%d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3]);

    printf("Adding one more element to trigger resize...\n");
    i32_array_add(&my_array, 50);
    printf("Added 5th element.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 5);
    assert(PArrayCapacity(my_array) > 4); // Capacity should have doubled
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);

    // 3. Insert an element
    printf("Inserting element 99 at index 2...\n");
    i32_array_insert(&my_array, 99, 2);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4], my_array.v[5]);
    assert(my_array.v[2] == 99);
    assert(PArraySize(my_array) == 6);

    // 4. Remove an element
    printf("Removing element at index 3...\n");
    i32_array_remove(&my_array, 3);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);
    assert(PArraySize(my_array) == 5);
    assert(my_array.v[2] == 99); // The element that was at index 2 should still be there
    assert(my_array.v[3] == 40); // The element at index 4 (before removal) should have shifted

    // 5. Clear the array
    printf("Clearing the array...\n");
    i32_array_clear(&my_array);
    printf("Current size: %llu\n", PArraySize(my_array));
    assert(PArraySize(my_array) == 0);
    printf("Array is now empty.\n\n");

    // 6. Kill the array
    printf("Killing the array...\n");
    i32_array_kill(&my_array);
    assert(my_array.v == NULL);
    printf("Array successfully killed.\n\n");

    free(main_arena); // Free mock arena

    printf("All tests passed!\n");
}

void test_i64_array()
{
    Arena* main_arena = arena_make(ArenaTypeProxy, 1024 * 1024);
    printf("--- Testing I64Array functionality ---\n\n");

    // 1. Create an array with initial capacity
    I64Array my_array = i64_array_make(main_arena, 4);
    printf("Created I64Array with initial capacity 4.\n");
    printf("Initial size: %llu\n", PArraySize(my_array));
    printf("Initial capacity: %llu\n\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 0);
    assert(PArrayCapacity(my_array) == 4);

    // 2. Add elements and test dynamic resizing
    printf("Adding elements...\n");
    i64_array_add(&my_array, 10);
    i64_array_add(&my_array, 20);
    i64_array_add(&my_array, 30);
    i64_array_add(&my_array, 40);
    printf("Added 4 elements.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 4);
    assert(PArrayCapacity(my_array) == 4);
    printf("Array contents: [%d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3]);

    printf("Adding one more element to trigger resize...\n");
    i64_array_add(&my_array, 50);
    printf("Added 5th element.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 5);
    assert(PArrayCapacity(my_array) > 4); // Capacity should have doubled
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);

    // 3. Insert an element
    printf("Inserting element 99 at index 2...\n");
    i64_array_insert(&my_array, 99, 2);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4], my_array.v[5]);
    assert(my_array.v[2] == 99);
    assert(PArraySize(my_array) == 6);

    // 4. Remove an element
    printf("Removing element at index 3...\n");
    i64_array_remove(&my_array, 3);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);
    assert(PArraySize(my_array) == 5);
    assert(my_array.v[2] == 99); // The element that was at index 2 should still be there
    assert(my_array.v[3] == 40); // The element at index 4 (before removal) should have shifted

    // 5. Clear the array
    printf("Clearing the array...\n");
    i64_array_clear(&my_array);
    printf("Current size: %llu\n", PArraySize(my_array));
    assert(PArraySize(my_array) == 0);
    printf("Array is now empty.\n\n");

    // 6. Kill the array
    printf("Killing the array...\n");
    i64_array_kill(&my_array);
    assert(my_array.v == NULL);
    printf("Array successfully killed.\n\n");

    free(main_arena); // Free mock arena

    printf("All tests passed!\n");
}

void test_b8_array()
{
    Arena* main_arena = arena_make(ArenaTypeProxy, 1024 * 1024);
    printf("--- Testing B8Array functionality ---\n\n");

    // 1. Create an array with initial capacity
    B8Array my_array = b8_array_make(main_arena, 4);
    printf("Created B8Array with initial capacity 4.\n");
    printf("Initial size: %llu\n", PArraySize(my_array));
    printf("Initial capacity: %llu\n\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 0);
    assert(PArrayCapacity(my_array) == 4);

    // 2. Add elements and test dynamic resizing
    printf("Adding elements...\n");
    b8_array_add(&my_array, 10);
    b8_array_add(&my_array, 20);
    b8_array_add(&my_array, 30);
    b8_array_add(&my_array, 40);
    printf("Added 4 elements.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 4);
    assert(PArrayCapacity(my_array) == 4);
    printf("Array contents: [%d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3]);

    printf("Adding one more element to trigger resize...\n");
    b8_array_add(&my_array, 50);
    printf("Added 5th element.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 5);
    assert(PArrayCapacity(my_array) > 4); // Capacity should have doubled
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);

    // 3. Insert an element
    printf("Inserting element 99 at index 2...\n");
    b8_array_insert(&my_array, 99, 2);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4], my_array.v[5]);
    assert(my_array.v[2] == 99);
    assert(PArraySize(my_array) == 6);

    // 4. Remove an element
    printf("Removing element at index 3...\n");
    b8_array_remove(&my_array, 3);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);
    assert(PArraySize(my_array) == 5);
    assert(my_array.v[2] == 99); // The element that was at index 2 should still be there
    assert(my_array.v[3] == 40); // The element at index 4 (before removal) should have shifted

    // 5. Clear the array
    printf("Clearing the array...\n");
    b8_array_clear(&my_array);
    printf("Current size: %llu\n", PArraySize(my_array));
    assert(PArraySize(my_array) == 0);
    printf("Array is now empty.\n\n");

    // 6. Kill the array
    printf("Killing the array...\n");
    b8_array_kill(&my_array);
    assert(my_array.v == NULL);
    printf("Array successfully killed.\n\n");

    free(main_arena); // Free mock arena

    printf("All tests passed!\n");
}

void test_b16_array()
{
    Arena* main_arena = arena_make(ArenaTypeProxy, 1024 * 1024);
    printf("--- Testing B16Array functionality ---\n\n");

    // 1. Create an array with initial capacity
    B16Array my_array = b16_array_make(main_arena, 4);
    printf("Created B16Array with initial capacity 4.\n");
    printf("Initial size: %llu\n", PArraySize(my_array));
    printf("Initial capacity: %llu\n\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 0);
    assert(PArrayCapacity(my_array) == 4);

    // 2. Add elements and test dynamic resizing
    printf("Adding elements...\n");
    b16_array_add(&my_array, 10);
    b16_array_add(&my_array, 20);
    b16_array_add(&my_array, 30);
    b16_array_add(&my_array, 40);
    printf("Added 4 elements.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 4);
    assert(PArrayCapacity(my_array) == 4);
    printf("Array contents: [%d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3]);

    printf("Adding one more element to trigger resize...\n");
    b16_array_add(&my_array, 50);
    printf("Added 5th element.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 5);
    assert(PArrayCapacity(my_array) > 4); // Capacity should have doubled
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);

    // 3. Insert an element
    printf("Inserting element 99 at index 2...\n");
    b16_array_insert(&my_array, 99, 2);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4], my_array.v[5]);
    assert(my_array.v[2] == 99);
    assert(PArraySize(my_array) == 6);

    // 4. Remove an element
    printf("Removing element at index 3...\n");
    b16_array_remove(&my_array, 3);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);
    assert(PArraySize(my_array) == 5);
    assert(my_array.v[2] == 99); // The element that was at index 2 should still be there
    assert(my_array.v[3] == 40); // The element at index 4 (before removal) should have shifted

    // 5. Clear the array
    printf("Clearing the array...\n");
    b16_array_clear(&my_array);
    printf("Current size: %llu\n", PArraySize(my_array));
    assert(PArraySize(my_array) == 0);
    printf("Array is now empty.\n\n");

    // 6. Kill the array
    printf("Killing the array...\n");
    b16_array_kill(&my_array);
    assert(my_array.v == NULL);
    printf("Array successfully killed.\n\n");

    free(main_arena); // Free mock arena

    printf("All tests passed!\n");
}

void test_b32_array()
{
    Arena* main_arena = arena_make(ArenaTypeProxy, 1024 * 1024);
    printf("--- Testing B32Array functionality ---\n\n");

    // 1. Create an array with initial capacity
    B32Array my_array = b32_array_make(main_arena, 4);
    printf("Created B32Array with initial capacity 4.\n");
    printf("Initial size: %llu\n", PArraySize(my_array));
    printf("Initial capacity: %llu\n\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 0);
    assert(PArrayCapacity(my_array) == 4);

    // 2. Add elements and test dynamic resizing
    printf("Adding elements...\n");
    b32_array_add(&my_array, 10);
    b32_array_add(&my_array, 20);
    b32_array_add(&my_array, 30);
    b32_array_add(&my_array, 40);
    printf("Added 4 elements.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 4);
    assert(PArrayCapacity(my_array) == 4);
    printf("Array contents: [%d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3]);

    printf("Adding one more element to trigger resize...\n");
    b32_array_add(&my_array, 50);
    printf("Added 5th element.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 5);
    assert(PArrayCapacity(my_array) > 4); // Capacity should have doubled
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);

    // 3. Insert an element
    printf("Inserting element 99 at index 2...\n");
    b32_array_insert(&my_array, 99, 2);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4], my_array.v[5]);
    assert(my_array.v[2] == 99);
    assert(PArraySize(my_array) == 6);

    // 4. Remove an element
    printf("Removing element at index 3...\n");
    b32_array_remove(&my_array, 3);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);
    assert(PArraySize(my_array) == 5);
    assert(my_array.v[2] == 99); // The element that was at index 2 should still be there
    assert(my_array.v[3] == 40); // The element at index 4 (before removal) should have shifted

    // 5. Clear the array
    printf("Clearing the array...\n");
    b32_array_clear(&my_array);
    printf("Current size: %llu\n", PArraySize(my_array));
    assert(PArraySize(my_array) == 0);
    printf("Array is now empty.\n\n");

    // 6. Kill the array
    printf("Killing the array...\n");
    b32_array_kill(&my_array);
    assert(my_array.v == NULL);
    printf("Array successfully killed.\n\n");

    free(main_arena); // Free mock arena

    printf("All tests passed!\n");
}

void test_b64_array()
{
    Arena* main_arena = arena_make(ArenaTypeProxy, 1024 * 1024);
    printf("--- Testing B64Array functionality ---\n\n");

    // 1. Create an array with initial capacity
    B64Array my_array = b64_array_make(main_arena, 4);
    printf("Created B64Array with initial capacity 4.\n");
    printf("Initial size: %llu\n", PArraySize(my_array));
    printf("Initial capacity: %llu\n\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 0);
    assert(PArrayCapacity(my_array) == 4);

    // 2. Add elements and test dynamic resizing
    printf("Adding elements...\n");
    b64_array_add(&my_array, 10);
    b64_array_add(&my_array, 20);
    b64_array_add(&my_array, 30);
    b64_array_add(&my_array, 40);
    printf("Added 4 elements.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 4);
    assert(PArrayCapacity(my_array) == 4);
    printf("Array contents: [%d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3]);

    printf("Adding one more element to trigger resize...\n");
    b64_array_add(&my_array, 50);
    printf("Added 5th element.\n");
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Current capacity: %llu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 5);
    assert(PArrayCapacity(my_array) > 4); // Capacity should have doubled
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);

    // 3. Insert an element
    printf("Inserting element 99 at index 2...\n");
    b64_array_insert(&my_array, 99, 2);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4], my_array.v[5]);
    assert(my_array.v[2] == 99);
    assert(PArraySize(my_array) == 6);

    // 4. Remove an element
    printf("Removing element at index 3...\n");
    b64_array_remove(&my_array, 3);
    printf("Current size: %llu\n", PArraySize(my_array));
    printf("Array contents: [%d, %d, %d, %d, %d]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);
    assert(PArraySize(my_array) == 5);
    assert(my_array.v[2] == 99); // The element that was at index 2 should still be there
    assert(my_array.v[3] == 40); // The element at index 4 (before removal) should have shifted

    // 5. Clear the array
    printf("Clearing the array...\n");
    b64_array_clear(&my_array);
    printf("Current size: %llu\n", PArraySize(my_array));
    assert(PArraySize(my_array) == 0);
    printf("Array is now empty.\n\n");

    // 6. Kill the array
    printf("Killing the array...\n");
    b64_array_kill(&my_array);
    assert(my_array.v == NULL);
    printf("Array successfully killed.\n\n");

    free(main_arena); // Free mock arena

    printf("All tests passed!\n");
}

void test_f32_array()
{
    void* main_arena = arena_make(ArenaTypeProxy, 1024 * 1024);
    printf("--- Testing F32Array functionality ---\n\n");

    // 1. Create an array with initial capacity
    F32Array my_array = f32_array_make(main_arena, 4);
    printf("Created F32Array with initial capacity 4.\n");
    printf("Initial size: %zu\n", PArraySize(my_array));
    printf("Initial capacity: %zu\n\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 0);
    assert(PArrayCapacity(my_array) == 4);

    // 2. Add elements and test dynamic resizing
    printf("Adding elements...\n");
    f32_array_add(&my_array, 10.1f);
    f32_array_add(&my_array, 20.2f);
    f32_array_add(&my_array, 30.3f);
    f32_array_add(&my_array, 40.4f);
    printf("Added 4 elements.\n");
    printf("Current size: %zu\n", PArraySize(my_array));
    printf("Current capacity: %zu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 4);
    assert(PArrayCapacity(my_array) == 4);
    printf("Array contents: [%.1f, %.1f, %.1f, %.1f]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3]);

    printf("Adding one more element to trigger resize...\n");
    f32_array_add(&my_array, 50.5f);
    printf("Added 5th element.\n");
    printf("Current size: %zu\n", PArraySize(my_array));
    printf("Current capacity: %zu\n", PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 5);
    assert(PArrayCapacity(my_array) > 4);
    printf("Array contents: [%.1f, %.1f, %.1f, %.1f, %.1f]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);

    // 3. Insert an element
    printf("Inserting element 99.9f at index 2...\n");
    f32_array_insert(&my_array, 99.9f, 2);
    printf("Current size: %zu\n", PArraySize(my_array));
    printf("Array contents: [%.1f, %.1f, %.1f, %.1f, %.1f, %.1f]\n\n", my_array.v[0], my_array.v[1], my_array.v[2],
        my_array.v[3], my_array.v[4], my_array.v[5]);
    assert(my_array.v[2] == 99.9f);
    assert(PArraySize(my_array) == 6);

    // 4. Remove an element
    printf("Removing element at index 3...\n");
    f32_array_remove(&my_array, 3);
    printf("Current size: %zu\n", PArraySize(my_array));
    printf("Array contents: [%.1f, %.1f, %.1f, %.1f, %.1f]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);
    assert(PArraySize(my_array) == 5);
    assert(my_array.v[2] == 99.9f);
    assert(my_array.v[3] == 40.4f);

    // 5. Clear the array
    printf("Clearing the array...\n");
    f32_array_clear(&my_array);
    printf("Current size: %zu\n", PArraySize(my_array));
    assert(PArraySize(my_array) == 0);
    printf("Array is now empty.\n\n");

    // 6. Kill the array
    printf("Killing the array...\n");
    f32_array_kill(&my_array);
    assert(my_array.v == NULL);
    printf("Array successfully killed.\n\n");

    free(main_arena);

    printf("All tests passed!\n");
}

void test_f64_array()
{
    void* main_arena = arena_make(ArenaTypeProxy, 1024 * 1024);
    printf("--- Testing F64Array functionality ---\n\n");

    // 1. Create an array with initial capacity
    F64Array my_array = f64_array_make(main_arena, 4);
    printf("Created F64Array with initial capacity 4.\n");
    printf("Initial size: %llu\n", (unsigned long long)PArraySize(my_array));
    printf("Initial capacity: %llu\n\n", (unsigned long long)PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 0);
    assert(PArrayCapacity(my_array) == 4);

    // 2. Add elements and test dynamic resizing
    printf("Adding elements...\n");
    f64_array_add(&my_array, 10.1);
    f64_array_add(&my_array, 20.2);
    f64_array_add(&my_array, 30.3);
    f64_array_add(&my_array, 40.4);
    printf("Added 4 elements.\n");
    printf("Current size: %llu\n", (unsigned long long)PArraySize(my_array));
    printf("Current capacity: %llu\n", (unsigned long long)PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 4);
    assert(PArrayCapacity(my_array) == 4);
    printf("Array contents: [%.1f, %.1f, %.1f, %.1f]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3]);

    printf("Adding one more element to trigger resize...\n");
    f64_array_add(&my_array, 50.5);
    printf("Added 5th element.\n");
    printf("Current size: %llu\n", (unsigned long long)PArraySize(my_array));
    printf("Current capacity: %llu\n", (unsigned long long)PArrayCapacity(my_array));
    assert(PArraySize(my_array) == 5);
    assert(PArrayCapacity(my_array) > 4);
    printf("Array contents: [%.1f, %.1f, %.1f, %.1f, %.1f]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);

    // 3. Insert an element
    printf("Inserting element 99.9 at index 2...\n");
    f64_array_insert(&my_array, 99.9, 2);
    printf("Current size: %llu\n", (unsigned long long)PArraySize(my_array));
    printf("Array contents: [%.1f, %.1f, %.1f, %.1f, %.1f, %.1f]\n\n", my_array.v[0], my_array.v[1], my_array.v[2],
        my_array.v[3], my_array.v[4], my_array.v[5]);
    assert(my_array.v[2] == 99.9);
    assert(PArraySize(my_array) == 6);

    // 4. Remove an element
    printf("Removing element at index 3...\n");
    f64_array_remove(&my_array, 3);
    printf("Current size: %llu\n", (unsigned long long)PArraySize(my_array));
    printf("Array contents: [%.1f, %.1f, %.1f, %.1f, %.1f]\n\n", my_array.v[0], my_array.v[1], my_array.v[2], my_array.v[3],
        my_array.v[4]);
    assert(PArraySize(my_array) == 5);
    assert(my_array.v[2] == 99.9);
    assert(my_array.v[3] == 40.4);

    // 5. Clear the array
    printf("Clearing the array...\n");
    f64_array_clear(&my_array);
    printf("Current size: %llu\n", (unsigned long long)PArraySize(my_array));
    assert(PArraySize(my_array) == 0);
    printf("Array is now empty.\n\n");

    // 6. Kill the array
    printf("Killing the array...\n");
    f64_array_kill(&my_array);
    assert(my_array.v == NULL);
    printf("Array successfully killed.\n\n");

    free(main_arena);

    printf("All tests passed!\n");
}

int main()
{
    // test_u8_array();
    // test_u16_array();
    test_u32_array();
    // test_u64_array();

    // test_i8_array();
    // test_i16_array();
    // test_i32_array();
    // test_i64_array();

    // test_b8_array();
    // test_b16_array();
    // test_b32_array();
    // test_b64_array();

    // test_f32_array();
    // test_f64_array();
}
