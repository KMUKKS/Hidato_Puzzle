#pragma once
#include <vector>
#include <fstream>
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
	Solver() {
		orderOfMat = 0;
		indexOfMiddle = 0;
		total = 0;
		finish = false;
	}
	~Solver() {
		for (int i = 0; i < sizeY; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	void input(fstream &file) {
		//��Ʈ���� ������ �о size���� �޾ƿ�
		//size ������ matrix�� 2���迭�� �����Ҵ�
		//������ matrix�� ��������
		//-1 ���� �ƴϸ� total++ ����.
		//�о���� �� 0, -1 ���� �ƴ� ���̸� middle�� push����
		//middle���� ������������ ��������
	}
	void output(fstream &file) {
		//�ؽ�Ʈ���Ϸ� �������� ���.
	}
	bool search(int Y, int X, int middle) {	
		// �ֺ��� ���� ������ �߰����� �ִ��� �˻�
		// ������ true, ������ false ����
	}
	void floodFill(int Y, int X) {
		/*
		
		
		*/
	}
	void solve() {
		// main���� ������� �Լ�.
		// floodFill�� ����ؼ� ������ ǰ.
	}

	
		
};