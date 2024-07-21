#include "s21_test.h"

START_TEST(determinant_1) {
  matrix_t value_1;
  s21_create_matrix(3, 3, &value_1);
  int k = 1;
  for (register int i = 0; i < value_1.rows; i++) {
    for (register int j = 0; j < value_1.columns; j++) {
      value_1.matrix[i][j] = k;
      k++;
    }
  }

  value_1.matrix[2][0] = 11;
  double result = 0;
  int res = s21_determinant(&value_1, &result);
  int check = OK;
  double check_det = -12;
  ck_assert_int_eq(res, check);
  ck_assert_double_eq(result, check_det);

  s21_remove_matrix(&value_1);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t A;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 0;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[1][3] = 5;
  A.matrix[2][0] = 11;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  A.matrix[2][3] = 0;
  A.matrix[3][0] = 0;
  A.matrix[3][1] = 2;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 0;

  double result = 0;
  int res = s21_determinant(&A, &result);
  int check = OK;
  double check_det = 240;
  ck_assert_int_eq(res, check);
  ck_assert_double_eq_tol(result, check_det, 0.0000001);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t value_1;
  s21_create_matrix(2, 2, &value_1);
  int k = 1;
  for (register int i = 0; i < value_1.rows; i++) {
    for (register int j = 0; j < value_1.columns; j++) {
      value_1.matrix[i][j] = k;
      k++;
    }
  }

  double result = 0;
  int res = s21_determinant(&value_1, &result);
  int check = OK;
  double check_det = -2;
  ck_assert_int_eq(res, check);
  ck_assert_double_eq(result, check_det);

  s21_remove_matrix(&value_1);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;

  double result = 0;
  int res = s21_determinant(&A, &result);
  int check = OK;
  double check_det = 12;
  ck_assert_int_eq(res, check);
  ck_assert_double_eq_tol(result, check_det, 0.0000001);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 8;

  double result = 0;
  int res = s21_determinant(&A, &result);
  int check = OK;
  double check_det = -25;
  ck_assert_int_eq(res, check);
  ck_assert_double_eq_tol(result, check_det, 0.0000001);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_6) {
  matrix_t A;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 1;
  A.matrix[1][0] = 10;
  A.matrix[1][1] = 56;
  A.matrix[1][2] = 4;
  A.matrix[1][3] = 8;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 10;
  A.matrix[2][2] = 23;
  A.matrix[2][3] = 4;
  A.matrix[3][0] = 6;
  A.matrix[3][1] = 4;
  A.matrix[3][2] = 5;
  A.matrix[3][3] = 9;

  double result = 0;
  int res = s21_determinant(&A, &result);
  int check = OK;
  double check_det = -13522;
  ck_assert_int_eq(res, check);
  ck_assert_double_eq_tol(result, check_det, 0.0000001);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_7) {
  matrix_t value_1;
  double result = 0;
  s21_create_matrix(3, 0, &value_1);

  int res = s21_determinant(&value_1, &result);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(res, check);
}
END_TEST

START_TEST(determinant_8) {
  matrix_t value_1;
  double result = 0;
  s21_create_matrix(3, 2, &value_1);

  int res = s21_determinant(&value_1, &result);
  int check = ERROR_CALCULATION;
  ck_assert_int_eq(res, check);
  s21_remove_matrix(&value_1);
}
END_TEST

START_TEST(determinant_9) {
  matrix_t value_1;
  double *result = NULL;
  s21_create_matrix(3, 2, &value_1);

  int res = s21_determinant(&value_1, result);
  int check = ERROR_INCORRECT_MATRIX;
  ck_assert_int_eq(res, check);
  s21_remove_matrix(&value_1);
}
END_TEST

START_TEST(determinant_10) {
  matrix_t value_1;
  double result = 0;
  s21_create_matrix(1, 1, &value_1);
  value_1.matrix[0][0] = 2;
  double det_check = 2;
  int res = s21_determinant(&value_1, &result);
  int check = OK;
  ck_assert_int_eq(res, check);
  ck_assert_double_eq(det_check, result);
  s21_remove_matrix(&value_1);
}
END_TEST

Suite *test_s21_determinant() {
  Suite *suite = suite_create("s21_determinant");
  TCase *t_case = tcase_create("s21_determinant");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, determinant_1);
  tcase_add_test(t_case, determinant_2);
  tcase_add_test(t_case, determinant_3);
  tcase_add_test(t_case, determinant_4);
  tcase_add_test(t_case, determinant_5);
  tcase_add_test(t_case, determinant_6);
  tcase_add_test(t_case, determinant_7);
  tcase_add_test(t_case, determinant_8);
  tcase_add_test(t_case, determinant_9);
  tcase_add_test(t_case, determinant_10);
  return suite;
}