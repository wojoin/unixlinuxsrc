// GeneratorClass.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
using namespace std;

extern "C" {
	int IFRInitialize(const char* engine, void* reserved);
	typedef int(*Proc_IFRInitialize)(const char* engine, void* reserved);

	int IFRCreateInst(const char* svt, const char* params);
	typedef int(*Proc_IFRCreateInst)(const char* svt, const char* params);

	int IFRProcess(const char* svt, const char* params);
	typedef int(*Proc_IFRProcess)(const char* svt, const char* params);

	int IFRCloseInst(const char* params);
	typedef int(*Proc_IFRCloseInst)(const char* params);

	int IFRDestroy(const char* engine);
	typedef int(*Proc_IFRDestroy)(const char* engine);
}
#define proc_addr_decl(cmd_name)	\
	Proc_##cmd_name		cmd_name;
#define proc_decl(cmd_name)			\
	proc_addr_decl(cmd_name)

#define set_proc(cmd_name, funcname)	\
	this->cmd_name = funcname;


int init(const char* engine, void* reserved)
{
	printf("======%s  init\n", engine);
	return 0;
}

int process(const char* svt, const char* params)
{
	printf("======%s  process\n", svt);
	return 0;
}

int destroy(const char* engine)
{
	printf("======%s  destroy\n", engine);
	return 0;
}


class Generator
{
public:
	Generator() {}
	void load_porc()
	{
		set_proc(IFRInitialize, init)
		set_proc(IFRProcess, process)
		set_proc(IFRDestroy, destroy)
	}

public:
		proc_decl(IFRInitialize)
		proc_decl(IFRCreateInst)
		proc_decl(IFRProcess)
		proc_decl(IFRCloseInst)
		proc_decl(IFRDestroy)
};

int main()
{
	Generator* g = new Generator;
	g->load_porc();
	g->IFRInitialize("IFR", 0);
	g->IFRProcess("IFR, Face Recognization", "");
	g->IFRDestroy("IFR");

	system("pause");
	return 0;
}

