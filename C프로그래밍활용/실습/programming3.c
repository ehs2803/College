#include<stdio.h>
#include<stdlib.h>
struct mail {
	char title[20];
	char sender[20];
	char receiver[20];
	char content[20];
	char data[20];
	int pri;
};
int main(void)
{
	struct mail s;

	strcpy(s.title,"�Ⱥ� ����" );
	strcpy(s.sender,"chulsoo@hankuk.ac.kr" );
	strcpy(s.receiver,"hsh@hankuk.ac.kr" );
	strcpy(s.content,"�ȳ��Ͻʴϱ�? ���� ����������?" );
	strcpy(s.data,"2010/9/1");
	s.pri = 1;
	printf("����: %s\n������: %s\n�߽���: %s\n����: %s\n��¥: %s\n�켱����: %d",
		s.title, s.sender, s.receiver, s.content, s.data);
}