#include "s21_test.h"

START_TEST(remove_1) {
  matrix_t value;
  s21_create_matrix(3, 3, &value);
  s21_remove_matrix(&value);
  ck_assert_int_eq(value.columns, 0);
  ck_assert_int_eq(value.rows, 0);
  ck_assert_ptr_null(value.matrix);
}
END_TEST

START_TEST(remove_2) {
  matrix_t *value = NULL;
  s21_remove_matrix(value);
  ck_assert_ptr_null(value);
}
END_TEST

Suite *test_s21_remove_matrix() {
  Suite *suite = suite_create("s21_remove_matrix");
  TCase *t_case = tcase_create("s21_remove_matrix");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, remove_1);
  tcase_add_test(t_case, remove_2);
  return suite;
}