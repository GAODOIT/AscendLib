#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>


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

/*
int main(int argc, char* argv[])
{
    DATA_ST tmp;
    set_data(&tmp);
    printf("---------------%d--%s\n", tmp.num, tmp.str);
    printf("---------------%p\n", tmp.str);
    free(tmp.str);
    return 0;
}
*/

/*
210.25.132.181属于IP地址的ASCII表示法，也就是字符串形式。
英语叫做IPv4 numbers-and-dots notation。
如果把210.25.132.181转换为整数形式，是3524887733
这个就是整数形式的IP地址。英语叫做binary data。（其实binary是二进制的意思）
uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort);
uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);

struct in_addr { 
　　in_addr_t s_addr; 
}; 
结构体in_addr 用来表示一个32位的IPv4地址. 
in_addr_t 一般为 32位的unsigned long. 
其中每8位代表一个IP地址位中的一个数值. 
例如192.168.3.144记为0xc0a80390,
其中 c0 为192 ,a8 为 168, 03 为 3 , 90 为 144 
打印的时候可以调用inet_ntoa()函数将其转换为char *类型.
in_addr_t inet_addr(const char *cp);
convert ip_str to ip_int
return network_byte;
if cp == 255.255.255.255 ret = -1;
cannot deal 255.255.255.255

in_addr_t inet_network(const char *cp);
convert ip_str to ip_int
return host_byte;
if cp == 255.255.255.255 ret = -1;
cannot deal 255.255.255.255

int inet_aton(const char *cp, struct in_addr *inp);
return inp is network_byte
struct in_addr in_ip;
if(inet_aton(ip_str[0], &in_ip))
{
    ipaddr= ntohl(in_ip.s_addr);
}

char *inet_ntoa(struct in_addr in);
return ip_str;
*/

int main()
{
    char str[]="255.255.255.255";
    in_addr_t r1,r2,r3;
    struct in_addr inp;
    r1=inet_addr(str);
    if(r1==-1){
        printf("inet_addr return -1 when 255.255.255.255\n");
    }else{
        printf("inet_addr:ip=%lu\n",ntohl(r1));
    }
    r2=inet_network(str);
    if(r2==-1){
        printf("inet_network return -1 when 255.255.255.255\n");
    }else{
        printf("inet_network:ip=%lu\n",r2);
    }
    r3=inet_aton(str,&inp);
    if(r3==0){
        printf("inet_aton return -1 when 255.255.255.255\n");
    }else{
        printf("inet_aton:ip=%lu--=%d\n",ntohl(inp.s_addr), r3);
    }
    return 0;
}
