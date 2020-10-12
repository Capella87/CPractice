#include <stdio.h>
#include <string.h>
#define SIZE 100
#define MAX 10

int main(void)
{
    char arr[SIZE]; // 입력 받을 문자열
    double num[MAX]; // 추출한 수를 저장할 배열
    char* pos = arr; // 루프에서 사용할 포인터
    int temp = 0, numcount = 0; // 각각 임시로 수를 저장하는 변수와 추출한 숫자 개수를 저장하는 변수이다.

    scanf("%[^\n]", arr); // 입력을 받는다.
    for (; pos < arr + strlen(arr); pos++) // strlen으로 문자열 길이를 구해 거기까지 반복한다.
    {
        while (*pos >= '0' && *pos <= '9') // 숫자가 나온 경우 숫자가 아닐때까지 루프를 구동한다.
        {
            temp = temp * 10 + (int)(*pos - '0'); // 숫자 추출 후 임시로 저장
            pos++; // 포인터 증가
        }
        if (temp != 0) // 숫자가 나오고 나서 다른 문자가 나온 경우에만 작동한다.
        {
            num[numcount++] = (double)temp; // temp를 배열에 대입하고 후치연산으로 추출 개수 변수를 증가한다.
            temp = 0; // 0으로 초기화
        }
    }
    for (int i = 0; i < numcount; i++) // 출력하는 루프
        printf(" %.0lf", num[i]); // 춝력
    putchar('\n');

    return 0;
}
