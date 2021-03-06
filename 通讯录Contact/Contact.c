#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void InitContact(struct Contact* ps)
{
	memset(ps->date, 0, sizeof(ps->date));  // ps->date 是数组名 放在sizeof()里面就是求出来整个数组的总大小
	ps->size = 0; //设置通讯录最初只有0个元素
}

//在你编写代码前应该就思考以下问题：1.你增加内容，但是容量本身是有可能满了的
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满，无法增加\n");
	}
	else
	{
		 //★★这里其实不是非常的好理解  什么叫增加？增加就是放在已有元素的下一个位置
		//开始的时候里面有0个元素 ，0放在下标为1的地方，第一个元素放在下标为2的地方
		printf("请输入名字：>");
		scanf("%s", ps->date[ps->size].name);
		printf("请输入年龄：>");   //要记住这里的名字是一个变量所以要加&符号
		scanf("%s", &(ps->date[ps->size].age));
		printf("请输入性别：>");
		scanf("%s", ps->date[ps->size].sex);
		printf("请输入电话：>");
		scanf("%s", ps->date[ps->size].tel);
		printf("请输入地址：>");
		scanf("%s", ps->date[ps->size].addr);
		ps->size++;
		printf("添加成功\n");    //  在这里我们虽然报了添加成功但是对于你自己来说你并没有看见是否这一步真的成功了
									//  所以我们在这里直接考虑写ShowContact函数
	}

}

void ShowContact(const struct Contact* ps)   //因为只是显示绝对不会改变ps指向的对象的  所以加一个const
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		// 我想在能不能直接在外面打印出来一个标题，姓名 年龄 性别 电话 地址  这样就能更加清楚的展示下面的信息
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名","年龄","性别","电话","地址"); 
		//易错点：这里的年龄是一个字符 用%s打印     而下面的则是要用%d的形式进行打印，不然就会在下面报错
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",ps->date[i].name,ps->date[i].age,ps->date[i].sex,ps->date[i].tel,ps->date[i].addr);
		}
	}
}


static int FindByName(const struct Contact* ps, char name[MAX_NAME])  //只能在这个原文件中出现
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
void DelContact(struct Contact* ps)    //  这里使用const地下就会报错，因为你说的是ps所指向的位置是不会发生改变的
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字：>");
	scanf("%s", name);
	//找到了就返回名字所在元素的下标    没有找到就返回一个-1
	int pos = FindByName(ps, name);
	//删除

	if (-1 == pos)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j<ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

//1.查找要删除的人在什么位置   这一块的代码多次重复，为了是整个代码看着简洁省事我们封装一个函数就是用来查找名字的
//int i = 0;
//for (i = 0; i < ps->size; i++)
//{
//	if (0 == strcmp(ps->date[i].name, name))
//	{
//		break;
//	}
//}
//来到这里有两种情况1.break跳到这里了（删除掉它）   2.你把所有的判别完了，都还没有找到一样的
//	if (i == ps->size)
//	{
//		printf("要删除的人不存在\n");
//	}
//	else
//	{
//		//删除数据    假设 1 2 3 4 5 6 7  
//		//2.删除  用覆盖法  也就是后面的一个元素往前移动
//		int j = 0;
//		for (j = i;j<ps->size-1;j++)
//		{
//			ps->date[j] = ps->date[j + 1];
//		}
//		ps->size--;
//		printf("删除成功\n");
//	}
//}

void SearchContact(const struct Contact* ps)
{
	//此时此刻出现了代码重复，修改，删除，查找这几个函数都是需要先找到指定的联系人
	char name[MAX_NAME];
	printf("请输入要查找的人名字：>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		//这里找到了不要单纯的只是说一句找到了，把他的信息打印出来
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n", ps->date[pos].name, ps->date[pos].age, ps->date[pos].sex, ps->date[pos].tel, ps->date[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改的人名字：>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		// 修改相当于重新录入一边
		printf("请输入名字：>");
		scanf("%s", ps->date[pos].name);
		printf("请输入年龄：>");   
		scanf("%s", &(ps->date[pos].age));
		printf("请输入性别：>");
		scanf("%s", ps->date[pos].sex);
		printf("请输入电话：>");
		scanf("%s", ps->date[pos].tel);
		printf("请输入地址：>");
		scanf("%s", ps->date[pos].addr);
		printf("修改成功\n");
	}
}