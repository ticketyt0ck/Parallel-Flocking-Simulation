#include "vector.h"



Vector2D init_vector(double x, double y) {
	Vector2D u;
	
	u.x = x;
	u.y = y;
	
	return u;
}


Vector2D divide(double z, Vector2D* v) {
	Vector2D u;
	
	u.x = v->x / z;
	u.y = v->y / z;
	
	return u;
	
}


void divide_equals(Vector2D* curr, double z) {
	if ((abs(curr->x - 0.0) < TOL)) {
		curr->x = 0;
	}else
		curr->x /= z;

	if((abs(curr->y - 0.0) < TOL))
		curr->y = 0;
	else
		curr->y /= z;
}

double dot(Vector2D* u, Vector2D* v) {
	return ((u->x * v->x) + (u->y * v->y));
	
}

int equals(Vector2D* u, Vector2D* v) {
	
	if (((abs(u->x) - v->x) < TOL) && ((abs(u->y) - v->y) < TOL)) {
		return 1;
	}
	return 0;
	
}

double vector_angle(Vector2D* v) {
	if ((abs(v->x - 0.0) < TOL) && ((abs(v->y - 0.0) < TOL))) {
		return 0.0;
	}
	
	return atan2(v->y, v->x);
}

Vector2D get_left_ortho(Vector2D* v) {
	Vector2D u;
	
	u.x = v->y * (-1);
	u.y = v->x;
	
	return u;
}

Vector2D get_right_ortho(Vector2D* v) {
	Vector2D u;
	
	u.x = v->y;
	u.y = v->x * (-1);
	
	return u;
	
}



double magnitude(Vector2D* curr) {
	
	return sqrt((curr->x * curr->x) + (curr->y * curr->y));	
	
}

Vector2D get_normalized(Vector2D* curr) {
	Vector2D u;
	
	if ((abs(curr->x - 0.0) < TOL) && (abs(curr->y - 0.0) < TOL)) {
		u.x = 0;
		u.y = 0;
		
		return u;
	}
	
	//double magnitude = sqrt((curr->x * curr->x) + (curr->y * curr->y));
	double mag = magnitude(curr);
	u.x = curr->x / mag;
	u.y = curr->y / mag;

	return u;
}

double magnitude_squared(Vector2D* curr) {
	return (curr->x * curr->x) + (curr->y * curr->y);	
}

void reflect_x(Vector2D* curr) {
	curr->x = curr->x * (-1);
}

void reflect_y(Vector2D* curr) {
	curr->y = curr->y * (-1);
	
}

Vector2D plus(Vector2D* v, Vector2D* u) {
		Vector2D z;
		double new_x, new_y;
		
		new_x = v->x + u->x;
		new_y = v->y + u->y;
		
		if ((new_x - 0.0) < TOL) {
			new_x = 0.0;
		}
		if ((new_y - 0.0) < TOL) {
			new_y = 0.0;
		}
		
		z.x = new_x;
		z.y = new_y;
		
		return z;

			
}

void plus_equals(Vector2D* curr, Vector2D* u) {
	double new_x, new_y;
	
	new_x = curr->x + u->x;
	new_y = curr->y + u->y;
	
	if ((new_x - 0.0) < TOL) {
		new_x = 0.0;
	}
	
	if ((new_y - 0.0) < TOL) {
		new_y = 0.0;
	}
	
	curr->x = new_x;
	curr->y = new_y;
	
}

Vector2D minus(Vector2D* v, Vector2D* u) {
	Vector2D z;
	double new_x, new_y;
	
	new_x = v->x - u->x;
	new_y = v->y - u->y;
	
	if ((new_x - 0.0) < TOL) {
		new_x = 0.0;
	}

	if ((new_y - 0.0) < TOL) {
		new_y = 0.0;
	}
	
	z.x = new_x;
	z.y = new_y;
	
	return z;
	
}

void minus_equals(Vector2D* curr, Vector2D* u) {
	double new_x, new_y;
	
	new_x = curr->x - u->x;
	new_y = curr->y - u->y;
	
	if ((new_x - 0.0) < TOL) {
		new_x = 0.0;
	}
	
	if ((new_y - 0.0) < TOL) {
		new_y = 0.0;
	}
	
	curr->x = new_x;
	curr->y = new_y;
	
}

void negate(Vector2D* curr) {
	curr->x = curr->x * (-1);
	curr->y = curr->y * (-1);
	
}

void normalize(Vector2D* curr) {
	Vector2D u;
	
	if ((abs(curr->x - 0.0) < TOL) && ((abs(curr->y - 0.0) < TOL))) {
		curr->x = 0.0;
		curr->y = 0.0;
	}
	
	u = get_normalized(curr);
	curr->x = u.x;
	curr->y = u.y;
}

Vector2D scale_plus(Vector2D* curr, Vector2D* u, double scalar) {
	double new_x, new_y;

	new_x = (u->x * scalar) + curr->x;
	new_y = (u->y * scalar) + curr->y;

	Vector2D v = init_vector(new_x, new_y);
	return v;	
	
}

void scale_plus_equals(Vector2D* curr, Vector2D* u, double scalar) {
	curr->x += (u->x * scalar);
	curr->y += (u->y * scalar);
		
}

void set_left_ortho(Vector2D* curr) {
	Vector2D u = get_left_ortho(curr);
	
	curr->x = u.x;
	curr->y = u.y;
}

void set_right_ortho(Vector2D* curr) {
	Vector2D u = get_right_ortho(curr);
	
	curr->x = u.x;
	curr->y = u.y;
}

Vector2D times(Vector2D* curr, double d) {
	double new_x, new_y;
	
	new_x = curr->x * d;
	new_y = curr->y * d;
	
	Vector2D v = init_vector(new_x, new_y);
	return v;
		
}

void times_equals(Vector2D* curr, double d) {
	curr->x = curr->x * d;
	curr->y = curr->y * d;	
}









	
	
