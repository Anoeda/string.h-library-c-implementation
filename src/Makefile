CC=gcc 
ifeq ($(shell uname), Linux)
	CHKFLAGS=-pthread -lcheck_pic -pthread -lrt -lm -lsubunit
else
	CHKFLAGS=-lcheck
endif

all: s21_string.a

clean:
	@rm -rf *.o *.gcda *.gcno *.html *.css *.out *.a test gcov_report

s21_string.o: s21_string.c
	gcc -o s21_string.o $^ -c

s21_string.a: s21_string.o
	ar crs $@ $^

test:
	$(CC) s21_string.c -c -o s21_string_test.o
	$(CC) s21_test.c -c -o test_test.o
	$(CC) test_test.o s21_string_test.o -o $@ $(CHKFLAGS)
	./$@

gcov_report:
	$(CC) --coverage s21_string.c -c -o s21_string_coverage.o
	$(CC) s21_test.c -c -o test_coverage.o
	$(CC) s21_string_coverage.o test_coverage.o -o $@ $(CHKFLAGS) -lgcov
	./$@
	gcovr --html --html-details -o report.html

linter:
	@cp ../materials/linters/CPPLINT.cfg ./
	@find . -name "*.c" -exec python3 ../materials/linters/cpplint.py {} \;
	@find . -name "*.h" -exec python3 ../materials/linters/cpplint.py {} \;
	@rm -f CPPLINT.cfg

.PHONY: linter clean test gcov_report