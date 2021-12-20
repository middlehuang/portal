/*
 * circle.h
 *
 *  Created on: Dec 14, 2021
 *      Author: teuton
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "shape.h"

typedef struct {
    Shape super; /* <== inherits Shape */

    /* attributes added by this subclass... */
    double __rad;
} Circle;

/* constructor */
void Circle_ctor(Circle * this, char* name, double x, double y,
                 double rad);
double Circle_getRad(Circle * this);
void Circle_setRad(Circle * this, double rad);

#endif /* CIRCLE_H_ */
