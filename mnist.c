//
// Standard includes
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Local macros
//
#define MAX_PATH_LEN	256
#define MNIST_TRAIN_SZ	60000

//
// Globals
//
extern int errno;
unsigned char mnist_train_lbls[MNIST_TRAIN_SZ];

void usage(char **argv) {

	printf("%s <path_to_mnist_data_dir>\n", (char *)argv[0]);
}

void load_mnist(char *data_dir) {

	char path[MAX_PATH_LEN];
	unsigned char header[8];

	// open file
	sprintf(path,"%s/train-labels-idx1-ubyte", data_dir);
	FILE *fp = fopen(path, "rb");
	if (fp==NULL) {
		printf("Error: Could not open '%s' errno=%d errstr='%s'.\n", path, errno, strerror(errno));
		exit(1);
	}

	// read header
	int sz = fread(header,8,1,fp);
	if (sz!=1) {
		printf("Error: Invalid header read.\n");
		fclose(fp);
		exit(1);
	}

	// read train labels
	sz = fread(mnist_train_lbls, MNIST_TRAIN_SZ, 1, fp);
	if (sz!=1) {	
		printf("Error: Invalid train lbls read.\n");
		fclose(fp);
		exit(1);
	}

	for (int i=0;i<MNIST_TRAIN_SZ;i++) {
		printf("%d:%d ",i,mnist_train_lbls[i]);
	}
	printf("\n");

}

int main(int argc, char **argv) {

	if (argc!=2) {
		usage(argv);
		exit(1);
	}

	load_mnist(argv[1]);


	exit(0);	
}
