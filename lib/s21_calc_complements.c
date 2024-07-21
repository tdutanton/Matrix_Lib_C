#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  result_code code = ERROR_INCORRECT_MATRIX;
  if (check_acceptable_matrix(A) && result) {
    if (A->rows != A->columns)
      code = ERROR_CALCULATION;
    else {
      matrix_t self;
      s21_create_matrix(A->columns, A->rows, &self);
      if (A != result) s21_create_matrix(A->rows, A->columns, result);
      for (register int i = 0; i < A->rows; i++) {
        for (register int j = 0; j < A->columns; j++) {
          matrix_t tmp;
          double minor = 0;
          one_minor_matrix(i + 1, j + 1, A, &tmp);
          s21_determinant(&tmp, &minor);
          self.matrix[i][j] = pow(-1, i + j) * minor;
          s21_remove_matrix(&tmp);
        }
      }
      copy_matrix(&self, result);
      s21_remove_matrix(&self);
      code = OK;
    }
  }
  return code;
}