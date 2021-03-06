#include "lab2-api.h"
#include "usertraps.h"
#include "misc.h"

#include "q1.h"

// Consumer 3:
// Consumes N and OO; Produces NOO
void main (int argc, char *argv[])
{
	// Variable declarations
	sem_t s_n;
	sem_t s_oo;
	sem_t s_noo;
	sem_t s_proc;				
    	char usage[] = "<h_s_proc> <h_s_n> <h_s_oo> <h_s_noo>\n";

	// Check CLA's
  	if(argc != 5) 
    	{  Printf("Usage: "); Printf(argv[0]); Printf(usage); Exit();  }

  	// Convert the command-line strings into integers for use as handles
  	s_proc = dstrtol(argv[1], NULL, 10);
  	s_n = dstrtol(argv[2], NULL, 10);
  	s_oo = dstrtol(argv[3], NULL, 10);
  	s_noo = dstrtol(argv[4], NULL, 10);

        if(sem_wait(s_n) != SYNC_SUCCESS) 
        {  Printf("Bad semaphore s_n (%d) in ",s_n); Printf(argv[0]); Printf(", exiting...\n"); Exit();  }
Printf("REACTION3: PID %d is complete, ", Getpid());
Printf("removed one N atom, removed one O2 molecule, added one NO2 molecule.\n");
    	if(sem_wait(s_oo) != SYNC_SUCCESS)
    	{  Printf("Bad sem s_oo (%d) in ",s_oo); Printf(argv[0]); Printf(", exiting...\n"); Exit();  }
    	
	if(sem_signal(s_noo) != SYNC_SUCCESS)
    	{  Printf("Bad sem s_hh (%d) in ",s_noo); Printf(argv[0]); Printf(", exiting...\n"); Exit();  }



    if(sem_signal(s_proc) != SYNC_SUCCESS)
    {  Printf("Bad sem s_proc (%d) in ",s_proc); Printf(argv[0]); Printf(", exiting...\n"); Exit();  }
}
