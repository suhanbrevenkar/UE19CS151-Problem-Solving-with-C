#include<stdio.h>
#include<stdbool.h>
#include<string.h>
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

int viewDetails(int c){
    int i;
    cart array[c];
    getFileContent(array);
    printf("values in array are:[]\n");
    //prints values in cartCode[] and cartName[]
    for(i=0;i<c;i++){   
        printf("code:%s\n",array[i].id);
        printf("Name:%s\n",array[i].name);
        printf("Qauntity:%s\n",array[i].qty);
        printf("Price:%s\n",array[i].price);
        printf("------------------------------\n");
    }
    printf("\n");
    //converting string to integer in c:
    return 0; 
}

int addtoFile(int c,cart temp){//owerwrites employee to file
    cart array[c];
    getFileContent(array);

    //rewrites file with details of temp added
    int i;
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="cart.txt";
    //*file name is a pointer pointing to the path of the text file
    fp=fopen(filename,"w");//opening th file
    if(fp==NULL){
        printf("Could not open file");
        return -1;//important
    }
    char strtemp[100];
    //******************************************
    for(i=0;i<c;i++){//rewrites file
        strcpy(strtemp,array[i].id);
        strcat(strtemp," ");
        strcat(strtemp,array[i].name);
        strcat(strtemp," ");
        strcat(strtemp,array[i].qty);
        strcat(strtemp," ");
        strcat(strtemp,array[i].price);
        strcat(strtemp,"\n");
        fputs(strtemp,fp);
    }
    //adds temp
    strcpy(strtemp,temp.id);
    strcat(strtemp," ");
    strcat(strtemp,temp.name);
    strcat(strtemp," ");
    strcat(strtemp,temp.qty);
    strcat(strtemp," ");
    strcat(strtemp,temp.price);
    strcat(strtemp,"\n");
    fputs(strtemp,fp);
    fclose(fp);
    return 0;
}

int modifyFile(int c,cart temp){
    cart array[c];
    getFileContent(array);

    //rewrites file with details of temp added
    int i;
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="cart.txt";
    //*file name is a pointer pointing to the path of the text file
    fp=fopen(filename,"w");//opening the file
    if(fp==NULL){
        printf("Could not open file");
        return -1;//important
    }
    char strtemp[200];

    //******************************************
    for(i=0;i<c;i++){//rewrites file
        if(strcmp(temp.id,array[i].id)==0){//id are equal
            printf("\n");
            strcpy(strtemp,temp.id);
            strcat(strtemp," ");
            strcat(strtemp,temp.name);
            strcat(strtemp," ");
            strcat(strtemp,temp.qty);
            strcat(strtemp," ");
            strcat(strtemp,temp.price);
            strcat(strtemp,"\n");
            fputs(strtemp,fp);
        }
        else{//id are not equal
            printf("");
            strcpy(strtemp,array[i].id);
            strcat(strtemp," ");
            strcat(strtemp,array[i].name);
            strcat(strtemp," ");
            strcat(strtemp,array[i].qty);
            strcat(strtemp," ");
            strcat(strtemp,array[i].price);
            strcat(strtemp,"\n");
            fputs(strtemp,fp);
        }
    }
    fclose(fp);
    return 0;
}

int removefromFile(int c,char* id){
    cart array[c];
    getFileContent(array);

    //rewrites file with details of temp added
    int i;
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="cart.txt";
    //*file name is a pointer pointing to the path of the text file
    fp=fopen(filename,"w");//opening the file
    if(fp==NULL){
        printf("Could not open file");
        return -1;//important
    }
    char strtemp[200];

    //******************************************
    for(i=0;i<c;i++){//rewrites file
        if(strcmp(id,array[i].id)==0){//id are equal
            printf("s:%d\n",i);
            continue;//skips one record
        }
        else{//id are not equal
            printf("");
            strcpy(strtemp,array[i].id);
            strcat(strtemp," ");
            strcat(strtemp,array[i].name);
            strcat(strtemp," ");
            strcat(strtemp,array[i].qty);
            strcat(strtemp," ");
            strcat(strtemp,array[i].price);
            strcat(strtemp,"\n");
            fputs(strtemp,fp);
        }
    }
    fclose(fp);
    return 0;
}
int choice(){
    int n;
    printf("Enter options:\n");
    printf("1-view Cart:\n");
    printf("2-modify\n");
    printf("3-exit\n");
    scanf("%d",&n);
    return n;
}
void getdata(cart* temp){
    printf("Enter itemID:\n");
    scanf("%s",temp->id);
    
    printf("Enter itemName:\n");
    scanf("%s",temp->name);
    
    printf("Enter itemQty:\n");
    scanf("%s",temp->qty);

    printf("Enter itemQual:\n");
    scanf("%s",temp->price);

}
int main()
{
    bool t =true;
    bool t1=true;
    int n;
    int n1;
    int c;
    do{
        n=choice();
        switch(n){
            case 1:
            c=getLines();//returns n of lines in prgm
            printf("%d\n",c);
            viewDetails(c);
            break;
            case 2:
            do{
                c=getLines();//returns n of lines in prgm//important
                printf("Enter \n");
                printf("1-add Cart\n");
                printf("2-modify Cart details\n");
                printf("3-remove item from Cart\n");
                printf("4-exit\n");
                scanf("%d",&n1);
                cart temp;
                char cartid[10];
                switch(n1){
                    case 1:
                    getdata(&temp);//initialises temp
                    addtoFile(c,temp);
                    break;
                    case 2:
                    printf("Enter itemid:\n");
                    scanf("%s",cartid);
                    printf("Enter Cart details:\n");
                    getdata(&temp);
                    modifyFile(c,temp);
                    break;
                    case 3:
                    printf("Enter Cartid:\n");
                    scanf("%s",cartid);
                    removefromFile(c,cartid);
                    break;
                    default:
                    t1=false;
                    break;
                }
            }while(t1);
            break;
            default:
            t=false;
            break;
        }
    }while(t);
}