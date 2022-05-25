#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;

//Klash ylopoihshs struct
class Structure{
public:
  int num;
  string string1;
  string string2;
  string string3;
	Structure* p_left;
	Structure* p_rigth;
  //gia na mporesoume na dhmiourgisoume ena array typou class Structure
  //tha prepei na ftiaksoume enan dummy constructor
  Structure(){}
  Structure(int number,string s1,string s2,string s3){
    num=number;
    s1=string1;
    s2=string2;
    s3=string3;
  }
};

Structure* createNode(int num);
void addInOrder(Structure *root, Structure *newNode);

int main(){
  Structure array_str[100];
	//perasma tyxaiwn dedomenwn apo to arxeio rand_data.csv sto pinaka array_str
  fstream rand_data;
  rand_data.open("rand_data.csv",ios::in);
	vector<string>row;
	for(int i=0;i<100;i++){
		row.clear();
		//h katalhksh .clear() katharizei to vector
		string line,word;
		getline(rand_data,line);
		stringstream s(line);
		while (getline(s,word,','))
			row.push_back(word);
    //to vector apo8hkeyei string data,ara to row2[0] pou periexei ton akeraio arithmo prepei na metatrapei apo string se int
    int a=stoi(row[0]);
		array_str[i]=Structure(a,row[1],row[2],row[3]);
	}
  cout<<createNode(array_str[0].num)<<endl;
	
	return 0;
}

Structure* createNode(int num) {
	Structure *r;
	
	r = (Structure *) malloc(sizeof(Structure));
	if (r != NULL) {
		int key=num;
  		r->p_left;
  		r->p_rigth;
  	}
	return r;
}

void addInOrder(Structure *root, Structure *newNode,int key) {
	if (strcmp(newNode->num, root->num) <= 0) {
		if (root->p_left == NULL) { 
			root->p_left = newNode;
		}
		else {
			addInOrder(root->p_left, newNode);
		}
	}
	else {  
		if (root->p_rigth == NULL) {
			root->p_rigth = newNode;
		}
		else {
			addInOrder(root->p_rigth, newNode);
		}
	}
}
