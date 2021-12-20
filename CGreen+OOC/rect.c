/*
 * rect.c
 *
 *  Created on: Dec 14, 2021
 *      Author: teuton
 */

#include "rect.h"
//#include <cgreen/cgreen.h>
#include<stdio.h>
#include<stdlib.h>

//Describe(Cgreen);
//BeforeEach(Cgreen) {}
//AfterEach(Cgreen) {}

/* Rectangle's prototypes of its virtual functions */
/* NOTE: the "me" pointer has the type of the superclass to fit the vtable */
static void Rectangle_xtor_(Shape * this);
static double Rectangle_area_(Shape * this);
static void Rectangle_draw_(Shape * this);

/* constructor */
void Rectangle_ctor(Rectangle * this, char* name, double x, double y, double width, double height){
    static struct ShapeVtbl vtbl = { /* vtbl of the Rectangle class */
    	&Rectangle_xtor_,
        &Rectangle_area_,
        &Rectangle_draw_
    };
    Shape_ctor(&this->super, name, x, y); /* call the superclass' ctor */
    this->super.vptr = &vtbl; /* override the vptr */
    this->__width = width;
    this->__height = height;
}

/* Rectangle's class implementations of its virtual functions... */
static void Rectangle_xtor_(Shape * this){
    Rectangle * me_ = (Rectangle *)this; /* explicit downcast */
    free(me_);
}

double Rectangle_area_(Shape * this) {
    Rectangle * me_ = (Rectangle *)this; /* explicit downcast */
    return me_->__width * me_->__height;
}

void Rectangle_draw_(Shape * this) {
    Rectangle * me_ = (Rectangle *)this; /* explicit downcast */
    printf("Rectangle_draw_(x=%f2,y=%f2,width=%f2,height=%f2)\n", Shape_getx(this), Shape_gety(this), me_->__width, me_->__height);
}

double Rectangle_getWidth(Rectangle * this){
	return this->__width;
}
double Rectangle_getHeight(Rectangle * this){
	return this->__height;
}
void Rectangle_setWidth(Rectangle * this, double width){
	this->__width = width;
}
void Rectangle_setHeight(Rectangle * this, double height){
	this->__height = height;
}

