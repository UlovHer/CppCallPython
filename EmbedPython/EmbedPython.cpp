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
	//python文件不要命名为test.py
	//由于test.py是python内置python脚本文件，也就是python有自己的test.py文件，并且其优先级比自己创建的高

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
	// 绝对路径
	wchar_t* argv[] = { L"E:/CppProject/EmbedPython/DataFile/google.mp4", L"1" };
	//初始化宽字节字符指针数组,将其首地址赋值给二级指针

	int callState = callPythonFile(scriptName, scriptPath, 2, argv);

	system("pause");
	return 0;
}