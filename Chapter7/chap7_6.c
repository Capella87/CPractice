#include <stdio.h>
#define SIZE 3

int main(void)
{
    char answer[SIZE];
    char status[SIZE] = { '_', '_', '_' }; // �ϴ� ��ũ�� ó���ϱ� ���� �̸� ���� �Է��� �ξ���.
    int i, count = 1; // count -> �õ� Ƚ��
    char ch; // �ϴ� ���ڸ� �Է¹��� ����

    for (i = 0; i < SIZE; i++) // ������ �Է¹޴� ����
        scanf("%c", &answer[i]);
    getchar();

    while (count <= 5)
    {
        scanf("%c", &ch);
        getchar(); // ���� ���ڸ� �޾Ƽ� ������ �뵵
        for (i = 0; i < SIZE; i++) // ����� �����ϴ� ����
        {
            if (ch == answer[i]) // ���� ���
                status[i] = ch; // status �迭�� ch �� ����
            else
                continue;
        }
        for (i = 0; i < SIZE; i++)
            printf(" %c", status[i]); // ���� ���� ���
        putchar('\n');
        count++; // �õ� Ƚ�� ����
        if (status[0] != '_' && status[1] != '_' && status[2] != '_') // ���� �� ���� ��� �����Ѵ�.
            break;
    }
    return 0;
}