#include <stdlib.h>
#include <stdio.h>
#include "steering_behaviors.h"
#include "window.h"


#include <sys/time.h>
// Main class for running the parallel flocking sim

#define WINDOWSIZE 1000

int main(int argc, char **argv) {
	
	long num_agents;
	long num_steps;
	char* filename;
	long timestep;

	if (argc != 4) {
        printf("Usage: num_agents num_steps filename\n");
        exit(1);
        }
        
        num_agents = atol(argv[1]);
        num_steps = atol(argv[2]);
        filename = argv[3];
        
        
        
        printf("Running a simulation with %lu agents for %lu steps and saving the data to the file %s...\n", 
        	num_agents, num_steps, filename);
        
        // here's the simulation skeleton
        
        
        // create the agents, with random headings, maybe random locations or all in a bunch
        unsigned int i = 1;
        int j;
        Agent *agent_list = malloc(num_agents * sizeof(Agent));
        
        
        struct timeval tv;
        gettimeofday(&tv, NULL);
        
        
        srand(tv.tv_usec);
        for(j = 0; j < num_agents - 1; j++){
        	//printf("Creating agent %d\n", j);
        	Vector2D heading = init_vector((rand_r(&i) % 5), (rand_r(&i) % 5));
        	//printf("Done vector creation\n");
        	Point2D start_loc = init_point((rand_r(&i) % WINDOWSIZE), (rand_r(&i) % WINDOWSIZE));
        	double speed = 5;
        	Agent_Type prey_type = prey;
        	//printf("initing agent\n");
        	Agent new_agent = init_agent(&heading, &start_loc, speed, prey_type);
        	//printf("Adding to list\n");	
        	agent_list[j] = new_agent;
        	
        	//printf("Done creating agent %d\n", j);
        }
        Vector2D heading = init_vector((rand_r(&i) % 5), (rand_r(&i) % 5));
        Point2D start_loc = init_point((rand_r(&i) % WINDOWSIZE), (rand_r(&i) % WINDOWSIZE));
        double speed = 5;
        Agent_Type predator_type = predator;
        agent_list[j] = init_agent(&heading, &start_loc, speed, predator_type);
        
        //printf("After first loop\n");
        
        // for each numstep
        for(timestep = 0; timestep < num_steps; timestep++){
        
        	int k;
        	for(k = 0; k< num_agents; k++){
        		Vector2D s,c,a;
        		s = separation(&agent_list[k], k, agent_list, num_agents);
        		c = cohesion(&agent_list[k], k, agent_list, num_agents);
        		a = alignment(&agent_list[k], k, agent_list, num_agents);
        		     		

        		Vector2D combo = plus(&agent_list[k].heading, &s);
        		plus_equals(&combo, &c);
   		        plus_equals(&combo, &a);
   		        //printf("Combo x is %f and y is %f\n", combo.x, combo.y);
   		        divide_equals(&combo, 1.1);
   		        
        		agent_list[k].heading.x = combo.x;
        		agent_list[k].heading.y = combo.y;
        	}
        	//printf("just changed headings\n");
        	for(k = 0; k< num_agents; k++){
        		agent_update(&agent_list[k], 1);
        		//printf("TRYING TO MOD %f \n", agent_list[k].position.x);
        		agent_list[k].position.x = ((int)agent_list[k].position.x % WINDOWSIZE);
        		agent_list[k].position.y = ((int)agent_list[k].position.y % WINDOWSIZE);
        		//printf("AND I GOT %f \n", agent_list[k].position.x);
        		add_point_to_file(agent_list[k].position.x, agent_list[k].position.y, 0, filename);
        	}
        	if(timestep != num_steps -1)
        		add_terminator_to_file(-2, filename);
        	
        	//printf("timestep is %d\n", timestep);
        }
        add_terminator_to_file(-1, filename);
        	
        		
        //	for each agent
        //		do cohesion, alignment, and seperation
        //		update new heading
        // 	
        // 	for each agent
        //		update the agent location
        //		check their position within boundaries, fix it with mod	
        //		update old heading by setting it = to new heading
        //		write position of agent to file
        //
        //	(if it's not the last step)
        //	write -2 to file
        
        
        //
        // write -1 to file
        
        
        
        create_window(WINDOWSIZE, WINDOWSIZE, "Test");
        run_file(filename);

        
        
        
        
        
        
        
        
        
        
        return 0;
        
}
