#include "window.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



int main(int argc, char **argv) {
	
	
	create_window(400,400, "Test");
	
	
	
	add_point_to_file(1, 1, 1, "test2.txt");
	add_point_to_file(2, 1, 1, "test2.txt");
	add_point_to_file(3, 1, 0, "test2.txt");
	//add_terminator_to_file(-2, "test2.txt");
	add_terminator_to_file(-1, "test2.txt");

	run_file("test2.txt");
	/*
	int i = 0;
	int j = 0;
	int k = 0;
	for(k = 0; k < 100; k++){
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
	}}
	//update_window();
	*/
	wait_until_keypress();
	close_window();
	
	
	return 1;
}
