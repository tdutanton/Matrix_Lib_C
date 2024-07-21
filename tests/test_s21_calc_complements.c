#include "s21_test.h"

START_TEST(calc_comp_1) {
  matrix_t value_1, comp_res, comp_check;
  s21_create_matrix(3, 3, &value_1);
  s21_create_matrix(3, 3, &comp_check);

  value_1.matrix[0][0] = 1;
  value_1.matrix[0][1] = 2;
  value_1.matrix[0][2] = 3;
  value_1.matrix[1][0] = 0;
  value_1.matrix[1][1] = 4;
  value_1.matrix[1][2] = 2;
  value_1.matrix[2][0] = 5;
  value_1.matrix[2][1] = 2;
  value_1.matrix[2][2] = 1;

  comp_check.matrix[0][0] = 0;
  comp_check.matrix[0][1] = 10;
  comp_check.matrix[0][2] = -20;
  comp_check.matrix[1][0] = 4;
  comp_check.matrix[1][1] = -14;
  comp_check.matrix[1][2] = 8;
  comp_check.matrix[2][0] = -8;
  comp_check.matrix[2][1] = -2;
  comp_check.matrix[2][2] = 4;

  int res = s21_calc_complements(&value_1, &comp_res);
  int check = OK;
  int res_matrix_eq = s21_eq_matrix(&comp_res, &comp_check);
  int check_eq = SUCCESS;
  ck_assert_int_eq(res, check);
  ck_assert_int_eq(res_matrix_eq, check_eq);

  s21_remove_matrix(&value_1);
  s21_remove_matrix(&comp_res);
  s21_remove_matrix(&comp_check);
}
END_TEST

START_TEST(calc_comp_2) {
  matrix_t value_1, comp_res;
  s21_create_matrix(3, 2, &value_1);

  int res = s21_calc_complements(&value_1, &comp_res);
  int check = ERROR_CALCULATION;
  ck_assert_int_eq(res, check);

  s21_remove_matrix(&value_1);
}
END_TEST

START_TEST(calc_comp_3) {
  matrix_t value_1, comp_check;
  s21_create_matrix(3, 3, &value_1);
  s21_create_matrix(3, 3, &comp_check);

  value_1.matrix[0][0] = 1;
  value_1.matrix[0][1] = 2;
  value_1.matrix[0][2] = 3;
  value_1.matrix[1][0] = 0;
  value_1.matrix[1][1] = 4;
  value_1.matrix[1][2] = 2;
  value_1.matrix[2][0] = 5;
  value_1.matrix[2][1] = 2;
  value_1.matrix[2][2] = 1;

  comp_check.matrix[0][0] = 0;
  comp_check.matrix[0][1] = 10;
  comp_check.matrix[0][2] = -20;
  comp_check.matrix[1][0] = 4;
  comp_check.matrix[1][1] = -14;
  comp_check.matrix[1][2] = 8;
  comp_check.matrix[2][0] = -8;
  comp_check.matrix[2][1] = -2;
  comp_check.matrix[2][2] = 4;

  int res = s21_calc_complements(&value_1, &value_1);
  int check = OK;
  int res_matrix_eq = s21_eq_matrix(&value_1, &comp_check);
  int check_eq = SUCCESS;
  ck_assert_int_eq(res, check);
  ck_assert_int_eq(res_matrix_eq, check_eq);

  s21_remove_matrix(&value_1);
  s21_remove_matrix(&comp_check);
}
END_TEST

START_TEST(calc_comp_4) {
  matrix_t value_1, comp_res;
  s21_create_matrix(3, 0, &value_1);

  int res = s21_calc_complements(&value_1, &comp_res);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(res, check);
}
END_TEST

START_TEST(calc_comp_5) {
  matrix_t value_1;
  matrix_t *comp_res = NULL;
  s21_create_matrix(3, 0, &value_1);

  int res = s21_calc_complements(&value_1, comp_res);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(res, check);
}
END_TEST

Suite *test_s21_calc_complements() {
  Suite *suite = suite_create("s21_calc_complements");
  TCase *t_case = tcase_create("s21_calc_complements");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, calc_comp_1);
  tcase_add_test(t_case, calc_comp_2);
  tcase_add_test(t_case, calc_comp_3);
  tcase_add_test(t_case, calc_comp_4);
  tcase_add_test(t_case, calc_comp_5);
  return suite;
}