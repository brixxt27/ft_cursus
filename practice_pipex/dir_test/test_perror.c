#include <stdio.h>

int main(void)
{
    perror("str");
    // 실제 errno 가 저장이 되지 않는 이상 success 를 출력한다.
    return (0);
}