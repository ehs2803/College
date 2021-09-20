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

	strcpy(s.title,"안부 메일" );
	strcpy(s.sender,"chulsoo@hankuk.ac.kr" );
	strcpy(s.receiver,"hsh@hankuk.ac.kr" );
	strcpy(s.content,"안녕하십니까? 별일 없으신지요?" );
	strcpy(s.data,"2010/9/1");
	s.pri = 1;
	printf("제목: %s\n수신자: %s\n발신자: %s\n내용: %s\n날짜: %s\n우선순위: %d",
		s.title, s.sender, s.receiver, s.content, s.data);
}