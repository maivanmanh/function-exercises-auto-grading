#include <stdio.h>
#include <math.h>
#include "task.h"

int total_tests = 0;
int passed_tests = 0;

// === Assertion macros ===
#define EPS 0.001
#define ASSERT_EQ_DOUBLE(expected, actual) \
    do { \
        double _e = (expected); double _a = (actual); \
        if (fabs(_e - _a) > EPS) { \
            printf("    ❌ FAIL: expected %.3f, got %.3f\n", _e, _a); \
            test_failed = 1; \
        } \
    } while (0)

// === Test wrapper macro ===
#define RUN_TEST(test_fn) \
    do { \
        total_tests++; \
        printf("Running %-35s ... ", #test_fn); \
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

// === Test functions for calculateShippingCost ===

void test_S_domestic_boundaries() {
    // weight <=0 -> -1.0 (early invalid)
    ASSERT_EQ_DOUBLE(-1.0, calculateShippingCost(0.0, 'S', 1));
    // <=5.0 -> 4.99
    ASSERT_EQ_DOUBLE(4.99, calculateShippingCost(5.0, 'S', 1));
    // >5.0 and <=20.0 -> 8.99
    ASSERT_EQ_DOUBLE(8.99, calculateShippingCost(5.01, 'S', 1));
    ASSERT_EQ_DOUBLE(8.99, calculateShippingCost(20.0, 'S', 1));
    // >20.0 -> 12.99
    ASSERT_EQ_DOUBLE(12.99, calculateShippingCost(20.1, 'S', 1));
}

void test_S_international_boundaries() {
    ASSERT_EQ_DOUBLE(-1.0, calculateShippingCost(0.0, 'S', 2));
    ASSERT_EQ_DOUBLE(15.00, calculateShippingCost(2.0, 'S', 2));
    ASSERT_EQ_DOUBLE(25.00, calculateShippingCost(2.01, 'S', 2));
    ASSERT_EQ_DOUBLE(25.00, calculateShippingCost(10.0, 'S', 2));
    ASSERT_EQ_DOUBLE(40.00, calculateShippingCost(10.1, 'S', 2));
}

void test_S_invalid_zone_method() {
    // invalid zone
    ASSERT_EQ_DOUBLE(-1.0, calculateShippingCost(1.0, 'S', 3));
}

void test_E_domestic_boundaries() {
    ASSERT_EQ_DOUBLE(-1.0, calculateShippingCost(0.0, 'E', 1));
    ASSERT_EQ_DOUBLE(10.50, calculateShippingCost(1.0, 'E', 1));
    ASSERT_EQ_DOUBLE(18.50, calculateShippingCost(1.01, 'E', 1));
    ASSERT_EQ_DOUBLE(18.50, calculateShippingCost(15.0, 'E', 1));
    ASSERT_EQ_DOUBLE(25.50, calculateShippingCost(15.1, 'E', 1));
}

void test_E_international_boundaries() {
    ASSERT_EQ_DOUBLE(-1.0, calculateShippingCost(0.0, 'E', 2));
    ASSERT_EQ_DOUBLE(35.00, calculateShippingCost(5.0, 'E', 2));
    ASSERT_EQ_DOUBLE(50.00, calculateShippingCost(5.01, 'E', 2));
}

void test_E_invalid_zone() {
    ASSERT_EQ_DOUBLE(-1.0, calculateShippingCost(1.0, 'E', 99));
}

void test_O_domestic_and_international() {
    ASSERT_EQ_DOUBLE(-1.0, calculateShippingCost(0.0, 'O', 1));
    ASSERT_EQ_DOUBLE(30.00, calculateShippingCost(10.0, 'O', 1));
    ASSERT_EQ_DOUBLE(45.00, calculateShippingCost(10.1, 'O', 1));
    // Overnight not supported for international
    ASSERT_EQ_DOUBLE(-1.0, calculateShippingCost(5.0, 'O', 2));
}

void test_invalid_method() {
    ASSERT_EQ_DOUBLE(-1.0, calculateShippingCost(1.0, 'X', 1));
}

int main() {
    printf("===== Shipping Cost Unit Tests =====\n");

    RUN_TEST(test_S_domestic_boundaries);
    RUN_TEST(test_S_international_boundaries);
    RUN_TEST(test_S_invalid_zone_method);
    RUN_TEST(test_E_domestic_boundaries);
    RUN_TEST(test_E_international_boundaries);
    RUN_TEST(test_E_invalid_zone);
    RUN_TEST(test_O_domestic_and_international);
    RUN_TEST(test_invalid_method);

    printf("\n===== Summary =====\n");
    printf("✅ Passed: %d/%d tests\n", passed_tests, total_tests);
    printf("=====================\n");

    // Exit with code 0 if all passed, 1 if any failed
    return (passed_tests == total_tests) ? 0 : 1;
}
