#include <stdio.h> 
#include <string.h>             // strlen() ���ڿ��� ���̸� ��ȯ

int main(void)               // int(�Լ� ����� return�� �ްڽ��ϴ�) main(main �Լ��Դϴ�) void(������ �����ϴ�)
{
	char arr[20];                 //char(����/ ���ڿ�) arr(���ڿ���) [100] (�Ҵ� �޸�, 100 bite, ������ ���� ���)
	char *a = arr;                 // a == arr == &arr[0]
	int n, len;                 // int(������ ����) n(������)

	printf("���ڿ��� �Է����ּ���.\n");                  // printf(ȭ�鿡 �ؽ�Ʈ ���)
	scanf_s("%s", arr,20);                  //scanf(���� �Է¹���) "%s"(���ڿ��� �Է¹޽��ϴ�) arr(�Էµ� ���ڿ��� arr�� ����)

	len = strlen(arr);                       // arr�� ���̸� len�� ����
	a =a+( len-1);

	for (n = 0; n < len; n++)                         // for(�ݺ���), �ڿ������� ��½�Ŵ
	{
		printf("%c", *a);                         // "%c"(��ȯ ���ڿ�) arr[n](arr ���ڿ��� n+1 ��° ���ڸ� )
		a--;
	}
}
//20191124
