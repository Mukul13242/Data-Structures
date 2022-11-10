//MUKUL GOYAL
//ECE
//SID:21105071

#include <iostream>             
using namespace std;        

/*
QUESTION:
Compare Bubble sort and Selection sort based on the following:
1. Number of comparisons
2. Number of swaps
3. Inplace and Outplace implementations
*/


//SOLUTION

void bubble_sort(int arr[],int n){
    int i=0,j=1,t=n-1;
    int no_of_swap=0;
    int no_of_comp=0;
    while(t>0){
        while(j<=t){
            if(arr[i]>arr[j]){swap(arr[i],arr[j]);no_of_swap++;}
            i++,j++;
            no_of_comp++;
        }
        t--;
        i=0,j=1;
    }
    cout<<" . No. of Swaps:"<<no_of_swap<<endl;
    cout<<" . No. of COMPARISON:"<<no_of_comp<<endl;
    cout<<" . [INPLACE SORTING ALGORITHM USED]"<<endl;
}

int min(int arr[],int si,int ei){
    int m=arr[si];            
    int min_ind=si;          
    for(int i=si;i<=ei;i++){
        int min_prev=m;
        m=min(m,arr[i]);
        if(m<min_prev){min_ind=i;}
    }
    return min_ind;
}

void selection_sort(int arr[],int n){
    //si=starting index
    //ei=ending index
    int si=0,ei=n-1;
    int no_of_swap=0;
    int no_of_comp=0;
    while(si<ei){
    int mi=min(arr,si,ei);  //mi=index holding minimum value
    no_of_comp=no_of_comp+(ei-si+1);
    if(si!=mi){swap(arr[si],arr[mi]);
    no_of_swap++;}
    si++;
    }
    cout<<" . No. of SWAP:"<<no_of_swap<<endl;
    cout<<" . No. of COMPARISON:"<<no_of_comp<<endl;
    cout<<" . [INPLACE SORTING ALGORITHM USED]"<<endl;
}

//Function to print the array
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}

int main(){
    int n; //Size of array
    cout<<"Enter number of elements in array:";
    cin>>n;
    int arr1[n];
    int arr2[n];
    //taking array as input 
    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++){
        int a;cin>>a;
        arr1[i]=a;
        arr2[i]=a;
        }
    //printing array before sorting
    cout<<"\nARRAY before sorting:";
    print(arr1,n);
    //Printing Sorted array using bubble sort 
    cout<<"BUBBLE SORT"<<endl;
    bubble_sort(arr1,n);
    cout<<" . ARRAY After Sorting Using Bubble Sorting:";
    print(arr1,n);
    //Printing Sorted array using insertion sort and printing it
    cout<<"SELECTION SORT"<<endl;
    selection_sort(arr2,n);
    cout<<" . ARRAY After Sorting Using Selection Sorting:";
    print(arr2,n);
}
/*

BONUS QUESTION

TIME COMPLEXITY OF BUBBLE SORT
   From the above code of BUBBLE SORT we can see that there are two
   while loops which will we executed.First while loop will run n-1
   times and second while loop will run n-2 times and so on till 1 time.
   Time Complexity=(n-1)+(n-2)+(n-3)....+2+1=(n-1)(n)/2
                  =O(n^2)

TIME COMPLEXITY OF SELECTION SORT
    In selection sort the main time consuming task is finding minimum 
    element from the array.We have to scan all the elements of the
    array to find the minimum element.
    With reference to the above code of SELECTION SORT,first we will 
    search for minimum element in array of size n,then in the same array of size n-1,and so on till array of size 1.
    Time Complexity=(n)+(n-1)+(n-2)...1=(n)(n+1)/2
                   =O(n^2)

*/
