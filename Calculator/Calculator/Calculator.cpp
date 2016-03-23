#include "Calculator.h"

#include <iostream>

bool Scan::ToStringQueue(string input)

{

	size_t markOfReadPos = 0; //��ʶ�Ѿ����뵽input�ĵڼ�λ,��ʼ0Ϊinput��һλ

	bool ifDigit = false; //��ʶ��ǰ�������ַ��Ƿ�������

	bool ifdecimal = false; //��ʶ�Ƿ���С��

	for (size_t i = 0; i != input.size(); i++)

	{

		if (isdigit(input[i]) || input[i] == '.') //�ж��Ƿ�Ϊ����,����С����

		{

			if (input[i] == '.') //˵���˿̵�����С������

			{

				ifdecimal = true;

			}

			ifDigit = true;

			continue;
		}


		else //Ϊ���� + - * % �� ��
		
		{
			
			if (ifDigit == true) //�ж��Ƿ�ն���һ������
			
			{
				
				ifDigit = false;

				string tmp = input.substr(markOfReadPos,i - markOfReadPos); //i - markOfReadPosΪҪ��ȡ���ַ����ַ���

				//�ж�����������Ƿ񳬹�10λ

				if (ifdecimal) //��С��λʱ��Ҫ�ų�С���㡰.��ռ��λ
				
				{
					
					if ((tmp.size() - 1) > 10) //�������� + С������ ����10λ
					
					{
						
						return false;
						
					}
					
				}


				else //����
				
				{
					
					if (tmp.size() > 10) //�������ֳ���10λ
					
					{
						
						return false;
						
					}
					
				}


				m_scanstring.push(tmp); //��markOfReadPos �� iλ�õ����� ��string����queue

				markOfReadPos = i;

				ifdecimal = false;
				
			}


			string sign;

			sign.insert( sign.begin(), input[i] ); //��charת����string

			m_scanstring.push(sign);

			markOfReadPos++;
			
		}
		
	}


	if (ifDigit) //��ʾ���ʽ���Ϊ����
	
	{
		string tmp = input.substr(markOfReadPos,input.size() - markOfReadPos); //i - markOfReadPosΪҪ��ȡ���ַ����ַ���


		//�ж�����������Ƿ񳬹�10λ

		if (ifdecimal) //��С��λʱ��Ҫ�ų�С���㡰.��ռ��λ
		
		{
			
			if ((tmp.size() - 1) > 10) //�������� + С������ ����10λ
			
			{
				
				return false;
				
			}
			
		}


		else //����
		
		{
			
			if (tmp.size() > 10) //�������ֳ���10λ
			
			{
				
				return false;
				
			}
			
		}


		m_scanstring.push(tmp); //��markOfReadPos �� iλ�õ����� ��string����queue
		
	}

	return true;
	
}


void Print::PrintQueue(queue<string>& tmpQueue)

{
	while(!tmpQueue.empty()) //���ֱ��������queue
	
	{
		
		cout<<tmpQueue.front()<<endl;

		tmpQueue.pop();
		
	}
				
}
