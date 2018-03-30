/****************************************************************************************

*****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define TRUE    (1)
#define FALSE   (0)
#define STACK_SIZE (100)
#define STACK_SIZE_ADD (10)

//结构体定义
typedef struct
{
    int *base;
    int *top;
    int stacksize;
}Stack_Op;

//栈的初始化
int Stack_Init(Stack_Op *pstack)
{
    pstack->base = (int *)malloc(STACK_SIZE * sizeof(int));
    if(NULL == pstack->base)
    {
        return FALSE;
    }
    pstack->top = pstack->base;     //top指针指向栈底，该栈处于初始化
    pstack->stacksize = STACK_SIZE;
    
    return TRUE;
}

//入栈操作
int StackPush_Process(Stack_Op *pstack, int item)
{
    if((pstack->top - pstack->base) >= pstack->stacksize)
    {
        pstack->base = (int *)realloc(pstack->base, (pstack->stacksize + STACK_SIZE_ADD) * sizeof(int));

        if(NULL == pstack->base)
        {
            return FALSE;
        }
        pstack->top = pstack->base + pstack->stacksize;
        pstack->stackzie += STACK_SIZE_ADD;
    }
    *(pstack->top) = item;
    
    return TRUE;
}

//出栈操作
int StackPop_Process()
{
    return TRUE;
}

//
