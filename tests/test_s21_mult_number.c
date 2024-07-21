#include "s21_test.h"

START_TEST(mult_1) {
  matrix_t value_1, mul_res, mul_check;
  double mul = 2;
  s21_create_matrix(3, 3, &value_1);
  s21_create_matrix(3, 3, &mul_check);
  value_1.matrix[0][0] = 2;
  mul_check.matrix[0][0] = 4;
  int res = s21_mult_number(&value_1, mul, &mul_res);
  int check = OK;
  int res_matrix_eq = s21_eq_matrix(&mul_res, &mul_check);
  int check_eq = SUCCESS;
  ck_assert_int_eq(res, check);
  ck_assert_int_eq(res_matrix_eq, check_eq);

  s21_remove_matrix(&value_1);
  s21_remove_matrix(&mul_res);
  s21_remove_matrix(&mul_check);
}
END_TEST

Suite *test_s21_mult_number() {
  Suite *suite = suite_create("s21_mult_number");
  TCase *t_case = tcase_create("s21_mult_number");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, mult_1);
  return suite;
}