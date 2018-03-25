#include<stdio.h>
#include<conio.h> 

struct ProcessControlBlock
{
	char process_name;
	int arrival_time;
	int burst_time;
	int burst_time1;
	int completion_time;
	int turn_around_time;
	int process_waiting_time;
	
}p[20];

struct ProcessControlBlock *ready_queue[20];
int front = -1;
int rear = -1;
int flag=0;


					char qinsert(struct ProcessControlBlock  *item)
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
							return ready_queue[rear]->process_name;
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
	
	
	for(a = 0; a < number_of_process; a++)
	{
		int temp;
		p[a].process_name = 'A'+a;
		
		printf("\nEnter Process Arraival Time for the process %c : ",p[a].process_name);
		scanf("%d",&p[a].arrival_time);
		printf("\nEnter Process Burst Time for the process having Process %c : ",p[a].process_name);
		scanf("%d",&p[a].burst_time);
		 p[a].burst_time1 = p[a].burst_time;
		
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
	
			for(j = 0; j < time_quantum; j++)
			{
				
				//Arrival Department Start
				for(k = 0; k < number_of_process; k++)
				{	
					if(p[k].arrival_time == time)
					{
						qinsert(&p[k]);
						//printf("\n Process %c is inserted in the Ready Queue.\n",p[k].process_name);
						
					}
				}
				
			ready_queue[front]->burst_time = ready_queue[front]->burst_time - 1;
			time = time + 1;
			 
			 
			if(ready_queue[front]->burst_time==0)
			{
				printf("\nProcess %c is Finished at Time: %d.\n",ready_queue[front]->process_name,time);
			
				ready_queue[front]->completion_time = time;
				flag = flag + 1;
				qdelete();	
			}
			

				
		}
			
			
			
			if(ready_queue[front]->burst_time>0)
			{
				struct ProcessControlBlock *last = ready_queue[front];
			
				qdelete();
				qinsert(last);
				printf("\nProcess %c is interrupted at time = %d. ",last->process_name,time);
			
			
			}

		
	}
	
	
/*for(m=0;m<number_of_process;m++)
{
	printf("\n");
	printf("%d",m);
	printf("\n");
	printf("%d",p[m].burst_time1);
	p[m].process_waiting_time = p[m].turn_around_time - p[m].burst_time1;
	total_waiting_time = p[m].process_waiting_time + total_waiting_time;
}
	avg_waiting_time = total_waiting_time/number_of_process;
	printf("\nTotal Waiting Time: %d\n",total_waiting_time);
    printf("\nAvarage Waiting Time: %d\n",avg_waiting_time);


	*/
	return 0;
}

