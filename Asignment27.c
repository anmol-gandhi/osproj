#include<windows.h>
//#include<unistd.h>            // Here it is Used For Sleep Function in Ubuntu
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int fault=0;            //  Counting Fault
int Ptr_Index=0;        //  Pointer Index
int Page_Replacement(int Ref_Str[],int Len_of_Str,int frames)
{
	int i,j,FIFO[frames],count=0;
	for(i=0,j=0;i<Len_of_Str;i++,j++)
	{	
		if(i>=0 && i<frames)
		{
			fault++;              // Incrementing Fault
			FIFO[j]=Ref_Str[i];   // Implementing Queue Operation
		}
		else
		{
			if(j==frames)
			{
				j=0;
				Ptr_Index=0;
			}
			
			if(FIFO[j]==Ref_Str[i])
			{
					
			}
			else
			{
				FIFO[j]=Ref_Str[i];   // Implementing Queue Operation
				fault++;
				Ptr_Index++;          // Incrementing Pointer Index
			}
		}	
		
		if(i>=frames-1)
		{
			printf("\n\n###############################");
			printf("\n#  %d  # Pointing At Index : %d #",Ref_Str[i],Ptr_Index);
			printf("\n###############################");
			usleep(800*1000);
			int k;
			for(k=0;k<frames;k++)
			{
				printf("\n#  %d  #",FIFO[k]);
				printf("\n#######");
				usleep(500*1000);              // Used For Sleep Time
			}
			printf("\n###############################");
			printf("\n#      Total Fault : %d        #",fault);
			printf("\n###############################");
		}	
		if(count==frames)
		{
			printf("\n\n");
			count=0;	
		}
		count++;
	}
	printf("\nTotal Fault : %d \n",fault);
}



int main()
{
	int top,n,i;
	Y:
	printf("\nEnter How Many Number Of Reference String You Want : ");
	scanf("%d",&n);
	
	if(n<0)
	{	
		printf("\nInvalid Number Of Reference String.");
		goto Y;
	}
	
	int Ref_Str[n];            // Reference String Array Variable
	
	srand(time(0));	           // Giving Seed to 

	for(i=0;i<n;i++)
	{
		Ref_Str[i]=rand()%10;		// Generating Random Reference String
	}	
	
	for(i=0;i<n;i++)
	{
		printf(" %d ",Ref_Str[i]);      // Displaying Reference String
	}
	
	int frames; 				// Frame Variable

	X:
	printf("\nEnter How Many Number Of Frames U Want (Range [ 0-7] ) : ");
	scanf("%d",&frames);

	if(frames>7 || frames<0)
	{
		printf("\nInvalid Frame.");
		goto X;
	}

	Page_Replacement(Ref_Str,n,frames);  	// Page_Replacement Function Calling With Parameters	

	return 0;
}
