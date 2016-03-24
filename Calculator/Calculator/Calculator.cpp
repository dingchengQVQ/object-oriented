#include "Calculator.h"
#include <iostream>
bool Scan::ToStringQueue(string input)
{
	size_t markOfReadPos = 0; //��ʶ�Ѿ����뵽input�ĵڼ�λ,��ʼ0Ϊinput��һλ
	bool isDigit = false; 
	bool isdecimal = false; 
	
	for (size_t i = 0; i != input.size(); i++)
	{
		if (isdigit(input[i]) || input[i] == '.') //�ж��Ƿ�Ϊ����,����С����
		{
			if (input[i] == '.') 
			{
				isdecimal = true;	
			}
			
			isDigit = true;
			continue;
		}


		else 
		{
			if (isDigit == true) //�ж��Ƿ�ն���һ������
			{
				isDigit = false;
				string tmp = input.substr(markOfReadPos,i - markOfReadPos); //i - markOfReadPosΪҪ��ȡ���ַ����ַ���

				//�ж�����������Ƿ񳬹�10λ

				if (isdecimal) 
				{
					if ((tmp.size() - 1) > 10) 
					{	
						return false;	
					}
		    	}


				else 
				{
					if (tmp.size() > 10) //�������ֳ���10λ
					{	
					  return false;	
					}
				}


				m_scanstring.push(tmp); //��markOfReadPos �� iλ�õ����� ��string����queue
				markOfReadPos = i;
				isdecimal = false;
			}


			string sign;
			sign.insert( sign.begin(), input[i] ); //��charת����string
			m_scanstring.push(sign);
			markOfReadPos++;
		}	
	}


	if (isDigit) //��ʾ���ʽ���Ϊ����
	{
		string tmp = input.substr(markOfReadPos,input.size() - markOfReadPos); //i - markOfReadPosΪҪ��ȡ���ַ����ַ���


		//�ж�����������Ƿ񳬹�10λ

		if (isdecimal) 
		{	
			if ((tmp.size() - 1) > 10) 
			{	
				return false;	
			}	
		}


		else 
		{	
	    	if (tmp.size() > 10) 
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
