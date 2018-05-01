//
//  main.c
//  Test for Pointer and Array
//
//  Created by Louis on 2018/4/30.
//  Copyright © 2018 Louis.Aeilot.D. All rights reserved.
//

//Including Head Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Structs for these tests:
//For Test 3:
typedef struct{
    char name[64];    //=Name of point
    double x;         //=(x,y,z)
    double y;         //=
    double z;         //=
}Point;

//End

/* Photos for Test 1
 
 *
 **
 ***
 ****
 *****
 ******
 *******    ->  size(row)
 
 1000000
 1100000
 1110000
 1111000
 1111100
 1111110
 1111111
 
 Diagonal : row = column
 Up : row <= col
 Down : row >= col

 */

//Test 1:
void test_triangle(int size){     //size means how many rows are in your triangle
    int col , row ;
    char* tag=0;
    row = size ;
    col = size ;
    tag=(char*)malloc(row*col);
    memset(tag,0,row*col);
/*  Plan 1
    for (int i = 0;i<row; i++) {
        for (int j = 0;j<col; j++) {
            if (i >= j) {
                tag[i*col+j]=1;
            }
        }
    }
*/
    
    for (int i = 0;i<row; i++) {
        for (int j = 0;j<=i; j++) {
                tag[i*col+j]=1;
        }
    }
    for (int i = 0;i<row; i++) {
        for (int j = 0;j<col; j++) {
            if (tag[i*col+j]==1) {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    free(tag);
}
//Test 2:
void test_array_type()
{
    ///win64 sizeof(void*)=8
    ///gcc64 sizeof(void)=1
    printf("sizeof(void*)=%lu\n",sizeof(void*));
    printf("sizeof(void)=%lu\n",sizeof(void));
    printf("sizeof(char)=%lu\n",sizeof(char));
    printf("sizeof(short)=%lu\n",sizeof(short));
    printf("sizeof(int)=%lu\n",sizeof(int));
    printf("sizeof(float)=%lu\n",sizeof(float));
    printf("sizeof(double)=%lu\n",sizeof(double));
//Mind the '%lu'  It's not '%d'
}
//Test 3:
void test_3D_point(){
    FILE * csv = fopen("/Users/louis/Downloads/Test.csv", "r");    //"/Users/louis/Downloads/Test.csv" You Must Change it!!!
    char line[100];
    Point * user=0;
    Point a;
    int row=0;
    while (fgets(line, 100, csv)!=NULL) {
        sscanf(line,"%[^,],%lf,%lf,%lf\n",a.name,&a.x,&a.y,&a.z);
        row++;
        user = realloc(user, row*sizeof(Point));
        user[row-1]=a;
    }
    fclose(csv);
    for (int r=0; r<row; r++) {
        printf("Row %d    Name %s    X %lf    Y %lf    Z %lf\n",r+1,user[r].name,user[r].x,user[r].y,user[r].z);
    }
    free(user);
}



int main(int argc, const char * argv[]) {
    // insert code here...
    int row;
    printf("===============================\n");
    printf("Test 1 : Triangle\n");
    printf("How many rows? :");
    scanf("%d",&row);
    test_triangle(row);
    for (int i=0; i<row+3; i++) {
        printf("=");
    }
    printf("\n");
    printf("Test 2 : On Your Mac (Or Linux)\n");
    printf("Warning: If it says : command not found , it means the system of your computer is Windows\n");
    system("cd /Users/louis/Desktop && ls -l");
    printf("===============================\n");
    printf("Test 3 : Array Type\n");
    test_array_type();
    printf("===============================\n");
    printf("Test 4 : 3D Point\n");
    printf("The Code :/Users/louis/Downloads/Test.csv ,You Must Change it!!!\n");
    test_3D_point();
    return 0;
}
