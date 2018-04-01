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
    int *base;        //栈底指针
    int *top;         //栈顶指针
    int stacksize;    //栈的大小
}Stack_Op;

//栈的初始化
int Stack_Init(Stack_Op *ptstack)
{
    ptstack->base = (int *)malloc(STACK_SIZE * sizeof(int));    //申请栈的空间
    if(NULL == ptstack->base)
    {
        return FALSE;
    }
    ptstack->top = ptstack->base;     //top指针指向栈底，该栈处于初始化
    ptstack->stacksize = STACK_SIZE;
    
    return TRUE;
}

//入栈操作
int StackPush_Process(Stack_Op *ptstack, int item)
{
    if((ptstack->top - ptstack->base) >= ptstack->stacksize)    //检查申请的栈的大小
    {
        ptstack->base = (int *)realloc(ptstack->base, (ptstack->stacksize + STACK_SIZE_ADD) * sizeof(int));

        if(NULL == ptstack->base)
        {
            return FALSE;
        }
        ptstack->top = ptstack->base + ptstack->stacksize;
        ptstack->stackzie += STACK_SIZE_ADD;
    }
    *(ptstack->top++) = item;    //给申请的栈空间进行依次赋值，先赋值，栈顶指针再累加
    
    return TRUE;
}

//出栈操作
int StackPop_Process(Stack_Op *ptstack， int &item)
{
    if(ptstack->top == ptstack->base)    //栈中没有内容
    {
        return FALSE;
    }
    item = *(--ptstack->top);    //依次出栈操作，栈顶指针先递减，再出栈
        
    return TRUE;
}

//获取栈顶元素
int StackGetTop_Process(Stack_Op *ptstack, int &item)
{
    if(ptstack->top == ptstack->base)
    {
        return FALSE;
    }
    item = *(ptstack->top - 1);    //获取栈顶元素
    
    return TRUE;
}

//判断栈是否为空
int StackEmpty_Process(Stack_Op *ptstack)
{
    if(ptstack->top == ptstack->base)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//栈的销毁
int StackDel_Process(Stack_Op *ptstack)
{
    ptstack->top = ptstack->base;
    free(ptstack->base);
    ptstack->stacksize = STACK_SIZE;
    
    return TRUE;
}

//main.c实现入栈、出栈的基本操作
int main()
{
    Stack_Op *ptstack;
    int push_num;
    int push_val;
    
    /* 初始化栈 */
    Stack_Init(ptstack);
    printf("The size of stack is %d\n", &pstack->stacksize);
    
    /* 根据输入进行栈的填充 */
    printf("Please enter the number to push into stack: ");
    scanf("%d\n", &push_num);
    
    while(push_num--)
    {
        scanf("%d\n", &pushval);
        StackPush_Process(ptstack, push_val);
        printf("The size after push value:%d,%d\n", push_val, ptstack->stacksize);
    }
    
    //获取栈顶元素
    StackGetTop_Process(ptstack, push_val);
    printf("The top value is: %d\n", push_val);
    
    return TRUE;
}
