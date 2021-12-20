/*
 * mock.c
 *
 *  Created on: Dec 17, 2021
 *      Author: teuton
 */

#include <cgreen/cgreen.h>
#include <cgreen/mocks.h>

void mocked_callback(int x, int y) {
    mock(x, y);
}

typedef struct {
	int a;
	int b;
}MockOb;

Describe(mock_test);
BeforeEach(mock_test) {}
AfterEach(mock_test) {}

void Mock_add_more(MockOb* obj){
	mocked_callback(obj->a, obj->b);
	obj->a += 1;
	obj->b += 2;
	mocked_callback(obj->a, obj->b);
}

Ensure(mock_test, mock_object) {
	MockOb mocky;
	mocky.a = 2;
	mocky.b = 1;
	expect(mocked_callback,
			when(x, is_equal_to(2)),
			when(y, is_equal_to(1)));
	expect(mocked_callback,
			when(x, is_equal_to(3)),
			when(y, is_equal_to(3)));
	Mock_add_more(&mocky);
}

TestSuite *mock_tests() {
    TestSuite *suite = create_test_suite();
    add_test_with_context(suite, mock_test, mock_object);
    return suite;
}
