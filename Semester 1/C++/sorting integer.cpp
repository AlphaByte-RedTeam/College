#include <iostream> 
using namespace std;  
  
int partition ( int array[], int low, int high ){  

    int pivot = array[high]; 
    int i = (low - 1);
  
    for ( int j = low; j <= high - 1; j++ ){  

        if ( array[j] < pivot ){  
          
            i++;
            int temp = array[i];
    		array[i] = array[j];
    		array[j] = temp;
        }  
    } 
    
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    
    return ( i + 1 );  
}  
  
void quickSort ( int array[], int low, int high ){ 

    if ( low < high ){

        int indexPartition = partition( array, low, high );  
  
        quickSort( array, low, indexPartition - 1 );  
        quickSort( array, indexPartition + 1, high );  
    }  
}  

void printArr ( int array[], int n ) {
	for ( int i = 0; i < n; i++ ){
		cout << array[i] << " ";
	}
}  

int main (){  

	int n = 10;
	int array[n];
	
	for (int i=0; i<n; i++){

		cout << "Input integer (Max. 10 Numbers) " << i + 1 << ": ";
		cin >> array[i];

	}
	
	cout << endl;
	cout << "Unsorted Data: \n";  
	printArr(array, n);
	cout << endl;
	cout << "---------------------\n";
	quickSort( array, 0, n - 1 );
    
    cout << "Sorted Data: \n";  
    printArr( array, n );
    
    return 0;  
}

/*

//PARTITION FUNCTION
    partition : integer ( array[] : integer, low : integer, high : integer )

    DECLARATION:
        pivot : integer <-- array[high]
        i : integer <-- (low - 1)

        for ( j <-- low : integer; j <= high - 1; j++ )

            if ( array[j] < pivot )
        
                i++
        	    int temp = array[i]
    		    array[i] = array[j]
    		    array[j] = temp
        

        temp : integer <-- array[i + 1]
        array[i + 1] <-- array[high]
        array[high] <-- temp
    
        return ( i + 1 )


//QUICK SORT FUNCTION

    quickSort : void ( array[] : integer, low : integer, high : integer )

        if ( low < high )

            indexPartition : integer <-- partition( array, low, high )  
  
            quickSort( array, low, indexPartition - 1 ) 
            quickSort( array, indexPartition + 1, high )


//PRINT ARRAY

    void printArr ( int array[], int n )
	    for ( int i = 0; i < n; i++ )
		    write : array[i]




MAIN PROGRAM: 

DECLARATION:
	n <-- 10 : integer
	array[n] : integer
	
	for (i <-- 0 : integer; i < n; i++)

		write(Input integer (Max. 10 Numbers)) : i + 1 : (: )
		read : array[i]

	
	write(Unsorted Data: )  
	printArr(array, n);
	write(---------------------)
	quickSort( array, 0, n - 1 )
    
    write(Sorted Data: )  
    printArr( array, n )
    
    return 0

*/