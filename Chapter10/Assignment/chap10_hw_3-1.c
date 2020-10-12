#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

int main(void)
{
    char arr[MAX] = ""; // 처음 문자열
    char arr2[MAX] = ""; // 비교할 문자열
    char* pos = arr; // 루프에서 사용할 포인터
    int count = 0; // 개수 세는 카운터 변수

    scanf("%[^\n]", arr); // 개행 문자 전까지 입력받는다.
    getchar(); // 개행 문자를 먹는다.
    scanf("%[^\n]", arr2); // 두번째 문자열도 위와 같이 받는다.
    
    while (pos - arr <= (int)(strlen(arr) - strlen(arr2))) // 첫번째 문자열의 길이에서 두번째 문자열 길이를 뺀 인덱스까지 루프를 돌린다.
    {
        if (strncmp(pos, arr2, strlen(arr2)) == 0) // pos가 가리키는 문자열 부분과 두번째 문자열에서 두번째 문자열의 길이만큼 비교해서 일치(=0)하는 경우
        {
            count++; // 카운터를 올린다.
            pos += strlen(arr2); // 이미 맞는 것으로 확인되었기 때문에 그만큼 그냥 패스한다.
        }
        else // 그렇지 않은 경우 주솟값을 올린다.
            pos++;
    }
    printf("%d\n", count); // 나온 횟수 출력

    return 0;
}