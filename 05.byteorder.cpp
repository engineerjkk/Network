#pragma comment(lib, "ws2_32")
#include <WinSock2.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	//�����ʱ�ȭ �κ�
	WSADATA wsa;
	if(WSAStartup(MAKEWORD(2,2),&wsa)!=0)
		return 1;

	//16��Ʈ������ short ���� ����
	u_short x1=0x1234; //16bit!
	u_long y1=0x12345678; //32bit!
	u_short x2;
	u_long y2;

	//ȣ��Ʈ ����Ʈ -> ��Ʈ��ũ ����Ʈ
	printf("[ȣ��Ʈ ����Ʈ -> ��Ʈ��ũ ����Ʈ]\n");
	printf("0x%x->0x%x\n",x1,x2=htons(x1));
	printf("0x%x->0x%x\n",y1,y2=htons(y1));

	//��Ʈ��ũ ����Ʈ -> ȣ��Ʈ ����Ʈ
	printf("\n[��Ʈ��ũ ����Ʈ -> ȣ��Ʈ ����Ʈ]\n");
	printf("0x%x -> 0x%x\n",x2,ntohs(x2));
	printf("0x%x -> 0x%x\n", y2,ntohl(y2));

	//�߸��� ��� ��
	printf("\n[�߸��� ��� ��]\n");
	printf("0x%x -> 0x%x\n",x1,htonl(x1));//x1�� short�ε� htonl�� long���̴�.

	WSACleanup();
	return 0;
}

//������� ����������