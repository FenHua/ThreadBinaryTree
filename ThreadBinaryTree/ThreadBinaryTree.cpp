// ThreadBinaryTree.cpp : �������̨Ӧ�ó������ڵ㡣
#include"BinaryTreeThd.h"
#include<iostream>
using namespace std;
void test()
{
	int array[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	size_t size = sizeof(array) / sizeof(array[0]);
	BinaryTreeThd<int>bt1(array, size, '#');
	cout << "�������������>";
	bt1.InOrderThread();
	bt1.InOrder();

	BinaryTreeThd<int>bt2(array, size, '#');
	cout << "������ǰ�����>";
	bt2.PrevOrderThread();
	bt2.PrevOrder();

	BinaryTreeThd<int> bt3(array, size, '#');
	cout << "�������������>";
	bt3.PostOrderThread();
	bt3.PostOrder();

}
int main()
{
	test();
	system("pause");
	return 0;
}