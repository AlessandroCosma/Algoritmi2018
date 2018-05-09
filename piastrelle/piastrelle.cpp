#include <iostream>
#include <fstream>

using namespace std;

ofstream out;

void componi(int spazio, string precedente, string p) {

	if(spazio == 0){
		out << precedente + p + "\n";
		return;
	}
	
	precedente = precedente + p;
	componi(spazio-1, precedente, "[O]");
	
	if(spazio>1)
		componi(spazio-2, precedente, "[OOOO]");
	
		
	return;
}

int main() 
{
	ifstream in;
	in.open("input.txt", ios::in);
	
	int N;
	in >> N;

	out.open("output.txt", ios::out);
	
	componi(N,"","");


    return 0;
}

