#include<stdio.h>
#include<stdlib.h>

Vector2D separation(Agent* a, int index, Agent *agentarray, int num_agents) {
	Vector2D steering_force = init_vector(0.0, 0.0);
	
	int i;
	
	for(i = 0; i < num_agents; i++) {
		if (i != index) {
			
			Vector2D toAgent = point_minus(&a->position, &agentarray[i].position);
			
			normalize(&toAgent);
			double mag = magnitude(&toAgent);
			toAgent = divide(mag, &toAgent);
			
			plus_equals(&steering_force, &toAgent);

		}
	}
	
	
	return steering_force;
	
}


Vector2D cohesion(Agent* a, int index, Agent *agentarray, int num_agents) {
	Vector2D steering_force = init_vector(0.0, 0.0);
	Point2D center_point_mass = init_point(0.0, 0.0);
	Vector2D v;
	
	
	
	
	int neighborcount = 0;
	int i;
	double xavg = 0;
	double yavg = 0;
	
	for(i = 0; i < num_agents; i++) {
		if (i != index) {
			xavg += agentarray[i].position.x;
			yavg += agentarray[i].position.y;
			++neighborcount;
		}
	}
	
	if (neighborcount > 0) {
		
		steering_force.x = xavg / neighborcount;
		steering_force.y = yavg / neighborcount;
		
		center_point_mass.x = steering_force.x;
		center_point_mass.y = steering_force.y;
				
		v = minus(&center_point_mass, &a->position);
		normalize(&v);
		v = times(&v, a->speed);
		steering_force = minus(&v, a->heading);
	}
	
	return steering_force;
}

Vector2D alignment(Agent* a, int index, Agent *agentarray, int num_agents) {
	Vector2D average_heading = init_vector(0.0, 0.0);
	Vector2D steering_force = init_vector(0.0, 0.0);	
	
	int neighborcount = 0;
	int i;

	for(i = 0; i < num_agents; i++) {
		if (i != index) {
			plus_equals(&average_heading, &agentarray[i].heading);
			++neighborcount;
		}
		
		if (neighborcount > 0) {
			steering_force = divide(neighborcount, &average_heading);
			
			steering_force = minus(&steering_force, &a->heading);
				
			
		}
		
	}
	
	return steering_force;
	
	
}
