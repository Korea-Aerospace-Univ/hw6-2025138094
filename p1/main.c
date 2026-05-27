#include <stdio.h>

int main()
{
    char str[10] = {}; //입력받을 10개의 영문자를 저장할 배열 str 선언 및 초기화
    char maxchar = '\0'; //가장 많이 나타난 문자를 저장할 변수 maxchar 선언 및 초기화
    int currentfreq, maxfreq = 0; //현재 빈도수를 저장할 변수 currentfreq와 최다빈도수를 저장할 변수 maxfreq
    char *p = nullptr; //문자형 포인터 p 선언 및 초기화
    char *q = nullptr; //문자형 포인터 q 선언 및 초기화 (힌트에서 제공받은 포인터를 사용해 돌릴 중첩반복문을 위함)
    
    for(p = str; p < str + 10; p++) //10개의 영문자를 입력받을 반복문
        scanf("%c", p); //포인터를 사용해 배열에 영문자를 각 인덱스에 하나씩 저장함

    //빈도수를 계산할 중첩반복문
    for(p = str; p < str + 10; p++) {
        currentfreq = 0; //현재 계산중인 빈도수 초기화
        for(q = str; q < str + 10; q++) //입력받은 영문자 하나를 기준으로 삼고 10개의 영문자를 비교
        {
            if(*p == *q) currentfreq++; //비교할때 기준 영문자와 현재 비교하는 영문자가 동일할시 현재 계산 빈도수에 +1을 해준다.
        }  

        //반복문을 빠져나와서 현재 계산 빈도수와 최대빈도수를 비교
        if (currentfreq > maxfreq) { //현재빈도수가 최대빈도수보다 크다면 최대빈도수에 현재 계산 빈도수를 넣는다.
            maxfreq = currentfreq;
            maxchar = *p; //기준 영문자를 최대빈도수 문자에 넣는다. 
        }
        //모든 문자를 볼때까지 반복
    }

    //반복문을 빠져나와서 최종적으로 저장된 최대빈도문자와, 최대빈도수를 출력한다.
    printf("%c %d", maxchar, maxfreq);
    
    return 0;
}
