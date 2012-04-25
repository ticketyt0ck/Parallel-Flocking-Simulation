#include "point.h"


// Create a new Point2D with the given values for x and y
Point2D init_point(double x, double y){
    Point2D p;

    p.x = x;
    p.y = y;

    return p;
}

// Get the Vector2D representing curr - rhs
Vector2D point_minus(Point2D* curr,Point2D* rhs){

    double new_x = curr->x - rhs->x;
    double new_y = curr->y - rhs->y;

    return init_vector(new_x, new_y);

}

// Get the Vector2D representing curr + rhs
Point2D point_plus(Point2D* curr,Vector2D* rhs){

    double new_x = curr->x + rhs->x;
    double new_y = curr->y + rhs->y;

    return init_point(new_x, new_y);

}

// Compute the Point2D repesenting curr = curr + rhs
// The result will be in the given Point2D
void point_plus_equals(Point2D* curr, Vector2D* rhs){

    curr->x = curr->x + rhs->x;
    curr->y = curr->y + rhs->y;



}

// Compute the addition of the given point and a scaled vector
Point2D point_scale_plus(Point2D* curr, Vector2D* v, double scalar){

    double new_x = v->x * scalar;
    double new_y = v->y * scalar;

    new_x = curr->x + new_x;
    new_y = curr->y + new_y;

    return init_point(new_x, new_y);

}

// Compute the addition of the given point and the scaled vector
// and put the result in the given point curr
void point_scale_plus_equals(Point2D* curr, Vector2D* v, double scalar){

    double new_x = v->x * scalar;
    double new_y = v->y * scalar;

    new_x = curr->x + new_x;
    new_y = curr->y + new_y;

    curr->x = new_x;
    curr->y = new_y;


}

// Check if 2 Point2Ds are equal
int point_equals(Point2D* curr, Point2D* other){

    if((curr->x - other->x) > TOL)
        return 0;

    if((curr->y - other->y) > TOL)
        return 0;

    return 1;


}


