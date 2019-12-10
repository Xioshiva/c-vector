#include "test_vector.h"
#include <stdio.h>
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"

int main() {

    CU_pSuite vector_suite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

    /* add a suite to the registry */
    vector_suite = CU_add_suite("Vector suite", NULL, NULL);
    if (NULL == vector_suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(vector_suite, "test of vector_init", test_vector_init)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_is_equal", test_vector_is_equal)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_length", test_vector_length)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_push", test_vector_push)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_pop", test_vector_pop)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_set", test_vector_set)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_get", test_vector_get)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_remove", test_vector_remove)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_insert", test_vector_insert)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_empty", test_vector_empty)) ||
        (NULL == CU_add_test(vector_suite, "test of vector_free", test_vector_free)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic (console output) and Automated (xml output) interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");

    CU_automated_run_tests();
   
    // return CU_get_error();
    return CU_get_number_of_tests_failed();
}