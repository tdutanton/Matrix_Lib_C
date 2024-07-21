#include "s21_test.h"

START_TEST(mult_m_1) {
  matrix_t value_1, value_2, mul_res, mul_check;
  s21_create_matrix(3, 2, &value_1);
  s21_create_matrix(2, 3, &value_2);
  s21_create_matrix(3, 3, &mul_check);
  int k = 1;
  int m = 1;
  for (register int i = 0; i < value_1.rows; i++) {
    for (register int j = 0; j < value_1.columns; j++) {
      value_1.matrix[i][j] = k;
      k++;
    }
  }

  for (register int i = 0; i < value_2.rows; i++) {
    for (register int j = 0; j < value_2.columns; j++) {
      value_2.matrix[i][j] = m;
      m++;
    }
  }

  mul_check.matrix[0][0] = 9;
  mul_check.matrix[0][1] = 12;
  mul_check.matrix[0][2] = 15;
  mul_check.matrix[1][0] = 19;
  mul_check.matrix[1][1] = 26;
  mul_check.matrix[1][2] = 33;
  mul_check.matrix[2][0] = 29;
  mul_check.matrix[2][1] = 40;
  mul_check.matrix[2][2] = 51;

  int res = s21_mult_matrix(&value_1, &value_2, &mul_res);
  int check = OK;
  int res_matrix_eq = s21_eq_matrix(&mul_res, &mul_check);
  int check_eq = SUCCESS;
  ck_assert_int_eq(res, check);
  ck_assert_int_eq(res_matrix_eq, check_eq);

  s21_remove_matrix(&value_1);
  s21_remove_matrix(&value_2);
  s21_remove_matrix(&mul_res);
  s21_remove_matrix(&mul_check);
}
END_TEST

START_TEST(mult_m_2) {
  matrix_t value_1, value_2, mul_res;
  s21_create_matrix(3, -2, &value_1);
  s21_create_matrix(2, 3, &value_2);

  int res = s21_mult_matrix(&value_1, &value_2, &mul_res);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(res, check);

  s21_remove_matrix(&value_2);
}
END_TEST

START_TEST(mult_m_3) {
  matrix_t value_1, value_2, mul_res;
  s21_create_matrix(3, 5, &value_1);
  s21_create_matrix(2, 3, &value_2);

  int res = s21_mult_matrix(&value_1, &value_2, &mul_res);
  int check = ERROR_CALCULATION;
  ck_assert_int_eq(res, check);
  s21_remove_matrix(&value_1);
  s21_remove_matrix(&value_2);
}
END_TEST

Suite *test_s21_mult_matrix() {
  Suite *suite = suite_create("s21_mult_matrix");
  TCase *t_case = tcase_create("s21_mult_matrix");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, mult_m_1);
  tcase_add_test(t_case, mult_m_2);
  tcase_add_test(t_case, mult_m_3);
  return suite;
}