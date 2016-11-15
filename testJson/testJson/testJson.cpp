// testJson.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
//�����Ҫ��ͷ�ļ�
#include "include/json/json.h"

using namespace std;

//������Ҫ�Ŀ��ļ�
#ifdef _DEBUG
#pragma comment(lib,"lib_json_d.lib")
#else
#pragma comment(lib,"lib_json.lib")
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"����jsonд��"<<endl;
	Json::Value jsonRoot;
	Json::Value jsonItem;
	jsonItem["item1"] = "��һ����Ŀ";
	jsonItem["item2"] = "�ڶ�����Ŀ";
	jsonItem["item3"] = 3;
	jsonRoot.append(jsonItem);
	jsonItem.clear();//��������Ѿ���ֵ����
	jsonItem["First"]="1";
	jsonItem["Second"]=2;
	jsonItem["Third"]=3.0F;
	jsonRoot.append(jsonItem);
	cout<<jsonRoot.toStyledString()<<endl;

	cout<<"����jsonд�뵽�ļ�"<<endl;

	ofstream ofs;
	ofs.open("test1.json");
	ofs<<jsonRoot.toStyledString();
	ofs.close();

	cout<<"����json��ȡ"<<endl;
	string sJson = jsonRoot.toStyledString();
	jsonRoot.clear();
	Json::Reader jsonReader;
	if (!jsonReader.parse(sJson,jsonRoot))
	{
		return -1;
	}
	for (auto it = jsonRoot.begin();
		it!=jsonRoot.end();
		it++)
	{
		for (auto sit = it->begin();
			sit != it->end();
			sit++)
		{
			cout<<sit.key()<<"\t"<<sit.name()<<endl;
		}
	}
	cout<<"���Զ�ȡjson�ļ�"<<endl;
	ifstream ifs;
	ifs.open("test1.json");

	jsonRoot.clear();
	if (!jsonReader.parse(ifs, jsonRoot))
	{
		return -1;
	}
	ifs.close();
	for (auto it = jsonRoot.begin();
		it!=jsonRoot.end();
		it++)
	{
		for (auto sit = it->begin();
			sit != it->end();
			sit++)
		{
			cout<<sit.key()<<"\t"<<sit.name()<<endl;
		}
	}
	return 0;
}

