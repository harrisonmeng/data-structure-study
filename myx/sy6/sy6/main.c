#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int Menu()
{
    int choice;
    printf("1:paidui\n2:jiuzhen\n3:chakanpaidui\n4:yicijiuzhen\n5:xiaban\n");
    scanf("%d", &choice);
    system("cls");
    return choice;
}

void PaiDui(int binglihao, queuetype *q)
{
    printf("choice:1\n");
    enQueue(q, binglihao);
    printf("%d ", binglihao);
    system("pause");
    system("cls");
}

void JiuZhen(queuetype *q)
{
    printf("%d ",deQueue(q));
    system("pause");
    system("cls");
}

void ChaKan(queuetype *q)
{
    DisplayQueue(q);
    system("pause");
    system("cls");
}

void YiCiJiuZhen(queuetype *q)
{
    OutQueue(q);
    system("pause");
    system("cls");
}

int main()
{
    int binglihao;
    queuetype *q;

    InitQueue(&q);
    binglihao = 0;
    while(1)
    {
        switch (Menu())
        {
        case 1:
            PaiDui(binglihao, q);
            binglihao++;
            break;
        case 2:
            JiuZhen(q);
            break;
        case 3:
            ChaKan(q);
            break;
        case 4:
            YiCiJiuZhen(q);
        case 5:
            FreeQueue(q);
            return 0;
        }
    }
    return 0;
}
