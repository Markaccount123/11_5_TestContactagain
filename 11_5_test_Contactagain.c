#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//����һ����̬�ڴ�İ汾����Ϊ��ᷢ����һ���Դ��������ô�����Կռ����һ�����˷ѣ�����ҪĬ��������ֻ�����3����λ������������ʱ��ÿ������2����λ
//ֻ��Add��������Ҫ��̬�����ڴ�ģ������Ķ���������Ҫ�����о���Ҫ�Կ��ٵĿռ�����ͷ�

//���Ǿ�����п��Լ������ȥ����Ϣ�ڹص�����һ˲�䣬���������ˣ���������Ҳ���԰����޸ĳ�Ϊһ���ļ������İ汾������ʹ���ٹر��Ժ���һ�δ���Ϣ���ɴ���
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
	//����ͨѶ¼ 
	struct Contact con;  // con����ͨѶ¼���������dateָ���size����capacity
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
			//���˳�ǰ��Ҫ���ٶ�̬���ٵ��ڴ�
			DestroyContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		case SAVE:
			SaveContact(&con);
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}
