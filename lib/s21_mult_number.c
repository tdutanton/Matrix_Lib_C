#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  result_code code = ERROR_INCORRECT_MATRIX;
  if (result && check_acceptable_matrix(A)) {
    if (A != result) s21_create_matrix(A->rows, A->columns, result);
    for (register int i = 0; i < A->rows; i++) {
      for (register int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
        if (fabs(result->matrix[i][j]) == 0) result->matrix[i][j] = 0;
      }
    }
    code = OK;
  }
  return code;
}