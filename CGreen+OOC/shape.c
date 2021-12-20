/*
 * shape.c
 *
 *  Created on: Dec 14, 2021
 *      Author: teuton
 */

#include "shape.h"
//#include <cgreen/cgreen.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>

//Describe(Cgreen);
//BeforeEach(Cgreen) {}
//AfterEach(Cgreen) {}

/* Shape's prototypes of its virtual functions */
static void Shape_xtor_(Shape * this);
static double Shape_area_(Shape * this);
static void Shape_draw_(Shape * this);

/* constructor */
void Shape_ctor(Shape * this, const char* name, double x, double y){
	static struct ShapeVtbl vtbl = { /* vtbl of the Shape class */
			&Shape_xtor_,
	        &Shape_area_,
	        &Shape_draw_
	};
	this->vptr = &vtbl; /* "hook" the vptr to the vtbl */
	this->__name = malloc(sizeof(char)* (strlen(name)+1));
	if(this->__name == NULL){
		puts("initialize object fail4");
		return;
	}
	strcpy(this->__name, name);
	this->__x = x;
	this->__y = y;
}

/* move-by operation */
void Shape_moveby(Shape* this, double dx, double dy){
	this->__x += dx;
	this->__y += dy;
}

/* "getter" operations implementation */
char* Shape_getname(Shape * this){
	return this->__name;
}


double Shape_getx(Shape * this){
	return this->__x;
}

double Shape_gety(Shape * this){
	return this->__y;
}

void Shape_setx(Shape * this, double x){
	this->__x = x;
}

void Shape_sety(Shape * this, double y){
	this->__y = y;
}

/* Shape class implementations of its virtual functions... */
void Shape_xtor_(Shape * this){
	free(this);
}

static double Shape_area_(Shape * this) {
    assert(0); /* purely-virtual function should never be called */
    return 0.0; /* to avoid compiler warnings */
}

static void Shape_draw_(Shape * this) {
    assert(0); /* purely-virtual function should never be called */
}

/* the following code finds the largest-area shape in the collection */
Shape const *largestShape(Shape *shapes[], uint32_t nShapes) {
    Shape const *s = (Shape *)0;
    double max = 0.0;
    uint32_t i;
    for (i = 0U; i < nShapes; ++i) {
        double area = Shape_area(shapes[i]); /* virtual call */
        if (area > max) {
            max = area;
            s = shapes[i];
        }
    }
    return s; /* the largest shape in the array shapes[] */
}

/* The following code will draw all Shapes on the screen */
void drawAllShapes(Shape *shapes[], uint32_t nShapes) {
    uint32_t i;
    for (i = 0U; i < nShapes; ++i) {
        Shape_draw(shapes[i]); /* virtual call */
    }
}
