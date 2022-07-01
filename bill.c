#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>//for atoi and itoa
//employee details:
//ID NAME DOB Qualification Job Salary PhoneNO

typedef struct cartDetails{
    char id[10];
    char name[20];
    char qty[10];
    char price[10];
}cart;


int getLines(){
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="cart.txt";
    //*file name is a pointer pointing to the path of the text file
    fp=fopen(filename,"r");//opening th file
    if(fp==NULL){
        printf("Could not open file");
        return -1;//important
    }
    //******************************************
    int c=0;
    while(fgets(str,max,fp)!=NULL){//fgets() function reads line by line
        // if(strcmp(str,"*")==0)
        // break;
        c++;
    }
    fclose(fp);
    return c;
}

int getFileContent(cart* array){//array of structures
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="cart.txt";
    //*file name is a pointer pointing to the path of the text file
    fp=fopen(filename,"r");//opening th file
    if(fp==NULL){
        printf("Could not open file");
        return -1;//important
    }
    //******************************************
    int c=0,i,j,k;
    char store[50][50];//can store 50 user name and password (together seperated by lines) with 50 characters
    while(fgets(str,max,fp)!=NULL){//fgets() function reads line by line
        // if(strcmp(str,"*")==0)
        // break;
        strcpy(store[c],str);
        c++;
    }

    for(i=0;i<c;i++){
        char *p;
        p=strchr(store[i],' ');
        int n=p-store[i]; //index of first space
        store[i][n]='`';

        p=strchr(store[i],' ');
        int n1=p-store[i]; //index of second space
        store[i][n1]='`';

        p=strchr(store[i],' ');
        int n2=p-store[i]; //index of third space
        store[i][n2]='`';

        p=strchr(store[i],'\n');
        int n3=p-store[i];

        for(j=0;j<n;j++)
            array[i].id[j]=store[i][j];//gets usn
        array[i].id[n]='\0';//to terminate the string so that strlen would work
        
        for(j=n+1;j<n1;j++)
            array[i].name[j-n-1]=store[i][j];//gets passwords
        array[i].name[j-n-1]='\0';//one is new line
        
        for(j=n1+1;j<n2;j++)
            array[i].qty[j-n1-1]=store[i][j];
        array[i].qty[j-n1-1]='\0';

        for(j=n2+1;j<n3;j++)
            array[i].price[j-n2-1]=store[i][j];
        array[i].price[j-n2-1]='\0';//overwrites \n charater
    }
    fclose(fp);
    return 0;
}
int getTotal(int c){
    int i,total=0;
    cart array[c];
    getFileContent(array);
    for(i=0;i<c;i++){
        int p,q;
        p=atoi(array[i].price);//converts string to int
        q=atoi(array[i].qty);
        total+=(p*q);
        
    }
    return total;
}
int genBill(int c){//owerwrites employee to file
    cart array[c];
    getFileContent(array);

    //rewrites file with details of temp added
    int i;
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="Bill1.txt";
    //*file name is a pointer pointing to the path of the text file
    fp=fopen(filename,"w");//opening th file
    if(fp==NULL){
        printf("Could not open file");
        return -1;//important
    }
    char strtemp[100];
    //******************************************
    char st[200]="\t\t\t\tXY SuperMarket\n";
    char st0[200]="-------------------------------------------------------------------------------------------------------------------------------------------------\n";
    fputs(st,fp);
    char st1[100]="Slno:\tItemcode\tName\t\tQuantity\tprice\n";
    fputs(st1,fp);
    char st2[200]="-------------------------------------------------------------------------------------------------------------------------------------------------\n";
    fputs(st2,fp);
    for(i=0;i<c;i++){//rewrites file
        char st[5];
        itoa((i+1),st,10);//conbverts to string for fputs
        strcat(st,"\t");
        fputs(st,fp);
        strcpy(strtemp,array[i].id);
        strcat(strtemp,"\t");
        strcat(strtemp,array[i].name);
        strcat(strtemp,"\t\t");
        strcat(strtemp,array[i].qty);
        strcat(strtemp,"\t");
        strcat(strtemp,array[i].price);
        strcat(strtemp,"\n");
        fputs(strtemp,fp);
    }
    char st7[200]="------------------------------------------------------------------------------------------------------------------------------------------------\n";
    int t=getTotal(c);
    char st801[10];
    itoa(t,st801,10);//conbverts to string for fputs
   
    int tax=t+(15/100)*t;
     char st802[10];
      itoa(t,st802,10);//conbverts to string for fputs
   
    char st8[200]="\t\t\tTotal:\t";
    char st9[200]="\t\t\tAfter tax:\t";
    char st10[200]="------------------------------------------------------------------------------------------------------------------------------------------------\n";
    char st11[4]="\n";
    char st12[50]="\t\t\tThank you for shopping\n";
    fputs(st7,fp);
    fputs(st8,fp);
    fputs(st801,fp);
    fputs("\n",fp);
    fputs(st9,fp);
    fputs(st802,fp);
    fputs("\n",fp);
    fputs(st10,fp);
    fputs(st11,fp);
    fputs(st12,fp); 
    fclose(fp);
    return 0;
}
int main(){
    int c=getLines();
    int n;
    printf("Generate Bill?:\n");
    printf("1-genBill\n");
    printf("2-Cancel\n");
    scanf("%d",&n);
    if(n==1){
        genBill(c);
        printf("Bill generated\n");
    }
    else{
        printf("Bill not generated\n");
    }
}