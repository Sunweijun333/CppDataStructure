#include <iostream>
#include <map>  //������ӳ�䣬���ǹ�ϣӳ��,��������
#include <string>
#include "LinearMap.h"
#include "HashMap.h"
#include <hash_map>//C++��������õ�hashӳ�䣬΢�����õ�
using namespace std;
int main()
{
	map <string, int> m;
	m["bill"] = 98;
	m["Tom"] = 67;
	m["Mary"] = 100;
	//��������..1000���
	//�ٶ�ΪO(log(n))
	cout << m["Tom"];

	LinearMap <string, int> lm;
	lm.Put("Bill", 99);
	lm.Put("Tom", 98);
	//...........�źܶ�����
	//�ٶ�ΪO(n)
	cout << "LinearMap: " << lm.get("Tom");

	//�ҵĹ�ϣӳ��
	cout << "�ҵĹ�ϣӳ��:" << endl;
	HashMap <string, int> myHashMap;
	//cout << myHashMap.hash("Bill") << endl;
	//cout << myHashMap.myhash("Billl") << endl;
	myHashMap.Put("Bill", 999);
	myHashMap.Put("Tom", 888);
	cout<<myHashMap.get("Tom");
	//ϵͳ�Ĺ�ϣӳ��hash_Map
	hash_map<string, int> hash;
	hash["Bill"] = 2;
	hash["Tom"] = 3;
	cout << hash["Bill"] << endl;

	system("pause");
	return 0;
}