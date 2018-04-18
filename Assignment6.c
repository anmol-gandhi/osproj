#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<pthread.h>
#include<semaphore.h>

int Teaching_Assistnt = 0;
int count=0;
int waiting_queue[3];

pthread_mutex_t mutex;

void *office()
{
        pthread_mutex_lock(&mutex);     //  Mutex Lock Active
        Teaching_Assistnt = 1;
		Sleep(30);
        Teaching_Assistnt = 0;
        pthread_mutex_unlock(&mutex);      //  Mutex Lock Deactive
    Sleep(3);
	
}

int main()
{
	pthread_t thread[4];
	printf("\n\tTeaching Assistant is in Rest..");
	int opt;
	X:
	printf("\n\tWould You Like to Ask For Help..[Yes = 1 : NO = 0] : ");
	scanf("%d",&opt);
	if(opt==1)
	{
		if(count>=1 && count<4)
		{	
			printf("\n\tTeaching Assistant is Bussy. You Have To Wait..\n");
			pthread_mutex_init(&mutex, NULL);
			pthread_create(&thread[count],NULL,office,NULL);
			pthread_join(thread[count],NULL);
			count++;
			goto X;
		}
		if(count==4)
		{
			printf("\n\tWaiting Queue is Already Full Come Back Tomorrow..");
			Y:
			printf("\n\tWould u Like To Exit [ Yes = 1 : No = 0 ]");
			scanf("%d",&opt);
			if(opt==1)
			{
				int i;
				printf("\n\t%d Student Asked For Help.",count);
				for(i=0;i<4;i++)
					{
						printf("\n\t###############################################");
        				printf("\n\t##   Student %d    ##    Succesfully Helped   ##",i+1);		
					}
				printf("\n\t###############################################\n");
				printf("\n\tTeaching Assistant is Now Sleeping..!!! ");
	
				return 0;
			}
			else if(opt==0)
			{
				goto X;
			}
			else
			{
				printf("\n\tInvalid Option..");
				goto Y;
			}
			sleep(1);
		}
		if(count==0)
		{
			pthread_mutex_init(&mutex, NULL);
			pthread_create(&thread[count],NULL,office,NULL);
			count++;
			goto X;
		}
		count++;
		goto X;
	}
	else if(opt==0)
	{
		int i;
		printf("\n\t%d Student Asked For Help.",count);
		for(i=0;i<count;i++)
		{
			printf("\n\t###############################################");
        	printf("\n\t##   Student %d    ##    Succesfully Helped   ##",i+1);		
		}
		printf("\n\t###############################################\n");
		printf("\n\tTeaching Assistant is Now Sleeping..!!! ");
		return 0;
	}
	else
	{
		printf("\n\tInvalid Option..");
		goto X;
	}

	
}
