#include "s21_test.h"

START_TEST(inverse_1) {
  matrix_t value_1, inv_res, inv_check;
  s21_create_matrix(3, 3, &value_1);
  s21_create_matrix(3, 3, &inv_check);

  value_1.matrix[0][0] = 2;
  value_1.matrix[0][1] = 5;
  value_1.matrix[0][2] = 7;
  value_1.matrix[1][0] = 6;
  value_1.matrix[1][1] = 3;
  value_1.matrix[1][2] = 4;
  value_1.matrix[2][0] = 5;
  value_1.matrix[2][1] = -2;
  value_1.matrix[2][2] = -3;

  inv_check.matrix[0][0] = 1;
  inv_check.matrix[0][1] = -1;
  inv_check.matrix[0][2] = 1;
  inv_check.matrix[1][0] = -38;
  inv_check.matrix[1][1] = 41;
  inv_check.matrix[1][2] = -34;
  inv_check.matrix[2][0] = 27;
  inv_check.matrix[2][1] = -29;
  inv_check.matrix[2][2] = 24;

  int res = s21_inverse_matrix(&value_1, &inv_res);
  int check = OK;
  int res_matrix_eq = s21_eq_matrix(&inv_res, &inv_check);
  int check_eq = SUCCESS;
  ck_assert_int_eq(res, check);
  ck_assert_int_eq(res_matrix_eq, check_eq);

  s21_remove_matrix(&value_1);
  s21_remove_matrix(&inv_res);
  s21_remove_matrix(&inv_check);
}
END_TEST

START_TEST(inverse_2) {
  matrix_t value_1, inv_res;
  s21_create_matrix(3, 0, &value_1);

  int res = s21_inverse_matrix(&value_1, &inv_res);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(res, check);
}
END_TEST

START_TEST(inverse_3) {
  matrix_t value_1;
  matrix_t *inv_res = NULL;
  s21_create_matrix(3, 0, &value_1);

  int res = s21_inverse_matrix(&value_1, inv_res);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(res, check);
}
END_TEST

START_TEST(inverse_4) {
  matrix_t value_1, inv_res;
  s21_create_matrix(3, 2, &value_1);

  int res = s21_inverse_matrix(&value_1, &inv_res);
  int check = ERROR_CALCULATION;
  ck_assert_int_eq(res, check);
  s21_remove_matrix(&value_1);
}
END_TEST

START_TEST(inverse_5) {
  matrix_t value_1, inv_res;
  s21_create_matrix(2, 2, &value_1);
  value_1.matrix[0][0] = 0;
  value_1.matrix[0][1] = 0;
  value_1.matrix[1][0] = 2;
  value_1.matrix[1][1] = 3;

  int res = s21_inverse_matrix(&value_1, &inv_res);
  int check = ERROR_CALCULATION;
  ck_assert_int_eq(res, check);
  s21_remove_matrix(&value_1);
}
END_TEST

Suite *test_s21_inverse_matrix() {
  Suite *suite = suite_create("s21_inverse_matrix");
  TCase *t_case = tcase_create("s21_inverse_matrix");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, inverse_1);
  tcase_add_test(t_case, inverse_2);
  tcase_add_test(t_case, inverse_3);
  tcase_add_test(t_case, inverse_4);
  tcase_add_test(t_case, inverse_5);
  return suite;
}