/*Name: Jose Guerrero
Description: This program tests vector functions.*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VECMAX (9)
#define NOTFOUND (-1)
typedef int item;
typedef int index;
typedef item vector[VECMAX];

void printVector(char*, index, const vector);
void setValVector(index, vector, item);
void setIdxVector(index, vector);
void setRandomVector(index, vector, item, item);
void squareVector(index, vector);
void addScalarVector(index, vector, item);
void mulScalarVector(index, vector, item);
void divScalarVector(index, vector, item);
void addVectors(index, const vector, const vector, vector);
void mulVectors(index, const vector, const vector, vector);
item sumVector(index, const vector);
item dotProduct(index, const vector, const vector);
item findMax(index, const vector);
item findMin(index, const vector);
bool findValue(index, const vector, item, index*);
void rotateOneLeft(index, vector);
void rotateOneRight(index, vector);
void rotateNleft(index, vector, index);
void rotateNright(index, vector, index);
void reverseVector(index, vector);
void rotateVectors(void);
void setVectors(void);
void findVectorValues(void);
void addMulVectors(void);

int main(void) {
    printf("Exercise vector functions\n");
    // setVectors();
    //rotateVectors();
    //findVectorValues();
    //   addMulVectors();
    return EXIT_SUCCESS;
}/*main*/

void setVectors(void) {
    printf("Initialize vectors\n");
    index len = VECMAX;
    item v[VECMAX];
    item val = 17;
    item scalar = 2;
    item low = 3;
    item high = 19;
    setValVector(len, v, val);
    printVector("Set 17:", len, v);
    addScalarVector(len, v, scalar);
    printVector("Add 2:", len, v);
    mulScalarVector(len, v, scalar);
    printVector("Mul 2:", len, v);
    divScalarVector(len, v, scalar);
    printVector("Div 2:", len, v);
    setIdxVector(len, v);
    printVector("Set index:", len, v);
    printf("Sum of {0 .. %d} = %d\n", len, sumVector(len, v));
    setRandomVector(len, v, low, high);
    printVector("Set rand:", len, v);
    squareVector(len, v);
    printVector("Square vector:", len, v);
}/*setVectors*/

void rotateVectors(void) {
    index len = VECMAX;
    item v[VECMAX];
    item low = 3;
    item high = 19;
    item n = 3;
    printf("Rotate vectors\n");
    setRandomVector(len, v, low, high);
    printVector("Rand", len, v);
    rotateOneLeft(len, v);
    printVector("Shift 1 Left", len, v);
    rotateOneRight(len, v);
    printVector("Shift 1 Right",len, v);
    rotateNleft(len, v, n);
    printVector("Shift 3 Left", len, v);
    rotateNright(len, v, n);
    printVector("Shift 3 Right", len, v);
    reverseVector(len, v);
    printVector("Reverse vector:", len, v);
}/*rotateVectors*/

void findVectorValues(void) {
    index len = VECMAX;
    item v1[VECMAX];
    item val;
    item low = 3;
    item high = 19;
    printf("Find values in vector\n");
    setRandomVector(len, v1, low, high);
    printVector("Rand Vec in range [3..19]:", len, v1);
    printf("Min = %d\n", findMin(len, v1));
    printf("Max = %d\n", findMax(len, v1));
    index fidx;
    val = 17;
    if (findValue(len, v1, val, &fidx))
        printf("%d found at position v1[%d]\n", val, fidx);
    else
        printf("%d not found at position v1\n", val);
    val = 77;
    if (findValue(len, v1, val, &fidx))
        printf("%d found at position v1[%d]\n", val, fidx);
    else
        printf("%d not found at position v1\n", val);
}/*findVectorValues*/

void addMulVectors(void){
    index len = VECMAX;
    item v1[VECMAX];
    item v2[VECMAX];
    item v3[VECMAX];
    item val = 17;
    item low = 3;
    item high = 19;
    printf("Vector addition and dot product\n");
    setValVector(len, v1, val);
    setRandomVector(len, v2, low, high);
    addVectors(len, v1, v2, v3);
    printVector("V1", len, v1);
    printVector("V2", len, v2);
    printVector("V3", len, v3);
    mulVectors(len, v1, v2, v3);
    printVector("V1", len, v1);
    printVector("V2", len, v2);
    printVector("V3", len, v3);
    printf("DotProduct V1 . V2 = %d\n", dotProduct(len, v1, v2));
}/*addMulVectors*/

void printVector(char* s, index len, const vector v) {
    // print all values of 'v' onto one line in the console
    printf("%s ", s);
    for (index k = 0; k < len; k++)
        printf("%d ", v[k]);
    printf("\n");
}/*printVector*/

void setValVector(index len, vector v, item val){
    // initialize each component of 'v' with 'val'
    for (index k = 0; k < len; k++) v[k] = val;
}/*setValVector*/

void setIdxVector(index len, vector v){
    for(index k=0;k<len; k++)v[k]=k;
    // initialize each component of 'v' with its index
}/*setIdxVector*/

void setRandomVector(index len, vector v, item low, item high){
    for(index k=0; k<len; k++)v[k]= rand()%(high-low+1)+low;
    // initialize each component of 'v' with a pseudo
    // random numbers in the range of 'low' to 'high'
    // using rand() defined in <stdlib.h>
}/*setRandomVector*/

item sumVector(index len, const vector v){
    index sum=0;
    for (index k=0; k<len; k++)sum = sum+v[k];
    return sum;
    // return the sum of all components of 'v'
}/*sumVector*/

void addScalarVector(index len, vector v, item scalar){
    for(index k= 0;k <len; k++) v[k]=v[k]+scalar;
    // add 'scalar' to each component of 'v'
}/*addScalarVector*/

void mulScalarVector(index len, vector v, item scalar){
    for(index k=0; k<len; k++) v[k] = v[k]*scalar;
    // multiply each component of 'v' by 'scalar'
}/*mulScalarVector*/

void divScalarVector(index len, vector v, item scalar){
    for(index k= 0; k<len; k++) v[k]=v[k]/scalar;
    // divide each component of 'v' by 'scalar'
}/*divScalarVector*/

void squareVector(index len, vector v){
    for(index k=0; k<len; k++) v[k]=v[k]*v[k];
    // return v = v * v
}/*squareVector*/

void addVectors(index len, const vector v1, const vector v2, vector v3){
    for(index k=0; k<len; k++) v3[k]=v1[k]+v2[k];
    // return v3 = v1 + v2 (component by component)
}/*addVectors*/

void mulVectors(index len, const vector v1, const vector v2, vector v3){
    for(index k=0; k<len; k++) v3[k]= v1[k]*v2[k];
    // return v3 = v1 * v2 (component by component)
}/*mulVectors*/

item dotProduct(index len, const vector v1, const vector v2){
    item dp=0;
    item dpf=0;
    for(index k=0; k<len; k++) dp= v1[k]*v2[k]; dpf= dpf+dp;
    return dpf;
    // return dot product of v1 and v2
    // Ex: dot product of [1 7 6 2 4] and [3 1 2 1 4] is 40
}/*dotProduct*/

item findMin(index len, const vector v) {
    index min=v[0];
    for(index k= 0; k<len; k++){

        if(v[k]<min)min=v[k];
    }
    return min;
    // find and return min array element
    // Ex: min of [1 7 6 2 4] is 1
}/*findMin*/

item findMax(index len, const vector v) {
    index max=v[0];
    for(index k=0; k<len; k++){
        if(v[k]>max)max=v[k];
    }
    return max;
    // find and return max array element
    // Ex: min of [1 7 6 2 4] is 7
}/*findMax*/

bool findValue(index len, const vector v, item val, index* fidx){
    for (index k=0; k<len; k++){
        if(v[k]==val){ *fidx = k; return true;}
    }
    *fidx = NOTFOUND;
    return false;
    // if value 'val' is in array 'v'
    // return true and its index in 'fidx'
    // Ex: Is 6 in [1 7 6 2 4]? true at fidx = 2
    // Ex: Is 9 in [1 7 6 2 4]? false at fidx = NOTFOUND
}/*findValue*/

void rotateOneRight(index len, vector v){
    item temp=v[len-1];
    for(index k=len-1; k>0; k--){
        v[k]=v[k-1];
    }
    v[0]=temp;

    // rotate all array elements one position
    // to the right without losing any elements
    // move the last element into the first
    // Ex: [1 7 6 2 4] ==> [4 1 7 6 2]
}/*rotateOneRight*/

void rotateNright(index len, vector v, index pos) {
    for (index n = 0; n < pos; n++) {
        item temp = v[len-1];
        for (index k = len-1; k >0; k--) {
            v[k] = v[k - 1];
        }
        v[0] = temp;
    }
    // rotate all array elements N positions
    // to the right without losing any elements
    // the elements that fall of the end
    // are moved to the beginning of the array
}/*rotateNright*/

void rotateOneLeft(index len, vector v){
    item temp=v[0];
    for(index k=1; k<len; k++){
        v[k-1]=v[k];
    }
    v[len-1]=temp;
    // rotate all array elements one position
    // to the left without losing any elements
    // move the first element into the last
    // Ex: [1 7 6 2 4] ==> [7 6 2 4 1]
}/*rotateOneLeft*/

void rotateNleft(index len, vector v, index pos){
    for(index n=0; n<pos; n++) {
        item temp = v[0];
        for (index k =1; k <len ; k++) {
            v[k - 1] = v[k];
        }
        v[len-1] = temp;
    }
    // rotate all array elements N positions
    // to the left without losing any elements
    // the elements that fall of the front
    // are moved to the end of the array
}/*rotateNleft*/

void reverseVector(index len, vector v){
    index v2[len];
    for(index k=0;k<len;k++)v2[k]=v[k];
    for(index k=0; k<len+1/2; k++) v[k]=v[len-1-k];
    for (index k=0; k<len+1/2;k++)v[len-1-k]=v2[k];
    // reverse the elements in the array
    // Ex: [1 7 6 2 4] ==> [4 2 6 7 1]
}/*reverseVector*/

