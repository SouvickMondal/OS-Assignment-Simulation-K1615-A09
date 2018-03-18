//Scheduler


//Ques. 16. Design a scheduler that can schedule the processes arriving system at periodical intervals. 
//Every process is assigned with a fixed time slice t milliseconds. 
//If it is not able to complete its execution within the assigned time quantum, then automated timer generates an interrupt. 
//The scheduler will select the next process in the queue and dispatcher dispatches the process to processor for execution. 
//Compute the total time for which processes were in the queue waiting for the processor. 
//Take the input for CPU burst, arrival time and time quantum from the user. 
 



#include<stdio.h>
#include<conio.h>
#include<stdbool.h>



struct ProcessControlBlock
{
	char process_name;
	int process_id;
	int arrival_time;
	int burst_time;
	int burst_time1;
	int completion_time;
	int turn_around_time;
	int process_completion_status;
	int process_readyqueue_status;
	int process_waiting_time;
	
}p[20];

struct ProcessControlBlock *ready_queue[100];
int front = -1;
int rear = -1;
int waiting_time[20];
int wt = 0;	
int avg_waiting_time;
int total_waiting_time = 0;
int flag=0;


					char qinsert(struct ProcessControlBlock * item)
						{
							if(front<0)
							{
								front = 0;
								rear = 0;
							}
							else
							{
								rear = rear + 1;
							}
							ready_queue[rear] = item;
							return item->process_name;
						}
						
						char qdelete()
						{
							struct ProcessControlBlock *del = ready_queue[front];
								if(front == rear)
							{
				
								front = -1;
								rear = -1;
							}
							else
							{	
								front = front + 1;
							}
							return del->process_name;
						}
  

int main()
{
	int number_of_process;
	int time_quantum;
	int time;
	int j,k,a;
	
	printf("-------- How many processes are there in the queue ? --------- \n Enter the number:- ");
	scanf("%d",&number_of_process);
	printf("\n<<<<<    Thank you for entering the number of processes    >>>>>>>\n");
	
	printf("\n Enter the Time Quantum : ");
	scanf("%d",&time_quantum);
	printf("\n<<<<<   Thank you for entering the Time Quantum   >>>>>>\n");
	
	//Process Completion Status Check Function
	
	/* int check()
   {
   	int i1 = 0;
   	for(i1 = 0;i1<number_of_process;i1 ++)
   	{
   		if(p[i1].process_completion_status!=2)
   		{
   			break;
		   }
		   
	   }
	 if(i1 == number_of_process)
	 {
	 	return 2;
	   } 
	   else
	   {
	   	return 3;
		} 
   	
	}		
	*/
	
	
	
	for(a = 0; a < number_of_process; a++)
	{
		int temp;
		p[a].process_name = 'A'+a;
		p[a].process_id = 101 + a;
		p[a].process_completion_status = -1;
		p[a].process_readyqueue_status = -1;
		
		printf("\nEnter Process Arraival Time for the process %c : ",p[a].process_name);
		scanf("%d",&p[a].arrival_time);
		printf("\nEnter Process Burst Time for the process having Process %c : ",p[a].process_name);
		scanf("%d",&p[a].burst_time);
		temp = p[a].burst_time;
		 p[a].burst_time1 = temp;
		
	}
	//To Find Starting Time
	
	int loop;
	int min=p[0].arrival_time;
	for(loop=0;loop<number_of_process;loop++)
	{
		if(p[loop].arrival_time<min)
		{
			min = p[loop].arrival_time;
		}
	}
	time = min;
	while(flag<number_of_process)
	{
	/*	int i = 0;
		while(i<number_of_process)
		{
			if(p[i].process_completion_status<0)
			{
				break;
			}
			else
			{
				i = i + 1;
			}
		}
		if(i == number_of_process)
		{
			return 0;
		}
	*/	
	//else
	//	{
			
	
int m;
for(m=0;m<number_of_process;m++)
{
	printf("\n");
	printf("%d",m);
	printf("\n");
	printf("%d",p[m].burst_time1);
/*	p[m].process_waiting_time = p[m].turn_around_time - p[m].burst_time1;
	total_waiting_time = p[m].process_waiting_time + total_waiting_time;*/
}	
	/*avg_waiting_time = total_waiting_time/number_of_process;
	printf("\nTotal Waiting Time: %d\n",total_waiting_time);
    printf("\nAvarage Waiting Time: %d\n",avg_waiting_time);
	*/
}

