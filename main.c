#include <stdlib.h>
#include <stdio.h>
#include "steering_behaviors.h"
#include "window.h"
#include <omp.h>


#include <sys/time.h>
// Main class for running the parallel flocking sim

#define WINDOWSIZE 1000

int main(int argc, char **argv) {
	
	long num_agents;
	long num_steps;
	int thread_count;
	char* filename;
	long timestep;

	if (argc != 5) {
        printf("Usage: num_agents num_steps filename\n");
        exit(1);
        }
        
        thread_count = atoi(argv[1]);
        num_agents = atol(argv[2]);
        num_steps = atol(argv[3]);
        filename = argv[4];
        
        
        
        printf("Running a simulation with %lu agents for %lu steps and saving the data to the file %s...\n", 
        	num_agents, num_steps, filename);
        
        // here's the simulation skeleton
        
        
        // create the agents, with random headings, maybe random locations or all in a bunch
        unsigned int i = 1;
        int j;
        
        Agent **agent_lists_at_timesteps;
        
        agent_lists_at_timesteps = malloc(num_steps * sizeof(Agent*));
        
	int a;
	for(a=0; a<num_steps; a++)
	{
		agent_lists_at_timesteps[a] = malloc(num_agents * sizeof(Agent));	
	}
        
      //  Agent *agent_list = malloc(num_agents * sizeof(Agent));
        
        
        struct timeval tv;
        gettimeofday(&tv, NULL);
        
        
        srand(tv.tv_usec);
        for(j = 0; j < num_agents - 1; j++){
        	//printf("Creating agent %d\n", j);
        	Vector2D heading = init_vector(-(rand_r(&i) % 5), -(rand_r(&i) % 5));
        	//printf("Done vector creation\n");
        	Point2D start_loc = init_point((rand_r(&i) % WINDOWSIZE), (rand_r(&i) % WINDOWSIZE));
        	double speed = 5;
        	Agent_Type prey_type = prey;
        	//printf("initing agent\n");
        	Agent new_agent = init_agent(&heading, &start_loc, speed, prey_type);
        	//printf("Adding to list\n");	
        	agent_lists_at_timesteps[0][j] = new_agent;
        	
        	//printf("Done creating agent %d\n", j);
        }
        Vector2D heading = init_vector((rand_r(&i) % 5), (rand_r(&i) % 5));
        Point2D start_loc = init_point((rand_r(&i) % WINDOWSIZE), (rand_r(&i) % WINDOWSIZE));
        double speed = 5;
        Agent_Type predator_type = predator;
        agent_lists_at_timesteps[0][j] = init_agent(&heading, &start_loc, speed, predator_type);
        int agent_close;
        double ts, te;
        
        
        // for each numstep
        ts = omp_get_wtime();
        
        for(timestep = 1; timestep < num_steps; timestep++){
        
        	int k;
        	Vector2D s,c,a, combo, seek_vector;
        	
# 		pragma omp parallel for num_threads(thread_count) \
        		private(s, c, a, combo, k)
        	for(k = 0; k< num_agents; k++){
        		if(agent_lists_at_timesteps[timestep-1][k].type == prey) {
        			
				s = separation(&agent_lists_at_timesteps[timestep-1][k], k, agent_lists_at_timesteps[timestep-1], num_agents);
				c = cohesion(&agent_lists_at_timesteps[timestep-1][k], k, agent_lists_at_timesteps[timestep-1], num_agents);
				a = alignment(&agent_lists_at_timesteps[timestep-1][k], k, agent_lists_at_timesteps[timestep-1], num_agents);
						
				
	
				combo = plus(&agent_lists_at_timesteps[timestep-1][k].heading, &s);
				plus_equals(&combo, &c);
				plus_equals(&combo, &a);
				divide_equals(&combo, 1.1);
				
				agent_lists_at_timesteps[timestep][k].heading.x = combo.x;
				agent_lists_at_timesteps[timestep][k].heading.y = combo.y;
				
				agent_lists_at_timesteps[timestep][k].position.x = agent_lists_at_timesteps[timestep-1][k].position.x;
				agent_lists_at_timesteps[timestep][k].position.y = agent_lists_at_timesteps[timestep-1][k].position.y;
				
				agent_lists_at_timesteps[timestep][k].speed = agent_lists_at_timesteps[timestep-1][k].speed;
				agent_lists_at_timesteps[timestep][k].type = agent_lists_at_timesteps[timestep-1][k].type;
        		}
        		
        		else {
        			/*
        			if(((timestep - 1) % 50) == 0) {
        				
        				agent_close = find_closest(&agent_lists_at_timesteps[timestep-1][k], k, agent_lists_at_timesteps[timestep-1], num_agents);	
        			}
        			*/
        			
        			//seek_vector = seek(&agent_lists_at_timesteps[timestep-1][k], &agent_lists_at_timesteps[timestep-1][agent_close]);
        			seek_vector = init_vector(5.0, 0.0);
        			
        			agent_lists_at_timesteps[timestep][k].heading.x = seek_vector.x;
				agent_lists_at_timesteps[timestep][k].heading.y = seek_vector.y;
					
				agent_lists_at_timesteps[timestep][k].position.x = agent_lists_at_timesteps[timestep-1][k].position.x;
				agent_lists_at_timesteps[timestep][k].position.y = agent_lists_at_timesteps[timestep-1][k].position.y;
					
				agent_lists_at_timesteps[timestep][k].speed = agent_lists_at_timesteps[timestep-1][k].speed;
				agent_lists_at_timesteps[timestep][k].type = agent_lists_at_timesteps[timestep-1][k].type;
        				
        			}
        			
        			
        	}
        				
        			
        			
        		
        		
        	
        	printf("just changed headings\n");
# 		pragma omp parallel for num_threads(thread_count)
        	for(k = 0; k< num_agents; k++){
        		agent_update(&agent_lists_at_timesteps[timestep][k], 1);
        		//printf("TRYING TO MOD %f \n", agent_list[k].position.x);
        		agent_lists_at_timesteps[timestep][k].position.x = ((int)agent_lists_at_timesteps[timestep][k].position.x % WINDOWSIZE);
        		agent_lists_at_timesteps[timestep][k].position.y = ((int)agent_lists_at_timesteps[timestep][k].position.y % WINDOWSIZE);
        		//printf("AND I GOT %f \n", agent_list[k].position.x);
        		
        	}
        	
        	/* for(k = 0; k < num_agents; k++){
        		add_point_to_file(agent_lists_at_timesteps[timestep][k].position.x, agent_lists_at_timesteps[timestep][k].position.y, 0, filename);	
        	}
        	
        	if(timestep != num_steps -1)
        		add_terminator_to_file(-2, filename); */
        	
        	//printf("timestep is %d\n", timestep);
        	
        }
 /*        add_terminator_to_file(-1, filename); */
        
        te = omp_get_wtime();
        
        
        printf("Time to do all computation and updating %f\n", te-ts);
        	
        		
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
      //  run_file(filename);
      run_sim(agent_lists_at_timesteps, num_steps, num_agents);
        
        
        
        
        
        
        
        
        
        
        return 0;
        
}
