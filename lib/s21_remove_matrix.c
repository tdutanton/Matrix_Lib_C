#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A) {
    free_matrix(A);
    A->rows = 0;
    A->columns = 0;
    A->matrix = NULL;
  }
}