#include "unity.h"
#include "my_module.h"

// Optional: Called before each test
void setUp(void) {
    // You can initialize variables here if needed
}

// Optional: Called after each test
void tearDown(void) {
    // You can clean up resources here
}

// A test function for the add() function
void test_add_basic(void) {
    // Unity's assertion macros are the core of the framework
    TEST_ASSERT_EQUAL_INT(5, add(2, 3));
}

// Another test function
void test_add_negative_numbers(void) {
    TEST_ASSERT_EQUAL_INT(-5, add(-2, -3));
}

// The main function that runs all tests
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_basic);
    RUN_TEST(test_add_negative_numbers);
    return UNITY_END();
}
