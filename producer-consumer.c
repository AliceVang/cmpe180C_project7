// lab7: producer-consumer.c

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <semaphore.h>

typedef enum {MODE_NONE, MODE_PRODUCER, MODE_CONSUMER} mode_type;
typedef enum {IPC_NONE, IPC_UNIX_SOCKET, IPC_SHARED_MEMORY} ipc_t;
typedef struct{
	int capacity;
	int in;
	int out;
	sem_t mutex;
	sem_t empty;
	sem_t full;
	//char buff[][];
} shared_memory_queue_t;
sem_t *sem_full = NULL;
sem_t *sem_empty = NULL;
sem_t *sem_mutex = NULL;

static int e_status = 0;


int main (int argc, char *argv[]){
	mode_type mode = MODE_NONE;
	ipc_t ipc = IPC_NONE;
	char *message = NULL;
	int queue_depth = 0;

	int opt;
	while((opt = getopt(argc,argv, "pcm:q:use")) != -1){
		switch(opt){
			case'p':	// producer
				mode = MODE_PRODUCER;
				break;
			case 'c':	// consumer
				mode = MODE_CONSUMER;
				break;
			case 'm':	// message produced by producer
				message = optarg;
				break;
			case 'q':	// depth of the queue
				queue_depth = atoi(optarg);
				break;
			case 'u':	// unit socket
				ipc = IPC_UNIX_SOCKET;
				break;
			case 's':	// shared memory
				ipc = IPC_SHARED_MEMORY;
				break;
			case 'e':	// print the string being produced/consumed + \n
				e_status = 1;
				break;
			default:
				fprintf(stderr, "Error: Unknown option.\n");
				exit(1);
		}
	}
	if(mode == MODE_PRODUCER && !message){
		fprintf(stderr, "Error: producer needs a message.\n");
		return 1;
	}

	if(ipc == IPC_SHARED_MEMORY){
		if(mode == MODE_PRODUCER){
			// run producer in shared memory

		} else if(mode == MODE_CONSUMER) {
			// run consumer in shared memory
		}
	} else if(ipc = IPC_UNIX_SOCKET){
		if(mode == MODE_PRODUCER){
			// run producer in unix socket
		} else if(mode == MODE_CONSUMER){
			// run consumer in unix socket
		}
	}


	return 0;
}
