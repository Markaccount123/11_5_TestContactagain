#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void InitContact(Contact* ps)
{
	ps->date = (PeoInfo*)malloc(3 * sizeof(PeoInfo));   //  ��Ȼ�㶯̬������һ��ռ䵱�㲻�õ�ʱ��һ��Ҫ�������ϵͳ��Ҫ��������ͷ�
	if (ps->date == NULL)   // ֻҪ�Ƕ�̬�ڴ濪�ٵ�ָ��һ��Ҫ����һ���жϣ���Ȼ�ں���������õ�ʱ������ֱ�ӱ���
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
}

void CheckCapacity(Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		//����   ������������  realloc�������Ҫ��һ���µ�ָ�������ܣ����һ�Ҫ�ж����ָ���Ƿ�ΪNULL����������Ľ����õ��³������
		PeoInfo* ptr = (PeoInfo*)realloc(ps->date, (ps->capacity + 2)*sizeof(PeoInfo));  //  ����һ�μ�2���ռ�
		if (ptr != NULL)
		{
			ps->date = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}
	}
}

//�����д����ǰӦ�þ�˼���������⣺1.���������ݣ����������������п������˵�
void AddContact(struct Contact* ps)
{
	//��⵱ǰͨѶ¼������
	//1.������˾����ӿռ�
	//2.���������ɶ������
	CheckCapacity(ps); 
	//Ҫô�ռ䱾���͹��þ�û������if��䣬Ҫô�������ݳɹ��ˣ��ռ��Ѿ�������
	//��������
	printf("���������֣�>");
	scanf("%s", ps->date[ps->size].name);
	printf("���������䣺>");   //Ҫ��ס�����������һ����������Ҫ��&����
	scanf("%d", &(ps->date[ps->size].age));
	printf("�������Ա�>");
	scanf("%s", ps->date[ps->size].sex);
	printf("������绰��>");
	scanf("%s", ps->date[ps->size].tel);
	printf("�������ַ��>");
	scanf("%s", ps->date[ps->size].addr);
	ps->size++;
	printf("��ӳɹ�\n"); 
}

void ShowContact(const struct Contact* ps)   //��Ϊֻ����ʾ���Բ���ı�psָ��Ķ����  ���Լ�һ��const
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		// �������ܲ���ֱ���������ӡ����һ�����⣬���� ���� �Ա� �绰 ��ַ  �������ܸ��������չʾ�������Ϣ
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����","����","�Ա�","�绰","��ַ"); 
		//�״�㣺�����������һ���ַ� ��%s��ӡ     �����������Ҫ��%d����ʽ���д�ӡ����Ȼ�ͻ������汨��
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",ps->date[i].name,ps->date[i].age,ps->date[i].sex,ps->date[i].tel,ps->date[i].addr);
		}
	}
}


static int FindByName(const struct Contact* ps, char name[MAX_NAME])  //ֻ�������ԭ�ļ��г���
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
void DelContact(struct Contact* ps)    //  ����ʹ��const���¾ͻᱨ����Ϊ��˵����ps��ָ���λ���ǲ��ᷢ���ı��
{
	char name[MAX_NAME];
	printf("������Ҫɾ���˵����֣�>");
	scanf("%s", name);
	//�ҵ��˾ͷ�����������Ԫ�ص��±�    û���ҵ��ͷ���һ��-1
	int pos = FindByName(ps, name);
	//ɾ��

	if (-1 == pos)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j<ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

//1.����Ҫɾ��������ʲôλ��   ��һ��Ĵ������ظ���Ϊ�����������뿴�ż��ʡ�����Ƿ�װһ���������������������ֵ�
//int i = 0;
//for (i = 0; i < ps->size; i++)
//{
//	if (0 == strcmp(ps->date[i].name, name))
//	{
//		break;
//	}
//}
//�����������������1.break���������ˣ�ɾ��������   2.������е��б����ˣ�����û���ҵ�һ����
//	if (i == ps->size)
//	{
//		printf("Ҫɾ�����˲�����\n");
//	}
//	else
//	{
//		//ɾ������    ���� 1 2 3 4 5 6 7  
//		//2.ɾ��  �ø��Ƿ�  Ҳ���Ǻ����һ��Ԫ����ǰ�ƶ�
//		int j = 0;
//		for (j = i;j<ps->size-1;j++)
//		{
//			ps->date[j] = ps->date[j + 1];
//		}
//		ps->size--;
//		printf("ɾ���ɹ�\n");
//	}
//}

void SearchContact(const struct Contact* ps)
{
	//��ʱ�˿̳����˴����ظ����޸ģ�ɾ���������⼸������������Ҫ���ҵ�ָ������ϵ��
	char name[MAX_NAME];
	printf("������Ҫ���ҵ������֣�>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		//�����ҵ��˲�Ҫ������ֻ��˵һ���ҵ��ˣ���������Ϣ��ӡ����
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n", ps->date[pos].name, ps->date[pos].age, ps->date[pos].sex, ps->date[pos].tel, ps->date[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ������֣�>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		// �޸��൱������¼��һ��
		printf("���������֣�>");
		scanf("%s", ps->date[pos].name);
		printf("���������䣺>");   
		scanf("%d", &(ps->date[pos].age));
		printf("�������Ա�>");
		scanf("%s", ps->date[pos].sex);
		printf("������绰��>");
		scanf("%s", ps->date[pos].tel);
		printf("�������ַ��>");
		scanf("%s", ps->date[pos].addr);
		printf("�޸ĳɹ�\n");
	}
}

void DestroyContact(Contact* ps)
{
	free(ps->date);
	ps->date = NULL;
}

void SaveContact(Contact* ps)
{
	FILE* pf = fopen("contact.dat", "wb");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return;   //�����Ķ�����void  �������ﷵ�ؾͺ��ˣ���Ҫ��0
	}
	//дͨѶ¼�е����ݵ��ļ���
	//һ��һ����д��
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->date[i]), sizeof(PeoInfo), 1, pf);
	}
	printf("����ɹ�\n");
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}