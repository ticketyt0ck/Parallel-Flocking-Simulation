#include <stdlib.h>
#include <math.h>
#include "vector.h"

#define TOL 0.00000001


typedef struct {
	double x;
	double y;
	
	
	
} Point2D;


Point2D init_point(double x, double y);
Vector2D point_minus(Point2D* curr,Point2D* rhs);
Point2D point_plus(Point2D* curr,Vector2D* rhs);
void point_plus_equals(Point2D* curr, Vector2D* rhs);
Point2D point_scale_plus(Point2D* curr, Vector2D* v, double scalar);
void point_scale_plus_equals(Point2D* curr, Vector2D* v, double scalar);
int point_equals(Point2D* curr, Point2D* other);
