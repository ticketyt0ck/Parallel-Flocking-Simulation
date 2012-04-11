#include "window.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



int main(int argc, char **argv) {
	
	
	create_window(400,400, "Test");
	


	int i = 0;
	int j = 0;
	for(j = 0; j < 1000; j++){// for each step in the simulation
	for(i = 0; i< 1000; i++){// for each agent
		set_color(i*i *j *j);
		
		plot_point(i, j);
		plot_point(i, j-1);
		plot_point(i, j+1);
		plot_point(i, j+2);
		//update_window();
		
		
	}
	update_window();
	}
	//update_window();
	wait_until_keypress();
	close_window();
	
	
	return 1;
}
