#include "greatest.h"

TEST x_should_equal_1(void) {
    int x = 1;
    ASSERT_EQ(1, x);                              /* default message */
    ASSERT_EQm("yikes, x doesn't equal 1", 1, x); /* custom message */
    /* printf expected and actual values as "%d" if they differ */
    ASSERT_EQ_FMT(1, x, "%d");
    PASS();
}

TEST x_should_equal_1000(void) {
    int x;
    x = return_a_int();

    ASSERT_EQ(1000, x);                              /* default message */
    ASSERT_EQm("yikes, x doesn't equal 1", 1000, x); /* custom message */
    /* printf expected and actual values as "%d" if they differ */
    ASSERT_EQ_FMT(1000, x, "%d");
    PASS();
}

SUITE(io_test) {
    RUN_TEST(x_should_equal_1);
    RUN_TEST(x_should_equal_1000);
}

/* Expand to all the definitions that need to be in
the test runner's main file. */
GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();      /* command-line arguments, initialization. */
    RUN_SUITE(io_test);         /* run a suite */
    GREATEST_MAIN_END();        /* display results */
}
