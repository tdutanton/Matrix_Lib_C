#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  result_code code = ERROR_INCORRECT_MATRIX;
  if (result && check_acceptable_matrix(A) && check_acceptable_matrix(B)) {
    if (A->rows != B->rows || A->columns != B->columns)
      code = ERROR_CALCULATION;
    else {
      s21_create_matrix(A->rows, A->columns, result);
      for (register int i = 0; i < result->rows; i++) {
        for (register int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
      code = OK;
    }
  }
  return code;
}