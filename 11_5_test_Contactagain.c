#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//这是一个动态内存的版本，因为你会发现你一次性创造出来那么多个会对空间造成一定的浪费，我想要默认情形下只存放这3个空位，当发现满的时候每次增加2个空位
//只有Add函数是需要动态开辟内存的，其他的都基本不需要，还有就是要对开辟的空间进行释放

//我们经常会感慨自己输入进去的信息在关掉的那一瞬间，都不存在了，所以这里也可以把他修改成为一个文件操作的版本，可以使他再关闭以后，下一次打开信息依旧存在
void menu()
{
	printf("*************************\n");
	printf("***1.add        2.del***\n");
	printf("***3.search   4.modify***\n");
	printf("***5.show       6.sort***\n");
	printf("***7.save       0.exit***\n");
	printf("*************************\n");
}
int main()
{
	int input = 0;
	//创建通讯录 
	struct Contact con;  // con就是通讯录，里面包含date指针和size还有capacity
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
			//在退出前，要销毁动态开辟的内存
			DestroyContact(&con);
			printf("退出通讯录\n");
			break;
		case SAVE:
			SaveContact(&con);
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}
