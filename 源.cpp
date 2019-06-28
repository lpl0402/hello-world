#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include<vector>
#include<iomanip>
#define MAX 10000
#define MAX2 100
using namespace std;
//文本中以%为->，以#为ε
fstream token, production_txt, prase_table, first_follow, print_result;//分别打开token和产生式的文档

char token_char[MAX] = { '0' };
char production[MAX] = { '0' };
char terminal[MAX2][MAX2] = { "#", ";", "[", "int", "void", "]", "(", ")", ",", "{", "}", "if", "else", "while", "return", "=", "<", ">", "!", "+", "-", "*", "/", "ID", "NUM", "==", "!="};
string unterminal[MAX2];//每个非终结符
string tree[MAX];//存储推导式前面的string
bool judge[MAX];
 int treeNUM = 0;//存储推导式数量
int unterminal_number = 0;//产生式数量
int proce_number[MAX2];//存储每个非终结符有几条产生式




vector<string>first[MAX2];//存放每一个非终结符的first
vector<string>follow[MAX2];//存放每一个非终结符的follow
vector<string>proce[MAX2][MAX2];//每个非终结符的每条产生式
vector<string>first_proc[MAX2][MAX2];//存储每个非终结符每个产生式的first
vector<string> TOKENS;//存储token
vector<string> PraseTable[MAX2][MAX2];//存储预测分析表，二维数组
vector<string>PraseStack;//存储分析栈
vector<string>tree_stack[MAX];//存储推导式后面的字符串
vector<string>final_stack;//洗碗工是最后一个vector，将要输出的依次推入


void OpenSourceFile();
void Proc_Readin();
void First(int i);
void Follow(int i);
bool Isterminal(string temp);
int WhichUnterminal(string temp);
bool IsInFirst(string temp, int a);
bool IsInFollow(string temp, int a);
bool Have_ε(int i);
void write_first_follow();
void Produce_Parse();
int Have_terminal(int a, string temp);
bool Have_follow(int a, string temp);
void Reading_tokens();
int Whichterminal(string temp);
void transTOKENS();
void Tree();
int WhichFinalPop(string temp);


int main() {
	char choose;
	char print_result_char[MAX] = {'0'};
	OpenSourceFile();
	Proc_Readin();
	for (int i = 0; i < unterminal_number; i++) {
		if(first[i].size() == 0)
			First(i);
	}
	for (int i = 0; i < unterminal_number; i++) {
		if(follow[i].size() == 0)
			Follow(i);
	}
	write_first_follow();
	Produce_Parse();
	Reading_tokens();
	transTOKENS();
	token.close();
	production_txt.close();
 	prase_table.close();
	first_follow.close();
	final_stack.push_back(tree[0]);
	cout << "是否打印树？ Y/N" << endl;
	cin >> choose;
	if(choose == 'Y')
		Tree();

	cout << "是否打印FIRST&FOLLOW集合？ Y/N" << endl;
	cin >> choose;
	if (choose == 'Y') {
		print_result.open("FIRST&&FOLLOW.txt", ios::in | ios::binary);
		print_result.read((char *)&print_result_char, sizeof(print_result_char));
		cout << print_result_char << endl;
		print_result.close();
	}
	cout << "是否打印PraseTable? Y/N" << endl;
	cin >> choose;
	if (choose == 'Y') {
		print_result.open("PraseTable.txt", ios::in | ios::binary);
		print_result.read((char *)&print_result_char, sizeof(print_result_char));
		int aa = strlen(print_result_char);
		for (int i = 0; i < aa; i++)
			cout << print_result_char[i];
		cout << endl;
		print_result.close();
	}






	system("pause");
}
void Tree() {
	cout << final_stack[0] << endl;
	final_stack.push_back("eof");
	while (final_stack.size() != 1) {
		string temp = final_stack.front();
		final_stack.erase(final_stack.begin(),  final_stack.begin() + 1);
		if (!Isterminal(temp) && temp != "eof") {
			int a = WhichFinalPop(temp);
			if (a == -1)
				continue;
		for (int i = 0; i < tree_stack[a].size(); i++) {
				cout << tree_stack[a][tree_stack[a].size() - 1 - i] << " ";
				final_stack.push_back(tree_stack[a][tree_stack[a].size() - 1 - i]);
			}
		}
		else if (temp == "eof") {
			cout << endl;
			final_stack.push_back("eof");
		}
	}
}
int WhichFinalPop(string temp) {
	for (int i = 0; i < treeNUM; i++) {
		if (tree[i] == temp && !judge[i]) {
			judge[i] = true;
			return i;
		}
	}
	return -1;
}
void Reading_tokens() {
	token.open("tokens_prase.txt", ios::in | ios::binary);
	if (token.fail()) {
		cout << "tokens_prase.txt打开失败" << endl;
	}
	token.read((char *)&token_char, sizeof(token_char));
	string temp = "";
	int token_lenth = strlen(token_char);
	token_char[token_lenth] = '\n';
	int token_a = 0;
	while (token_a < token_lenth) {
		if (token_char[token_a] != '\r' && token_char[token_a] != '\n') {
			temp += token_char[token_a];
			token_a += 1;
		}
		else if (temp != "") {
			TOKENS.push_back(temp);
			temp = "";
			token_a += 1;
		}
		else
			token_a += 1;
	}
}
void transTOKENS() {
	PraseStack.push_back(unterminal[0]);
	for (int i = 0; i < TOKENS.size();) {
		string temp = PraseStack.back();
		if (!Isterminal(temp)) {
			cout << left << setw(6) << i;
			cout << "$ ";
			for (int j = 0; j < PraseStack.size(); j++)
				cout << PraseStack[j] << " ";
			cout << endl;
			tree[treeNUM] = temp;
			treeNUM += 1;
			PraseStack.pop_back();
			int a = WhichUnterminal(temp);
			int b = Whichterminal(TOKENS[i]);
			for (int j = 0; j < PraseTable[a][b].size(); j++) {
				string temp_stack = PraseTable[a][b][PraseTable[a][b].size() - j - 1];
				tree_stack[treeNUM - 1].push_back(temp_stack);
				if(temp_stack != "ε" && temp_stack != "error")
					PraseStack.push_back(temp_stack);
				else if (temp_stack == "error") {
					cout << "编译代码存在语法错误" << endl << "出错位置在：" << TOKENS[i] << endl;
					return;
				}
			}
		}
		else {
			//将终结符match出去
			if (temp == TOKENS[i]) {
				PraseStack.pop_back();
				i += 1;
			}
			else {
				cout << "编译代码存在语法错误" << endl << "出错位置在：" << TOKENS[i] << endl;
				return;
			}
		}
	}
	cout << endl << endl;
	cout << "ACCEPT！代码没有语法问题" << endl << endl;
}
void OpenSourceFile() {
	production_txt.open("Cminus.txt", ios::in | ios::binary);
	if (production_txt.fail()) {
		cout << "Cminus产生式文本不存在" << endl;
		return;
	}
	production_txt.read((char *)& production, sizeof(production));
	production[strlen(production)] = '\r';
}
void Proc_Readin() {
	int size = strlen(production);
	for (int i = 0; i < size; i++) {
		string temp;
		while (i < size && production[i] != '%' ) {
			temp += production[i];
			i += 1;
		}
		i += 1;//把→略掉
		unterminal[unterminal_number] = temp;
		unterminal_number += 1;
		temp = "";
		int a = 0;//记录有几条产生式
		while (production[i] != '\r') {
			if (production[i] == '|') {
				proce[unterminal_number - 1][a].push_back(temp);
				temp = "";
				a += 1;
			}
			else if (production[i] == ' ') {
				proce[unterminal_number - 1][a].push_back(temp);
				temp = "";
			}
			else {
				temp += production[i];
			}
			i += 1;
		}
		if(temp != "")
			proce[unterminal_number - 1][a].push_back(temp);
		a += 1;
		proce_number[unterminal_number - 1] = a;
		i += 1;//略过\n
	}
}
void First(int i) {
	for (int j = 0; j < proce_number[i]; j++) {
		int k = 0;
		//如果产生式第一个是终结符，则放入first
		if (Isterminal(proce[i][j][k])) {
			if (!IsInFirst(proce[i][j][k], i))
				first_proc[i][j].push_back(proce[i][j][k]);
				first[i].push_back(proce[i][j][k]);
		}
		else if (proce[i][j][k] == "#") {
			//第一个是ε
			first_proc[i][j].push_back("#");
			first[i].push_back("#");
		}
		//是非终结符时
		else {
			//直到有的非终结符没有ε或到最后或遇到终结符
			while (k < proce[i][j].size() && !Isterminal(proce[i][j][k]) ) {
				int a = WhichUnterminal(proce[i][j][k]);
				if(first[a].size() == 0)
					First(a);
				if (!Have_ε(a)) {
					//下一非终结符的first中无ε，直接读入后结束
					for (int b = 0; b < first[a].size(); b++) {
						if (!IsInFirst(first[a][b], i)) {
							first_proc[i][j].push_back(first[a][b]);
							first[i].push_back(first[a][b]);
						}
					}
					break;
				}
				else{
					for (int b = 0; b < first[a].size(); b++) {
						//当非终结符中的终结符在该表达式中没有时
						if (!IsInFirst(first[a][b], i)) {
							if (first[a][b] != "#") {
								first_proc[i][j].push_back(first[a][b]);
								first[i].push_back(first[a][b]);
							}
							//当非终结符中有ε时
							else {
								if (k == proce[i][j].size() - 1) {
									//读到最后一个非终结符时，如果first中没有ε，则放入
									if (!IsInFirst(first[a][b], i)) {
										first_proc[i][j].push_back(first[a][b]);
										first[i].push_back(first[a][b]);
									}
								}
								//不是最后一个，但已经读到了ε，则读入下一个
							}
						}
					}
				}
				k += 1;
			}
			//遇到终结符
			if (k < proce[i][j].size()) {
				if (Isterminal(proce[i][j][k])) {
					//当因为是终结符跳出循环后将终结符放入first集合
					if (!IsInFirst(proce[i][j][k], i)) {
						first_proc[i][j].push_back(proce[i][j][k]);
						first[i].push_back(proce[i][j][k]);
					}
				}
			}
		}
	}
}
void Follow(int xx) {
	if (xx == 0)
		follow[xx].push_back("$");
	//遍历所有非终结符的产生式
	for (int i = 0; i < unterminal_number; i++) {
		if (xx == 29 && i == 25) {
			int mm = 0;
		}
		//遍历每个非终结符的每一条产生式
		for (int j = 0; j < proce_number[i]; j++) {
			for (int k = 0; k < proce[i][j].size(); k++) {
				if (unterminal[xx] == proce[i][j][k]) {
					//后面还有符号
					if (k < proce[i][j].size() - 1) {
						if (Isterminal(proce[i][j][k + 1])) {
							//后面的符号是终结符
							if(!IsInFollow(proce[i][j][k + 1], xx))
								follow[xx].push_back(proce[i][j][k + 1]);
						}
						else {
							//后面的符号是非终结符
							int a = WhichUnterminal(proce[i][j][k + 1]);
							if (follow[a].size() == 0)
								Follow(a);
							if (!Have_ε(a)) {
								//后面的非终结符不含ε
								for (int b = 0; b < first[a].size(); b++) {
									if (!IsInFollow(first[a][b], xx))
										follow[xx].push_back(first[a][b]);
								}
							}
							else {
								//后面的终结符含ε
								int temp_k = k + 1;
								while (temp_k < proce[i][j].size() && Have_ε(a)) {
									for (int b = 0; b < first[a].size(); b++) {
										if (first[a][b] != "#") {
											if (!IsInFollow(first[a][b], xx))
												follow[xx].push_back(first[a][b]);
										}
									}
									temp_k += 1;
									//是终结符
									if (temp_k == proce[i][j].size())//最后一位
										break;
									if (Isterminal(proce[i][j][temp_k])) {
										if (!IsInFollow(proce[i][j][temp_k], xx))
											follow[xx].push_back(proce[i][j][temp_k]);
										break;
									}
									else {
										a = WhichUnterminal(proce[i][j][temp_k]);
										//if (a == -1)
										//	continue;
										if (follow[a].size() == 0)
											Follow(a);
										if (!Have_ε(a)) {
											for (int b = 0; b < first[a].size(); b++) {
												if (!IsInFollow(first[a][b], xx))
													follow[xx].push_back(first[a][b]);
											}
										}
									}
								}
								if (temp_k == proce[i][j].size()) {
									if (follow[i].size() == 0)
										Follow(i);
									for (int b = 0; b < follow[i].size(); b++) {
										if (!IsInFollow(follow[i][b], xx))
											follow[xx].push_back(follow[i][b]);
									}
								}
							}
						}
					}
					else {
						//后面没有符号了
						if (xx == i)
							continue;
						if(follow[i].size() == 0)
							Follow(i);
						for (int b = 0; b < follow[i].size(); b++) {
							if(!IsInFollow(follow[i][b], xx))
							follow[xx].push_back(follow[i][b]);
						}
					}
				}
			}
		}
	}
}
bool Isterminal(string temp) {
	for (int i = 0; i < 26; i++) {
		string temp_compara = terminal[i + 1];
		if (temp == temp_compara)
			return true;
	}
	return false;
}
int WhichUnterminal(string temp) {
	for (int i = 0; i < unterminal_number; i++) {
		if (temp == unterminal[i])
			return i;
	}
//	return -1;
}
//判断该终结符是否已经进入first集合
bool IsInFirst(string temp, int a) {
	for (int i = 0; i < first[a].size(); i++) {
		if (temp == first[a][i])
			return true;
	}
	return false;
}
bool IsInFollow(string temp, int a) {
	for (int i = 0; i < follow[a].size(); i++) {
		if (temp == follow[a][i])
			return true;
	}
	return false;
}
bool Have_ε(int i) {
	//判断first是否有ε
	for (int j = 0; j < first[i].size(); j++) {
		if (first[i][j] == "#")
			return true;
	}
	return false;
}
void write_first_follow() {
	first_follow.open("FIRST&&FOLLOW.txt", ios::out | ios::binary);
	if (first_follow.fail()) {
		cout << "FIRST&&FOLLOW文件不存在" << endl;
	}
	for (int i = 0; i < unterminal_number; i++) {
		first_follow << "Vu:  " + unterminal[i] + "\r\n";
		first_follow << "FIRST: ";
		for (int j = 0; j < first[i].size(); j++) {
			first_follow << first[i][j] << " ";
		}
		first_follow << "\r\n";
		first_follow << "FOLLOW: ";
		for (int j = 0; j < follow[i].size(); j++) {
			first_follow << follow[i][j] << " ";
		}
		first_follow << "\r\n\r\n";
	}
}
void Produce_Parse() {
	prase_table.open("PraseTable.txt", ios::out | ios::binary);
	string ky = " ";
	prase_table << left << setw(40) << ky ; 
	for (int i = 0; i < 26; i++) {
		prase_table << left <<setw(40) << terminal[i + 1] ;
	}
	prase_table<<left  << setw(40) << "$" ;
	prase_table << "\r\n";
	for (int i = 0; i < unterminal_number; i++) {
		prase_table << left << setw(40) << unterminal[i] ;
		if (!Have_ε(i)) {
			//first集合中没有ε
			for (int j = 0; j < 26; j++) {
				string temp = terminal[j + 1];
				int a = Have_terminal(i, temp);
				if (a != -1) {
					//非终结符的first中有该终结符，a为非终结符的哪条产生式
					int temp_strlen = unterminal[i].size() + 4;
					prase_table << unterminal[i] + " -> ";
					for (int b = 0; b < proce[i][a].size(); b++) {
						prase_table << proce[i][a][b] << " ";
						PraseTable[i][j + 1].push_back(proce[i][a][b]);
						temp_strlen = temp_strlen + proce[i][a][b].size() + 1;
					}
					prase_table << setw(40 - temp_strlen) << ky ;
				}
				else {
					//非终结符中无该first
					prase_table << setw(40) << "error" ;
					PraseTable[i][j + 1] .push_back("error");
				}
			}
		}
		else {
			//该非终结符中有ε
			for (int j = 0; j < 26; j++) {
				string temp = terminal[j + 1];
				//判断first中是否有
				int a = Have_terminal(i, temp);
				if (a != -1) {
					//非终结符的first中有该终结符，a为非终结符的哪条产生式
					int temp_strlen = unterminal[i].size() + 4;
					prase_table << unterminal[i] + " -> ";
					for (int b = 0; b < proce[i][a].size(); b++) {
						PraseTable[i][j + 1].push_back(proce[i][a][b]);
						prase_table << proce[i][a][b] << " ";
						temp_strlen = temp_strlen + proce[i][a][b].size() + 1;
					}
					prase_table << setw(40 - temp_strlen) << ky ;
				}
				else {
					//非终结符中无该first
					if (Have_follow(i, temp)) {
						//该终结符在follow中
						int temp_strlen = unterminal[i].size() + 4;
						prase_table << unterminal[i] + " -> " + "ε";
						prase_table << setw(40 - temp_strlen - strlen("ε")) ;
						PraseTable[i][j + 1].push_back("ε");
					}
					else {
						//既不在first也不在follow中
						prase_table << setw(40) << "error" ;
						PraseTable[i][j + 1] .push_back("error");
					}
				}
			}
		}
		prase_table << "\r\n";
	}
}
int Have_terminal(int a, string temp) {
	//判断是非终结符的哪个产生式
	for (int i = 0; i < proce_number[a]; i++) {
		for (int j = 0; j < first_proc[a][i].size(); j++) {
			if (first_proc[a][i][j] == temp) {
				return i;
			}
		}
	}
	return -1;
}
bool Have_follow(int a, string temp){
	//判断follow集合中是否有该终结符
	for (int i = 0; i < follow[a].size(); i++) {
		if (temp == follow[a][i])
			return true;
	}
	return false;
}
int Whichterminal(string temp) {
	for (int i = 0; i < 26; i++) {
		string temp_terminal = terminal[i + 1];
		if (temp == temp_terminal)
			return i + 1;
	}
}