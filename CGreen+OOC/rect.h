/*
 * rect.h
 *
 *  Created on: Dec 14, 2021
 *      Author: teuton
 */

#ifndef RECT_H_
#define RECT_H_

#include"shape.h"

/* Rectangle's attributes... */
typedef struct {
    Shape super; /* <== inherits Shape */

    /* attributes added by this subclass... */
    double __width;
    double __height;
} Rectangle;

/* constructor prototype */
void Rectangle_ctor(Rectangle * this, char* name, double x, double y,
                    double width, double height);
double Rectangle_getWidth(Rectangle * this);
double Rectangle_getHeight(Rectangle * this);
void Rectangle_setWidth(Rectangle * this, double width);
void Rectangle_setHeight(Rectangle * this, double height);

#endif /* RECT_H_ */
