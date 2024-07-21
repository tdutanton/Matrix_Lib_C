#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  result_code code = ERROR_INCORRECT_MATRIX;
  s21_mult_number(B, -1, B);
  code = s21_sum_matrix(A, B, result);
  return code;
}