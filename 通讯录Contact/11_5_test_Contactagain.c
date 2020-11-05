#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//1.test 测试功能
//2.contact.c  实现函数的功能
//contact.h   声明函数
//存放1000个好友的信息
//好友信息包含：名字，电话，性别，地址 ，年龄
//功能：增加好友信息   删除指定好友的信息  查找好友信息  修改好友信息 打印好友信息
//对于一个目前的这些项目来说，大同小异在test.c的文件中的实现方式是差不多的
void menu()
{
	printf("*************************\n");
	printf("***1.add        2.del***\n");
	printf("***3.search   4.modify***\n");
	printf("***5.show       6.sort***\n");
	printf("***0.exit             ***\n");
	printf("*************************\n");
}
int main()
{
	int input = 0;
	//创建通讯录 
	struct Contact con;  // con就是通讯录，里面包含1000个元素的数和size
	                         //  这里可以使用动态内存malloc进行一个开辟，在后续会修改
	//初始化通讯录
	InitContact(&con);  // 1.传地址效率高  2.结构体传地址才能通过InitContac 改变 strcut Contac里面的内容
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch (input)   //  这里我们选择写1，2，3你会发现代码的可读性不高，我不知道这里具体的数字代表着什么意思
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);     // 这里虽然不需要改变什么，只是需要打印显示出来，但是传地址的效率会很高
			break;
		case SORT:
			//SortContact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}
