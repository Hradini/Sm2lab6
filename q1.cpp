#include<iostream>
using namespace std;

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
		cout<<arr[i];
	}
	cout<<endl;	
} 

int main(){
	int arr[] = {5,3,1,6,0};
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
