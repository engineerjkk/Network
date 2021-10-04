#pragma comment(lib, "ws2_32")
#include <WinSock2.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	//윈속초기화 부분
	WSADATA wsa;
	if(WSAStartup(MAKEWORD(2,2),&wsa)!=0)
		return 1;

	//16비트정도의 short 변수 설정
	u_short x1=0x1234; //16bit!
	u_long y1=0x12345678; //32bit!
	u_short x2;
	u_long y2;

	//호스트 바이트 -> 네트워크 바이트
	printf("[호스트 바이트 -> 네트워크 바이트]\n");
	printf("0x%x->0x%x\n",x1,x2=htons(x1));
	printf("0x%x->0x%x\n",y1,y2=htons(y1));

	//네트워크 바이트 -> 호스트 바이트
	printf("\n[네트워크 바이트 -> 호스트 바이트]\n");
	printf("0x%x -> 0x%x\n",x2,ntohs(x2));
	printf("0x%x -> 0x%x\n", y2,ntohl(y2));

	//잘못된 사용 예
	printf("\n[잘못된 사용 예]\n");
	printf("0x%x -> 0x%x\n",x1,htonl(x1));//x1은 short인데 htonl은 long형이다.

	WSACleanup();
	return 0;
}

//디버깅을 보도록하자
