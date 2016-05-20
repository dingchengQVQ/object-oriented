#include<stdio.h>
typedef struct link
{
	int address;
	int data;
	int nextaddr;
	struct link *next;//ָ���¸��ڵ��ָ��
} Link;
int i=1;
int data[100004];
int next[100004];
int temp;
int num=0;
Link a[100004];

//��������
void create(Link *head)
{
	i = 1;
	while (1)
	{
		if (a[i-1].nextaddr == -1)
		{
			a[i-1].next = NULL;
			num = i-1;
			break;
		}

		a[i].address = a[i-1].nextaddr;
		a[i].data = data[a[i].address];
		a[i].nextaddr = next[a[i].address];
		a[i-1].next = a+i;
		i++;
	}
}

//����ת
Link *listReverse(Link *head, int k)
{
	int count=1;
	Link *s=head->next;
	Link *old=s->next;
	Link *temp=NULL;

	while(count<k)
	{
		temp=old->next;
		old->next=s;
		old->nextaddr=s->address;
		s=old;  //s�����һ���ڵ�
		old=temp;  //temp�����һ���ڵ�
		count++;
	}

	//ʹ��ת������һ���ڵ�ָ����һ��������ĵ�һ���ڵ�
	head->next->next=old;

	if(old!=NULL)
	{
		head->next->nextaddr=old->address;	//�޸�nextֵ��ʹ��ָ����һ���ڵ��λ��
	}
	else
	{
		//���oldΪNULL,��û����һ����������ô��ת������һ���ڵ㼴�������������һ���ڵ�
		head->next->nextaddr=-1;
	}
	return s;
}
int main()
{
	int firstaddr;
	int n=0,k=0;
	Link *head;
	scanf("%d%d%d",&firstaddr,&n,&k);
	a[0].nextaddr=firstaddr;
	for(; i<n+1; i++)
	{
		scanf("%d",&temp);
		scanf("%d %d",&data[temp],&next[temp]);
	}
	create(head);

	Link *p=a; //pָ��ͷ���
	Link *q=NULL;//��ת�������ķ���ֵ
	if(k<=num)
	{
		for(i=0; i<(num/k); i++)
		{
			q=listReverse(p,k);
			p->next=q; // ��һ��ִ�У�a[0]->next ָ���һ��������ת�ĵ�һ���ڵ�
			p->nextaddr=q->address;  // ����Nextֵ��ָ����ת��������һ���ڵ��λ��

			//ʹpָ����һ����Ҫ��ת���������ͷ���
			int j=0;
			while(j<k)
			{
				p=p->next;
				j++;
			}
		}
	}
	p=a;
	while(p->next!=NULL)
	{
		p=p->next;
		if(p->nextaddr!=-1)
		{
			printf("%05d %d %05d\n",p->address,p->data,p->nextaddr);
		}
		else
		{
			printf("%05d %d -1\n",p->address,p->data);
		}
	}
	return 0;
}


