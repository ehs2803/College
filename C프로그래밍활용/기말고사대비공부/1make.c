#include <stdio.h> 
#include <string.h>             // strlen() 문자열의 길이를 반환

int main(void)               // int(함수 결과로 return을 받겠습니다) main(main 함수입니다) void(변수는 없습니다)
{
	char arr[20];                 //char(문자/ 문자열) arr(문자열명) [100] (할당 메모리, 100 bite, 무조건 숫자 사용)
	char *a = arr;                 // a == arr == &arr[0]
	int n, len;                 // int(정수형 변수) n(변수명)

	printf("문자열을 입력해주세요.\n");                  // printf(화면에 텍스트 출력)
	scanf_s("%s", arr,20);                  //scanf(값을 입력받음) "%s"(문자열을 입력받습니다) arr(입력된 문자열을 arr에 저장)

	len = strlen(arr);                       // arr의 길이를 len에 저장
	a =a+( len-1);

	for (n = 0; n < len; n++)                         // for(반복문), 뒤에서부터 출력시킴
	{
		printf("%c", *a);                         // "%c"(변환 문자열) arr[n](arr 문자열의 n+1 번째 글자를 )
		a--;
	}
}
//20191124
