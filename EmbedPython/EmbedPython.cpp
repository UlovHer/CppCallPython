// EmbedPython.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CallPython.h"
#include <iostream>
using namespace std;

int main()
{
	//std::cout << "call python funciotn" << std::endl;
	int addRes = callPythonAdd("call_python", "add");
	//int callState = callPythonFunc("call_python", "cpp_call_python");
	//python�ļ���Ҫ����Ϊtest.py
	//����test.py��python����python�ű��ļ���Ҳ����python���Լ���test.py�ļ������������ȼ����Լ������ĸ�

	/*
	if (callState > 0)
	{
	cout << "call python function success!" << endl;
	}
	else if (callState == -1)
	{
	cout << "call python function faile!" << endl;
	}
	else
	{
	cout << "call python script faile!" << endl;
	}
	*/

	std::cout << "call python script file" << std::endl;
	const char* scriptName = "call_python_file.py";
	const char* scriptPath = "../PyrthonScripts/call_python_file.py";
	// ����·��
	wchar_t* argv[] = { L"E:/CppProject/EmbedPython/DataFile/google.mp4", L"1" };
	//��ʼ�����ֽ��ַ�ָ������,�����׵�ַ��ֵ������ָ��

	int callState = callPythonFile(scriptName, scriptPath, 2, argv);

	system("pause");
	return 0;
}