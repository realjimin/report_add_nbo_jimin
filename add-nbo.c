#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv)
{
    if (argc != 3){
        printf("error");
        return 0;
    }

    FILE* pFile = fopen(argv[1], "rb");
    FILE* pFile_1 = fopen(argv[2], "rb");
    
    if(pFile == NULL)
    {
        printf("no file");
        return 0;
    }

    if(pFile_1 == NULL)
    {
        printf("no file");
        return 0;
    }

    int str;
    int str_1;
    int num;
    int num1;
    int num2;
    char f_1[4]={0};
    char f_m[8]={0};
    char f_2[4]={0};
    char f_m_2[8]={0};


    while ((str = fgetc(pFile)) != EOF ){
	sprintf(f_1, "%02x", str);
	strcat(f_m, f_1);
    }

    num1 = strtol(f_m, NULL, 16);

    while ((str_1 = fgetc(pFile_1)) != EOF ){
        sprintf(f_2, "%02x", str_1);
        strcat(f_m_2, f_2);
    }


    num2 = strtol(f_m_2, NULL, 16);

    num = num1 + num2;

    printf("%d + %d = %d\n", num1, num2, num);

    fclose(pFile);

    return 0;
}

