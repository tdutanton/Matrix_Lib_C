#ifndef SERVICE_H
#define SERVICE_H

#include <math.h>
#include <stdio.h>

typedef struct matrix_struct matrix_t;

typedef enum {
  OK,
  ERROR_INCORRECT_MATRIX,
  ERROR_CALCULATION,
} result_code;

typedef enum {
  FAIL_TMP,
  OK_TMP,
} tmp_code;

typedef enum {
  NOT_EQUAL,
  EQUAL,
} compare_doubles;

void free_matrix(matrix_t* value);
int compare_matrix_elements(double a, double b);
int check_acceptable_matrix(matrix_t* value);
int one_minor_matrix(int row, int col, matrix_t* value, matrix_t* result);
int determinant_of_two(matrix_t value, double* determinant);
int determinant_of_triangle(matrix_t value, double* determinant);
void swap_rows(matrix_t* value, int row_1, int row_2);
void get_upper_triangle_matrix(matrix_t* value, int* det_sign);
void add_multing_row(matrix_t* value, int row_give, int row_take, double mult);
void copy_matrix(matrix_t* value, matrix_t* dest);
#endif
