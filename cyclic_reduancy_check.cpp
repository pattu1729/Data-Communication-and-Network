#include <stdio.h> 
#include <conio.h> 
#include <string.h> 

int main() 
{ 
	int i,j,keylength,msglength; 
	char input[100], key[30],temp[30],quotient[100],remainder[30],key1[30]; 
	printf("Enter Data: "); 
 	gets(input); 
 	printf("Enter Key: "); 
 	gets(key); 
 	keylength=strlen(key); 
 	msglength=strlen(input); 
 	strcpy(key1,key); 
 	for (i=0;i<keylength-1;i++)
	{ 
 		input[msglength+i]='0'; 
 	} 
 	for (i=0;i<keylength;i++) 
 		temp[i]=input[i]; 
 	for (i=0;i<msglength;i++)
	{ 
 		quotient[i]=temp[0]; 
 		if(quotient[i]=='0') 
 			for (j=0;j<keylength;j++) 
 				key[j]='0'; 
		else 
 			for (j=0;j<keylength;j++) 
				key[j]=key1[j]; 
 			for (j=keylength-1;j>0;j--)
			{ 
 				if(temp[j]==key[j]) 
 					remainder[j-1]='0'; 
				else 
 					remainder[j-1]='1'; 
 	} 
 	remainder[keylength-1]=input[i+keylength]; 
 	strcpy(temp,remainder); 
	} 
	
 	strcpy(remainder,temp); 
 	printf("\nQuotient is "); 
 	for (i=0;i<msglength;i++) 
 		printf("%c",quotient[i]); 
		printf("\nRemainder is "); 
 	for (i=0;i<keylength-1;i++) 
 		printf("%c",remainder[i]); 
 	printf("\nFinal data is: "); 
 	for (i=0;i<msglength;i++) 
 		printf("%c",input[i]); 
 	for (i=0;i<keylength-1;i++) 
		printf("%c",remainder[i]); 

} 

