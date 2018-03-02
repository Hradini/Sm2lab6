#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

class list{
	public:
	node *head, *tail;
	
		//default constructor
		list(){
			head=NULL;
			tail=NULL;
		}
		//function to insert new node
		void insert(int value){
			node *temp = new node;
			temp->data= value; //assigns value to temp
			temp->next=NULL;//points temp to null
			if (head == NULL){
				head = temp;
				tail=temp;
			}else{
				tail->next=temp; //points last node to temp
				tail=temp;//points tail to temp
			}
		}
		//function to display all items in the list
		void display(){
			node*cur= new node;
			cur=head;
			//traverses the linked list and preint every data from the node
			while(cur!=NULL){
				cout<< cur->data << "-> ";
				cur=cur->next;
			}
				cout<< "NULL\n";
			}
		
};

void bsearch(int arr[],int lsize, int rsize, int key){
	// Make a variable.
	int mid = (lsize +rsize)/2;
	// float mid;
	if (key <= arr[rsize] && key >= arr[lsize]){
		if(arr[mid] == key){
			cout << "Found at " << mid << " in the sorted array";
		}
		else{
			if(arr[mid] < key){
				bsearch(arr,mid+1,rsize,key);
			}
			else{
				bsearch(arr,lsize,mid-1,key);
			}
		}
	}
	else{
		cout << "Not found";
	}
}
void displayarr(int arr[], int n){
	int i;
	for (i = 0; i < n; ++i){
		cout<<arr[i]<<"\t";
	}
	cout<<endl;	
} 

int main(){
	int arr[5]; 
	list list1;
	list1.insert(2);
	list1.insert(5);
	list1.insert(6);
	list1.insert(1);
	list1.insert(4);
	list1.display();
	node* temp;
	temp=list1.head;
	
	int k=0;
	for(k=0;k<=5;++k){
		if(temp!=NULL){
		arr[k]=temp->data;
		temp=temp->next;
		}
	}
	displayarr(arr,5);
	
	int key = 1;
	int size = 5;
	int n=size;
	int i, j;
	for (i = 0; i < n; ++i){ //traverses array multiple times
		for (j = 0; j < n-i-1; ++j){ //traverses the array
			if (arr[j] > arr[j+1]){
				arr[j] = arr[j]+arr[j+1]; //swaps elements
				arr[j+1] = arr[j]-arr[j + 1];
				arr[j] = arr[j]-arr[j + 1];
			}
		}
	}	
 	cout<<"The sorted array is "<<endl;
	 displayarr(arr,n);
	// Function call for b...
	bsearch(arr,0,size-1,key);
	return 0;
}
