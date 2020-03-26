#include <stdio.h>
#include <time.h>

int main()
{
	int a,b,c,d,e,f,g,h,i;
	int flag;
	int count=0;
	int row1,row2,row3,col1,col2,col3,dia1,dia2;
	int total_time;
	clock_t start, end;

	int array1[9];
	
	FILE *fptr;
	fptr = fopen("results1.txt","w");
	
	if(fptr == NULL)
	{
		printf("File Error!");   
		//exit(1);             
	}
	printf("Magic Square Initiated\n");
	start = clock();
	
	for (a=1;a<10;a++)
	{
		for (b=1;b<10;b++)
		{
			for (c=1;c<10;c++)
			{
				for (d=1;d<10;d++)
				{
					for (e=1;e<10;e++)
					{
						for (f=1;f<10;f++)
						{
							for (g=1;g<10;g++)
							{
								for (h=1;h<10;h++)
								{
									for (i=1;i<10;i++)
									{
										//printf("Core Loop!");
										array1[0] = a;
										array1[1] = b;
										array1[2] = c;
										array1[3] = d;
										array1[4] = e;
										array1[5] = f;
										array1[6] = g;
										array1[7] = h;
										array1[8] = i;
										
										flag = 0;
										for(int m=0; m<9; m++)
										{	
											for(int n=0; n<9; n++)
											{
												if(m!=n && array1[m] == array1[n])
												{
														flag = 1;
												}
											}
										}
										if(flag == 0)
										{
											row1 = a + b + c;
											row2 = d + e + f;
											row3 = g + h + i;
											
											col1 = a + d + g;
											col2 = b + e + h;
											col3 = c + f + i;
											
											dia1 = a + e + i;
											dia2 = g + e + c;
											
											
											if(row1 == 15 && row2 == 15 && row3 == 15 && col1 == 15 && col2 == 15 && col3 == 15 && dia1 == 15 && dia2 == 15)
											{
												count++;
												printf("%d\n",count);
												
												fprintf(fptr,"%d\n",count);
												
												fprintf(fptr,"+---+---+---+\n");
												fprintf(fptr,"| %d | %d | %d |\n",a,b,c);
												fprintf(fptr,"+---+---+---+\n");
												fprintf(fptr,"| %d | %d | %d |\n",d,e,f);
												fprintf(fptr,"+---+---+---+\n");
												fprintf(fptr,"| %d | %d | %d |\n",g,h,i);
												fprintf(fptr,"+---+---+---+\n");
												fprintf(fptr,"\n");
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	end = clock();
   
	printf("Matrix count = %d\n",count);
	
	//time count stops 
	total_time = (end - start) / CLOCKS_PER_SEC;
	
	printf("\nTime taken to find perfect 15 is: %d total seconds ", total_time);
	printf("\nTime taken to find perfect 15 is: %d mins %d secs ", total_time/60, total_time%60);
	fprintf(fptr,"\nTime taken to find perfect 15 is: %d mins %d secs ", total_time/60, total_time%60);
	
	fclose(fptr);
    return 0;
}
