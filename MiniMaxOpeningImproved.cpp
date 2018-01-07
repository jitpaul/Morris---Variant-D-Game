#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;


/* Returns true if the board state/ board position is a close mill. False otherwise*/
bool closeMill(vector <string> board, int pos) {
	switch (pos) {
	case 0: {
		if ((board[1] == board[0] && board[2] == board[0]) || (board[3] == board[0] && board[6] == board[0]) || (board[8] == board[0] && board[20] == board[0])) return true;
		else return false; }
	case 1: {
		if ((board[0] == board[1] && board[2] == board[1])) return true;
		else return false; }
	case 2: {
		if ((board[0] == board[2] && board[1] == board[2]) || (board[5] == board[2] && board[7] == board[2]) || (board[13] == board[2] && board[22] == board[2])) return true;
		else return false; }
	case 3: {
		if ((board[0] == board[3] && board[6] == board[3]) || (board[4] == board[3] && board[5] == board[3]) || (board[9] == board[3] && board[17] == board[3])) return true;
		else return false; }
	case 4: {
		if ((board[3] == board[4] && board[5] == board[4])) return true;
		else return false; }
	case 5: {
		if ((board[2] == board[5] && board[7] == board[5]) || (board[3] == board[5] && board[4] == board[5]) || (board[12] == board[5] && board[19] == board[5])) return true;
		else return false; }
	case 6: {
		if ((board[0] == board[6] && board[3] == board[6]) || (board[10] == board[6] && board[14] == board[6])) return true;
		else return false; }
	case 7: {
		if ((board[2] == board[7] && board[5] == board[7]) || (board[11] == board[7] && board[16] == board[7])) return true;
		else return false; }
	case 8: {
		if ((board[0] == board[8] && board[20] == board[8]) || (board[9] == board[8] && board[10] == board[8])) return true;
		else return false; }
	case 9: {
		if ((board[8] == board[9] && board[10] == board[9]) || (board[3] == board[9] && board[17] == board[9])) return true;
		else return false; }
	case 10: {
		if ((board[8] == board[10] && board[9] == board[10]) || (board[6] == board[10] && board[14] == board[10])) return true;
		else return false; }
	case 11: {
		if ((board[7] == board[11] && board[16] == board[11]) || (board[12] == board[11] && board[13] == board[11])) return true;
		else return false; }
	case 12: {
		if ((board[11] == board[12] && board[13] == board[12]) || (board[5] == board[12] && board[19] == board[12])) return true;
		else return false; }
	case 13: {
		if ((board[11] == board[13] && board[12] == board[13]) || (board[2] == board[13] && board[22] == board[13])) return true;
		else return false; }
	case 14: {
		if ((board[6] == board[14] && board[10] == board[14]) || (board[15] == board[14] && board[16] == board[14]) || (board[17] == board[14] && board[20] == board[14])) return true;
		else return false; }
	case 15: {
		if ((board[14] == board[15] && board[16] == board[15]) || (board[18] == board[15] && board[21] == board[15])) return true;
		else return false; }
	case 16: {
		if ((board[14] == board[16] && board[15] == board[16]) || (board[19] == board[16] && board[22] == board[16]) || (board[7] == board[16] && board[11] == board[16])) return true;
		else return false; }
	case 17: {
		if ((board[3] == board[17] && board[9] == board[17]) || (board[18] == board[17] && board[19] == board[17]) || (board[14] == board[17] && board[20] == board[17])) return true;
		else return false; }
	case 18: {
		if ((board[15] == board[18] && board[21] == board[18]) || (board[17] == board[18] && board[19] == board[18])) return true;
		else return false; }
	case 19: {
		if ((board[17] == board[19] && board[18] == board[19]) || (board[5] == board[19] && board[12] == board[19]) || (board[16] == board[19] && board[22] == board[19])) return true;
		else return false; }
	case 20: {
		if ((board[0] == board[20] && board[8] == board[20]) || (board[21] == board[20] && board[22] == board[20]) || (board[14] == board[20] && board[17] == board[20])) return true;
		else return false; }
	case 21: {
		if ((board[20] == board[21] && board[22] == board[21]) || (board[15] == board[21] && board[18] == board[21])) return true;
		else return false; }
	case 22: {
		if ((board[20] == board[22] && board[21] == board[22]) || (board[16] == board[22] && board[19] == board[22]) || (board[2] == board[22] && board[13] == board[22])) return true;
		else return false; }
	default:
		return false;}}


vector <int> neighbours(int i) {
	switch (i) {
	case 0:
		return { 1,3,8 };
	case 1:
		return { 0,2,4 };
	case 2:
		return { 1,5,13 };
	case 3:
		return { 0,4,6,9 };
	case 4:
		return { 1,3,5 };
	case 5:
		return { 2,4,7,12 };
	case 6:
		return { 3,7,10 };
	case 7:
		return { 5,6,11 };
	case 8:
		return { 0,9,20 };
	case 9:
		return { 3,8,10,17 };
	case 10:
		return { 6,9,14 };
	case 11:
		return { 7,12,16 };
	case 12:
		return { 5,11,13,19 };
	case 13:
		return { 2,12,22 };
	case 14:
		return { 10,15,17 };
	case 15:
		return { 14,16,18 };
	case 16:
		return { 11,15,19 };
	case 17:
		return { 9,14,18,20 };
	case 18:
		return { 15,17,19,21 };
	case 19:
		return { 12,16,18,22 };
	case 20:
		return { 8,17,21 };
	case 21:
		return { 18,20,22 };
	case 22:
		return { 13,19,21 };
	default:
		return {};}}

/* Returns the number of potential close mills for the location specified. */
int potentialCloseMillCount(vector <string> board, int location){
    int ret =0;
    switch (location) {
	case 0: {
		if ((board[1] == board[0] && board[2] != board[0]) || (board[1] != board[0] && board[2] == board[0]))
		    ret++;		
		if ((board[3] == board[0] && board[6] != board[0]) || (board[3] != board[0] && board[6] == board[0]))
		    ret++;
		if ((board[8] == board[0] && board[20] != board[0])|| (board[8] != board[0] && board[20] == board[0]))
		    ret++;}
	case 1: {
		if ((board[0] == board[1] && board[2] != board[1]) ||(board[0] != board[1] && board[2] == board[1]))
		    ret++; }
	case 2: {
		if ((board[0] == board[2] && board[1] != board[2]) || (board[0] != board[2] && board[1] == board[2])) 
		    ret++;
		if ((board[5] == board[2] && board[7] != board[2]) || (board[5] != board[2] && board[7] == board[2])) 
		    ret++;
		if ((board[13] == board[2] && board[22] != board[2]) || (board[13] != board[2] && board[22] == board[2]) ) 
		    ret++;}
	case 3: {
		if ((board[0] == board[3] && board[6] != board[3]) || (board[0] != board[3] && board[6] == board[3]) )
		    ret++;
		if ((board[4] == board[3] && board[5] != board[3]) || (board[4] != board[3] && board[5] == board[3]) )
		    ret++;
		if ((board[9] == board[3] && board[17] != board[3]) || (board[9] != board[3] && board[17] == board[3]))
		    ret++;}
	case 4: {
		if ((board[3] == board[4] && board[5] != board[4]) || (board[3] != board[4] && board[5] == board[4]) )
		    ret++; }
	case 5: {
		if ((board[2] == board[5] && board[7] != board[5]) || (board[2] != board[5] && board[7] == board[5]) )
		    ret++;
		if ((board[3] == board[5] && board[4] != board[5]) || (board[3] != board[5] && board[4] == board[5]))
		    ret++;
		if ((board[12] == board[5] && board[19] != board[5]) || (board[12] != board[5] && board[19] == board[5]))
		    ret++;}
	case 6: {
		if ((board[0] == board[6] && board[3] != board[6]) || (board[0] != board[6] && board[3] == board[6]))
		    ret++;
		if ((board[10] == board[6] && board[14] != board[6]) || (board[10] != board[6] && board[14] == board[6]))
		    ret++;}
	case 7: {
		if ((board[2] == board[7] && board[5] != board[7]) || (board[2] != board[7] && board[5] == board[7]) )
		    ret++;
		if ((board[11] == board[7] && board[16] != board[7]) || (board[11] != board[7] && board[16] == board[7]) )
		    ret++;}
	case 8: {
		if ((board[0] == board[8] && board[20] != board[8]) || (board[0] != board[8] && board[20] == board[8])) 
		    ret++;
		if ((board[9] == board[8] && board[10] != board[8]) || (board[9] != board[8] && board[10] == board[8])) 
		    ret++;}
	case 9: {
		if ((board[8] == board[9] && board[10] != board[9]) || (board[8] != board[9] && board[10] == board[9]))
		    ret++;
		if ((board[3] == board[9] && board[17] != board[9]) || (board[3] != board[9] && board[17] == board[9]))
		    ret++;}
	case 10: {
		if ((board[8] == board[10] && board[9] != board[10]) || (board[8] != board[10] && board[9] == board[10]))
		    ret++;
		if ((board[6] == board[10] && board[14] != board[10]) || (board[6] != board[10] && board[14] == board[10]))
		    ret++;}
	case 11: {
		if ((board[7] == board[11] && board[16] != board[11]) || (board[7] != board[11] && board[16] == board[11]))
		    ret++;
		if((board[12] == board[11] && board[13] != board[11]) || (board[12] != board[11] && board[13] == board[11]))
		    ret++;}
	case 12: {
		if ((board[11] == board[12] && board[13] != board[12]) || (board[11] != board[12] && board[13] == board[12]))
		    ret++;
		if ((board[5] == board[12] && board[19] != board[12]) || (board[5] != board[12] && board[19] == board[12]))
		    ret++;}
	case 13: {
		if ((board[11] == board[13] && board[12] != board[13]) || (board[11] != board[13] && board[12] == board[13]) )
		if ((board[2] == board[13] && board[22] != board[13]) || (board[2] != board[13] && board[22] == board[13]))
		    ret++;}
	case 14: {
		if ((board[6] == board[14] && board[10] != board[14]) || (board[6] != board[14] && board[10] == board[14]) )
		    ret++;
		if ((board[15] == board[14] && board[16] != board[14]) || (board[15] != board[14] && board[16] == board[14])) 
		    ret++;
		if ((board[17] == board[14] && board[20] != board[14]) || (board[17] != board[14] && board[20] == board[14]))
		    ret++;}
	case 15: {
		if ((board[14] == board[15] && board[16] != board[15]) || (board[14] != board[15] && board[16] == board[15]) )
            ret++;		
		if ((board[18] == board[15] && board[21] != board[15]) || (board[18] != board[15] && board[21] == board[15]) )
		    ret++;}
	case 16: {
		if ((board[14] == board[16] && board[15] != board[16]) || (board[14] != board[16] && board[15] == board[16]))
		    ret++;
		if ((board[19] == board[16] && board[22] != board[16]) || (board[19] != board[16] && board[22] == board[16]) )
            ret++;		
		if ((board[7] == board[16] && board[11] != board[16]) || (board[7] != board[16] && board[11] == board[16]))
		    ret++;}
	case 17: {
		if ((board[3] == board[17] && board[9] != board[17]) || (board[3] != board[17] && board[9] == board[17]))
		    ret++;
		if ((board[18] == board[17] && board[19] != board[17]) || (board[18] != board[17] && board[19] == board[17]) )
		    ret++;
		if ((board[14] == board[17] && board[20] != board[17]) || (board[14] != board[17] && board[20] == board[17]))
		    ret++;}
	case 18: {
		if ((board[15] == board[18] && board[21] != board[18]) || (board[15] != board[18] && board[21] == board[18]))
		    ret++;
		if ((board[17] == board[18] && board[19] != board[18]) || (board[17] != board[18] && board[19] == board[18]))
		    ret++; }
	case 19: {
		if ((board[17] == board[19] && board[18] != board[19]) || (board[17] != board[19] && board[18] == board[19]))
		    ret++;
		if ((board[5] == board[19] && board[12] != board[19])  || (board[5] != board[19] && board[12] == board[19])) 
		    ret++;
		if ((board[16] == board[19] && board[22] != board[19]) || (board[16] != board[19] && board[22] == board[19]))
		    ret++; }
	case 20: {
		if ((board[0] == board[20] && board[8] != board[20]) || (board[0] != board[20] && board[8] == board[20]))
		    ret++;
		if ((board[21] == board[20] && board[22] != board[20]) || (board[21] != board[20] && board[22] == board[20])) 
		    ret++;
		if ((board[14] == board[20] && board[17] != board[20]) || (board[14] != board[20] && board[17] == board[20]))
		    ret++;}
	case 21: {
		if ((board[20] == board[21] && board[22] != board[21]) || (board[20] != board[21] && board[22] == board[21]))
		    ret++;
		if ((board[15] == board[21] && board[18] != board[21]) || (board[15] != board[21] && board[18] == board[21]))
		    ret++;}
	case 22: {
		if ((board[20] == board[22] && board[21] != board[22]) || (board[20] != board[22] && board[21] == board[22]))
		    ret++;
		if ((board[16] == board[22] && board[19] != board[22]) || (board[16] != board[22] && board[19] == board[22]))
		    ret++;
		if ((board[2] == board[22] && board[13] != board[22]) || (board[2] != board[22] && board[13] == board[22]))
		    ret++; }
	default:
	return ret;}}


/* Returns the total number of close mills for the location specified. */
int totalCloseMillCount(vector <string> board, int location){
    int ret =0;
    switch (location) {
	case 0: {
		if ((board[1] == board[0] && board[2] == board[0]))
		    ret++;		
		if ((board[3] == board[0] && board[6] == board[0]))
		    ret++;
		if ((board[8] == board[0] && board[20] == board[0]))
		    ret++;}
	case 1: {
		if ((board[0] == board[1] && board[2] == board[1]))
		    ret++; }
	case 2: {
		if ((board[0] == board[2] && board[1] == board[2])) 
		    ret++;
		if ((board[5] == board[2] && board[7] == board[2])) 
		    ret++;
		if ((board[13] == board[2] && board[22] == board[2])) 
		    ret++;}
	case 3: {
		if ((board[0] == board[3] && board[6] == board[3]))
		    ret++;
		if ((board[4] == board[3] && board[5] == board[3]))
		    ret++;
		if ((board[9] == board[3] && board[17] == board[3]))
		    ret++;}
	case 4: {
		if ((board[3] == board[4] && board[5] == board[4]))
		    ret++; }
	case 5: {
		if ((board[2] == board[5] && board[7] == board[5]))
		    ret++;
		if ((board[3] == board[5] && board[4] == board[5]))
		    ret++;
		if ((board[12] == board[5] && board[19] == board[5]))
		    ret++;}
	case 6: {
		if ((board[0] == board[6] && board[3] == board[6]))
		    ret++;
		if ((board[10] == board[6] && board[14] == board[6]))
		    ret++;}
	case 7: {
		if ((board[2] == board[7] && board[5] == board[7]))
		    ret++;
		if ((board[11] == board[7] && board[16] == board[7]))
		    ret++;}
	case 8: {
		if ((board[0] == board[8] && board[20] == board[8])) 
		    ret++;
		if ((board[9] == board[8] && board[10] == board[8])) 
		    ret++;}
	case 9: {
		if ((board[8] == board[9] && board[10] == board[9]))
		    ret++;
		if ((board[3] == board[9] && board[17] == board[9]))
		    ret++;}
	case 10: {
		if ((board[8] == board[10] && board[9] == board[10]))
		    ret++;
		if ((board[6] == board[10] && board[14] == board[10]))
		    ret++;}
	case 11: {
		if ((board[7] == board[11] && board[16] == board[11]))
		    ret++;
		if((board[12] == board[11] && board[13] == board[11]))
		    ret++;}
	case 12: {
		if ((board[11] == board[12] && board[13] == board[12]))
		    ret++;
		if ((board[5] == board[12] && board[19] == board[12]))
		    ret++;}
	case 13: {
		if ((board[11] == board[13] && board[12] == board[13]))
		if ((board[2] == board[13] && board[22] == board[13]))
		    ret++;}
	case 14: {
		if ((board[6] == board[14] && board[10] == board[14]))
		    ret++;
		if ((board[15] == board[14] && board[16] == board[14])) 
		    ret++;
		if ((board[17] == board[14] && board[20] == board[14]))
		    ret++;}
	case 15: {
		if ((board[14] == board[15] && board[16] == board[15]))
            ret++;		
		if ((board[18] == board[15] && board[21] == board[15]))
		    ret++;}
	case 16: {
		if ((board[14] == board[16] && board[15] == board[16]))
		    ret++;
		if ((board[19] == board[16] && board[22] == board[16]))
            ret++;		
		if ((board[7] == board[16] && board[11] == board[16]))
		    ret++;}
	case 17: {
		if ((board[3] == board[17] && board[9] == board[17]))
		    ret++;
		if ((board[18] == board[17] && board[19] == board[17]))
		    ret++;
		if ((board[14] == board[17] && board[20] == board[17]))
		    ret++;}
	case 18: {
		if ((board[15] == board[18] && board[21] == board[18]))
		    ret++;
		if ((board[17] == board[18] && board[19] == board[18]))
		    ret++; }
	case 19: {
		if ((board[17] == board[19] && board[18] == board[19]))
		    ret++;
		if ((board[5] == board[19] && board[12] == board[19])) 
		    ret++;
		if ((board[16] == board[19] && board[22] == board[19]))
		    ret++; }
	case 20: {
		if ((board[0] == board[20] && board[8] == board[20]))
		    ret++;
		if ((board[21] == board[20] && board[22] == board[20])) 
		    ret++;
		if ((board[14] == board[20] && board[17] == board[20]))
		    ret++;}
	case 21: {
		if ((board[20] == board[21] && board[22] == board[21]))
		    ret++;
		if ((board[15] == board[21] && board[18] == board[21]))
		    ret++;}
	case 22: {
		if ((board[20] == board[22] && board[21] == board[22]))
		    ret++;
		if ((board[16] == board[22] && board[19] == board[22]))
		    ret++;
		if ((board[2] == board[22] && board[13] == board[22]))
		    ret++; }
	default:
	return ret;}}


int totalEvaluated = 0;

/* Returns the static estimate for the board state/ board position */
int evaluate(vector <string> board) {
	totalEvaluated++;
	int white = 0, black = 0, pCloseMills = 0, noOfOpponentBlocked = 0, totalCloseMills = 0;
	for (int i = 0; i < board.size(); i++) {
		if (board[i] == "W") {
			pCloseMills += potentialCloseMillCount(board,i);
			totalCloseMills += totalCloseMillCount(board,i);
			white++;}
		else if (board[i] == "B")
	        black++;}
    //pCloseMills is divided by two because it is double counted (once by each piece in the potential close mill).
	//totalCloseMills is divided by three because it is triple counted (once by each piece in the close mill).
	return ((3 * pCloseMills/2) + totalCloseMills/3 + 5*(white - black));} 


struct Node {
	int miniMaxEstimate;
	vector <string> board;
	Node(int x, vector <string> board) : miniMaxEstimate(x), board(board) {}};


/* Determines the next best move. Recursively traverse the tree upto the specified
depth, calls evaluate() for the board positions at that depth
and returns the one with the best static estimate.*/
Node* miniMax(vector <string> board, int flag, int depth) {
	if (depth == 0)
		return new Node(evaluate(board), board);
	// minimizer
	if (flag == 0) {
		int ret = 100000;
		Node* temp;
		vector <string> bestBoard = board;
		for (int i = 0; i < board.size(); i++) {
			if (board[i] == "x") {
				board[i] = "B";
				if (closeMill(board, i)) {
					for (int i = 0; i < board.size(); i++) {
						if (board[i] == "W" && !closeMill(board, i)) {
							board[i] = "x";
							temp = miniMax(board, 1, depth - 1);
							if (temp->miniMaxEstimate < ret) {
								bestBoard = board;
								ret = temp->miniMaxEstimate;}
							board[i] = "W";}}}
				else {
					temp = miniMax(board, 1, depth - 1);
					if (temp->miniMaxEstimate < ret) {
						bestBoard = board;
						ret = temp->miniMaxEstimate;}}
				board[i] = "x";}}
		return new Node(ret, bestBoard);}
	// maximizer
	else {
		Node * temp;
		int ret = -100000;
		vector <string> bestBoard = board;
		for (int i = 0; i < board.size(); i++) {
			if (board[i] == "x") {
				board[i] = "W";
				if (closeMill(board, i)) {
					for (int i = 0; i < board.size(); i++) {
						if (board[i] == "B" && !closeMill(board, i)) {
							board[i] = "x";
							temp = miniMax(board, 0, depth - 1);
							if (temp->miniMaxEstimate > ret) {
								bestBoard = board;
								ret = temp->miniMaxEstimate;}
							board[i] = "B";}}}
				else {
					temp = miniMax(board, 0, depth - 1);
					if (temp->miniMaxEstimate > ret) {
						bestBoard = board;
						ret = temp->miniMaxEstimate;}}
				board[i] = "x";}}
		return new Node(ret, bestBoard);}}


int main(int argc, char *argv[]) {

	/* Check if the number of arguments are correct.*/
	if (argc != 4) {
		cerr << "Incorrect number of Arguments. " << endl;
		exit(1);}

	/* Open file for reading. Throw error if the input file cannot be opened.*/
	string board1, tp1;
	vector <string> array;
	ifstream ifs(argv[1]);
	if (!ifs) {
		// Print an error and exit.
		cerr << argv[1] << " could not be opened for reading!" << endl;
		exit(1);}

	/* Read from the input file and store the contents in a vector<string>.*/
	getline(ifs, board1);
	int totalWhiteCount = 0, totalBlackCount = 0;
	for (int i = 0; i < board1.size(); i++) {
		tp1 = board1[i];
		if (tp1 == "W")
			totalWhiteCount++;
		array.push_back(tp1);}
	ifs.close();

	/* Find the next best move only if the total number of whites on the board is less than 9 */
	Node* retNode;
	if (totalWhiteCount < 9)
		retNode = miniMax(array, 1, stoi(argv[3]));

	/* Open file for writing. Throw error if the output file cannot be opened.*/
	ofstream ofs(argv[2]);
	if (!ofs) {
		// Print an error and exit
		cerr << argv[1] << " could not be opened for writing!" << endl;
		exit(1);}

	/* Write to the output file.*/
	string board2 = "";
	for (string tp : retNode->board)
		board2.append(tp);
	ofs << board2;
	ofs.close();

	/* Print the results into the console.*/
	cout << "Board Position: " << board2 << endl;
	cout << "Positions evaluated by static estimation: " << totalEvaluated << endl;
	cout << "MINIMAX estimate: " << retNode->miniMaxEstimate << endl;
	getchar();
	return 0;}