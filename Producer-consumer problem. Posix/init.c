#include <stdio.h>
#include <mqueue.h>
#define size 100

struct{
	int typ;
	int pnr;
	char text[size];
} kom_t;

void main(int argc, char *argv[]) {
    	int kom, res,i;
    	mqd_t mq;
    	unsigned int prior;
    	struct mq_attr attr;
        attr.mq_maxmsg = 4;
        attr.mq_msgsize = sizeof(kom_t);
        attr.mq_flags = 0;
        mq_unlink("/Kolejka");  
    	mq=mq_open("/Kolejka", O_RDWR | O_CREAT, 0660, &attr );
    	if (mq<0)  {
        	perror("Open mq");
        	return;
    	}
}
