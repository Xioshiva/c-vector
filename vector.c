#include "vector.h"

error_code vector_init(vector *v) {
    return ok;
}

bool vector_is_equal(vector *v1, vector *v2){
    return false;
}

error_code vector_length(vector *v, int *length) {
    return ok;
}

error_code vector_push(vector *v, type element) {
    return ok;
}

error_code vector_pop(vector *v, type *element) {
    return ok;
}

error_code vector_set(vector *v, int index, type element) {
    return ok;
}

error_code vector_get(vector *v, int index, type *element) {
    return ok;
}

error_code vector_remove(vector *v, int index) {
    return ok;
}

error_code vector_insert(vector *v, type element, int index) {
    return ok;
}

error_code vector_empty(vector *v) {
    return ok;
}

error_code vector_free(vector *v) {
    return ok;
}

void vector_print_int(vector *v) {
    return ok;
}

error_code vector_map(vector *v, type  (*f)(type), vector *rhs) {
    return ok;
}

error_code vector_filter(vector *v, bool  (*f)(type), vector *rhs) {
    return ok;
}

type square(type element){
    return 1;
}

bool is_even(type element){
    return false;
}