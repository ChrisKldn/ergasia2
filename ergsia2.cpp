#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;

//Klash ylopoihshs struct
class node{
public:
  int num;
  string string1;
  string string2;
  string string3;
	node* left;
	node* right;
  //gia na mporesoume na dhmiourgisoume ena array typou class Structure
  //tha prepei na ftiaksoume enan dummy constructor
  node(){}
  node(int number,string s1,string s2,string s3){
    num=number;
    string1=s1;
    string2=s2;
    string3=s3;
  }
};

node* GetNewNode(int data);
node* Insert(node* root,int data);
node* Search(node* root,int data);
void Postorder(node* node);
void Preorder(node* node);
void Inorder( node* node);

int main(){
  node array_str[100];
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
		array_str[i]=node(a,row[1],row[2],row[3]);
	}
  //Eisagwgh eggrafwn sto dyadiko dendro
  node* stoixeio;
  node* root = NULL;  // DHmiourgia adeiou dendrou
  for(int i=0;i<100;i++){
    root = Insert(root,array_str[i].num);
    if (i==0)
      stoixeio=root;
  }
	cout<<"Menu"<<endl;
	cout<<"1. Search "<<endl;
	cout<<"2. Print Preorder  "<<endl;
	cout<<"3. Print Postorder "<<endl;
	cout<<"4. Print Inorder "<<endl;
  int answer;
  cin>>answer;
	if (answer==1){
		int numberS;
		cout<<"Eisagete ton arithmo anazhthshs: ";
		cin>>numberS;
		node* komvos=Search(root,numberS);
    	for(int i=0;i<100;i++){
      		if(array_str[i].num == numberS){
        		cout<<"Eggrafh: "<<endl;
        		cout<<array_str[i].string1<<endl;
        		cout<<array_str[i].string2<<endl;
       			cout<<array_str[i].string3<<endl;
       		}
    	}
	}else if(answer==2){
		Preorder(stoixeio);
	}else if(answer==3){
		Postorder(stoixeio);
	}else if(answer==4){
		Inorder(stoixeio);
	}

	return 0;
}

node* GetNewNode(int data) {
	node* newNode = new node();
	newNode->num = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//Eisagwgh eggrafhs sto dyadiko dendro
node* Insert(node* root,int data) {
	if(root == NULL) {
		root = GetNewNode(data);
	}
	//an to num ths eggrafhs einai mikrotero,tote ginetai eisasgwgh ths eggrafhs sto aristero ypodendro
	else if(data <= root->num) {
		root->left = Insert(root->left,data);
	}
	//diaforetika,eisagwgh sto deksi ypodendro
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}

//Anazhthsh eggrafhs,epistrefei True an h eggrafh yparxei sto dyadiko dendro
node* Search(node* root,int data) {
	if(root == NULL) {
		cout<<"O arithmos pou anazhthte den yparxei.";
	}
	else if(root->num == data) {
		return root;
	}
	else if(data <= root->num) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

//Postorder diasxish dendrou
void Postorder(node* node){
    if (node == NULL)
        return;
    // first recur on left subtree
    Postorder(node->left);
    // then recur on right subtree
    Postorder(node->right);
    // now deal with the node
    printf("%d ", node->num);
}

//Preorder diasxish dendrou
void Preorder(node* node){
    if (node == NULL)
        return;
    printf("%d ", node->num);

    Preorder(node->left);

    Preorder(node->right);
}

//Inorder diasxish dendrou
void Inorder( node* node){
    if (node == NULL)
        return;

    Inorder(node->left);

    printf("%d ", node->num);

    Inorder(node->right);
}
