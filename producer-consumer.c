// lab7: producer-consumer.c

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

int main (int argc, char *argv[]){
	int opt;
	while((opt = getopt(argc,argv, "pcm:q:use")) != -1){
		switch(opt){
			case'p':	// producer
				printf("case p\n");
				break;
			case 'c':	// consumer
				printf("case c\n");
				break;
			case 'm':	// message produced by producer
				printf("case m\n");
				break;
			case 'q':	// depth of the queue
				printf("case q\n");
				break;
			case 'u':	// unit socket
				printf("case u\n");
				break;
			case 's':	// shared memory
				printf("case s\n");
				break;
			case 'e':	// print the string being produced/consumed + \n
				printf("case e\n");
				break;
			default:
				fprintf(stderr, "Error: Unknown option.\n");
				exit(1);
		}
	}

	return 0;
}
