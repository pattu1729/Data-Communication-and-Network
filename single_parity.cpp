#include<stdio.h> 

void singleparity(int databits[20],int parity,int nob) 
{ 
 	int i,one=0,zero=0; 
 	for(i=0;i<nob;i++) 
 	{ 
 		if(databits[i]==1) 
 			one++; 
 		if(parity==0) 
 		{
		 	if(one%2!=0) 
		 		databits[nob]=1; 
			else 
		 		databits[nob]=0; 
		}

		else 
 		{ 
 			if(one%2!=0) 
 				databits[nob]=0; 
 			else 
 				databits[nob]=1; 
		} 
 	} 
 	
	for(i=0;i<=nob;i++) 
 		printf("%d",databits[i]); 
 	printf("\n"); 
 	for(i=0;i<=nob;i++) 
 	{ 
 		if(databits[i]==1) 
 		zero++; 
 	} 
 	
 	printf("Receiver Side:\n"); 
 	if(parity==0) 
 	{ 
 		if(zero%2==0) 
 			printf("Data Received as it is\n"); 
 		else 
 			printf("Data is not same\n"); 
 	} 
 	else if(parity==1) 
 	{ 
 		if(zero%2!=0) 
 			printf("Data is same\n"); 
 		else 
 			printf("Data is not same\n"); 
 	} 
} 

int main() 
{ 
 	int databits[20],i,parity,nob,one=0,zero=0; 
 	printf("Sender Side:\n"); 
	printf("Enter the Parity 0 for even and 1 for odd\n"); 
	scanf("%d",&parity); 
	printf("Enter the Total number of bits:"); 
	scanf("%d",&nob); 
	printf("Enter the Data Bits:\n"); 
    for(i=0;i<nob;i++) 
		scanf("%d",&databits[i]); 
	singleparity(databits,parity,nob); 
	return 0; 
} 

