#include <iostream>
using namespace std;

class process {
public:
	int start;
	int end;
	int turn;
};

void averageWT(process one, process two, process three, process four, process five) {
	double wt;
	wt = (one.start + two.start + three.start + four.start + five.start)/5.0;
	cout << "Average wait time: " << wt << " ms" << endl;
}

int main() {

//FCFS:
	process P1;
	P1.start = 0;
	P1.end = 2;
	P1.turn = P1.end - P1.start;
	process P2;
	P2.start = 2;
	P2.end = 3;
	P2.turn = P2.end - P2.start;
	process P3;
	P3.start = 3;
	P3.end = 11;
	P3.turn = P3.end - P3.start;
	process P4;
	P4.start = 11;
	P4.end = 15;
	P4.turn = P4.end - P4.start;
	process P5;
	P5.start = 15;
	P5.end = 20;
	P5.turn = P5.end - P5.start;

	cout << "FCFS:" << endl;
	cout << "Process ID | Waiting Time | Turnaround Time" << endl;
	cout << "     1     |       " << P1.start << "      |        " << P1.turn << endl;
	cout << "     2     |       " << P2.start << "      |        " << P2.turn << endl;
	cout << "     3     |       " << P3.start << "      |        " << P3.turn << endl;
	cout << "     4     |       " << P4.start << "     |        " << P4.turn << endl;
	cout << "     5     |       " << P5.start << "     |        " << P5.turn << endl;
	averageWT(P1,P2,P3,P4,P5);
	cout << endl;
	//SJF:

	P1.start = 1;
	P1.end = 3;
	P1.turn = P1.end - P1.start;
	
	P2.start = 0;
	P2.end = 1;
	P2.turn = P2.end - P2.start;
	
	P3.start = 12;
	P3.end = 20;
	P3.turn = P3.end - P3.start;
	
	P4.start = 3;
	P4.end = 7;
	P4.turn = P4.end - P4.start;
	
	P5.start = 7;
	P5.end = 12;
	P5.turn = P5.end - P5.start;

	cout << "SJF:" << endl;
	cout << "Process ID | Waiting Time | Turnaround Time" << endl;
	cout << "     1     |       " << P1.start << "      |        " << P1.turn << endl;
	cout << "     2     |       " << P2.start << "      |        " << P2.turn << endl;
	cout << "     3     |       " << P3.start << "     |        " << P3.turn << endl;
	cout << "     4     |       " << P4.start << "      |        " << P4.turn << endl;
	cout << "     5     |       " << P5.start << "      |        " << P5.turn << endl;
	averageWT(P1, P2, P3, P4, P5);

	return 0;
}
