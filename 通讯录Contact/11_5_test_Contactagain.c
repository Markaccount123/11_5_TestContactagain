#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//1.test ���Թ���
//2.contact.c  ʵ�ֺ����Ĺ���
//contact.h   ��������
//���1000�����ѵ���Ϣ
//������Ϣ���������֣��绰���Ա𣬵�ַ ������
//���ܣ����Ӻ�����Ϣ   ɾ��ָ�����ѵ���Ϣ  ���Һ�����Ϣ  �޸ĺ�����Ϣ ��ӡ������Ϣ
//����һ��Ŀǰ����Щ��Ŀ��˵����ͬС����test.c���ļ��е�ʵ�ַ�ʽ�ǲ���
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
	//����ͨѶ¼ 
	struct Contact con;  // con����ͨѶ¼���������1000��Ԫ�ص�����size
	                         //  �������ʹ�ö�̬�ڴ�malloc����һ�����٣��ں������޸�
	//��ʼ��ͨѶ¼
	InitContact(&con);  // 1.����ַЧ�ʸ�  2.�ṹ�崫��ַ����ͨ��InitContac �ı� strcut Contac���������
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d",&input);
		switch (input)   //  ��������ѡ��д1��2��3��ᷢ�ִ���Ŀɶ��Բ��ߣ��Ҳ�֪�������������ִ�����ʲô��˼
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
			ShowContact(&con);     // ������Ȼ����Ҫ�ı�ʲô��ֻ����Ҫ��ӡ��ʾ���������Ǵ���ַ��Ч�ʻ�ܸ�
			break;
		case SORT:
			//SortContact(&con);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}
