/*
 * main.c
 *
 *  Created on: Dec 14, 2021
 *      Author: teuton
 */

#include "rect.h"   /* Rectangle class interface */
#include "circle.h" /* Circle class interface */
#include <stdio.h>  /* for printf() */
#include<stdlib.h>
#include <cgreen/cgreen.h>

TestSuite *encapsolise_tests();
TestSuite *Inherence_tests();
TestSuite *Vertual_tests();
TestSuite *stub_tests();
TestSuite *spy_tests();
TestSuite *mock_tests();

int main(int argc, char **argv) {
    TestSuite *suite = create_test_suite();
    add_suite(suite, encapsolise_tests());
    add_suite(suite, Inherence_tests());
    add_suite(suite, Vertual_tests());
    add_suite(suite, stub_tests());
    add_suite(suite, spy_tests());
    add_suite(suite, mock_tests());
    if (argc > 1) {
    	return run_single_test(suite, argv[1], create_text_reporter());
    }
    return run_test_suite(suite, create_text_reporter());
}
