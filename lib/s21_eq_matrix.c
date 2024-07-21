#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = FAILURE;
  if (A->rows == B->rows && A->columns == B->columns &&
      check_acceptable_matrix(A) && check_acceptable_matrix(B)) {
    int compare_tmp = EQUAL;
    for (register int i = 0; i < A->rows && compare_tmp == EQUAL; i++) {
      for (register int j = 0; j < A->columns && compare_tmp == EQUAL; j++) {
        compare_tmp = compare_matrix_elements(A->matrix[i][j], B->matrix[i][j]);
      }
    }
    if (compare_tmp == EQUAL) result = SUCCESS;
  }
  return result;
}