#include "agent.h"


Agent init_agent(Vector2D* h, Point2D* p, double speed, Agent_Type type){
	Agent a;
	
	a.heading = init_vector(h->x, h->y);
	a.position = init_point(p->x, p->y);
	a.speed = speed;
	a.type = type;
	
	
	return  a;
}

void agent_update(Agent* a, double delta) {
	Vector2D u, v;
	Point2D p;
	u = a->heading;
	p = a->position;
	v = times(&u, a->speed*delta);
	a->position = point_plus(&p, &v);
}
