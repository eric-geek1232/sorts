/*by eric 16/12/2020*/

#include <iostream>
#include <stdlib.h>
#include<bits/stdc++.h>

using namespace std;

//function prototypes
void bubbleSort(int *array, int length);  
void insertionSort(int *array, int lenght);
void shellSort(int *array, int lenght);
void selectionSort(int *array, int lenght);
void mergeSort(int *array, int ini, int end);
void merge(int *array, int ini, int mid, int end);
void quickSort(int *array, int ini, int end);
void radixSort(int *array, int length);
void showArray(int *array, int length);
void setArray(int *array, int length);

int main(){
	int length, option;
	int *array;
	
	do{
		cout<< "\t..::MENU::.."<< endl;
		cout<< "\n[1] Bubble sort"<< endl;
		cout<< "[2] Insertion sort"<< endl;
		cout<< "[3] Selection sort"<< endl;
		cout<< "[4] Merge sort"<< endl;
		cout<< "[5] Quick sort"<< endl;
		cout<< "[6] Shell sort"<< endl;
		cout<< "[7] Radix sort"<< endl;
		cout<< "[8] Quit"<< endl;
		
		cout<<"\nSelect: ";
		cin>> option;
	
		switch (option){
			case 1:
				system("cls");
				cout << "How many numbers would you like to sort?"<< endl;
				cin>> length;
				array = new int[length]; 
				setArray(array, length);
				
				bubbleSort(array, length);
				showArray(array, length);
				break;
	
			case 2:
				system("cls");
				cout << "How many numbers would you like to sort?"<< endl;
				cin>> length;
				array = new int[length]; 
				setArray(array, length);
				
				insertionSort(array, length);
				showArray(array, length);
				break;
			
			case 3:
				system("cls");
				cout << "How many numbers would you like to sort?"<< endl;
				cin>> length;
				array = new int[length]; 
				setArray(array, length);
				
				selectionSort(array, length);
				showArray(array, length);
				break;
			
			case 4:
				system("cls");
				cout << "How many numbers would you like to sort?"<< endl;
				cin>> length;
				array = new int[length]; 
				setArray(array, length);
				
				mergeSort(array, 0, length-1);
				showArray(array, length);
				break;
			
			case 5:
				system("cls");
				cout << "How many numbers would you like to sort?"<< endl;
				cin>> length;
				array = new int[length]; 
				setArray(array, length);
				
				quickSort(array, 0, length-1);
				showArray(array, length);
				break;
				
			case 6:
				system("cls");
				cout << "How many numbers would you like to sort?"<< endl;
				cin>> length;
				array = new int[length]; 
				setArray(array, length);
				
				shellSort(array, length);
				showArray(array, length);
				break;
			
			case 7:
				system("cls");
				cout << "How many numbers would you like to sort?"<< endl;
				cin>> length;
				array = new int[length]; 
				setArray(array, length);
				
				radixSort(array, length);
				showArray(array, length);
				break;
				
			case 8:
				system("cls");
				cout << "\t**See you soon**"<< endl;
				system("pause");
				break;
		}	
	} while(option != 8);
	
	return 0;
}

void setArray(int *array, int length){
	int number;
	
	system("cls");
	cout<< "type the numbers\n"<< endl;
	
	//fill array
	for (int i = 0; i < length; i++){
		cout<<"[" << i + 1<<"]" <<"= ";
		cin>> number;
		array[i] = number;
	}
}

void showArray(int *array, int length){
	
	//show array
	cout<< "\tShowing ascending list\n"<< endl;
	for (int i = 0; i < length; i++){
		cout<< "[ "<< i + 1<< " ]"<< " = "<< array[i]<< endl;
	}
	
	cout<< "\n\tShowing descending list\n"<< endl;
	for (int i = length-1; i >= 0; i--){
		cout<< "[ "<< i + 1<< " ]"<< " = "<< array[i]<< endl;
	}
	
	system("pause");
	system("cls");
}

void bubbleSort(int *array, int length){
	//step 1: iterate whole array
	for (int i = 0; i < length; i++) {
		//step 2: iterate one position later
        for (int j = 1; j < (length - i); j++) {
        	if (array[j - 1] > array[j]) {
        		//step 3: change values
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
        	}
        }
    }
}

void insertionSort(int *array, int lenght){
	// step 1: iterate whole array
	for(int i = 0; i < lenght; i++){
		int position = i;
		int temp = array[position]; // step 2: Get the number of the current position
		
		// step 3: iterate and compare current number position with previous position on main array
		while(position > 0 && temp < array[position - 1]){ 
			array[position] = array[position-1]; // change the largest numbers than current number to right side
			position--; // iterate until temp > array[position - 1] or position 0
		}
		
		//step 4: change number;
		array[position] = temp;
	}
}

void shellSort(int *array, int length){
	// step 1: get interval
	int interval = length / 2;
	int index, index_aux;

	// step 2: iterate until the interval becames 0
	while(interval >= 1){
		//step 3: iterate until overflow the main array
		for(int i = 0; i + interval < length; i++){
			index = i;
			//step 4: iterate and compare with interval help
			while(index >= 0){
				index_aux = index + interval;
				if(array[index] > array[index_aux]){
					//step 5: change values
					int temp = array[index];
					array[index] = array[index_aux];
					array[index_aux] = temp;
					index = index - interval; // in some cases overflow the array
				} else {
					index = -1; // overflow the array
				}
			}
		}
		//step 6: recalculate the interval
		interval = interval/2;
	}
}

void selectionSort(int *array, int lenght){
	//step 1: iterate whole array
	for(int i = 0; i < lenght; i++){
		//Get the number of the current position
		int min = i;
		
		//step 2: iterate one position later and compare the current number with the number one position later
		for(int j = i+1; j < lenght; j++){
			if(array[min] > array[j]){
				min = j; // get position of min value
			}
		}
		
		//step 3: change the values
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

void mergeSort(int *array, int ini, int end){
	//step 1: compare ini with end in each sub-array 
	if(ini < end){
		//step 2: get the middle part
		int mid=(ini+end)/2;
		//step 3: create sub-Arrays in two parts
        mergeSort(array,ini,mid);
        mergeSort(array,mid+1,end);
        // step 4: merge sub-arrays
        merge(array,ini,mid,end);
	}
}

void merge(int *array, int ini, int mid, int end){
	int left = ini;
	int right = mid + 1;
	int index = 0;
	int *array_aux = new int[0];
	int resume = 0;
	
	//iterate and sort until overflow any array
	while(left <= mid && right <= end){
		if(array[left] < array[right]){
			array_aux[index] = array[left];
			left++;
			index++;
		} else{
			array_aux[index] = array[right];
			right++;
			index++;
		}
	}
	
	// if there is something missing in the right array
	// iterate until the array whole 
	resume = right;
	while(resume <= end){
		array_aux[index] = array[resume];
		index++;
		resume++; 
	}
	
	// if there is something missing in the left array
	// iterate until the array whole 
	resume = left;
	while(resume <= mid){
		array_aux[index] = array[resume];
		index++;
		resume++; 
	}
	
	//change values from array_aux to main array
	for (int i = 0; i < index; i++){
		array[ini + i] = array_aux[i];
	}
}

void quickSort(int *array, int ini, int end){
	//the function of these variables is to segment in sub-array
	int end_aux = end;
	int ini_aux = ini;
	
	//step 1: get any pivot
	int pivot = array[ini];
	
	do{
		//step 2: iterate the sub-arrays
		while(array[ini] < pivot){
			ini +=1; 
		}
		
		while(array[end] > pivot){
			end -=1; 
		}
		
		//Step 3: change values
		if(ini <= end){
			int temp = array[ini];
			array[ini] = array[end];
			array[end] = temp;
			ini += 1;
			end -= 1;
		}
		
	}while(ini <= end);//iterate until ini and end intersect
	
	//step 4: recursive until to sort sub-array 
	if(ini_aux < end){
		quickSort(array, ini_aux, end);
	}
	if(ini < end_aux){
		quickSort(array, ini, end_aux);
	}
}

void radixSort(int *array, int length){
 
    // Step 1: Find the maxumum element
    int maximum = array[0];
 
    for(int i = 1; i < length; i++){
        maximum = max(maximum, array[i]);
    }
 
    // Step 2: Count the number of digits of the maximum number
    int digits = 0;
 
    while(maximum > 0){
        digits++;
        maximum /= 10;
    }
 
    // Step 3, 4, 5: Arrange the numbers on the basis of digits
    for(int i=0;i<digits;i++){
 
        // Units/Tens/Hundreds - used to determine which digit
        int power = pow(10, i);
 
        // Holds the updated array 
        int array_aux[length];
 
        // Counting Sort Array - required for arranging digits [0-9]
        int count[10];
 
        // Initializing Count Array
        memset(count, 0, sizeof(count));
 
        // Calculating frequency of digits
        for(int j = 0; j < length; j++){
 
            // The digit under consideration in this iteration
            int num = (array[j]/power) % 10;
 
            count[num]++;
        }
 
        // Cumulative frequency of count array
        for(int j = 1 ; j < 10; j++){
            count[j] += count[j-1];
        }
 
        // Designating new positions in the updated array
        for(int j = length-1; j >= 0; j--){
 
            // The digit under consideration in this iteration
            int num = (array[j]/power) % 10;
 
            array_aux[count[num]-1] = array[j];
            count[num]--;
        }
 
         //Updating the original array using New Array
        for(int j = 0; j < length; j++)
            array[j] = array_aux[j];
     
    }        
}
