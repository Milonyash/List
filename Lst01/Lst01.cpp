// Lst01.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "List.h"
#include "Iterator.h"
#include "string.h"

using namespace std;
int main()
{
	printf("List 1\n");
	List<int> ls;
	for (int j = 5; j < 10; ++j)
		ls.Add(j);
	
	ls.Delete(3);
	List<int>::iterator io = ls.begin();

	while (io != ls.end()) {
		cout << *io << " ";
		++io;
	}
	cout << "\n";

	printf("List 2\n");
	List <string> lst;
	lst.Add("a");
	lst.Add("b");
	lst.Add("c");
	lst.Add("d");

	lst.Delete(0);

	List<string>::iterator iostr = lst.begin();
	while (iostr !=lst.end()) {
		cout << (*iostr).c_str() << " ";
		++iostr;
	}
	cout << "\n";
	system("pause");
}
