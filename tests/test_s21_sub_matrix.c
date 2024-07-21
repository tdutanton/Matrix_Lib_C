#include "s21_test.h"

START_TEST(sub_1) {
  matrix_t value_1, value_2, sum_res, sum_check;
  s21_create_matrix(3, 3, &value_1);
  s21_create_matrix(3, 3, &value_2);
  s21_create_matrix(3, 3, &sum_check);
  value_1.matrix[0][0] = 2;
  value_2.matrix[0][0] = 1;
  sum_check.matrix[0][0] = 1;
  int res = s21_sub_matrix(&value_1, &value_2, &sum_res);
  int check = OK;
  int res_matrix_eq = s21_eq_matrix(&sum_res, &sum_check);
  int check_eq = SUCCESS;
  ck_assert_int_eq(res, check);
  ck_assert_int_eq(res_matrix_eq, check_eq);

  s21_remove_matrix(&value_1);
  s21_remove_matrix(&value_2);
  s21_remove_matrix(&sum_res);
  s21_remove_matrix(&sum_check);
}
END_TEST

START_TEST(sub_2) {
  matrix_t value_1, value_2, sum_res;
  s21_create_matrix(3, 3, &value_1);
  s21_create_matrix(3, 2, &value_2);
  int res = s21_sum_matrix(&value_1, &value_2, &sum_res);
  int check = ERROR_CALCULATION;
  ck_assert_int_eq(res, check);

  s21_remove_matrix(&value_1);
  s21_remove_matrix(&value_2);
}
END_TEST

START_TEST(sub_3) {
  matrix_t value_1, value_2, sum_res;
  s21_create_matrix(3, -3, &value_1);
  s21_create_matrix(3, 2, &value_2);
  int res = s21_sum_matrix(&value_1, &value_2, &sum_res);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(res, check);

  s21_remove_matrix(&value_2);
}
END_TEST

START_TEST(sub_4) {
  matrix_t value_1, value_2, sum_res;
  s21_create_matrix(3, 3, &value_1);
  s21_create_matrix(-2, 3, &value_2);
  int res = s21_sum_matrix(&value_1, &value_2, &sum_res);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(res, check);

  s21_remove_matrix(&value_1);
}
END_TEST

Suite *test_s21_sub_matrix() {
  Suite *suite = suite_create("s21_sub_matrix");
  TCase *t_case = tcase_create("s21_sub_matrix");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, sub_1);
  tcase_add_test(t_case, sub_2);
  tcase_add_test(t_case, sub_3);
  tcase_add_test(t_case, sub_4);
  return suite;
}