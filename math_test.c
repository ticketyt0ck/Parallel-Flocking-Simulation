#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main(int argc, char **argv) {
	Vector2D u;
	Vector2D v;
	Vector2D x;
	Vector2D y;
	Vector2D z;
	
	
	printf("Testing initializing vector with 1.0 and 2.0\n");
	v = init_vector(1.0, 2.0);
	printf("%f %f \n\n", v.x, v.y);
	
	printf("Testing divide equals, 1.0 / 2 and 2.0 / 2\n");
	divide_equals(&v, 2);
	printf("%f %f\n\n", v.x, v.y);
	
	printf("Testing divide 1.0 / 4 and 2.0 / 4\n");
	v = divide(2, &v);
	printf("%f %f\n\n", v.x, v.y);
	
	u = init_vector(2.0, 4.0);
	v = init_vector(2.0, 4.0);
	
	printf("Test dot product, 4 + 16\n");
	double dotval = dot(&u, &v);
	printf("%f\n\n", dotval);
	
	printf("Test equality of two vectors, true\n");
	int boolean = equals(&u, &v);
	printf("%d\n\n", boolean);
	
	printf("Test equality of two vectors, false\n");
	x = init_vector(1.0, 2.0);
	boolean = equals(&u, &x);
	printf("%d\n\n", boolean);
	
	
	printf("Test angle based on 4 primary positions on unit circle\n");
	u = init_vector(1.0, 0.0);
	v = init_vector(0.0, 1.0);
	x = init_vector(-1.0, 0.0);
	y = init_vector(0.0, -1.0);
	
	double angleu = vector_angle(&u);
	double anglev = vector_angle(&v);
	double anglex = vector_angle(&x);
	double angley = vector_angle(&y);
	printf("%f %f %f %f\n\n", angleu, anglev, anglex, angley);
	
	
	printf("Test get left ortho with 5 and 2, which should be -2 and 5\n");
	v = init_vector(5.0, 2.0);
	u = get_left_ortho(&v);
	printf("%f %f \n\n", u.x, u.y);
	
	
	printf("Test get right ortho with 5 and 2, which should be 2 and -5\n");
	v = init_vector(5.0, 2.0);
	u = get_right_ortho(&v);
	printf("%f %f \n\n", u.x, u.y);
	
	
	printf("Test magnitude with 3 and 4, which should be 5\n");
	v = init_vector(3.0, 4.0);
	double mag = magnitude(&v);
	printf("%f\n\n", mag);
	
	
	printf("Test get_normalized with 1 and 1, which should yield 1 / sqrt(2) \n");
	v = init_vector(1.0, 1.0);
	u = get_normalized(&v);
	printf("%f %f %f\n\n", u.x, u.y, 1 / sqrt(2));
	
	
	printf("Test magnitude squared with 3 and 4, which should yield 25\n");
	v = init_vector(3.0, 4.0);
	mag = magnitude_squared(&v);
	printf("%f\n\n", mag);
	
	
	printf("Test reflect x\n");
	v = init_vector(1.0, 1.0);
	reflect_x(&v);
	printf("%f %f\n\n", v.x, v.y);
	
	
	printf("Test reflect y\n");
	v = init_vector(1.0, 1.0);
	reflect_y(&v);
	printf("%f %f\n\n", v.x, v.y);
	
	
	printf("Test plus with 3 and 4 and 5 and 6, should yield 8 and 10\n");
	v = init_vector(3.0, 4.0);
	u = init_vector(5.0, 6.0);
	z = plus(&v, &u);
	printf("%f %f\n\n", z.x, z.y);
	
	
	printf("Test plus_equals\n");
	v = init_vector(3.0, 4.0);
	u = init_vector(5.0, 6.0);
	plus_equals(&v, &u);
	printf("%f %f\n\n", v.x, v.y);
	
	
	printf("Test minus with 5 and 6 and 3 and 4, which should yield 2 and 2\n");
	v = init_vector(5.0, 6.0);
	u = init_vector(3.0, 4.0);
	z = minus(&v, &u);
	printf("%f %f\n\n", z.x, z.y);
	
	
	printf("Test minus_equals with 5 and 6 and 3 and 4, which should yield 2 and 2\n");
	v = init_vector(5.0, 6.0);
	u = init_vector(3.0, 4.0);
	minus_equals(&v, &u);
	printf("%f %f\n\n", v.x, v.y);
	
	
	printf("Test negate with 1 and 1, should yield -1 and -1\n");
	v = init_vector(1.0, 1.0);
	negate(&v);
	printf("%f %f\n\n", v.x, v.y);
	
	
	printf("Test normalize with 1 and 1, which should yield 1/sqrt(2)\n");
	v = init_vector(1.0, 1.0);
	normalize(&v);
	printf("%f %f\n\n", v.x, v.y);
	
	
	printf("Test scale plus with 1 and 1, 2 and 2, and 2 should yield 5 and 5\n");
	v = init_vector(1.0, 1.0);
	u = init_vector(2.0, 2.0);
	double scal = 2;
	z = scale_plus(&v, &u, scal);
	printf("%f %f\n\n", z.x, z.y);
	
	
	Point2D p1;

	
	
	p1 = init_point(5,5);
	printf("P1 is (%f, %f)\n", p1.x, p1.y);	
	Point2D p2;
	p2 = init_point(1,1);
	v = point_minus(&p1, &p2);
	printf("Vector v is (%f, %f)\n", v.x,v.y);

	x = point_plus(&p1, &p2);
	printf("Vector x is (%f, %f)\n", x.x, x.y);
	
	Vector2D vp = init_vector(2,2);
	point_plus_equals(&p1, &vp);
	printf("Vector vp is (%f, %f)\n", p1.x, p1.y);
	
	Point2D p3 = init_point(5,5);
	Point2D ret = point_scale_plus(&p3, &vp, 2);
	printf("Point p3 after scale_plus is (%f, %f)\n", ret.x, ret.y);
	
	
	Point2D p4 = init_point(5,5);
	point_scale_plus_equals(&p4, &vp, 2);
	printf("Point p4 after scale_plus is (%f, %f)\n", p4.x, p4.y);
	
	
	Point2D p5 = init_point(8.1,10.5);
	Point2D p6 = init_point(8.1,10.5);
	
	int i = point_equals(&p5, &p6);
	printf("i should be 1, it is %d\n", i);
	
	Point2D p7 = init_point(-8.1, 10.5);
	
	i = point_equals(&p5, &p7);
	printf("i should be 0, it is %d\n", i);
	
	
	
	return 0;
}
