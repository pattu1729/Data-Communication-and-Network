#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int i,j;
int bin1[100],bin2[100],bin3[100],bin4[100];
int dec1,dec2,dec3,dec4;
int convert(int b[]);
int class_find(int val);
void display()
{
	printf("\nEntered ip in binary \t : ");
  	for(i=0;i<8;i++)
  		printf("%1d",bin1[i]);
  	printf(".");
  	for(i=0;i<8;i++)
  		printf("%1d",bin2[i]);
  	printf(".");
  	for(i=0;i<8;i++)
  		printf("%1d",bin3[i]);
  	printf(".");
  	for(i=0;i<8;i++)
  		printf("%1d",bin4[i]);
}
void enter_bin()
{
	printf("Enter the binary data 1:\n");
  	for(i=0;i<8;i++)
    	scanf("%1d",&bin1[i]);
  	printf("Enter the binary data 2:\n");
  	for(i=0;i<8;i++)
    	scanf("%1d",&bin2[i]);
  	printf("Enter the binary data 3:\n");
  	for(i=0;i<8;i++)
    	scanf("%1d",&bin3[i]);
  	printf("Enter the binary data 4:\n");
  	for(i=0;i<8;i++)
    	scanf("%1d",&bin4[i]);
    display();
}
void calculate()
{
	if(bin1[0]==0)
	{
		printf("\nClass A\n");
    	printf("Host id \t : %d\n",convert(bin1));		
		printf("Newtork id \t : %d.%d.%d\n",convert(bin2),convert(bin3),convert(bin4));
	}	
	else if((bin1[0]==1 && bin1[1]==0))
  	{
	  	printf("\nClass B\n");
	    printf("Host id \t : %d\n",convert(bin1));		
    	printf("Newtork id \t : %d.%d.%d\n",convert(bin2),convert(bin3),convert(bin4));
  	}
	else if((bin1[0]== 1 && bin1[1]==1 && bin1[2]==0))
  	{
    	printf("\nClass C\n");
    	printf("Host id \t : %d\n",convert(bin1));		
    	printf("Newtork id \t : %d.%d.%d\n",convert(bin2),convert(bin3),convert(bin4));
  	}
  	else if((bin1[0]== 1 &&bin1[1]==1 &&bin1[2]==1 && bin1[3]==0))
  	{
    	printf("\nClass D\n");
    	printf("Host id \t : not defined\n");
    	printf("Network id \t : not defined\n");
  	}
	else if((bin1[0]==1&&bin1[1]==1&&bin1[2]==1&&bin1[3]==1))
	{
    	printf("\nClass E\n");
    	printf("Host id \t : not defined\n");
    	printf("Network id \t : not defined\n");
  	}
  	else 
    	printf("\nInvalid\n");
}
int power_func(int c,int d)
{
	int value=1;
	int count=1;
	while(count<=d)
	{
		value=value*c;
		count++;
	}
	return value;
}
int convert(int b[])
{
	int digit_count=8,dec_num=0,a=0;
  	for(i=(digit_count-1);i>=0;i--)
  	{
  		dec_num=(b[i]*power_func(2,a)) + dec_num;
  		a++;
  	}
  	return dec_num;
}
int enter_decimal()
{
	printf("Enter the decimal 1\n");
	scanf("%d",&dec1);
	printf("Enter the decimal 2\n");
	scanf("%d",&dec2);
	printf("Enter the decimal 3\n");
	scanf("%d",&dec3);
	printf("Enter the decimal 4\n");
	scanf("%d",&dec4);
	printf("Entered ip\t%d.%d.%d.%d\n",dec1,dec2,dec3,dec4);
	class_find(dec1);
}
int class_find(int val)
{
	if(val>=0 && val<=127)
	{
		printf("\nClass A\n");
		printf("Host id \t : %d\n",val);
		printf("Network id \t : %d.%d.%d\n",dec2,dec3,dec4);
	}
	else if(val>=128 && val<=191)
	{
		printf("\nClass B\n");
		printf("Host id \t : %d\n",val);
		printf("Network id \t : %d.%d.%d\n",dec2,dec3,dec4);
	}
	else if(val>=192 && val<=223)
	{
		printf("\nClass C\n");
		printf("Host id \t : %d\n",val);
		printf("Network id \t : %d.%d.%d\n",dec2,dec3,dec4);
	}
	else if(val>=224 && val<=239)
	{
		printf("\nClass D\n");
		printf("Host id \t : Not defined\n");
		printf("Network id \t : Not defined\n");
	}
	else if(val>=240 && val<=255)
	{
		printf("\nClass E\n");
		printf("Host id \t : Not defined\n");
		printf("Network id \t : Not defined\n");
	}
	else
	{
		printf("\nInvalid\n");
	}
	return 0;
}
int main()
{
	printf("1.Binary Ip address\n2.Decimal Ip address\n");
	printf("Enter any of the following\n");
  	int num;
  	scanf("%d",&num);
  	switch(num)
  	{
  		case 1: enter_bin();
  				calculate();
  				break;
  		case 2: enter_decimal();
  				break;
  		default:printf("Invalid\n");
  	}
  	return 0;
}


