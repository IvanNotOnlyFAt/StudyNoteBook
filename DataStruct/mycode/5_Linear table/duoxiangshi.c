#include<stdio.h>
#define SIZE_1 5
#define SIZE_2 7

typedef struct mult
{
	int  coe;//xi
	int  idex;//zhi
}mult;

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;

   mult s1[SIZE_1] = {{1,0},{2,1},{3,2},{4,3},{5,4}};
   mult s2[SIZE_2] = {{2,1},{3,2},{4,3},{5,4},{6,5},{7,6},{8,7}};
   mult s3[SIZE_1 + SIZE_2];

   while(i < SIZE_1)
{
	if(s1[i].idex == s2[j].idex)
	{
		s3[k].coe = s1[i].coe + s2[j].coe;
		s3[k].idex = s1[i].idex;
		i++;
        j++;
        k++;
	}
    else if(s1[i].idex > s2[j].idex)
    {
        s3[k].coe  =  s2[j].coe;
		s3[k].idex = s2[j].idex;
		k++;
		j++;
    }
    else
    {
        s3[k].coe  =  s1[i].coe;
		s3[k].idex = s1[i].idex;
		k++;
		i++;
    }

}

while(k < SIZE_2+1)
{
        s3[k].coe =  s2[j].coe;
		s3[k].idex = s2[j].idex;
		k++;
        j++;
}
 
 i = 0;

while(i < k)
{
	printf("%d x ^ %d +",s3[i].coe,s3[i].idex);
	i++;
}
printf("\n");

return 0;
   
}
