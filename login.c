#include<stdio.h>
#include<stdbool.h>
#include<string.h>
//employee details:
//ID NAME DOB Qualification Job Salary PhoneNO


typedef struct loginDetails{
    char usn[20];
    char pass[20];
    char identity[5];//o or e
}login;

int getLines(){
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="passwords.txt";
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

int getFileContent(login* array){//array of structures
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="passwords.txt";
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

        p=strchr(store[i],'\n');
        int n2=p-store[i];

        for(j=0;j<n;j++)
            array[i].usn[j]=store[i][j];//gets usn
        array[i].usn[n]='\0';//to terminate the string so that strlen would work
        
        for(j=n+1;j<n1;j++)
            array[i].pass[j-n-1]=store[i][j];//gets passwords
        array[i].pass[j-n-1]='\0';//one is new line
        
        for(j=n1+1;j<n2;j++)
            array[i].identity[j-n1-1]=store[i][j];
        array[i].identity[j-n1-1]='\0';//overwrites \n charater
    }
    fclose(fp);
    return 0;
}

int viewDetails(int c){
    int i;
    login array[c];
    getFileContent(array);
    printf("values in array are:[]\n");
    //prints values in loginCode[] and loginName[]
    for(i=0;i<c;i++){   
        printf("USN:%s\n",array[i].usn);
        printf("PASS:%s\n",array[i].pass);
        printf("Identity:%s\n",array[i].identity);
        printf("------------------------------\n");
    }
    printf("\n");
    //converting string to integer in c:
    return 0; 
}

int addtoFile(int c,login temp){//overwrites file
    login array[c];
    getFileContent(array);

    //rewrites file with details of temp added
    int i;
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="passwords.txt";
    //*file name is a pointer pointing to the path of the text file
    fp=fopen(filename,"w");//opening th file
    if(fp==NULL){
        printf("Could not open file");
        return -1;//important
    }
    char strtemp[100];
    //******************************************
    for(i=0;i<c;i++){//rewrites file
        strcpy(strtemp,array[i].usn);
        strcat(strtemp," ");
        strcat(strtemp,array[i].pass);
        strcat(strtemp," ");
        strcat(strtemp,array[i].identity);
        strcat(strtemp,"\n");
        fputs(strtemp,fp);
    }
    //adds temp
    strcpy(strtemp,temp.usn);
    strcat(strtemp," ");
    strcat(strtemp,temp.pass);
    strcat(strtemp," ");
    strcat(strtemp,temp.identity);
    strcat(strtemp,"\n");
    fputs(strtemp,fp);
    fclose(fp);
    return 0;
}

int modifyFile(int c,login temp){
    login array[c];
    getFileContent(array);

    //rewrites file with details of temp added
    int i;
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="passwords.txt";
    //*file name is a pointer pointing to the path of the text file
    fp=fopen(filename,"w");//opening the file
    if(fp==NULL){
        printf("Could not open file");
        return -1;//important
    }
    char strtemp[200];

    //******************************************
    for(i=0;i<c;i++){//rewrites file
        if(strcmp(temp.usn,array[i].usn)==0){//id are equal
            printf("\n");
            strcpy(strtemp,temp.usn);
            strcat(strtemp," ");
            strcat(strtemp,temp.pass);
            strcat(strtemp," ");
            strcat(strtemp,temp.identity);
            strcat(strtemp,"\n");
            fputs(strtemp,fp);
        }
        else{//id are not equal
            printf("");
            strcpy(strtemp,array[i].usn);
            strcat(strtemp," ");
            strcat(strtemp,array[i].pass);
            strcat(strtemp," ");
            strcat(strtemp,array[i].identity);
            strcat(strtemp,"\n");
            fputs(strtemp,fp);
        }
    }
    fclose(fp);
    return 0;
}

int removefromFile(int c,char id[]){
    login array[c];
    getFileContent(array);

    //rewrites file with details of temp added
    int i;
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="passwords.txt";
    //*file name is a pointer pointing to the path of the text file
    fp=fopen(filename,"w");//opening the file
    if(fp==NULL){
        printf("Could not open file");
        return -1;//important
    }
    char strtemp[200];

    //******************************************
    for(i=0;i<c;i++){//rewrites file
        if(strcmp(id,array[i].usn)==0){//id are equal
            //printf("s:%d\n",i);
            //continue;//skips one record
        }
        else{//id are not equal
            printf("");
            strcpy(strtemp,array[i].usn);
            strcat(strtemp," ");
            strcat(strtemp,array[i].pass);
            strcat(strtemp," ");
            strcat(strtemp,array[i].identity);
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
    printf("1-view Password:\n");
    printf("2-modify\n");
    printf("3-exit\n");
    scanf("%d",&n);
    return n;
}
void getdata(login* temp){
    printf("Enter USN:\n");
    scanf("%s",temp->usn);
    
    printf("Enter Pass:\n");
    scanf("%s",temp->pass);
    
    printf("Enter Identity:\t(O/E):\n");
    scanf("%s",temp->identity);
}
int passcheck(int c,char* _usn,char* _pass,char* _id){//id s initially empty
    login array[c];
    getFileContent(array);
    int i,ret=0;
    for(i=0;i<c;i++){
        if(strcmp(_usn,array[i].usn)==0 && strcmp(_pass,array[i].pass)==0){
            ret=1;
            printf("Logged in successfully\n");
            break;
        }
    }
    return ret;
}
int main()
{
    bool t =true;
    bool t1=true;
    int n;
    int n1;
    int c;
    char usn[20];
    char pass[20];
    char id[5];
    printf("Enter usn and pass:\n");
    printf("Usn:");
    scanf("%s",usn);
    printf("Pass:");
    scanf("%s",pass);
    int check;
    c=getLines();//returns n of lines in prgm
    check=passcheck(c,usn,pass,id);
    if(check){
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
                printf("1-add Profile\n");
                printf("2-modify Profile details\n");
                printf("3-remove Profile \n");
                printf("4-exit\n");
                scanf("%d",&n1);
                login temp;
                char loginid[10];
                switch(n1){
                    case 1:
                    getdata(&temp);//initialises temp
                    addtoFile(c,temp);
                    break;
                    case 2:
                    printf("Enter itemid:\n");
                    scanf("%s",loginid);
                    printf("Enter login details:\n");
                    getdata(&temp);
                    modifyFile(c,temp);
                    break;
                    case 3:
                    printf("Enter loginid:\n");
                    scanf("%s",loginid);
                    removefromFile(c,loginid);
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
    else{
        printf("login failed\n");
    }
}