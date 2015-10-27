#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char T;

typedef struct ARRAY_ELE_ST
{
    T item_array[10];
} ARRAY_ELE_S;

ARRAY_ELE_S *pArray[200];
int iSize = 0; 

T *get(int idx)
{
    //确保索引有效  
    if((idx>=0) && (idx<iSize))  
    {  
        int idx_maj = idx/10; // 主索引
        printf("-----------------idx=%d----------%d----%d\n", __LINE__, idx, idx_maj);
        int idx_mor = idx%10; // 次索引 
        //int idx_mor = idx - idx_maj;
        printf("-----------------idx=%d----------%d----%d\n", __LINE__, idx, idx_mor);
        printf("---------------%d----------------------%c\n", __LINE__, &pArray[idx_maj]->item_array[idx_mor]);
        //return (&(pArray[idx_maj]->item_array[idx_mor-1]));
    }  
    return NULL;  
}

int n_malloc(int size)
{
    if(size >= 10*200)
    {
        return -1; //太大了
    }

    while(iSize <= size)
    {
        //分配内存，并初始化为0
        int idx = iSize/10;
        printf("---------------------------%d----%d----sizeof(ARRAY_ELE_S)=%d\n", __LINE__, idx, sizeof(ARRAY_ELE_S));
        pArray[idx] = (ARRAY_ELE_S*)calloc(1, sizeof(ARRAY_ELE_S));
        if(pArray[idx] == NULL)
        {
            return (-1);
        }
        memset(pArray[idx], '\0', sizeof(ARRAY_ELE_S));
        iSize += 10;
    }
    return 0;
}

int n_free()
{

}

int main(int argc, char* argv[])
{
    char *str = "0123456789abcdef";
    n_malloc(strlen(str));
    //memcpy(&pArray, str, strlen(str));
    //
    memcpy(&pArray[0], str, 10);
    memcpy(&pArray[1], str+10, strlen(str)-10);

    int i;
    for (i = 0; i < 10; i++)
    {
        printf("0=%c\n", &pArray[0]->item_array[i]);
    }

    for (i = 0; i < 10; i++)
    {
        printf("1=%c\n", &pArray[1]->item_array[i]);
    }

    printf("-----------------------%d----%s--%d\n", strlen((T*)&pArray), (T*)&pArray, sizeof((T*)&pArray));
    printf("---------------------------%s----%s\n", &pArray[0], &pArray[1]);

    get(9);

    return 0;
}
