#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include </usr/include/linux/types.h>
#include </usr/include/linux/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

/*
int open_COM1(void)
{
	int fd;
	struct termios new_flags;

	fd = open("/dev/ttyS0", O_RDWR|O_NOCTTY|O_NDELAY);
	if(fd< 0)
	{
		printf("\nOpen Com1 failure!\n");
		exit(0);
	}

	tcgetattr(fd, &new_flags);
	cfsetospeed(&new_flags, B9600);
	cfsetispeed(&new_flags, B9600);
	new_flags.c_lflag &=~(ICANON|ECHO|ECHOE|ISIG);
    new_flags.c_oflag &=~OPOST;
    new_flags.c_cflag &=~PARENB;
	new_flags.c_cflag &=~CSTOPB;
	new_flags.c_cflag &=~CSIZE;
    new_flags.c_cflag |=CS8;


	tcsetattr(fd, TCSANOW, &new_flags);
    fcntl(fd,F_SETFL,0);
	return (fd);
}
*/

int open_COM2(void)
{
	int fd;
	struct termios new_flags;

	fd = open("/dev/ttyS1", O_RDWR|O_NOCTTY|O_NDELAY);
	if(fd< 0)
	{
		printf("\nOpen Com2 failure!\n");
		exit(0);
	}

	tcgetattr(fd, &new_flags);
    tcflush(fd, TCIOFLUSH);
	cfsetospeed(&new_flags, B19200);
	cfsetispeed(&new_flags, B19200); //B19200  B115200  B9600
    new_flags.c_lflag &=~(ICANON|ECHO|ECHOE|ISIG);
    new_flags.c_oflag &=~OPOST;
	new_flags.c_cflag &=~PARENB;
    new_flags.c_cflag &=~CSTOPB;
    new_flags.c_cflag &=~CSIZE;
	new_flags.c_cflag |=CS8;

	tcsetattr(fd, TCSANOW, &new_flags);
    //fcntl(fd,F_SETFL,0);
	return (fd);
}

int lcd_writestring(int fd,char *stringbuff)
{
	int ret,i;
	int len=strlen(stringbuff);
	printf("---------------len=%d--%s\n", len, stringbuff);
  char buff_write[40];
  //lcd_clear(fd);
  memset(buff_write,0,40);
  lcd_reset(fd);
	buff_write[0]=0xf8;
	buff_write[1]=0x02;
//	buff_write[len+2]=0xa0;
	for (i=0;i<len;i++)
	{
		buff_write[i+2]=stringbuff[i];
	}
	ret=write(fd,buff_write, len+3);
	if (-1 == ret)
	{
		perror("lcd_writestring Write data error!");
		return -1;
	}
	else
		return ret;
}

int lcd_reset(int fd)
{
	int ret;
	char buff_write_reset[3]="";
	buff_write_reset[0]=0xf8;
	buff_write_reset[1]=0x02;
	ret=write(fd,buff_write_reset, 2);
	if (-1 == ret)
	{
		perror("Write data error!");
		return -1;
	}
	else
		return ret;
}
int lcd_clear(int fd)
{
	int ret;
	char buff_write_clear[3]="";
	buff_write_clear[0]=0xf8;
	buff_write_clear[1]=0x01;
	ret=write(fd,buff_write_clear, 2);
	if (-1 == ret)
	{
		perror("Write data error!");
		return -1;
	}
	else
		return ret;
}
