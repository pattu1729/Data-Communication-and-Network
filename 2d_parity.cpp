#include<stdio.h> 

int main() 
{ 
 	char d[6][11]; 
 	int i,j,n,count; 
 	for(i=0;i<5;i++) 
 	{ 
 		printf("Enter row %d :",i+1); 
 		scanf("%s",d[i]); 
 	} 
 	
 	for(i=0;i<5;i++) 
 	{ 
 		count=0; 
 		for(j=0;d[i][j]!='\0';j++) 
 		{ 
 			if(d[i][j]=='1') 
 			count++; 
 		} 
 		if(count%2==0) 
 			d[i][j]='0'; 
 		else 
 			d[i][j]='1'; 
 			j++; 
 			d[i][j]='\0'; 
 	} 
 	
 	for(j=0;j<=7;j++) 
 	{ 
 		count=0; 
 		for(i=0;i<5;i++) 
 		{ 
 			if(d[i][j]=='1') 
 			count++; 
 		} 
 		if(count%2==0) 
 			d[i][j]='0'; 
 		else 
 			d[i][j]='1'; 
 	} 
 	
	d[i][j]='\0'; 
	for(i=0;i<=5;i++) 
 	{ 
		printf("\n"); 
		printf("\n%s",d[i]); 
	} 
	printf("\n"); 
	return 0; 
} 
