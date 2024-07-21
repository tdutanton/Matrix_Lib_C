#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  result_code code = ERROR_INCORRECT_MATRIX;
  if (check_acceptable_matrix(A) && check_acceptable_matrix(B) && result) {
    if (A->rows == B->columns && A->columns == B->rows) {
      s21_create_matrix(A->rows, B->columns, result);
      for (register int i = 0; i < result->rows; i++) {
        for (register int j = 0; j < result->columns; j++) {
          int k = 0;
          while (k < A->columns) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            k++;
          }
        }
      }
      code = OK;
    } else
      code = ERROR_CALCULATION;
  }
  return code;
}