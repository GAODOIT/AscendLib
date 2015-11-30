//http://blog.csdn.net/bg2bkk/article/details/8668576
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<termios.h>
#include<errno.h>

#define FALSE -1
#define TRUE 0

int speed_arr[] = { B38400, B19200, B9600, B4800, B2400, B1200, B300,B38400, B19200, B9600, B4800, B2400, B1200, B300, };
int name_arr[] = {38400,  19200,  9600,  4800,  2400,  1200,  300, 38400, 19200,  9600, 4800, 2400, 1200,  300, };
void set_speed(int fd, int speed){
  int   i; 
  int   status; 
  struct termios   Opt;
  tcgetattr(fd, &Opt); 
  for ( i= 0;  i < sizeof(speed_arr) / sizeof(int);  i++) { 
    if  (speed == name_arr[i]) {     
      tcflush(fd, TCIOFLUSH);     
      cfsetispeed(&Opt, speed_arr[i]);  
      cfsetospeed(&Opt, speed_arr[i]);   
      status = tcsetattr(fd, TCSANOW, &Opt);  
      if  (status != 0) {        
        perror("tcsetattr fd1");  
        return;     
      }    
      tcflush(fd,TCIOFLUSH);   
    }  
  }
}

int set_Parity(int fd,int databits,int stopbits,int parity)
{ 
	struct termios options; 
	if  ( tcgetattr( fd,&options)  !=  0) { 
		perror("SetupSerial 1");     
		return(FALSE);  
	}
	options.c_cflag &= ~CSIZE; 
	switch (databits) 
	{   
	case 7:		
		options.c_cflag |= CS7; 
		break;
	case 8:     
		options.c_cflag |= CS8;
		break;   
	default:    
		fprintf(stderr,"Unsupported data size\n"); return (FALSE);  
	}
	switch (parity) 
	{   
		case 'n':
		case 'N':    
			options.c_cflag &= ~PARENB;   /* Clear parity enable */
			options.c_iflag &= ~INPCK;     /* Enable parity checking */ 
			break;  
		case 'o':   
		case 'O':     
			options.c_cflag |= (PARODD | PARENB); 
			options.c_iflag |= INPCK;             /* Disnable parity checking */ 
			break;  
		case 'e':  
		case 'E':   
			options.c_cflag |= PARENB;     /* Enable parity */    
			options.c_cflag &= ~PARODD;    
			options.c_iflag |= INPCK;       /* Disnable parity checking */
			break;
		case 'S': 
		case 's':  /*as no parity*/   
		    options.c_cflag &= ~PARENB;
			options.c_cflag &= ~CSTOPB;break;  
		default:   
			fprintf(stderr,"Unsupported parity\n");    
			return (FALSE);  
		}  
	
	switch (stopbits)
	{   
		case 1:    
			options.c_cflag &= ~CSTOPB;  
			break;  
		case 2:    
			options.c_cflag |= CSTOPB;  
		   break;
		default:    
			 fprintf(stderr,"Unsupported stop bits\n");  
			 return (FALSE); 
	} 
	/* Set input parity option */ 
	if (parity != 'n')   
		options.c_iflag |= INPCK; 
	tcflush(fd,TCIFLUSH);
	options.c_cc[VTIME] = 150; 
	options.c_cc[VMIN] = 0; /* Update the options and do it NOW */
	if (tcsetattr(fd,TCSANOW,&options) != 0)   
	{ 
		perror("SetupSerial 3");   
		return (FALSE);  
	} 
	return (TRUE);  
}

int open_COM(char* com_name)
{
	int fd;
	struct termios new_flags;
	//fd = open(com_name, O_RDWR|O_NOCTTY|O_NDELAY);
	fd = open(com_name, O_WRONLY);
	if(fd< 0)
	{
		printf("Open %s write failure!\n", com_name);
		exit(0);
	}

	tcgetattr(fd, &new_flags);
    tcflush(fd, TCIOFLUSH);
	cfsetospeed(&new_flags, B9600);
	cfsetispeed(&new_flags, B9600); //B19200  B115200  B9600
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

int main(int argc, char* argv[])
{ 
    int fd, iRet;
    if (argc < 2)
    {
        printf("please input:\n");
        return -1;
    }
	printf("This program updates last time at %s   %s\n",__TIME__,__DATE__);
	printf("STDIO COM0\n");


    fd = open_COM("/dev/ttyS0");
    /*
	fd = open("/dev/ttyS0", O_WRONLY);
	if(fd == -1)
	{
		perror("serialport error\n");
	}
	else
	{
		printf("O_WRONLY open ");
		printf("%s",ttyname(fd));
		printf(" succesfully\n");
	}

	set_speed(fd, 115200);
	if (set_Parity(fd,8,1,'N') == FALSE)  {
		printf("Set Parity Error\n");
		exit (0);
	}
	//char buf[] = "fe55aa07bc010203040506073d";
	*/
    printf("---------------%d-------%s\n", strlen(argv[1]), argv[1]);
    iRet = write(fd, argv[1], strlen(argv[1]));
    if (iRet <= 0)
    {
        printf("--write error!--%d--%s\n", iRet, strerror(iRet));
    }
    sleep(2);
    close(fd);
	return 0;
}
