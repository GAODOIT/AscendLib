#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct __DATA__
{
    int num;
    char* str;
}DATA_ST;

int set_data(DATA_ST* data)
{
    data->num = 444;
    data->str = (char*)malloc(10);
    memset(data->str, '\0', 10);
    memcpy(data->str, "11111111", strlen("11111111"));
    printf("-----------------%p\n", data->str);
    return 0;
}

int main(int argc, char* argv[])
{
    DATA_ST tmp;
    set_data(&tmp);
    printf("---------------%d--%s\n", tmp.num, tmp.str);
    printf("---------------%p\n", tmp.str);
    free(tmp.str);
    return 0;
}
