#include<stdio.h> 

int n,g[100][100],visited[100]; 



 

void DFS(int s) 

{ 

 int i; 

 visited[s]=1; 

 printf("\nvisited node is %d \n",s); 

 for(i=0;i<n;i++) 

 { 

 if(visited[i]==0 && g[s][i]==1) 

 { 

 DFS(i); 

 } 

 } 

} 

int main() 

{ 

 

 int i,j,s; 

 printf("Enter the number of vertices:"); 

 scanf("%d",&n); 

 printf("Enter the matrix:\n"); 

 for(i=0;i<n;i++) 

 

 { 

 for(j=0;j<n;j++) 


 { 

 scanf("%d",&g[i][j]); 

 } 

 } 

 for(i=0;i<n;i++) 

 visited[i]=0; 

 

 printf("Enter the starting/root vertex\n"); 

 scanf("%d",&s); 

 DFS(s); 

 return 0; 

} 
