# OS-project lpu 11810904
#include<stdio.h>
#include<conio.h>

struct process
{
int flag;
int p_no,arrival_t,burst_t,ct,wait_t,taround_time,p;
 }p_list[250];
int n;
 void Sort()
 {
struct process p;

int i, j;
for(i=0;i<n-1;i++)

{
for(j=i+1;j<n;j++)
{
if(p_list[i].arrival_t > p_list[j].arrival_t)
{
p = p_list[i];
p_list[i] = p_list[j];
p_list[j] = p;
}
}
}
 }
 int main()
 {

int i,t=0,b_t=0,peak;

int a[10];

float wait_time = 0, taround_time = 0, avg_w_t=0, avg_taround_time=0;

printf("please enter number of processes: ");
scanf("%d",&n);
for(i = 0; i < n; i++)

{

p_list[i].p_no = i+1;

printf("\nenter details for  process P%d :-\n", p_list[i].p_no);
printf("enter Arrival Time: ");
scanf("%d", &p_list[i].arrival_t );
printf("enter Burst Time: ");
scanf("%d", &p_list[i].burst_t);
p_list[i].flag = 0;
b_t = b_t + p_list[i].burst_t;
}
Sort();
for(i=0;i<n;i++)
{
a[i]=p_list[i].burst_t;
}
p_list[9].burst_t = 9999;
for(t = p_list[0].arrival_t; t <= b_t+1;)
{
peak = 9;
for(i=0;i<n;i++)
{
if(p_list[i].arrival_t <= t && p_list[i].burst_t < p_list[peak].burst_t && p_list[i].flag != 1)
{
peak = i;
}
if(p_list[peak].burst_t==0 && p_list[i].flag != 1)
{
p_list[i].flag = 1;
p_list[peak].ct=t;p_list[peak].burst_t=8887;
printf("P%d  process completed in %d time\n ",p_list[i].p_no,p_list[peak].ct);
}
}
t++;
(p_list[peak].burst_t)--;
}
for(i=0;i<n;i++)
{
p_list[i].taround_time=(p_list[i].ct)-(p_list[i].arrival_t);
avg_taround_time=avg_taround_time+p_list[i].taround_time;
p_list[i].wait_t=((p_list[i].taround_time)-a[i]);
avg_w_t=avg_w_t+p_list[i].wait_t;
}
printf("PNO\tAT\tCT\tTA\tWTt\n");
for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\n",p_list[i].p_no,p_list[i].arrival_t,p_list[i].ct,p_list[i].taround_time
,p_list[i].wait_t);
 }
printf("average turn around time is : %f\t\n\n",avg_taround_time);
printf("average waiting time is  :\t %f\t\n",avg_w_t);
}