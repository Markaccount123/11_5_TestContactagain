#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>    // ������ΪContact.c  ��  test.c �ļ�������Ҫ����contact.h ����ֱ����������������ͷ�ļ�
#include<string.h>   //menset��ͷ�ļ�
#include<stdlib.h>   // malloc��ͷ�ļ�
#include<errno.h>
//������д���ֵ�ʱ��Ҫ���Ǻ������޸ĺʹ���Ŀ���ֲ�� �������Ǿ��������ú궨��
//#define MAX 1000  
#define MAX_NAME 20
#define MAX_SEX  5
#define MAX_TEL 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3
//�������͵Ķ��壬�����������Ƿ���contact.h  һ�����ѵ���Ϣ����һ���ṹ��

typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
}PeoInfo;

//ö�ٵĵ�һ��������0 Ҫ��ס   �����ͱ������������ѡ��������ʲô��˼�������˴���Ŀɶ���
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

//ͨѶ¼����
typedef struct Contact
{
	struct PeoInfo* date;
	int size;
	int capacity;// ��ǰͨѶ¼�������������size��capacityһ�����ʱ��˵�����ˣ���Ҫ���������ˣ�
}Contact;

//��ʼ��
void InitContact(struct Contact* ps);
//����
void AddContact(struct Contact* ps);
//��ʾ
void ShowContact(const struct Contact* ps);
//ɾ��ָ������ϵ��
void DelContact(struct Contact* ps);    
//����ָ���˵���Ϣ
void SearchContact(const struct Contact* ps);
//�޸�ָ����ϵ��
void ModifyContact(struct Contact* ps);
//���˳�ǰ���ж�̬�ڴ濪�ٵ��ͷ�
void DestroyContact( Contact* ps);
//�����ļ�
void SaveContact( Contact* ps);