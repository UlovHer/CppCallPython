// CallPython.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "Python.h"
#include <iostream>
#include <string>
using namespace std;

int callPythonFunc(const char* scriptName, const char* funcName) {
	Py_Initialize();
	int callState = NULL;
	if (Py_IsInitialized()) {
		PyObject* pModule = NULL;
		PyObject* PFunc = NULL;
		PyRun_SimpleString("import sys");
		PyRun_SimpleString("sys.path.append('../PyrthonScripts/')");
		//初始化python系统文件路径，保证可以访问到 .py文件
		pModule = PyImport_ImportModule(scriptName);
		if (pModule) {
			cout << "Import module " << scriptName << " success" << endl;
			PFunc = PyObject_GetAttrString(pModule, funcName);
			if (PFunc || PyCallable_Check(PFunc)) {
				cout << "Import attribute " << funcName << " success" << endl;
				//创建一个元组,包含1个元素
				PyObject* pArgs = PyTuple_New(1);
				//s表示创建string型变量,赋值给第0个参数
				PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", "cpp is calling python function!"));
				PyObject* pReturn = PyEval_CallObject(PFunc, pArgs);
				PyArg_Parse(pReturn, "i", &callState);
				Py_DecRef(pArgs);
				Py_DecRef(pReturn);
				Py_DecRef(PFunc);
				Py_DecRef(pModule);
				//PyMem_Free(pArgs);
				//销毁创建的PyObject对象引用
				//当函数的返回值是New reference时，需要对PyObject* 变量使用Py_DECREF()
				//返回值是 Borrowed reference时，无需使用Py_DECREF()
			}
			else {
				callState = 0;
				cout << "Import attribute " << funcName << " faile" << endl;
			}
		}
		else
		{
			callState = -1;
			cout << "Import module " << scriptName << " faile" << endl;
		}
	}
	Py_Finalize();
	return callState;
}

int callPythonAdd(const char* scriptName, const char* funcName)
{
	Py_Initialize();
	int callState = NULL;
	if (Py_IsInitialized()) {
		PyObject* pModule = NULL;
		PyObject* PFunc = NULL;
		PyRun_SimpleString("import sys");
		PyRun_SimpleString("sys.path.append('../PyrthonScripts/')");
		//初始化python系统文件路径，保证可以访问到 .py文件
		pModule = PyImport_ImportModule(scriptName);
		if (pModule) {
			cout << "Import module " << scriptName << " success" << endl;
			PFunc = PyObject_GetAttrString(pModule, funcName);
			if (PFunc || PyCallable_Check(PFunc)) {
				cout << "Import attribute " << funcName << " success" << endl;
				PyObject*  pArgs = PyTuple_New(2);
				//i表示创建int型变量,赋值给第0个参数
				PyTuple_SetItem(pArgs, 0, Py_BuildValue("i", 10));
				PyTuple_SetItem(pArgs, 1, Py_BuildValue("i", 50));
				PyObject* pReturn = PyEval_CallObject(PFunc, pArgs);
				//解析返回参数
				PyArg_Parse(pReturn, "i", &callState);
				cout << "the result is " << callState << endl;
				Py_DecRef(pArgs);
				Py_DecRef(pReturn);
				Py_DecRef(PFunc);
				Py_DecRef(pModule);
				//PyMem_Free(pArgs);会出现内存非法访问
				//销毁创建的PyObject对象引用
				//当函数的返回值是New reference时，需要对PyObject* 变量使用Py_DECREF()
				//返回值是 Borrowed reference时，无需使用Py_DECREF()
			}
			else {
				callState = 0;
				cout << "Import attribute " << funcName << " faile" << endl;
			}
		}
		else
		{
			callState = -1;
			cout << "Import module " << scriptName << " faile" << endl;
		}
	}
	Py_Finalize();
	return callState;
}

int callPythonFile(const char* scriptName, const char* scriptPath, int argc, wchar_t** argv) {
	Py_Initialize();
	int callState = -1;
	if (Py_IsInitialized())
	{
		cout << " python interpreter initialize success" << endl;
		//Py_SetPath(scriptPath);
		//设置默认的模块搜索路径

		//切换路径函数 GetCurrentDirectory 和 SetCurrentDirectory
		/*wprintf(L"%s\n", scriptPath);
		wprintf(L"%s\n", argv[0]);
		wprintf(L"%s\n", argv[1]);
		*/
		PySys_SetArgv(argc, argv);
		//导入执行脚本时的命令行参数
		FILE *fp;
		//errno_t err = fopen_s(&fp, scriptFile, "r");
		if (!(fopen_s(&fp, scriptPath, "r")))
		{
			//获取python文件句柄
			cout << "open python script success" << endl;

			if (!(PyRun_AnyFile(fp, scriptName)))
			{
				callState = 1;
				cout << "call python script success" << endl;
			}
			//执行调用脚本文件命令, 注意文件的路径
		}
		else
		{
			callState = -2;
			cout << "open python script fail" << endl;
		}

		fclose(fp);
	}
	Py_Finalize();
	return callState;
}