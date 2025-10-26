#include <stdio.h>
#include "task.h"

int total_tests = 0;
int passed_tests = 0;

// === Assertion macro ===
#define ASSERT_EQ_INT(expected, actual) \
    if ((expected) != (actual)) { \
        printf("    ❌ FAIL: expected %d, got %d\n", (expected), (actual)); \
        test_failed = 1; \
    }

// === Test wrapper macro ===
#define RUN_TEST(test_fn) \
    do { \
        total_tests++; \
        printf("Running %-25s ... ", #test_fn); \
        test_failed = 0; \
        test_fn(); \
        if (test_failed) { \
            printf("❌ FAILED\n"); \
        } else { \
            printf("✅ PASSED\n"); \
            passed_tests++; \
        } \
    } while (0)

// === Global variable to track failure inside each test ===
int test_failed = 0;

// === Test functions ===
void test_reverse_normal() {
    int arr[] = {1, 2, 3, 4, 5};
    int expected[] = {5, 4, 3, 2, 1};
    reverseArray(arr, 5);
    for (int i = 0; i < 5; i++) {
        ASSERT_EQ_INT(expected[i], arr[i]);
    }
}

void test_reverse_single() {
    int arr[] = {42};
    reverseArray(arr, 1);
    ASSERT_EQ_INT(42, arr[0]);
}

void test_reverse_even() {
    int arr[] = {1, 2, 3, 4};
    int expected[] = {4, 3, 2, 1};
    reverseArray(arr, 4);
    for (int i = 0; i < 4; i++) {
        ASSERT_EQ_INT(expected[i], arr[i]);
    }
}

int main() {
    printf("===== C Unit Test Runner =====\n");

    RUN_TEST(test_reverse_normal);
    RUN_TEST(test_reverse_single);
    RUN_TEST(test_reverse_even);

    printf("\n===== Summary =====\n");
    printf("✅ Passed: %d/%d tests\n", passed_tests, total_tests);
    printf("=====================\n");

    // Exit with code 0 if all passed, 1 if any failed
    return (passed_tests == total_tests) ? 0 : 1;
}
