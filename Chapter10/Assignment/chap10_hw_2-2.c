#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[1000] = ""; // 첫줄에서 받아줄 문자열
    char words[10][100]; // 단어로 쪼개서 저장할 배열
    char temp[100]; // 버블 소팅을 위한 문자열 저장 배열
    char* pos = input; // 루프에서 사용할 포인터
    int count = 0, j = 0, i; // 단어수, 단어 길이 및 아래 루프에서 사용하는 변수

    scanf("%[^\n]s", input); // 개행 문자 전까지 입력 받고 \0를 붙인다.
    while (1) // 루프
    {
        while (*pos != ' ' && *pos != '\0') // 공백이 나오거나 \0이 나오기 전까지 단어로 간주하여 저장한다. \0가 있는 이유는 마지막에 오는 단어 때문이다.
            words[count][j++] = *(pos++);
        if (j != 0) // 공백이 여러번 온 경우도 있기 때문에 이런 경우를 걸러내기 위해 이 조건이 있다.
        {
            words[count][j] = '\0'; // 그동안 저장해 온 곳 끝에 \0를 붙인다.
            j = 0; // 단어길이 초기화
            puts(words[count++]); // 일단 나온 순서대로
        }
        if (*pos == '\0') // 어지간한 상황에서는 전부 \0이 붙으므로 끝에 왔을때 루프에서 나온다.
            break;
        else // 끝이 아닌 경우 계속한다.
            pos++;
    }
    for (i = 0; i < count - 1; i++) // 단어 정렬하는 루프
    {
        for (j = 0; j < count - 1 - i; j++) // 버블 소팅을 사용한다.
        {
            if (words[j][0] > words[j + 1][0]) // 앞의 배열 첫글자가 뒷 첫글자보다 사전 순서로 뒤에 있는 경우;
            {
                strcpy(temp, words[j]); // 일단 임시로 저장하는 곳으로 복사
                strcpy(words[j], words[j + 1]); // 덮어쓰기
                strcpy(words[j + 1], temp); // 임시로 저장한 곳에서 가져와 덮어쓴다.
            }
        }
    }
    for (int i = 0; i < count; i++) // 정렬된 순서대로 출력
        puts(words[i]);

    return 0;
}
