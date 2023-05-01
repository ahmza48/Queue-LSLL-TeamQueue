#include <iostream>
#include "Queue.h"
#include "Node.h"

using namespace std;

int index(int **arr, int row, int col, int elem) {
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (elem == arr[i][j]) {
				return i;
			}
		}
	}
	return -1;
}

int main() {
	//Queue<int> q;
	//q.Enqueue(1);
	//q.Enqueue(2);
	//q.Enqueue(3);
	//q.Enqueue(4);
	//cout << "BEFROE DEQUEUE:" << endl;
	//q.print();
	//cout << endl;

	//q.Dequeue();
	//cout << "AFTER DEQUEUE:" << endl;
	//q.print();
	//cout << endl;

	int teams;
	cout << "How Many Teams?" << endl;
	cin >> teams;
	while (teams < 0 || teams>1000)
	{
		cout << "Enter Valid Number of Teams" << endl;
		cin >> teams;
	}
	int Mem;
	int** teamArr = new int*[teams];
	for (int i = 0; i < teams; i++)
	{
		int members;
		cout << "How many members are in team: " << i + 1 << " ?" << endl;
		cin >> members;
		Mem = members;
		teamArr[i] = new int[members];
		cout << "Enter Members of the team: " << i + 1 << " " << endl;

		for (int j = 0; j < members; j++)
		{
			cin >> teamArr[i][j];
		}
	}

	//cout << "Teams and members are: " << endl;
	//for (int i = 0; i < teams; i++)
	//{
	//	for (int j = 0; j < Mem; j++)
	//	{
	//		cout << teamArr[i][j];
	//	}
	//	cout << endl;
	//}

	//Queue<int>* arr = new Queue<int>[teams];
	cout << endl;
	int t;
	int scenarios = 0;
	do
	{
		cout << "				Scenario # " << scenarios + 1 << endl;
		cout << endl;
		cout << "Enter the number of teams: " << endl;
		cin >> t;
		if (t != 0)
		{
			/*int scenarios = t;*/
			Queue<int>** arr = new Queue<int>*[t];
			for (int l = 0; l < t; l++)
			{
				arr[l] = new Queue<int>[t];
			}
			Queue<int> *infoArr = new Queue<int>[t];

			for (int i = 0; i < t; i++)
			{
				infoArr[i].Enqueue(-1);
			}
			cout << endl;
			int choice;
		
			do
			{
				//cout << "				Scenario # " << scenarios + 1 << endl;
				cout << "For Enqueue press 1." << endl;
				cout << "For Dequeue press 2." << endl;
				cout << "To Stop the test case press 3" << endl;
				cout << "Enter your choice" << endl;
				cin >> choice;
				if (choice == 1)
				{
					int elem;
					int ind;
					cout << "Enter element you want to enter: " << endl;
					cin >> elem;
					ind = index(teamArr, teams, Mem, elem);
					if (ind != -1) {
						arr[ind]->Enqueue(elem);
						int size = infoArr->sizeOfQueue();
						if (size <= t) {
							if (infoArr->peek() == -1) {
								infoArr->emptyQueue();
								infoArr->Enqueue(ind);
							}
							else {
								infoArr->Enqueue(ind);
							}
						}

					}
					else{
						cout << "					Member Doesn't Match the Team!" << endl;
					}
				}
				if (choice == 2)
				{
					int teamInfo;
					teamInfo = infoArr->peek();
					if (teamInfo == -1)
					{
						cout << "No Elements Present" << endl;
						continue;
						/*break;*/
					}
					int teamElem;
					teamElem = arr[teamInfo]->peek();
					if (teamElem == -999)
					{
						infoArr->Dequeue();
						cout << "LIST GOT EMPTY." << endl;
						infoArr->Enqueue(-1);
					}
					else {
						cout << teamElem << endl;
						arr[teamInfo]->Dequeue();
					}
					
					
					//do
					//{
					//	teamElem = arr[teamInfo]->peek();
					//	if (teamElem == -999) {
					//		break;
					//	}
					//	cout << teamElem << endl;
					//	arr[teamInfo]->Dequeue();
					//	/*if (teamElem != -999)
					//	{
					//		teamElem = arr[teamInfo]->peek();
					//		cout << teamElem << endl;
					//		arr[teamInfo]->Dequeue();
					//	}*/

					//} while (teamElem != -999);
					//
					//infoArr->Dequeue();

				}

			} while (choice > 0 && choice < 3);


		}
		cout << "---------------------------------------------------------------------------" << endl;
		scenarios++;
		cout << endl;
		/*cout << "Enter the number of teams: " << endl;
		cin >> t;*/
	} while (t != 0);

	//Queue<int> arr[3];
	//arr[0].Enqueue(101);
	//arr[0].Enqueue(102);
	//arr[0].Enqueue(103);
	//arr[1].Enqueue(202);
	//arr[1].Enqueue(203);
	//arr[1].Enqueue(204);
	//arr[2].Enqueue(301);
	//arr[2].Enqueue(302);
	//arr[2].Enqueue(303);
	//for (int i = 0; i < 3; i++)
	//{
	//	cout << endl;
	//	arr[i].print();
	//	cout << endl;
	//}

	//int x;
	//ifstream myfile("data.txt");
	//if (myfile.is_open()) {
	//	while (!myfile.eof()) {
	//		myfile >> x;
	//		cout << x << endl;
	//	}
	//	myfile.close();
	//}
	//else {
	//	cout << "Unable to open file";
	//}




	//cout << endl;
	//string line;
	//ifstream myfile("data.txt"); // opening the file
	//if (myfile.is_open()) {
	//	while (getline(myfile, line)) {
	//		cout << line << endl;
	//	}
	//	myfile.close();
	//}
	//else {
	//	cout << "Unable to open file";
	//}
	//

	return 0;
}