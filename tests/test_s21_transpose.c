#include "s21_test.h"

START_TEST(transpose_1) {
  matrix_t value_1, res, check;
  s21_create_matrix(2, 3, &value_1);
  s21_create_matrix(3, 2, &check);
  int k = 1;
  for (register int i = 0; i < value_1.rows; i++) {
    for (register int j = 0; j < value_1.columns; j++) {
      value_1.matrix[i][j] = k;
      k++;
    }
  }

  check.matrix[0][0] = 1;
  check.matrix[0][1] = 4;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = 5;
  check.matrix[2][0] = 3;
  check.matrix[2][1] = 6;

  int result = s21_transpose(&value_1, &res);
  int check_c = OK;
  int res_matrix_eq = s21_eq_matrix(&res, &check);
  int check_eq = SUCCESS;
  ck_assert_int_eq(result, check_c);
  ck_assert_int_eq(res_matrix_eq, check_eq);

  s21_remove_matrix(&value_1);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t value_1, res;
  s21_create_matrix(3, -2, &value_1);

  int result = s21_transpose(&value_1, &res);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(result, check);
}
END_TEST

Suite *test_s21_transpose() {
  Suite *suite = suite_create("s21_transpose");
  TCase *t_case = tcase_create("s21_transpose");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, transpose_1);
  tcase_add_test(t_case, transpose_2);
  return suite;
}