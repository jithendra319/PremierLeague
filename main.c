#include "sortpoints.h"
int *queue;
int *cnt1;
int *cnt;
void readFile(char fileName[1000]);
void schedule_match();
struct team
{
    int host;
    int guest;
};
int n;
int *visited;
struct team *stadium;
struct points *pointstable;

int main(int argc, char** argv){
int pid,mainpid;
queue = mmap(NULL, 10000*sizeof(queue), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);   /* Queue Using Shared Memory */
cnt1 = mmap(NULL, sizeof *cnt1, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);           /* cnt1 indictaes front of the queue and shared variable too */
cnt = mmap(NULL, sizeof *cnt, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);	      /* cnt indicates Rear of the queue */
*cnt = 0;											      /* initially rear is 0 */
*cnt1 = 0;											      /* initially front is 0 */
visited = (int *) malloc(10 * sizeof(int));
    for(int i=0;i<10;i++)
    visited[i]=0;
    char *fileName=argv[1];
    readFile(fileName);
    int i = 0;
    srand(time(0));

    for(int i=0;i<n;i++){
        pointstable[i].won=0;
	    pointstable[i].draw=0;
	    pointstable[i].lost=0;
	    pointstable[i].goals_scored=0;
	    pointstable[i].points=0;
    }



for(i ; i < n; i = i + 1){
	mainpid = getpid();
	pid=fork();	        
	int count=0;
	if (pid < 0)                      	
	{
		fprintf(stderr, "Fork Failed");
		return -1;
	}
	else if (pid == 0 )     		/* stadium manager Enters here */
	{
		int count=0;	
		queue[*cnt] = getpid();    	/* Pushing stadium process Into the queue */
		*cnt = *cnt + 1;
		kill(getpid(),SIGSTOP);
		while(count<n-1){
			count+=1;
			kill(getpid(),SIGSTOP);
        	}
        	if(count==n-1){
        		exit(0);
		}
		break;
	}
	else
	{   
		usleep(5000);
	}	

}
	
	if(mainpid==getpid()){
    	    schedule_match();
    	    for(int j=0;j<n;j++){
		kill(queue[j],SIGCONT);
	}		
	    usleep(5000);
	    bsort(pointstable,n);
 	    printf("Team\tW\tD\tL\tGS\tpoints\n");
	    printf("-------------------------------------------------\n");
    		for (i=1; i<=n; i++)
    		{
    		  	  printf("%d\t%d\t%d\t%d\t%d\t%d\n",pointstable[i].teamno,pointstable[i].won,pointstable[i].draw,pointstable[i].lost,pointstable[i].goals_scored,pointstable[i].points);   
    		}
    }
	usleep(5000);	
	while(wait(NULL)>0);
	
return 0;	

}


void readFile(char fileName[1000])

{
    FILE *filePtr;
    int host=0;
    int guest=0;
    int position = 0,*temp;
    filePtr= fopen(fileName,"r");
    fscanf(filePtr,"%d",&n);
    stadium = (struct team*)malloc(n*(n-1)*sizeof(struct team));
    pointstable = (struct points*)malloc((n+1)*sizeof(struct points));
    temp=realloc(visited, n);


    for(int i=0;i<n;i++)
	visited[i]=0;

    while (fscanf(filePtr, " %d %d", &host, &guest) != EOF)
    {
        stadium[position].host = host;
        stadium[position].guest = guest;
        position++;

    }

    fclose(filePtr);
}


void schedule_match(){
	int count1=0;
	int count2=0,i=0;
	for(i;i<n*(n-1);i++){

			int host=stadium[i].host;
			int guest=stadium[i].guest;
				
			printf("Starting Match: Team%d vs Team%d \n",host,guest);
	
			int p1,p2;
			p1=rand()%6;
			p2=rand()%6;
			printf("Ending Match: Team%d vs Team%d\tResult:%d-%d \n",host,guest,p1,p2);
			pointstable[host].goals_scored+=p1;
			pointstable[guest].goals_scored+=p2;
			pointstable[host].teamno=host;
			pointstable[guest].teamno=guest;
			if(p1>p2){
				pointstable[host].points+=3;
				pointstable[host].won+=1;
				pointstable[guest].lost+=1;
			}
			else if(p1==p2){
				pointstable[host].draw+=1;
				pointstable[guest].draw+=1;
				pointstable[host].points+=1;
				pointstable[guest].points+=1;
			}
			else{
				pointstable[guest].points+=3;
				pointstable[guest].won+=1;
				pointstable[host].lost+=1;
			}
	
    
			kill(queue[host - 1] , SIGCONT); 		     /*Resuming child Execution from the queue */
			sleep(3);
        	}


		
}


