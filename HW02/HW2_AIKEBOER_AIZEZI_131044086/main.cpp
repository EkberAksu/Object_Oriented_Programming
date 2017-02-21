/* 
 * Howmework 02
 * student name: Aikeboer Aizezi
 * student id: 131044086
 */

/* 
 * this code finds and prints the first occurence of
 * mode of the given array, whatever the type is.
 */


#include <iostream>  //include iostream library to use cin/cout/endl...
#include <cstddef>   //include cstddef library to get sizeof/size_t

using namespace std;

/* a DayOfYear structure which includes one integer day, one integer for month
  and one integer for year*/

struct DayOfYear {
    int day;
    int month;
    int year;
};

/* 
 * this global function finds and returns the first occurence of mode 
 * of given array, whateever its type is. it gets an array, size of the 
 * array, size of one element of the array, and a pointer to compare-check
 * function.
 */
int return_mode (const void * base, size_t num, size_t size, bool (* equals) 
                (const void *, const void *));

/*
 *this function compares two integers, returns true if they are equal,
 * false if they are not. it takes two constant void pointers as parameters.
 */
bool equals_int(const void* el1,const void* el2);  

/*
 *this function compares two doubles, returns true if they are equal,
 * false if they are not. it takes two constant void pointers as parameters.
 */
bool equals_double(const void* el1,const void* el2);

/*
 *this function compares two characters, returns true if they are equal,
 * false if they are not. it takes two constant void pointers as parameters.
 */
bool equals_char(const void*el1,const void* el2);

/*
 *this function compares two dayOfYear structers, returns true if they are equal,
 * false if they are not. it takes two constant void pointers as parameters.
 */
bool equals_struct(const void*el1,const void* el2);

/*
 *this function finds and returns the frist occurence of the maximum of
 * the array. it takes a const integer pointer, and size of the array.
 */
int first_max(const int *arr, const size_t size);


int main()
{
	size_t num=10;     //size of the array
	char array[num]={'a','a','a','b','c','b','c','c','c','d'};
        
        /*DayOfYear date[num];
        
        //a loop to fill the array
        for(int i=0;i<num;++i){
            
            cout<<"enter "<<num<<" DayOfYear respectively:\n";
            cin>>date[i].day>>date[i].month>>date[i].year;
        }*/

	int mode_index;  // the index of first occurence of mode
	
	mode_index=return_mode(array, num, sizeof(char), equals_char);
	
	cout<<"the first index of mode of this array is "<< mode_index<<".\n";
	
	return 0;
}

/*
 *this function compares two integers, returns true if they are equal,
 * false if they are not. it takes two constant void pointers as parameters.
 */
bool equals_int(const void* el1,const void* el2)
{
	int* num1= (int*) el1;
	int* num2= (int*) el2;
	
	if(*num1==*num2)
		return true;
	else
		return false;
}

/*
 *this function compares two doubles, returns true if they are equal,
 * false if they are not. it takes two constant void pointers as parameters.
 */
bool equals_double(const void* el1,const void* el2)
{
	double* num1= (double*) el1;
	double* num2= (double*) el2;
	
	if(*num1==*num2)
		return true;
	else
		return false;
}

/*
 *this function compares two characters, returns true if they are equal,
 * false if they are not. it takes two constant void pointers as parameters.
 */
bool equals_char(const void*el1,const void* el2)
{
    char* character1= (char*) el1;
    char* character2=(char*) el2;
    
    if(*character1== *character2)
        return true;
    else 
        return false;
}

/*
 *this function compares two dayOfYear structers, returns true if they are equal,
 * false if they are not. it takes two constant void pointers as parameters.
 */
bool equals_struct(const void*el1,const void* el2)
{
    DayOfYear* date1= (DayOfYear*)el1;
    DayOfYear* date2= (DayOfYear*)el2;
    
    if(date1->day == date2->day && date1->month == date2->month
                                && date1->year == date2->year)
        return true;
    else
        return false;
}

/*
 *this function finds and returns the frist occurence of the maximum of
 * the array. it takes a const integer pointer, and size of the array.
 */
int first_max(const int *arr,const size_t size)
{
	int max= arr[0];
	int index=0;
	
	for(size_t i=1; i<size; ++i)
	{
		if(max<arr[i])
		{
			max=arr[i];
			index=i;
			
		}
	}
	
	
	return index;
}

/* 
 * this global function finds and returns the first occurence of mode 
 * of given array, whateever its type is. it gets an array, size of the 
 * array, size of one element of the array, and a pointer to compare-check
 * function.
 */
int return_mode (const void * base, size_t num, size_t size, bool (* equals) 
                (const void *, const void *))
{
	unsigned char* curr_point = (unsigned char*) base;
	
	unsigned char* curr_point1 ;
	
	unsigned char* end_point = (unsigned char*) base + (num * size);
	
	int count=1;
	int cnt_arr[num];
	int point=0;
	int index;
	
	for(;curr_point<end_point;curr_point += size)
	{
            for(curr_point1=curr_point+size;curr_point1<end_point;curr_point1 += size)
            {
		if(equals(curr_point, curr_point1)==1)
		++count;
			
            }
		
		cnt_arr[point]=count;
		++point;
		count=1;
	}
	
	index= first_max(cnt_arr, point);
	
	return index;
}