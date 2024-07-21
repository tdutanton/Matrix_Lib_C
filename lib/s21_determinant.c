#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  result_code code = ERROR_INCORRECT_MATRIX;
  if (check_acceptable_matrix(A) && result) {
    *result = 1;
    if (A->rows != A->columns)
      code = ERROR_CALCULATION;
    else {
      if (A->rows == 1)
        *result = A->matrix[0][0];
      else if (A->rows == 2)
        determinant_of_two(*A, result);
      else if (A->rows == 3)
        determinant_of_triangle(*A, result);
      else {
        matrix_t tmp = *A;
        int sign = 0;
        get_upper_triangle_matrix(&tmp, &sign);
        for (register int i = 0; i < A->rows; i++) {
          *result *= tmp.matrix[i][i];
        }
        *result *= sign;
      }
      code = OK;
    }
  }
  return code;
}
