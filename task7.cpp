// task7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include < string.h >
#include < cstring >

int func5(int  masbin[],int find,int otvet,int a,int b) { //номер 5
	
	if (otvet == 0) {
		if (masbin[b] == find) {
			a = b;
			otvet = a + 1;
		}
		else if (masbin[a] == find) {
			b = a;
			otvet = a + 1;
		}
		else if (find < masbin[(a + b) / 2])
		{
			b = ((a + b) / 2);
		}
		else if (find == masbin[(a + b) / 2])
		{
			a = (a + b) / 2;
			b = a;
			otvet = a + 1;
		}
		if (find > masbin[(a + b) / 2]) {
			a = (a + b) / 2;

		}
		func5( masbin, find, otvet, a, b);
	}
	else {
		return otvet;
	}

}
void bin() {   //номер 5
	int q, * masbin, find;
	int otvet = 0;

	//	printf(" %d", a);
	//	printf(" %d", b);
	//	printf(" %d", masbin[a]);
	//	printf(" %d", masbin[b]);
	printf("\nВведите кол-во чисел в массиве? ");
	scanf_s("%d", &q);//q - кол-во эллементов массива 1

	masbin = (int*)malloc(q * sizeof(int)); //выделяем необходимую память
	for (int i = 0; i < q; i++) {
		scanf_s("%d", &masbin[i]);
	}
	printf("\nкакое число нужно найти? ");
	scanf_s("%d", &find);
	int a = 0, b; b = q - 1;
	printf("Ваше число на %d месте", func5( masbin, find, otvet, a, b));
	exit(0);
}

int qwe(int len,char word[],int n) {

	if (word[len] == ' ')
	{
		qwe(len - 1, word,n);
	
	}
	else if (word[n] == ' ')
	{
		qwe(len, word, n+1);
	
	}
	else {
		if ( (len - n) <= 0)
		{

			return 1;
		}
		if (word[len] == word[n] || abs(word[len] - word[n])==32)
		{
			qwe(len - 1, word, n + 1);
		}
		else {

			return -1;
		}
	}

}

void zadanie7(){//Задание 6

		int size = 256;
		char* word = new char[size];
		
		printf("Введите текст(только на английском): \n\n\n");
		

		scanf_s("\n");
		fgets(word, 254, stdin);
		int len = strlen(word);
 
		printf("Ответ: %d",qwe(len-2, word, 0));


}
void zadanie6() {
	// Считываем размеры массивов,
	int n, m;
	printf("\nКол-во эллементов в 1 массиве? ");
	scanf_s("%d",&n);
	printf("\nКол-во эллементов вo 2 массиве? ");
	scanf_s("%d",&m);
	//выделяем память
	int* a = new int[n];
	int* b = new int[m];

	// Считываем массивы;
	printf("\nВведите эллементы 1 массива  ");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d",&a[i]);
	}
	printf("\nВведите эллементы 2 массива  ");
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d", &b[i]);
	}

	int* result = new int[n + m];

	int i = 0, j = 0;

	int index = 0;
	while (i < n && j < m)
	{

		if (a[i] < b[j])
		{
			result[index] = a[i];
			i++;

		}
		else
		{
			result[index] = b[j];
			j++;

		}

		index++;
	}

	while (i < n)
	{
		result[index] = a[i];
		index++;
		i++;
	}

	while (j < m)
	{
		result[index] = b[j];
		index++;
		j++;
	}
	printf("Ответ:");
	// Выводим отсортированный массив
	for (int k = 0; k < n + m; k++)
	{
		printf("  %d",result[k]);
	}
}

int main()
{
	int q=-1;
	setlocale(LC_ALL, "Russian");
	
	//Task7 

	printf("\n\n5) (2) (Рекурсия) Найти заданный элемент в упорядоченном массиве (бинарный поиск)");
	printf("\n\n6) (2) Написать функцию, объединяющую два упорядоченных массива размером m и n в упорядоченный массив размером m+n (итоговый массив не сортировать)");
	printf("\n\n7) (2)Рекурсивно описать логическую функцию Pal(t), которая проверяет, является ли предложение t типа char t[20]; палиндромом.");
	printf("\n\n0)Выйти");
	while (q!=0) {
		printf("\n\nВведите номер нужного задания : ");
		scanf_s("%d", &q);
		switch(q){
		
		case 5: {
			bin();//Задание 5
			break;
		}
		case 6: {
			zadanie6();//Задание 6
			break;
		}
		case 7: {
			zadanie7();//Задание 7
			break;
		}
		}
	}
	return 0; 
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
