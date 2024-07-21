#include "service.h"

#include "../s21_matrix.h"

void free_matrix(matrix_t* value) {
  if (value) {
    for (int i = 0; i < value->rows; i++) {
      free(value->matrix[i]);
    }
    free(value->matrix);
  }
}

int compare_matrix_elements(double a, double b) {
  int result = NOT_EQUAL;
  double accuracy = 0.0000001;
  if (fabs(a - b) < accuracy) result = EQUAL;
  return result;
}

int check_acceptable_matrix(matrix_t* value) {
  int result = FAILURE;
  if (value && value->rows > 0 && value->columns > 0) result = SUCCESS;
  return result;
}

int one_minor_matrix(int row, int col, matrix_t* value, matrix_t* result) {
  int code = FAILURE;
  if (check_acceptable_matrix(value) && result && row > 0 && col > 0 &&
      value->columns == value->rows) {
    s21_create_matrix(value->rows - 1, value->columns - 1, result);
    int minor_row = 0;
    for (register int i = 0; i < value->rows; i++) {
      if (i == row - 1) continue;
      int minor_col = 0;
      for (register int j = 0; j < value->columns; j++) {
        if (j == col - 1) continue;
        result->matrix[minor_row][minor_col] = value->matrix[i][j];
        minor_col++;
      }
      minor_row++;
    }
    code = SUCCESS;
  }
  return code;
}

int determinant_of_two(matrix_t value, double* determinant) {
  int code = FAILURE;
  if (check_acceptable_matrix(&value) && determinant && value.columns == 2 &&
      value.rows == 2) {
    *determinant = value.matrix[0][0] * value.matrix[1][1] -
                   value.matrix[1][0] * value.matrix[0][1];
    code = SUCCESS;
  }
  return code;
}

int determinant_of_triangle(matrix_t value, double* determinant) {
  int code = FAILURE;
  if (check_acceptable_matrix(&value) && determinant && value.columns == 3 &&
      value.rows == 3) {
    double pos_part =
        value.matrix[0][0] * value.matrix[1][1] * value.matrix[2][2] +
        value.matrix[1][0] * value.matrix[0][2] * value.matrix[2][1] +
        value.matrix[0][1] * value.matrix[1][2] * value.matrix[2][0];
    double neg_part =
        value.matrix[0][2] * value.matrix[1][1] * value.matrix[2][0] +
        value.matrix[0][1] * value.matrix[1][0] * value.matrix[2][2] +
        value.matrix[1][2] * value.matrix[2][1] * value.matrix[0][0];
    *determinant = pos_part - neg_part;
    code = SUCCESS;
  }
  return code;
}

void swap_rows(matrix_t* value, int row_1, int row_2) {
  for (register int i = 0; i < value->columns; i++) {
    double temp = value->matrix[row_1][i];
    value->matrix[row_1][i] = value->matrix[row_2][i];
    value->matrix[row_2][i] = temp;
  }
}

void add_multing_row(matrix_t* value, int row_give, int row_take, double mult) {
  for (register int i = 0; i < value->columns; i++) {
    value->matrix[row_give][i] += value->matrix[row_take][i] * mult;
  }
}

void get_upper_triangle_matrix(matrix_t* value, int* det_sign) {
  int swap_count = 0;
  for (register int i = 1; i < value->rows; i++) {
    for (register int j = i; j < value->columns; j++) {
      if (value->matrix[j][i - 1] != 0) {
        if (value->matrix[i - 1][i - 1] == 0) {
          swap_rows(value, i - 1, j);
          swap_count++;
        }
        double delta =
            value->matrix[j][i - 1] / value->matrix[i - 1][i - 1] * -1;
        add_multing_row(value, j, i - 1, delta);
        value->matrix[j][i - 1] = 0;
      }
    }
  }
  *det_sign = (swap_count % 2 == 0) ? 1 : -1;
}

void copy_matrix(matrix_t* value, matrix_t* dest) {
  for (register int i = 0; i < value->rows; i++) {
    for (register int j = 0; j < value->columns; j++) {
      dest->matrix[i][j] = value->matrix[i][j];
    }
  }
}