/*************************************************************************
    > File Name: number_selection.c
    > Author: Kid Chao
    > E-mail: zzykid1412@gmail.com
    > Created Time: 2018年06月25日 星期一 11时01分33秒
    > Description: 

    > Version: 1.0 
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool checknum(char *num)
{
	if( (num[3]  == num[0] || num[3]  == num[1] || num[3]  == num[2])
	 && (num[4]  == num[0] || num[4]  == num[1] || num[4]  == num[2])
	 && (num[5]  == num[0] || num[5]  == num[1] || num[5]  == num[2])
	 && (num[6]  == num[0] || num[6]  == num[1] || num[6]  == num[2])
	 && (num[7]  == num[0] || num[7]  == num[1] || num[7]  == num[2])
	 && (num[8]  == num[0] || num[8]  == num[1] || num[8]  == num[2])
	 && (num[9]  == num[0] || num[9]  == num[1] || num[9]  == num[2])
	 && (num[10] == num[0] || num[10] == num[1] || num[10] == num[2]))
		return true;
	else
		return false;
}

/* num: phone number
 * mask: how many different number
 */
bool checknum1(unsigned char *num, unsigned mask)
{
	unsigned char temp[11];
	int i = 0;
	int j = 0;
	memset(temp, 0xFF, 11);
	while(i < 11)
	{
		if(temp[0] != num[i] && temp[1] != num[i] && temp[2] != num[i] && temp[3] != num[i])
		{
			temp[j] = num[i];
			j++;
			i++;
		} else {
			i++;
		}
	}

	if(temp[mask] == 0xFF && temp[0] != 0xFF)
	{
		return true;
	} else {
		return false;
	}

}

//head == tail
bool checknum2(unsigned char *num)
{
	if(num[0] == num[8] && num[1] == num[9] && num[2] == num[10])
	{
		return true;
	} else
	{
		return false;
	}
}

//huiwen
bool checknum3(unsigned char *num)
{
	if(num[0] == num[10] && num[1] == num[9] && num[2] == num[8])
	{
		return true;
	} else
	{
		return false;
	}
}

int main(int argc, char *argv[])
{
	unsigned char data[200] = {0};
	int i = 0;
	FILE *input = NULL;
	FILE *output1 = NULL;
	FILE *output2 = NULL;
	FILE *output3 = NULL;
	FILE *output4 = NULL;
	if(argc == 1)
	{
		//fp = fopen("number5.txt","rb");
		printf("Input Wrong");
	} else
	{
		input = fopen(argv[1],"rb");
	}

	if(input == NULL)
	{
		perror("open input failed");
		exit(EXIT_FAILURE);
	}

	output1 = fopen("three_num.txt","rw+");
	output2 = fopen("four_num.txt","rw+");
	output3 = fopen("headtail_num.txt","rw+");
	output4 = fopen("huiwen_num.txt","rw+");
	if(output1 == NULL || 
	   output2 == NULL || 
	   output3 == NULL || 
	   output4 == NULL)
	{
		perror("open output file failed");
		exit(EXIT_FAILURE);
	}

	while(!feof(input))
	{
		i++;
		memset(data, 0, 200);
		//fscanf(fp,"%s",data);
		fgets(data, 200, input);
		if(data[0] != '1')
		{
			continue;
		}

		if(checknum1(data, 3))
		{
			printf("Line %6d:Three number   ", i);
			printf("%s", data);
			printf("\n");
			fputs(data, output1);
		}

		if(checknum1(data, 4))
		{
			printf("Line %6d:Four number   ", i);
			printf("%s", data);
			printf("\n");
			fputs(data, output2);
		}

		if(checknum2(data))
		{
			printf("Line %6d:Head-Tail    ", i);
			printf("%s", data);
			printf("\n");
			fputs(data, output3);
		}

		if(checknum3(data))
		{
			printf("Line %6d:Huiwen   ", i);
			printf("%s", data);
			printf("\n");
			fputs(data, output4);
		}
	}

	fclose(input);
	fclose(output1);
	fclose(output2);
	fclose(output3);
	fclose(output4);
	return EXIT_SUCCESS;
}
