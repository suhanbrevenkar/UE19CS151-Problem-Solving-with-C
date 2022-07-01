#include<stdio.h>
#include<stdbool.h>
#include<string.h>
//employee details:
//ID NAME DOB Qualification Job Salary PhoneNO
typedef struct employee{
    char id[10];
    char name[20];
    char DOB[15];
    char Qual[10];
    char Job[10];
    char Salary[10];
    char Phone[15];
}emp;

int getLines(){
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="employeelist.txt";
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

int getFileContent(emp* array){//array of structures
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="employeelist.txt";
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
    /* char empid[50][5]; //50 empid
    char empName[50][25];//50 empNames
    char empDOB[50][13];//can store 50 DOB in dd//mm//yy format
    char empQual[50][10];//can store 50 qualifications
    char empJob[50][25];//50 empJob 
    char empSalary[50][10];//60 empsalary
    char empPhone[50][12];//50 phones
 */ 
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

        p=strchr(store[i],' ');
        int n3=p-store[i]; //index of fourth space
        store[i][n3]='`';

        p=strchr(store[i],' ');
        int n4=p-store[i]; //index of fifth space
        store[i][n4]='`';

        p=strchr(store[i],' ');
        int n5=p-store[i]; //index of sixth space
        store[i][n5]='`';
    
        //int n3=strlen(store[i]);
        p=strchr(store[i],'\n');
        int n6=p-store[i];

        for(j=0;j<n;j++)
            array[i].id[j]=store[i][j];//gets usn
        array[i].id[n]='\0';//to terminate the string so that strlen would work
        
        for(j=n+1;j<n1;j++)
            array[i].name[j-n-1]=store[i][j];//gets passwords
        array[i].name[j-n-1]='\0';//one is new line
        
        for(j=n1+1;j<n2;j++)
            array[i].DOB[j-n1-1]=store[i][j];
        array[i].DOB[j-n1-1]='\0';

        for(j=n2+1;j<n3;j++)
            array[i].Qual[j-n2-1]=store[i][j];
        array[i].Qual[j-n2-1]='\0';//overwrites \n charater
        
        for(j=n3+1;j<n4;j++)
            array[i].Job[j-n3-1]=store[i][j];
        array[i].Job[j-n3-1]='\0';//overwrites \n charater

        for(j=n4+1;j<n5;j++)
            array[i].Salary[j-n4-1]=store[i][j];
        array[i].Salary[j-n4-1]='\0';//overwrites \n charater

        for(j=n5+1;j<n6;j++)
            array[i].Phone[j-n5-1]=store[i][j];
        array[i].Phone[j-n5-1]='\0';//overwrites \n charater
        //printf("%s:%d\n",array[i].Phone,n6);
        //printf("%s",array[i].name);
    }
    fclose(fp);
}

int viewDetails(int c){
    int i;
    emp array[c];
    getFileContent(array);
    printf("values in array are:[]\n");
    //prints values in itemCode[] and itemName[]
    for(i=0;i<c;i++){   
        printf("code:%s\n",array[i].id);
        printf("Name:%s\n",array[i].name);
        printf("DOB:%s\n",array[i].DOB);
        printf("Qualification:%s\n",array[i].Qual);
        printf("Job:%s\n",array[i].Job);
        printf("Salary:%s\n",array[i].Salary);
        printf("Phone no.:%s\n",array[i].Phone);
        printf("------------------------------\n");
    }
    printf("\n");
    //converting string to integer in c:
    return 0; 
}

int addtoFile(int c,emp temp){//owerwrites employee to file
    emp array[c];
    getFileContent(array);

    //rewrites file with details of temp added
    int i;
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="employeelist.txt";
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
        strcat(strtemp,array[i].DOB);
        strcat(strtemp," ");
        strcat(strtemp,array[i].Qual);
        strcat(strtemp," ");
        strcat(strtemp,array[i].Job);
        strcat(strtemp," ");
        strcat(strtemp,array[i].Salary);
        strcat(strtemp," ");
        strcat(strtemp,array[i].Phone);
        strcat(strtemp,"\n");
        fputs(strtemp,fp);
    }
    //adds temp
    strcpy(strtemp,temp.id);
    strcat(strtemp," ");
    strcat(strtemp,temp.name);
    strcat(strtemp," ");
    strcat(strtemp,temp.DOB);
    strcat(strtemp," ");
    strcat(strtemp,temp.Qual);
    strcat(strtemp," ");
    strcat(strtemp,temp.Job);
    strcat(strtemp," ");
    strcat(strtemp,temp.Salary);
    strcat(strtemp," ");
    strcat(strtemp,temp.Phone);
    strcat(strtemp,"\n");
    fputs(strtemp,fp);
    fclose(fp);
    return 0;
}

int modifyFile(int c,emp temp){
    emp array[c];
    getFileContent(array);

    //rewrites file with details of temp added
    int i;
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="employeelist.txt";
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
            strcpy(strtemp,temp.id);
            strcat(strtemp," ");
            strcat(strtemp,temp.name);
            strcat(strtemp," ");
            strcat(strtemp,temp.DOB);
            strcat(strtemp," ");
            strcat(strtemp,temp.Qual);
            strcat(strtemp," ");
            strcat(strtemp,temp.Job);
            strcat(strtemp," ");
            strcat(strtemp,temp.Salary);
            strcat(strtemp," ");
            strcat(strtemp,temp.Phone);
            strcat(strtemp,"\n");
            fputs(strtemp,fp);
        }
        else{//id are not equal
            strcpy(strtemp,array[i].id);
            strcat(strtemp," ");
            strcat(strtemp,array[i].name);
            strcat(strtemp," ");
            strcat(strtemp,array[i].DOB);
            strcat(strtemp," ");
            strcat(strtemp,array[i].Qual);
            strcat(strtemp," ");
            strcat(strtemp,array[i].Job);
            strcat(strtemp," ");
            strcat(strtemp,array[i].Salary);
            strcat(strtemp," ");
            strcat(strtemp,array[i].Phone);
            strcat(strtemp,"\n");
            fputs(strtemp,fp);
        }
    }
    fclose(fp);
    return 0;
}

int removefromFile(int c,char* id){
    emp array[c];
    getFileContent(array);

    //rewrites file with details of temp added
    int i;
    int max=100;
    FILE *fp;//you dont need a header file for file handling
    char str[max];
    char *filename="employeelist.txt";
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
            continue;//skips one record
        }
        else{//id are not equal
            strcpy(strtemp,array[i].id);
            strcat(strtemp," ");
            strcat(strtemp,array[i].name);
            strcat(strtemp," ");
            strcat(strtemp,array[i].DOB);
            strcat(strtemp," ");
            strcat(strtemp,array[i].Qual);
            strcat(strtemp," ");
            strcat(strtemp,array[i].Job);
            strcat(strtemp," ");
            strcat(strtemp,array[i].Salary);
            strcat(strtemp," ");
            strcat(strtemp,array[i].Phone);
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
    printf("1-view Employee details:\n");
    printf("2-modify\n");
    printf("3-exit\n");
    scanf("%d",&n);
    return n;
}
void getdata(emp* temp){
    printf("Enter empID:\n");
    scanf("%s",temp->id);
    
    printf("Enter empName:\n");
    scanf("%s",temp->name);
    
    printf("Enter empDOB:\n");
    scanf("%s",temp->DOB);

    printf("Enter empQual:\n");
    scanf("%s",temp->Qual);

    printf("Enter empJob:\n");
    scanf("%s",temp->Job);
    
    printf("Enter empSalary:\n");
    scanf("%s",temp->Salary);
    
    printf("Enter empPhone:\n");
    scanf("%s",temp->Phone);
    
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
            viewDetails(c);
            break;
            case 2:
            do{
                c=getLines();//returns n of lines in prgm//important
                printf("Enter \n");
                printf("1-add emplyee\n");
                printf("2-modify employee details\n");
                printf("3-remove employee\n");
                printf("4-exit\n");
                scanf("%d",&n1);
                emp temp;
                char empid[10];
                switch(n1){
                    case 1:
                    getdata(&temp);//initialises temp
                    addtoFile(c,temp);
                    break;
                    case 2:
                    printf("Enter empid:\n");
                    scanf("%s",empid);
                    printf("Enter employee details:\n");
                    getdata(&temp);
                    modifyFile(c,temp);
                    break;
                    case 3:
                    printf("Enter empid:\n");
                    scanf("%s",empid);
                    removefromFile(c,empid);
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