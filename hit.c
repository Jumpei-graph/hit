#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <fcntl.h>
#define num 3

void set(int x[])
{
    for (int i = 0; i < num; i++)
    {
        x[i] = random() % 10;
    }
}

int main()
{
    int x[num], y[num], hit, brow;
    srandom(time(NULL));
    while (1)
    {
        set(x); // xに0～9の数字をセット
        printf("%d %d %d\n", x[0], x[1], x[2]);
        do
        {
            hit = 0, brow = 0; // hitとbrowを0にする
            for (int i = 0; i < num; i++)
            {
                int k=i;
                printf("y[%d]:", i);
                scanf("%d", &y[i]);           // yに予想した数字を入れてもらう
                for (int j = 0; j < num; j++) //その数字は当たってるか？
                {//最も大切なのは場所もあってるとき←1足して3で割ればいんじゃね？
                //jは回数を数えるだけのものとする
                    if (y[i] == x[k])
                    {
                        if (i == k)
                        {
                            hit++; //場所も当たってるならhit+1
                            brow++;
                            break;
                        }
                        brow++; //どれかに当たってるならbrow+1
                        break;
                    }
                    k=(k+1)%3;
                }
            }
            printf("hit:%d\nbrow:%d\n", hit, brow); // browの重複←消そうとするとhit見てくれない
        } while (hit < num);                        // 3つ当たるまで繰り返す
    }
    return 0;
}