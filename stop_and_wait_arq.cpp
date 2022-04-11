#include<stdio.h> 

#include<stdlib.h> 

#include<unistd.h> 

int no_frames; 

int frame[100]; 

char ack[100]; 

int data,r; 

int rece(); 

void resend(); 

void sender() 

{ 

 printf("\n--Sender side--\n"); 

 int i; 

 printf("Enter the number of frames to sent\n"); 

 scanf("%d",&no_frames); 

 for(i=0;i<no_frames;i++) 

 { 

 printf("Enter the data for the frame -> %d\n",(i+1)); 

 scanf("%d",&frame[i]); 

 ack[i]='y'; 

 rece(); 

 } 

} 

int rece() 

{ 

 printf("\n--Receiver side--\n"); 

 int i; 

 rand(); 

 r=rand()%no_frames; //not received frame 

 ack[r]='n'; //not received frame making not acknowledged so n 

 for(i=0;i<no_frames;i++) 

 { 

 if(ack[i]=='n') 

 { 

 printf("\nThe ack is not sent\n"); 

 resend(i); 

 } 

 else 

 printf("\nThe ack is sent\n"); 

 break; 

 } 

 return 0; 


} 

void resend(int i) 

{ 

 printf("\n--Resending--\n"); 

 sleep(2); 

 ack[i]='y'; 

 printf("\nFrame sent again\n"); 

 printf("\nThe ack is sent\n"); 

 

} 

int main() 

{ 

 printf("\n--Stop and Wait ARQ--\n"); 



 sender(); 

 return 0; 

} 

 
