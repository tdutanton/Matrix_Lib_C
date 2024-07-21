#include "s21_test.h"

START_TEST(eq_1) {
  matrix_t value_1, value_2;
  s21_create_matrix(3, 3, &value_1);
  s21_create_matrix(3, 3, &value_2);
  value_1.matrix[0][0] = 1;
  value_2.matrix[0][0] = 1;
  int res = s21_eq_matrix(&value_1, &value_2);
  int check = SUCCESS;
  ck_assert_int_eq(res, check);

  s21_remove_matrix(&value_1);
  s21_remove_matrix(&value_2);
}
END_TEST

START_TEST(eq_2) {
  matrix_t value_1, value_2;
  s21_create_matrix(3, 3, &value_1);
  s21_create_matrix(3, 3, &value_2);
  value_1.matrix[0][0] = 1;
  value_2.matrix[0][0] = 2;
  int res = s21_eq_matrix(&value_1, &value_2);
  int check = FAILURE;
  ck_assert_int_eq(res, check);

  s21_remove_matrix(&value_1);
  s21_remove_matrix(&value_2);
}
END_TEST

START_TEST(eq_3) {
  matrix_t value_1, value_2;
  s21_create_matrix(3, 3, &value_1);
  s21_create_matrix(3, 3, &value_2);
  value_1.matrix[0][0] = 1.12345678;
  value_2.matrix[0][0] = 1.12345679;
  int res = s21_eq_matrix(&value_1, &value_2);
  int check = SUCCESS;
  ck_assert_int_eq(res, check);

  s21_remove_matrix(&value_1);
  s21_remove_matrix(&value_2);
}
END_TEST

START_TEST(eq_4) {
  matrix_t value_1, value_2;
  s21_create_matrix(3, 3, &value_1);
  s21_create_matrix(3, 3, &value_2);
  value_1.matrix[0][0] = 1.12345688;
  value_2.matrix[0][0] = 1.12345678;
  int res = s21_eq_matrix(&value_1, &value_2);
  int check = FAILURE;
  ck_assert_int_eq(res, check);

  s21_remove_matrix(&value_1);
  s21_remove_matrix(&value_2);
}
END_TEST

START_TEST(eq_5) {
  matrix_t value_1, value_2;
  s21_create_matrix(2, 3, &value_1);
  s21_create_matrix(6, 3, &value_2);
  int res = s21_eq_matrix(&value_1, &value_2);
  int check = FAILURE;
  ck_assert_int_eq(res, check);

  s21_remove_matrix(&value_1);
  s21_remove_matrix(&value_2);
}
END_TEST

START_TEST(eq_6) {
  matrix_t value_1, value_2;
  s21_create_matrix(-2, 3, &value_1);
  s21_create_matrix(6, -3, &value_2);
  int res = s21_eq_matrix(&value_1, &value_2);
  int check = FAILURE;
  ck_assert_int_eq(res, check);
}
END_TEST

Suite *test_s21_eq_matrix() {
  Suite *suite = suite_create("s21_eq_matrix");
  TCase *t_case = tcase_create("s21_eq_matrix");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, eq_1);
  tcase_add_test(t_case, eq_2);
  tcase_add_test(t_case, eq_3);
  tcase_add_test(t_case, eq_4);
  tcase_add_test(t_case, eq_5);
  tcase_add_test(t_case, eq_6);
  return suite;
}