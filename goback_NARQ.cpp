#include<stdio.h> 

#include<stdlib.h> 

#include<unistd.h> 

int no_frames; 

int data,r; 

char ack[100]; 

int frame[100]; 

void receiver(); 

void resend_gob(); 

void sender() 

{ 

 printf("\n--Sender side--\n"); 

 int i; 

 printf("Enter the number of frames to sent\n"); 

 scanf("%d",&no_frames); 

 for(i=1;i<=no_frames;i++) 

 { 

 printf("Enter the data for the frame -> %d\n",i); 

 scanf("%d",&frame[i]); 

 ack[i]='y';//all acks are acknowledged 

 } 

} 

void receiver() 

{ 

 printf("\n--Receiver side--\n"); 

 int i; 

 rand(); 

 r=rand()%no_frames; //not received frame 

 ack[r]='n'; //not received frame making not acknowledged so n 

 for(i=1;i<=no_frames;i++) 

 { 

 if(ack[i]=='n') // 

 { 

 printf("\nThe frame -> %d is not received \n",r); 

 printf("\nThe ack of %d is not sent\n",r); 

 resend_gob(); 

 } 

 else 

 printf("\nAll Frames are received Successfully\n"); 

 break; 

 } 

} 

void resend_gob() 

{ 


 printf("\n--Resending--\n"); 

 int i; 

 printf("\nResending frames from frame %d\n",r); 

 for(i=r;i<=no_frames;i++) 

 { 

 sleep(2); 

 ack[i]='y'; 

 printf("\nReceived frame %d and data is %d \n",i,frame[i]); 

 printf("\nThe ack of %d is sent\n",i); 

 } 

} 

int main() 

{ 

 printf("----GO BACK N ARQ----\n"); 

 


 sender(); 

 receiver(); 

 printf("\n Exit Successfully\n"); 

 return 0; 

} 

 

 

