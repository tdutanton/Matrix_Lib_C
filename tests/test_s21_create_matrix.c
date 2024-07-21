#include "s21_test.h"

START_TEST(create_1) {
  matrix_t value;
  int res = s21_create_matrix(3, 3, &value);
  int check = OK;
  ck_assert_int_eq(res, check);
  free_matrix(&value);
}
END_TEST

START_TEST(create_2) {
  matrix_t value;
  int res = s21_create_matrix(0, 3, &value);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(res, check);
}
END_TEST

START_TEST(create_3) {
  matrix_t value;
  int res = s21_create_matrix(3, 0, &value);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(res, check);
}
END_TEST

START_TEST(create_4) {
  matrix_t value;
  int res = s21_create_matrix(0, 0, &value);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(res, check);
}
END_TEST

START_TEST(create_5) {
  matrix_t value;
  int res = s21_create_matrix(0, -3, &value);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(res, check);
}
END_TEST

START_TEST(create_6) {
  matrix_t *value = NULL;
  int res = s21_create_matrix(3, 3, value);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(res, check);
}
END_TEST

START_TEST(create_7) {
  matrix_t *value = NULL;
  int res = s21_create_matrix(-3, -3, value);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(res, check);
}
END_TEST

Suite *test_s21_create_matrix() {
  Suite *suite = suite_create("s21_create_matrix");
  TCase *t_case = tcase_create("s21_create_matrix");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, create_1);
  tcase_add_test(t_case, create_2);
  tcase_add_test(t_case, create_3);
  tcase_add_test(t_case, create_4);
  tcase_add_test(t_case, create_5);
  tcase_add_test(t_case, create_6);
  tcase_add_test(t_case, create_7);
  return suite;
}