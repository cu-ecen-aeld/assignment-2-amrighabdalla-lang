#include <syslog.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    openlog(NULL, 0, LOG_USER);
    if (argc < 3){
	syslog(LOG_ERR, "This function should take 2 arguments. Invalid Number of arguments: %d", argc);
	return 1;
    }else{
	const char *filename = argv[1];
	const char *str = argv[2];
	FILE * file = fopen(filename, "w");
	if (file == NULL){
	    fprintf(stderr, "Error opening File %s: ErrNo-Code(%d), ErrMsg(%s)", filename, errno, strerror(errno));
	    perror("perror returned");
	    syslog(LOG_ERR, "File does not exist: %s", filename);
	}else{
	    fprintf(file, "%s", str);
	    fclose(file);
	}
    }
    return 0;
}
