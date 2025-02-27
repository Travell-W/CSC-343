// MemoryManage.cpp

#include <iostream>
#include <cmath>
using namespace std;

class process {
public:
	int ID;
	int address;
	int size;
	int unused;
	double page;
	int pages;
	int bytes;
	
};
void userMemoryAllocation(process ary[]) {
for (int i = 0; i < 100; ++i) {
		ary[i].ID = i;
		ary[i].size = ((rand() % 30 )+ 1) * 80;
		ary[i].pages = ceil((double)ary[i].size/160);
		ary[i].bytes = ary[i].pages * 160;
		ary[i].unused = ary[i].bytes - ary[i].size;

		if (i == 0) {
			ary[i].address = 2000;
		}
		else {
			ary[i].address = ary[i-1].address + ary[i].bytes;
		}

	}
}

int main()
{
	process arry[100];
	srand(time(0));
	int start = 2000;
	userMemoryAllocation(arry);
	
	cout << "Process ID		Starting Memory Address		Size of the Process MB		Unused Space MG" << endl;
	for (int i = 0; i < 100; ++i) {
		cout << arry[i].ID << "				" << arry[i].address << "				" << arry[i].size << "				" << arry[i].bytes << endl;
	}
	return 0;
}



