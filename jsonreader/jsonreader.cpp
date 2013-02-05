// jsonreader.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
//#include <iostream.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	wifstream jsonreader("test.json");
	if (jsonreader == NULL)
		cout<<"failed to read json"<<endl;
	
	//cout<<jsonreader.rdbuf()<<endl;
	//char *chr[128];
	//chr = jsonreader.rdbuf();



	jsonreader.seekg(0, ios::end);
	int filesize = jsonreader.tellg();
	jsonreader.seekg(0, ios::beg);
	wchar_t *pBuffer = new wchar_t[filesize+1];
	jsonreader.read(pBuffer, filesize);
	pBuffer[filesize]='\0';
	wcout<<pBuffer<<endl;
	delete pBuffer;
	return 0;
}

