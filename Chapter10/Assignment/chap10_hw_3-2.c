#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[1000] = ""; // 입력을 받을 문자열
    char src[100]; // 비교할 문자열
    char words[10][100]; // 저장할 문자열
    char* pos = input; // 루프에서 사용할 문자열
    int count = 0, j = 0, i, srccnt = 0; // 각각 단어 개수, 루프에서 사용할 두 변수, 마지막으로 비교하는 문자열의 검출된 개수를 저장하는 변수이다.

    scanf("%[^\n]", input); // 입력을 받는다.
    getchar();
    scanf("%[^\n]", src); // 비교할 문자열을 입력받는다.
    getchar();

    while (1) // 루프
    {
        while (*pos >= 'a' && *pos <= 'z' || *pos >= 'A' && *pos <= 'Z') // 알파벳이 나온 경우
            words[count][j++] = *(pos++); // 단어를 만든다.
        if (j != 0) // 공백등의 다른 문자가 섞이는 것을 방지
        {
            words[count++][j] = '\0'; // 널을 집어넣어 문자열로 만든다.
            j = 0; // 철자 개수 초기화 
        }
        if (*pos == '\0') // 끝 부분에 온 경우 루프 탈출
            break;
        else // 그렇지 않은 경우 포인터 연산으로 다음 문자로..
            pos++;
    }
    for (i = 0; i < count; i++) // 비교하는 루프
        if (strcmp(words[i], src) == 0) // 완전히 일치하는 문자열이 나온 경우. strcmp는 철자 개수까지 완전히 일치해야 0을 반환하므로 (일치) 다른 단어 내에 있는 경우도 제외할 수 있다.
            srccnt++; // 개수 증가
    printf("%d\n", srccnt); // 찾은 개수 출력

    return 0;
}