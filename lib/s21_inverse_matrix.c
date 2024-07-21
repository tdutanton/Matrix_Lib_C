#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  result_code code = ERROR_INCORRECT_MATRIX;
  if (check_acceptable_matrix(A) && result) {
    double det = 0;
    int res_det = s21_determinant(A, &det);
    if (A->rows != A->columns || (res_det == OK && det == 0))
      code = ERROR_CALCULATION;
    else {
      s21_calc_complements(A, result);
      s21_transpose(result, result);
      s21_mult_number(result, -1, result);
      code = OK;
    }
  }
  return code;
}