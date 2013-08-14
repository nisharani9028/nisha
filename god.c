  //server:
    //header file
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>   //defining a preprocessor to assign value to MAX
#define MAX 30
  ////declaration of function which adds the numbers
int Add(int num1,int num2);

  //variable declaration
int sfd;
int cfd;
int serverlen,clientlen;
struct sockaddr_in serveraddr;
struct sockaddr_in clientaddr;
int result[MAX];
  //definition of structure  
typedef struct message
{
int input1,input2;
int output;
}message;


int main()
{

int msgLen;
     /*socket creation
       communication domain is internet domain
       stream communication. 0 indicate system                     
       select the protocol(TCP)*/
sfd=socket(AF_INET,SOCK_STREAM,0);
message *msg;
message *reply;

msg=(message*)malloc(sizeof(message));
reply=(message*)malloc(sizeof(message));

printf("\nSFD Value:%d",sfd);

msgLen=sizeof(message);


serveraddr.sin_family=AF_INET; 
    /*assigning internet address and port number*/
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
serveraddr.sin_port=2434;
serverlen=sizeof(serveraddr);
    /*socket binds to server's socket address*/
                                                                                         
bind(sfd,(struct sockaddr*)&serveraddr,serverlen);
printf("\nConnected to socket");
   /*server listen for client request for connection through  
        socket.5 indicate maximum number of request for connection*/

listen(sfd,5);
/*server accepts connection  
  request from client and  
  use new socket cfd          
  for  further 
 communication*/
cfd=accept(sfd,(struct sockaddr*)&clientaddr,&clientlen);
printf("\nConnection accepted successfully");
read(cfd,reply,msgLen);
reply->output=Add((int)reply->input1,(int)reply->input2);
write(cfd,reply,msgLen);
}

int Add(int num1,int num2)
{
int result=0;
result=num1+num2;
return result;
}
 


