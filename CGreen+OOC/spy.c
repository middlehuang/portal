/*
 * spy.c
 *
 *  Created on: Dec 17, 2021
 *      Author: teuton
 */

#include <cgreen/cgreen.h>

typedef struct {
	int a;
	int b;
	bool called_add;
}SpyOb;

Describe(spy_test);
BeforeEach(spy_test) {}
AfterEach(spy_test) {}

int Spy_add_up(SpyOb* obj){
	obj->called_add = true;
	return obj->a + obj->b;
}

Ensure(spy_test, spy_object) {
	SpyOb spyy;
	spyy.a = 1;
	spyy.b = 2;
	spyy.called_add = false;
	assert_that(Spy_add_up(&spyy), is_equal_to(3));
	assert_that(spyy.called_add, is_true);
}

TestSuite *spy_tests() {
    TestSuite *suite = create_test_suite();
    add_test_with_context(suite, spy_test, spy_object);
    return suite;
}
