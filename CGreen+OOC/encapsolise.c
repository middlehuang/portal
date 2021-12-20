/*
 * encapsolise.c
 *
 *  Created on: Dec 15, 2021
 *      Author: teuton
 */

#include <cgreen/cgreen.h>
#include"shape.h"

Shape test_sq;

Describe(encapsolise);
BeforeEach(encapsolise) {
	Shape_ctor(&test_sq, "sqareTS", 2.1, 3.3);
}
AfterEach(encapsolise) {}


Ensure(encapsolise, getter_function) {
	assert_that(Shape_getname(&test_sq), is_equal_to_string("sqareTS"));
//	free(&test_sq);
}

Ensure(encapsolise, moveby_function) {
	Shape_moveby(&test_sq, 1.1, 2.3);
	assert_that_double(Shape_getx(&test_sq), is_equal_to_double(2.1 + 1.1));
}

Ensure(encapsolise, setter_function) {
	Shape_sety(&test_sq, 2.7);
	assert_that_double(Shape_gety(&test_sq), is_equal_to_double(2.7));
}
TestSuite *encapsolise_tests() {
    TestSuite *suite = create_test_suite();
    add_test_with_context(suite, encapsolise, setter_function);
    add_test_with_context(suite, encapsolise, getter_function);
    add_test_with_context(suite, encapsolise, moveby_function);
    return suite;
}

