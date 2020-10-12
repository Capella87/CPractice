#include <stdio.h>
#include <string.h>

int main(void)
{
    char arr[100];
    char temp;
    size_t count;

    scanf("%[^\n]", arr); // 개행 문자전까지 일단 받는다.
    while (getchar() != '\n') // 개행 문자는 버퍼에 남아 있기 때문에 읽어서 제거한다.
        continue;
    count = strlen(arr); // 버블 소팅을 할 것인데, 이를 위해 문자 수를 일단 저장한다.

    for (int i = 0; i < (int)count - 1; i++) // 버블 소팅
    {
        for (int j = 0; j < (int)count - 1 - i; j++)
        {
            if (*(arr + j) > *(arr + j + 1)) // char형 세계에서 가리키는 문자가 사전순으로 뒤에 있는 것보다 뒤에 있는 경우
            {
                temp = *(arr + j); // 일단 값 임시 저장
                *(arr + j) = *(arr + j + 1); // 바꾼다
                *(arr + j + 1) = temp; // temp 값을 다시 불러온다.
            }
        }
    }
    puts(arr); // 결과를 출력한다.

    return 0; 
}
