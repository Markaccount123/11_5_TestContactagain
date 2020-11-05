#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>    // 这里因为Contact.c  和  test.c 文件都是需要引入contact.h 所以直接在这里面来引入头文件
#include<string.h>   //menset的头文件
#include<stdlib.h>   // malloc的头文件
#include<errno.h>
//在我们写数字的时候要考虑后续的修改和代码的可移植性 所以我们尽量都是用宏定义
//#define MAX 1000  
#define MAX_NAME 20
#define MAX_SEX  5
#define MAX_TEL 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3
//关于类型的定义，所以这里我们放在contact.h  一个好友的信息就是一个结构体

typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
}PeoInfo;

//枚举的第一个变量是0 要记住   这样就避免了忘记你的选择条件是什么意思！增加了代码的可读性
enum option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};

//通讯录类型
typedef struct Contact
{
	struct PeoInfo* date;
	int size;
	int capacity;// 当前通讯录的最大容量（当size和capacity一样大的时候说明满了，需要进行扩容了）
}Contact;

//初始化
void InitContact(struct Contact* ps);
//增加
void AddContact(struct Contact* ps);
//显示
void ShowContact(const struct Contact* ps);
//删除指定的联系人
void DelContact(struct Contact* ps);    
//查找指定人的信息
void SearchContact(const struct Contact* ps);
//修改指定联系人
void ModifyContact(struct Contact* ps);
//在退出前进行动态内存开辟的释放
void DestroyContact( Contact* ps);
//保存文件
void SaveContact( Contact* ps);