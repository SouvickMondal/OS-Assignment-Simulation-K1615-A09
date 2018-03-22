#include<iostream>
using namespace std;
//Author: SOuvick Mondal
struct ProcessControlBlock
{
	int at,bt,id,wtime;
	bool exe;
}s[10];
void sort(ProcessControlBlock** , int );
int main()
{
	int n,clock;
	cout<<"Enter Number of Process: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the arrival time for Process "<<i+1<<":";
		cin>>s[i].at;
		s[i].id=i+1;
		s[i].bt=s[i].at*2;
		s[i].exe=false;
		s[i].wtime=0;
	}
	cout<<"Details of ProcessControlBlockes are: \n";
	cout<<"ID\tArrival Time\tBurst Time\n";
	for(int i=0;i<n;i++)
	{
		cout<<s[i].id<<"\t"<<s[i].at<<"\t\t"<<s[i].bt;
		cout<<"\n";
	}

	ProcessControlBlock s1[n],*readyqueue[n];
	int size=0;
	clock=0;
	ProcessControlBlock *executing = NULL;
	while(true)
	{
		bool alldone=true;
		for(int i=0;i<n;i++)
		{
			if(s[i].exe==false)
			{
				alldone=false;
				break;
			}
		}	
		if(alldone)
			break;
		for(int i=0;i<n;i++)
		{
			if(s[i].at==clock && s[i].exe==false){
				readyqueue[size]=&s[i];
				size++;
			}
		}
		if ( executing != NULL && executing->bt + executing->wtime + executing->at == clock) {
			executing = NULL;
		}
		if(size>0 && executing == NULL)
		{
			sort(readyqueue,size);
			readyqueue[size-1]->exe=true;
			executing = readyqueue[size-1];
			cout<<readyqueue[size-1]->id<<" executed"<<endl;
			size--;
		}
		for(int j=0;j<size;j++)
		{
			readyqueue[j]->wtime++;
		}
		clock++;
	}
	int totalcomplete=0;
	int totalturnaround=0;
	int totalwaiting=0;
	for(int i=0;i<n;i++)
	{
		totalwaiting += s[i].wtime;
		totalcomplete=s[i].bt+s[i].wtime+s[i].at+totalcomplete;
		totalturnaround=(s[i].bt+s[i].wtime)+totalturnaround;
	}
	cout<<"Total Complete Time: "<<totalcomplete<<endl;
	cout<<"Total Turn Around Time: "<<totalturnaround<<endl;
	cout<<"Average Turn Around Time: "<<(float)(totalturnaround)/n<<endl;
	cout<<"Average Waiting Time: "<<(float)(totalwaiting)/n<<endl;
}
void sort(ProcessControlBlock *readyqueue[10],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(readyqueue[j]->bt>readyqueue[j+1]->bt)
			{
				ProcessControlBlock *temp=readyqueue[j];
				readyqueue[j]=readyqueue[j+1];
				readyqueue[j+1]=temp;
			}
		}
	}
}
