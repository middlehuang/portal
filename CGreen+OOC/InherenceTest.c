/*
 * InherenceTest.c
 *
 *  Created on: Dec 15, 2021
 *      Author: teuton
 */

#include <cgreen/cgreen.h>
#include"rect.h"

Rectangle rec;

Describe(Inherence);
BeforeEach(Inherence) {
	Rectangle_ctor(&rec, "rect3", 2.1, 3.2, 4.5, 5.4);
}
AfterEach(Inherence) {}

Ensure(Inherence, higher_function) {
	assert_that_double(Rectangle_getHeight(&rec), is_equal_to_double(5.4));
//	free(&test_sq);
}

Ensure(Inherence, lower_function) {
	assert_that(Shape_getname(&rec.super), is_equal_to_string("rect3"));
}

Ensure(Inherence, lower_function_change) {
	Shape_moveby(&rec.super, 1.1, 2.2);
	assert_that_double(Shape_getx(&rec.super), is_equal_to_double(2.1 + 1.1));
}

Ensure(Inherence, vertual_function) {
	assert_that_double(Shape_area(&rec.super), is_equal_to_double(4.5 * 5.4));
}

TestSuite *Inherence_tests() {
    TestSuite *suite = create_test_suite();
    add_test_with_context(suite, Inherence, higher_function);
    add_test_with_context(suite, Inherence, lower_function);
    add_test_with_context(suite, Inherence, lower_function_change);
    add_test_with_context(suite, Inherence, vertual_function);
    return suite;
}

