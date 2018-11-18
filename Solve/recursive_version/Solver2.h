//#pragma once
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Solver {
private:
	int startX, startY;   // ��������Ʈ
	vector<int> middle;   // �߰��� �迭
	int orderOfMat;		  // ������ǥ�� ��
	int indexOfMiddle;	  // ���� �߰��� ����
	int **matrix;		  // ����
	int sizeX, sizeY;	  // ������ ������
	int total;			  // ������ -1���� �ƴ� �� ������ ����(= ������ ����)
	bool finish;		  // floodfill���� finish�� true�� �Ǹ� ����

public:
	Solver() 
	{
		orderOfMat = 0;
		indexOfMiddle = 0;
		total = 0;
		finish = false;
	}
	~Solver() 
	{
		for (int i = 0; i < sizeY; i++) 
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}


	void input(ifstream &file) 
	{
		//��Ʈ���� ������ �о size���� �޾ƿ�
		//size ������ matrix�� 2���迭�� �����Ҵ�
		//������ matrix�� ��������
		//-1 ���� �ƴϸ� total++ ����.
		//�о���� �� 0, -1 ���� �ƴ� ���̸� middle�� push����
		//middle���� ������������ ��������

		file >> sizeX >> sizeY;
		matrix = new int*[sizeY];
		for (int i = 0; i < sizeY; i++) 
		{
			matrix[i] = new int[sizeX];
		}
		for (int i = 0; i < sizeY; i++) 
		{
			for (int j = 0; j < sizeX; j++) 
			{
				file >> matrix[i][j];
				if (matrix[i][j] != -1) 
				{
					total++;
					if (matrix[i][j] != 0) 
					{
						middle.push_back(matrix[i][j]);
						if (matrix[i][j] == 1) 
						{
							startX = j;
							startY = i;
						}
					}
				}
			}
		}
		sort(middle.begin(), middle.end());
	}


	void output(ofstream &file) 
	{
		//�ؽ�Ʈ���Ϸ� �������� ���.
		for (int i = 0; i < sizeY; i++) 
		{
			for (int j = 0; j < sizeX; j++) 
			{
				file << matrix[i][j] << " ";
			}
			file << endl;
		}
			
	}


	bool search(int Y, int X, int middle) 
	{
		cout << "searching" << endl;

		if (matrix[Y - 1][X] == middle)
			return true;


		if (matrix[Y - 1][X - 1] == middle)
			return true;

		if (matrix[Y - 1][X + 1] == middle)
			return true;
		if (matrix[Y][X + 1] == middle)
			return true;
		if (matrix[Y + 1][X + 1] == middle)
			return true;
		if (matrix[Y + 1][X] == middle)
			return true;
		if (matrix[Y + 1][X - 1] == middle)
			return true;
		if (matrix[Y][X - 1] == middle)
			return true;
		return false;
	}

	bool cTest(int Y, int X) {
		
		
		return true;
	}

	void floodFill(int Y, int X) {
		/*
		1.  finish�� 1���� �˻�.(��������)
		2.  ��ǥ�� 0 �̸����� �˻�(�ȵǴ���)
		3-1 ��ǥ���� 0�� �ƴ��� �˻�( ���̰ų� �߰���)
		3-2 ���� ��尪�� -1�� �ƴϸ�,
			orderOfMat+1 ���� ��������� middle������ �˻�
			middle���ϰ�� middle���̶�� ǥ��
		5.  orderOfMat++, matrix[Y][X] = orderOfMat  (0�� ���簪���� ����)
		6.  �ٽ� floodFill �ָ���
		7.  finish�� 1�̸� ����
		8.  orderOfMat--, matrix[Y][X] = 0( middle���̸� �װ����� �ٽ�)
		*/
		bool midf = false;
		int mid;

		if (finish) {					//1.  finish�� 1���� �˻�.(��������)
			cout << "1" << endl;
			return;
		}

		if (Y < 0 || X < 0 || Y == sizeY || X == sizeX) {           //2.  ��ǥ�� 0 �̸����� �˻�(�ȵǴ���)
			cout << "2" << endl;
			return;
		}
		if (matrix[Y][X] == -1) {       //3
			cout << "3" << endl;
			return;
		}

		/*
		if (orderOfMat + 2 == middle.at(indexOfMiddle)) {   // 4
			if (!search(Y, X, middle.at(indexOfMiddle))) {
				cout << "4" << endl;
				return;
			}
			cout << "4-2" << endl;

		}*/

		if (matrix[Y][X] == 0) {
			if (orderOfMat == middle.at(indexOfMiddle) - 1) {
				return;
			}
		}
		else if (matrix[Y][X] == middle.at(indexOfMiddle)) {
			midf = true;
			mid = middle.at(indexOfMiddle);
			indexOfMiddle++;
		}
		else {
			cout << "5" << endl;
			return;
		}
		
		

		orderOfMat++;                    
		matrix[Y][X] = orderOfMat;




		
		for (int i = 0; i < sizeY; i++) {
			for (int j = 0; j < sizeX; j++) {
				if (matrix[i][j] == 0) {
					cout << "00 ";
					continue;
				}
				else if (matrix[i][j] < 10 && matrix[i][j] > 0) {
					cout << " "<< matrix[i][j] << " ";
					continue;
				}
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "order : " << orderOfMat << ", index :" << indexOfMiddle << endl<<endl;




		if (orderOfMat == total) {        //���簪�� �ִ���ڸ� ����
			finish = true;
			cout << "6" << endl;
			return;
		}
		
		floodFill(Y - 1, X);              // 6
		floodFill(Y - 1, X + 1);
		floodFill(Y, X + 1);
		floodFill(Y + 1, X + 1);
		floodFill(Y + 1, X);
		floodFill(Y + 1, X - 1);
		floodFill(Y, X - 1);
		floodFill(Y - 1, X - 1);
		
		if (finish) {                     // 7
			cout << "7" << endl;
			return;
		}

		orderOfMat--;                     // 8
		if (midf) {
			cout << "8" << endl;
			indexOfMiddle--;
			matrix[Y][X] = mid;
			return;
		}

		matrix[Y][X] = 0;

	}


	void solve() {

		floodFill(startY, startX);

	}

};