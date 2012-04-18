#include <stdio.h>
#include <stdlib.h>
#include "agent.h"

int main(int argc, char **argv) {
	Agent a;
	Vector2D v = init_vector(1.0, 1.0);
	Point2D p = init_point(2.0, 2.0);
	double speed = 10.0;
	Agent_Type type = prey;
	
	
	a = init_agent(&v, &p, speed, type);
	
	printf("Agent heading = <%.2f,%.2f>\n", a.heading.x, a.heading.y);
	printf("Agent position = (%.2f, %.2f)\n", a.position.x, a.position.y);
	printf("Agent speed %.2f\n", a.speed);
	printf("Agent Type: %d\n", a.type);
	a.type = predator;
	printf("Agent Type: %d\n", a.type);

	agent_update(&a, .5);
	printf("Agent position = (%.2f, %.2f)\n", a.position.x, a.position.y);
	
	return 0;
	
}



