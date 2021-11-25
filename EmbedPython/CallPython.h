#pragma once
int callPythonFunc(const char* scriptName, const char* funcName);
int callPythonAdd(const char* scriptName, const char* funcName);
int callPythonFile(const char* scriptFile, const char* scriptPath, int argc, wchar_t** argv);