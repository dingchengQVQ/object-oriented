#include<queue>
#include "string"
using namespace std;

class Scan
{
	public:
		Scan() {};
		~Scan() {};
		
	public:
		bool ToStringQueue(string input); //��ȡ�û����������������ʽinupt,�ֽ��ת�浽m_scanstring
		
	public:
		queue<string> m_scanstring;	
};


class Print
{
	public:
		Print() {};
		~Print() {};
		
	public:
		void PrintQueue(queue<string>& tmpQueue); //����һ������
};
