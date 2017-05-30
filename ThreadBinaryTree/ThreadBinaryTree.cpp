// ThreadBinaryTree.cpp : 定义控制台应用程序的入口点。
#include"BinaryTreeThd.h"
#include<iostream>
using namespace std;
void test()
{
	int array[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	size_t size = sizeof(array) / sizeof(array[0]);
	BinaryTreeThd<int>bt1(array, size, '#');
	cout << "线索化中序遍历>";
	bt1.InOrderThread();
	bt1.InOrder();

	BinaryTreeThd<int>bt2(array, size, '#');
	cout << "线索化前序遍历>";
	bt2.PrevOrderThread();
	bt2.PrevOrder();

	BinaryTreeThd<int> bt3(array, size, '#');
	cout << "线索化后序遍历>";
	bt3.PostOrderThread();
	bt3.PostOrder();

}
int main()
{
	test();
	system("pause");
	return 0;
}