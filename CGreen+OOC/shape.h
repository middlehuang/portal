/*
 * shape.h
 *
 *  Created on: Dec 14, 2021
 *      Author: teuton
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <stdint.h>

/* Shape's Attributes */
struct ShapeVtbl; /* forward declaration */

typedef struct {
	struct ShapeVtbl *vptr; /* <== Shape's Virtual Pointer */
	char* __name;
	double __x;
	double __y;
}Shape;

/* Shape's virtual table */
struct ShapeVtbl{
	void (*xtor)(Shape * this);
	double (*area)(Shape * this);
	void (*draw)(Shape * this);
};

/* Shape's operations (Shape's interface)... */
void Shape_ctor(Shape * this, const char* name, double x, double y);
void Shape_moveby(Shape * this, double dx, double dy);
char* Shape_getname(Shape * this);
double Shape_getx(Shape * this);
double Shape_gety(Shape * this);
void Shape_setx(Shape * this, double x);
void Shape_sety(Shape * this, double y);

static inline void Shape_xtor(Shape * this) {
    (*this->vptr->xtor)(this);
}

static inline double Shape_area(Shape * this) {
    return (*this->vptr->area)(this);
}

static inline void Shape_draw(Shape * this) {
    (*this->vptr->draw)(this);
}

/* generic operations on collections of Shapes */
Shape const *largestShape(Shape *shapes[], uint32_t nShapes);
void drawAllShapes(Shape *shapes[], uint32_t nShapes);

#endif /* SHAPE_H */

