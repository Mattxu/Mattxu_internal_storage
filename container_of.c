/***************************************************
内容：内核container_of解析
说明：container_of(ptr,type,member)用于在已知结构体
      里面成员member和该成员指针ptr和结构体类型type，
	  返回该成员所在结构体指针。
作者：xupc
***************************************************/
struct student a
{
	char *name;
	int age;
}

int *page = &age;
container_of(page, struct student, a.age);    /* 返回结构体a的地址 */

/********************************************************************
内容分析：实现该方法分为3步
1、算出a.age在a里面的偏移，即((struct student*)0)->age
2、已知a.age的地址和在a里面的偏移，即可通过a.age地址减去
   偏移得到a的地址，即(char*)page - ((struct student*)0)->age
3、将得到的地址强制转换成struct student格式，即
   (struct student*)((char*)page - ((struct student*)0)->age)
********************************************************************/
#define container_of(ptr,type,member)  ({           \
    const typeof(((type*)0->member)*__mptr = (ptr); \
	(type*)((char*)__mptr - offset(type,member));
})

