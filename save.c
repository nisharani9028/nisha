 //client
 //header files
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

  //defining a preprocessor to assign value to MAX
#define MAX 30

typedef struct message
{
int input1,input2;
int output;
}message; 


int main()
{
int sfd,input1,input2;
int len;
int msgLen;
struct sockaddr_in address;
int result;

message *msg;
message *reply;

msg=(message*)malloc(sizeof(message));
reply=(message*)malloc(sizeof(message));
msgLen=sizeof(message);

sfd=socket(AF_INET,SOCK_STREAM,0);

address.sin_family=AF_INET;
address.sin_addr.s_addr=inet_addr("127.0.0.1");
address.sin_port=2434;
len=sizeof(address);
      /*client requests a connection via                    
      server's socket*/
result=connect(sfd,(struct sockaddr*)&address,len);
printf("\nConnection successful");

 printf("\nEnter Numbers:");
scanf("%d%d",&msg->input1,&msg->input2);
   //message is sent through socket
write(sfd,msg,msgLen);
   //result received
read(sfd,reply,msgLen);
printf("Output from server:%d",reply->output);

    //socket terminated
close(sfd);
}
