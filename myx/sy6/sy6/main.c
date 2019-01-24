#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int Menu()
{
    int choice;
    printf("1:Line Up\n2:Seek\n3:Check\n4:Seek Till The End\n5:Off\n");
    scanf("%d", &choice);
    system("cls");
    return choice;
}

void LineUp(int binglihao, queuetype *q)
{
    printf("choice:Line Up\n");
    enQueue(q, binglihao);
    printf("Case number : %d inserted.\n", binglihao);
    system("pause");
    system("cls");
}

void Seek(queuetype *q)
{
    printf("choice:Seek\n");
    printf("Current case number : %d.\n",deQueue(q));
    system("pause");
    system("cls");
}

void Check(queuetype *q)
{
    printf("choice:Check\n");
    DisplayQueue(q);
    system("pause");
    system("cls");
}

void SeekTillTheEnd(queuetype *q)
{
    printf("choice:Seek Till The End\n");
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
            LineUp(binglihao, q);
            binglihao++;
            break;
        case 2:
            Seek(q);
            break;
        case 3:
            Check(q);
            break;
        case 4:
            SeekTillTheEnd(q);
        case 5:
            FreeQueue(q);
            return 0;
        }
    }
    return 0;
}
