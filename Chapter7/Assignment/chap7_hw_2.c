#include <stdio.h>
#define SIZE 10

int main(void)
{
    int x[SIZE], i, temp, oddcount = 0, evencount = 0; // ���� ����

    for (i = 0; i < SIZE; i++) // �Է� �� �Ǻ��� ���� ����
    {
        scanf("%d", &temp); // temp��� ������ ���� �Է� ����
        if (temp % 2 == 0)
            x[SIZE - 1 - evencount++] = temp; // ¦���� ��� ���ʿ� temp ���� ���� �Է��� �� evencount�� 1�� ���� (��ġ ����)
        else
            x[oddcount++] = temp; // Ȧ���� ��� ���ʿ� temp ���� ���� �Է��� �� oddcount�� 1�� ���� (��ġ ����)
    }
    for (i = 0; i < SIZE; i++) // ��� ����
        printf("%d ", x[i]); // ���
    putchar('\n');
    return 0;
    
}