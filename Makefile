SHELL = /bin/sh

CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
LFLAGS = -lcheck -lm -lsubunit
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
EXE_NAME = test
LIB_NAME = s21_matrix.a

LIB_SRC = $(wildcard lib/*.c)
TEST_SRC = $(wildcard tests/*.c)

LIB_O = $(LIB_SRC:.c=.o)
TEST_O = $(TEST_SRC:.c=.o)

GCOV_NAME = gcov_tests.info

.PHONY: all clean s21_matrix.a clang_check clang_fix test gcov_report rebuild valgrind_test cppcheck_test

all: clean s21_matrix.a

s21_matrix.a: $(LIB_O)
	@ar rc $(LIB_NAME) $(LIB_O)
	@ranlib $(LIB_NAME)
	@rm -rf lib/*.o

test: $(TEST_O) $(LIB_NAME)
	@$(CC) $(CFLAGS) $(TEST_O) -o $(EXE_NAME) -L. -l:$(LIB_NAME) $(LFLAGS)
	@rm -rf $(TEST_O)
	@./$(EXE_NAME)
	@rm $(LIB_NAME)

gcov_report: clean
	$(CC) $(CFLAGS) -c $(LIB_SRC) --coverage
	$(CC) $(CFLAGS) -c $(TEST_SRC) 
	$(CC) *.o -o $(EXE_NAME) $(LFLAGS) $(GCOV_FLAGS)
	./$(EXE_NAME)
	lcov -t "gcov_tests" -o $(GCOV_NAME) -c -d .
	genhtml -o report $(GCOV_NAME)
	rm -rf *.o *.gcno *.gcda *.gcov $(GCOV_NAME)
	rm -rf $(EXE_NAME)

clean:
	rm -f $(LIB_NAME) $(EXE_NAME) ./lib/*.o
	rm -rf ./lib/*.o ./tests/*.o *.gcno *.gcda ./report *.o ./lib/*.gcno
	rm -rf $(EXE_NAME)

clang_check:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.h lib/*.c lib/*.h tests/*.c tests/*.h
	rm -rf .clang-format

clang_fix:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i *.h lib/*.c lib/*.h tests/*.c tests/*.h
	rm -rf .clang-format

rebuild: clean s21_matrix.a test

valgrind_test: rebuild
	valgrind --tool=memcheck --leak-check=yes --show-leak-kinds=all --track-origins=yes -s ./$(EXE_NAME)

cppcheck_test: 
	cppcheck --enable=all --suppress=missingIncludeSystem $(LIB_SRC)