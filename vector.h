#ifndef vector_head
	#define vector_head
	
	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	
	#define TOL 0.00000001
	
	typedef struct {
		double x;
		double y;
		
		
		
	} Vector2D;
	
	
	Vector2D init_vector(double x, double y);
	Vector2D divide(double z, Vector2D* v);
	void divide_equals(Vector2D* v, double z);
	double dot(Vector2D* u, Vector2D* v);
	int equals(Vector2D* u, Vector2D* v);
	double vector_angle(Vector2D* v);
	Vector2D get_left_ortho(Vector2D* v);
	Vector2D get_right_ortho(Vector2D* v);
	Vector2D get_normalized(Vector2D* v);
	double magnitude(Vector2D* v);
	double magnitude_squared(Vector2D* curr);
	void reflect_x(Vector2D* curr);
	void reflect_y(Vector2D* curr);
	Vector2D plus(Vector2D* v, Vector2D* u);
	void plus_equals(Vector2D* curr, Vector2D* u);
	Vector2D minus(Vector2D* v, Vector2D* u);
	void minus_equals(Vector2D* curr, Vector2D* u);
	void negate(Vector2D* curr);
	void normalize(Vector2D* curr);
	Vector2D scale_plus(Vector2D* curr, Vector2D* u, double scalar);
	void scale_plus_equals(Vector2D* curr, Vector2D* u, double scalar);
	void set_left_ortho(Vector2D* curr);
	void set_right_ortho(Vector2D* curr);
	Vector2D times(Vector2D* curr, double d);
	void times_equals(Vector2D* curr, double d);
	
#endif
