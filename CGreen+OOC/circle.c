/*
 * circle.c
 *
 *  Created on: Dec 14, 2021
 *      Author: teuton
 */

#include "circle.h"  /* Circle class interface */
#include<stdlib.h>
#include <stdio.h> /* for printf() */

/* NOTE: the "me" pointer has the type of the superclass to fit the vtable */
static void Circle_xtor_(Shape * this);
static double Circle_area_(Shape * this);
static void Circle_draw_(Shape * this);

/* constructor */
void Circle_ctor(Circle * this, char* name, double x, double y,
                 double rad)
{
    static struct ShapeVtbl vtbl = { /* vtbl of the Circle class */
    	&Circle_xtor_,
        &Circle_area_,
        &Circle_draw_
    };
    Shape_ctor(&this->super, name, x, y); /* call the superclass' ctor */
    this->super.vptr = &vtbl; /* override the vptr */
    this->__rad = rad;
}

/* Circle's class implementations of its virtual functions... */
void Circle_xtor_(Shape * this){
    Circle * me_ = (Circle *)this; /* explicit downcast */
    free(me_);
    free(this);
}

double Circle_area_(Shape * this) {
    Circle * me_ = (Circle *)this; /* explicit downcast */
    /* pi is approximated as 3.14 */
    return 3.14 * (double)me_->__rad * (double)me_->__rad;
}

void Circle_draw_(Shape * this) {
    Circle * me_ = (Circle *)this; /* explicit downcast */
    printf("Circle_draw_(x=%f2,y=%f2,rad=%f2)\n", Shape_getx(this), Shape_gety(this), me_->__rad);
}
