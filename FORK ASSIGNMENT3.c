#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int sum;
    int array[1000];
    
    for(int i=0;i<1000;i++)
    {
        array[i]=i+2;
    }
    
    int id=fork();
    if(id==0)
    {
        for(int j=0;j<100;j++)
        {
            sum = sum+array[j];
        }
    }
    else
    {
       
        for(int j=100;j<200;j++)
		{
            sum = sum+array[j];
        }

        for(int j=200;j<300;j++)
		{  	
            sum = sum+array[j];
        }
	  for(int j=300;j<400;j++)
		{
        	sum = sum+array[j];
        }
            
    	for(int j=400;j<500;j++)
		{
            sum = sum+array[j];
        }
                    
        for(int j=500;j<600;j++)
        {
            sum = sum+array[j];
        }        
                      
        for(int j=600;j<700;j++)
		{
        	sum = sum+array[j];
        }
                               
        for(int j=700;j<800;j++)
        {
            sum = sum+array[j];
        }
    
		for(int j=800;j<900;j++)
 		{
			sum = sum+array[j];
		}
       for(int j=900;j<1000;j++)
    	{
       		sum = sum+array[j];
    	}
		printf("Total Sum Is :: ",sum);
	}
    return 0;
}
