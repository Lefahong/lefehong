//线性表操作集的链式存储实现
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BianKuangChangDuBeiLv 1.2
typedef char DataType;        //定义链表结构体 
typedef struct node
{                             //定义学生信息
	int xuehao;
	DataType kechengming[40];
	DataType jiaoshi[30];
	int chengji; 
	struct node *next;
}*LinkList, NODE;
typedef char Node;
typedef char ElemType;



void Center_Align1(char a[], int Total_length)         //输入字符数组和边框长，使得在规定长的边框内字符串居中
{
    int char_length = strlen(a);     //字符串长
    int space_length = (Total_length - char_length) / 2;           //空格长
    int space;
    printf("|");
    for(space = 1; space <= space_length; space++) printf(" ");   //输入空格
    printf("%s", a);                                              //输入字符串
    for(space = 1; space <= space_length; space++) printf(" ");   //输入空格
}


void Center_Align2(char a[], int space_length)      //输入字符串和空格长，使得字符串两边有等长的空格，即居中
{
    int space;
    printf("|");
    for(space = 1; space <= space_length; space++) printf(" ");   //输入空格
    printf("%s", a);                                              //输入字符串
    for(space = 1; space <= space_length; space++) printf(" ");   //输入空格
}

int Compute_number_length(int number)              //计算一个数的位数
{
    int i = 1;
    while(i / 10) i++;
    return i;
}

void Capping(int Total_length)                      //用----封顶
{
    for(int i = 1; i<= Total_length; i++) printf("-");        //Total_length是边框总长
}

int Total_length_xuehao(LinkList L)       //输入链表         
{                                       //计算一个链表内的某类数字元素data，它的最多位数，如一个存有学号的链表中有最短学号110，最长学号3232707237，计算得到最长学号长度为10,*1.2表示边框长度是数字长度的1.2
    int length;
	L = L -> next;
    if(L)
    {
        length = Compute_number_length(L -> xuehao);
        L = L -> next;
    }
    else
    {
        printf("该链表为空");
        return;
    }
    while(L)
    {
        if(length > Compute_number_length(L -> xuehao))
        length = Compute_number_length(L -> xuehao);
        L = L -> next;
    }
    return length * BianKuangChangDuBeiLv;
}

int Total_length_chengji(LinkList L)       //输入链表         
{                                        //计算一个链表内的某类数字元素data，它的最多位数，如一个存有学号的链表中有最短学号110，最长学号3232707237，计算得到最长学号长度为10
    int length;
	L = L -> next;
    if(L)
    {
        length = Compute_number_length(L -> chengji);
        L = L -> next;
    }
    else
    {
        printf("该链表为空");
        return;
    }
    while(L)
    {
        if(length > Compute_number_length(L -> chengji))
        length = Compute_number_length(L -> chengji);
        L = L -> next;
    }
    return length * BianKuangChangDuBeiLv;
}


int Total_length_kechengming(LinkList L)     
{
    int length;
	L = L -> next;
    if(L)
    {
        length = strlen(L -> kechengming);
        L = L -> next;
    }
    else
    {
        printf("该链表为空");
        return;
    }
    while(L)
    {
        if(length > strlen(L -> kechengming))
        length = strlen(L -> kechengming);
        L = L -> next;
    }
    return length * BianKuangChangDuBeiLv;
}


int Total_length_jiaoshi(LinkList L)     
{
    int length;
	L = L -> next;
    if(L)
    {
        length = strlen(L -> jiaoshi);
        L = L -> next;
    }
    else
    {
        printf("该链表为空");
        return;
    }
    while(L)
    {
        if(length > strlen(L -> jiaoshi))
        length = strlen(L -> jiaoshi);
        L = L -> next;
    }
    return length * BianKuangChangDuBeiLv;
}


void InitList(LinkList *L)                 //初始化
{
	*L = (LinkList)malloc(sizeof(NODE));
	if(!*L)
	{
		printf("内存分配失败！\n");
		exit(1);
	}
	(*L) -> next = NULL;
}

void CreateFromTail(LinkList L)        //插入学生数据 
{
	LinkList s, r;
	int x = 1;
	int flag;
	int choice;
	int xuehao, chengji;
	DataType kechengming[40], jiaoshi[30];
	while(x)
	{
	printf("输入学号：\n");
	scanf("%d", &xuehao);
	printf("输入课程名：\n");
	scanf("%39s", kechengming);
	printf("输入教师名：\n");
	scanf("%29s", jiaoshi);
	printf("该学生成绩：\n");
	scanf("%d", &chengji);
	flag = 1;
	while(flag)
	{
	if(L -> next == NULL || ((L -> xuehao < xuehao) && (L -> next -> xuehao > xuehao)))        //顺序不能颠倒，不然程序会报错
	{
		r = L;
		s = (LinkList)malloc(sizeof(NODE));
		s -> xuehao = xuehao;
		strcpy(s -> kechengming, kechengming);
		strcpy(s -> jiaoshi, jiaoshi);
		s -> chengji = chengji;
		s -> next = r -> next;
		r -> next = s;
		flag = 0;
	}
	else L = L -> next;
	}
	printf("是否继续信息的录入，是按1，否按0：\n");
	scanf("%d", &x);
	}
	printf("信息录入完毕！\n");
}

void DelList(LinkList L)       // 删除指定位置的元素 
{
	int xuehao;
	LinkList temp;
	printf("你想要删除哪个学生的数据：\n");
	scanf("%d", &xuehao);

	while(L -> next != NULL && L -> next -> xuehao != xuehao)
	{
		L = L -> next;
	}
	if(L -> next == NULL)
	{
		printf("未找到学号为%d的学生。");
		return;
	}
	temp = L -> next;
	L -> next = temp -> next;
	free(temp);
}

void ChangeData(LinkList L)                      //更改信息
{
	int xuehao;
	int xinxi;
	int shuju;
	DataType kechengming[40];
	DataType jiaoshi[30];
	printf("输入学号：\n");
	scanf("%d", &xuehao);

	printf("输入你想改的信息，课程名为1，教师为2，成绩为3：\n");
	scanf("%d", &xinxi);
	printf("输入新的数据：\n");
	if(xinxi == 1) scanf("%s", kechengming);
	else if(xinxi == 2) scanf("%s", jiaoshi);
    else if(xinxi == 3) scanf("%d", &shuju);

	while(L -> xuehao != xuehao)
	{
		L = L -> next;
	}
	if(xinxi == 1) strcpy(L -> kechengming, kechengming);
	if(xinxi == 2) strcpy(L -> jiaoshi, jiaoshi);
	if(xinxi == 3) L -> chengji = shuju;
}

void GetData(LinkList L)     //查找指定位置函数 
{
	int xuehao;
	int choice;
	LinkList Head = L;
	printf("你想查找的人的学号：\n");
	scanf("%d", &xuehao);

	while((L -> xuehao != xuehao))
	{
		L = L -> next;
		if(!L) 
		{
		printf("未查找到此人的信息,结束进程。\n");
		return;
		}
	}
    printf("-------------------------------------------------------------------------------------------\n");
	printf("|       学号       |          课程名           |         教师           |       成绩      |\n");
	printf("|       %d        ", L -> xuehao);
	printf("|       %-*s       ",13, L -> kechengming );
	printf("|      %-*s        ",10, L -> jiaoshi);
	printf("|        %d       |\n", L -> chengji);
	printf("-------------------------------------------------------------------------------------------\n");
}


void ListLength(LinkList L)            //求表长 
{
	int length = 0;
	L = L -> next;
	while(L)
	{
		length++;
		L = L -> next;
	}
	printf("学生人数为：%d\n", length);
}

void Show(LinkList L)       //输出函数 
{
	int total_length = Total_length_xuehao(L) + Total_length_chengji(L) + Total_length_kechengming(L) + Total_length_chengji(L);
	L = L -> next;
	Capping(total_length);
	Center_Align1('xuehao', Total_length_xuehao);
	Center_Align1('kechengming', Total_length_kechengming);
	Center_Align1('jiaoshi', Total_length_jiaoshi);
	Center_Align1('chengji', Total_length_chengji);
	while(L)
	{
    Center_Align1(L -> xuehao, Total_length_xuehao);
	Center_Align1(L -> kechengming, Total_length_kechengming);
	Center_Align1(L -> jiaoshi, Total_length_jiaoshi);
	Center_Align1(L -> chengji, Total_length_chengji);
	printf("|\n");
	L = L -> next;
	}
	Capping(total_length);
}

void jiemian(LinkList L)
{
	int choice;
	int flag = 1;
	while(flag)
	{
	printf("------------------------------------------------------------------------------------------------------------\n");
	printf("|   退出操作   |   增加信息   |   删除信息   |   更改信息   |   查找信息   |   显示人数   |   显示选课表    |\n");
	printf("------------------------------------------------------------------------------------------------------------\n");
	printf("|     按0     |     按1      |      按2      |     按3      |     按4      |     按5      |        按6      |\n");
	printf("------------------------------------------------------------------------------------------------------------\n");
	printf("请选择操作：\n");
	scanf("%d", &choice);
	if(choice == 0) return;
	if(choice == 1)  CreateFromTail(L);
	if(choice == 2)  DelList(L);
	if(choice == 3)  ChangeData(L);
	if(choice == 4)  GetData(L);
	if(choice == 5)  ListLength(L);
	if(choice == 6)  Show(L);
	printf("输入1返回主界面, 输入0退出：\n");
	scanf("%d", &flag);
	}
}

int main()
{
	LinkList L;
	InitList(&L);
	jiemian(L);
	printf("你已经完成全部操作。");
}