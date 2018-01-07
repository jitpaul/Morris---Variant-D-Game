#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;


int totalEvaluated = 0;


/* Returns the static estimate for the board state/ board position */
int evaluate(vector <string> board) {
	totalEvaluated++;
	int whitePieces = 0, blackPieces = 0;
	for (int i = 0; i < board.size(); i++) {
		if (board[i] == "W")
			whitePieces++;
		else if (board[i] == "B")
			blackPieces++;}
	return (whitePieces - blackPieces);}


/* Returns true if the location forms a close mill with any of its neighbours. False otherwise*/
bool closeMill(vector <string> board, int location) {
	switch (location) {
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


struct Node {
	int miniMaxEstimate;
	vector <string> board;
	Node(int x, vector <string> board) : miniMaxEstimate(x), board(board) {}};


/* Determines the next best move. Recursively traverse the tree upto the specified
depth, calls evaluate() for the board positions at that depth
and returns the one with the best static estimate.*/
Node* miniMax(vector <string> board, int flag, int depth, int alpha, int beta) {
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
							temp = miniMax(board, 1, depth - 1, alpha, beta);
							if (temp->miniMaxEstimate < ret) {
								bestBoard = board;
								ret = temp->miniMaxEstimate;}
							if (ret <= alpha)
								return new Node(ret, board);
							beta = min(beta, ret);
							board[i] = "W";}}}
				else {
					temp = miniMax(board, 1, depth - 1, alpha, beta);
					if (temp->miniMaxEstimate < ret) {
						bestBoard = board;
						ret = temp->miniMaxEstimate;}
					if (ret <= alpha)
						return new Node(ret, board);
					beta = min(beta, ret);}
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
							temp = miniMax(board, 0, depth - 1, alpha, beta);
							if (temp->miniMaxEstimate > ret) {
								bestBoard = board;
								ret = temp->miniMaxEstimate;}
							if (ret >= beta)
								return new Node(ret, board);
							alpha = max(alpha, ret);
							board[i] = "B";}}}
				else {
					temp = miniMax(board, 0, depth - 1, alpha, beta);
					if (temp->miniMaxEstimate > ret) {
						bestBoard = board;
						ret = temp->miniMaxEstimate;}
					if (ret >= beta)
						return new Node(ret, board);
					alpha = max(alpha, ret);}
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
		retNode = miniMax(array, 1, stoi(argv[3]), -100000, 100000);

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