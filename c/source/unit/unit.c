/* unit.c -- unit tests for ??? */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "minunit.h"

/*
 * main() drops these here for anyone who wants them, keeping the code
 * in main() to a minimum.
 */

static
int argc;

static
char **argv;

/*
 * minunit setup and teardown.
 */

void
test_setup(void) {
	srand(6803); /* predictable but different sequence when using the bad generator. */
}

void
test_teardown(void) {}

/*
 * a test is made up of assertions
 */

MU_TEST(test_da) {
	mu_should(true);
	mu_shouldnt(false);
	mu_assert(1 == 1, "an assertion");
	mu_assert_int_eq(1, 1);
	printf("\nthis failure is deliberate for demonstration purposes\n");
	mu_assert_string_eq("expected", "result"); /* will fail */
}

/*
 * a test suite is made up of tests.
 */

MU_TEST_SUITE(test_suite) {

	MU_SUITE_CONFIGURE(test_setup, test_teardown);

	MU_RUN_TEST(test_da);
}

/*
 * and main runs the suites.
 */

int
main(int aargc, char *aargv[]) {
	argc = aargc;
	argv = aargv;

	MU_RUN_SUITE(test_suite);

	MU_REPORT();
	return MU_EXIT_CODE;
}
/* unit.c ends here */
