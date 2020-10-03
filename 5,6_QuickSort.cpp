//�� ����(Quick Sort)
// �ð����⵵ : O(N*logN)
// ���� ���� �˰���
// ������ ���ڵ��� ������������ �����ϴ� ���α׷��� �ۼ��ϼ���
// 1 10 5 8 7 6 4 3 2 9
// Ư���� ���� �������� ū ���ڿ� ���� ���ڸ� ������ ���?
// pivot : ���� ��
// 3 7 8 1 5 9 6 10 2 4 (pivot : 3)
// ���� ���� 3���� ū ��, ������ ���� 3���� ���� �� ã��
// 3 2 8 1 5 9 6 10 7 4 (pivot : 3) 
// 3 2 1 8 5 9 6 10 7 4 (pivot : 3)
// ���� ���� �ε����� ū ���� �ε��� ���� �۴�
// 1 2 3 8 5 9 6 10 7 4 (pivot : 1,8)
// 1 2 3 8 5 9 6 10 7 4 (pivot : 2,8)
// 1 2 3 8 5 9 6 10 7 4 (pivot : 8)
// 1 2 3 8 5 4 6 10 7 9 (pivot : 8)
// 1 2 3 8 5 4 6 7 10 9 (pivot : 8)
// 1 2 3 7 5 4 6 8 10 9 (pivot : 7,10)
// ...
// 1 2 3 4 5 => 5*5 = 25
// 6 7 8 9 10 => 5*5 = 25
// �� 50�� ���� 
// �־��� ��� O(N^2) �̴� => �̹� ������ �Ǿ��ִ� ��� 
#include <stdio.h>

int number = 10;
int data[10] = {1,10,5,8,7,6,4,3,2,9};
void quickSort(int *data, int start, int end){
	if (start >= end){//���Ұ� �Ѱ��� ���
		return; 
	}
	int key = start;//Ű�� ù��° ����
	int i = start+1;
	int j = end;
	int temp;
	while(i<=j){//������ ������ �ݺ�
		while(data[i] <= data[key]){//Ű ������ ū ���� ���� �� ���� 
			//�������� ������ ���ؼ��� data[i] >= data[key] 
			i++;
		} 
		while(data[j] >= data[key] && j > start){//Ű ������ ���� ���� ���� �� ����
			//�������� ������ ���ؼ��� data[j] <= data[key] && j > start 
			j--;
		}
		if(i > j){//���� ������ ���¸� Ű ���� ��ü
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;	
		} else{
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		} 
	}
	quickSort(data, start, j-1);
	quickSort(data, j+1, end);
	 
}
int main(void){
	quickSort(data,0,number-1);
	for(int i=0;i<number;i++){
		printf("%d ", data[i]);	
	}
}  
