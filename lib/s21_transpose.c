#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  result_code code = ERROR_INCORRECT_MATRIX;
  if (result && check_acceptable_matrix(A)) {
    matrix_t temp;
    s21_create_matrix(A->columns, A->rows, &temp);
    if (A != result) s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        temp.matrix[j][i] = A->matrix[i][j];
      }
    }
    copy_matrix(&temp, result);
    s21_remove_matrix(&temp);
    code = OK;
  }
  return code;
}