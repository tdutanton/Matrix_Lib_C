#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  result_code code = ERROR_INCORRECT_MATRIX;
  tmp_code temp_code = OK_TMP;
  if ((rows <= 0 || columns <= 0) && result) {
    result->rows = 0;
    result->columns = 0;
  } else if (rows > 0 && columns > 0 && result) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(rows * sizeof(double *));
    if (result->matrix) {
      for (register int i = 0; i < rows && temp_code;) {
        result->matrix[i] = (double *)malloc(columns * sizeof(double));
        if (result->matrix[i])
          i++;
        else
          temp_code = FAIL_TMP;
      }
    } else
      temp_code = FAIL_TMP;
    if (temp_code) {
      for (register int i = 0; i < rows; i++) {
        for (register int j = 0; j < columns; j++) {
          result->matrix[i][j] = 0;
        }
      }
      code = OK;
    }
  }
  return code;
}