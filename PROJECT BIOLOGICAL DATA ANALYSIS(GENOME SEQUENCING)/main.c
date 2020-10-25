#include <stdio.h>
#include <string.h>
char* substring(char input[], int startIndex, int length);
char* complementfunction(char input[], int length);


char* substring(char input[], int startIndex, int length)
{
    char out[length+1];
    int i;
    for(i=0;i<length;i++)
    {
        out[i] = input[startIndex+i];
    }
    out[i] = '\0';
    return out;
}

char* complementfunction(char input[], int length)
{
    int i;
    char out[length+1];
    for(i=0;i<length;i++)
    {
    if(input[i]=='C') out[i]='G';
    else if(input[i]=='A') out[i]='T';
    else if(input[i]=='T') out[i]='A';
        else if(input[i]=='G') out[i]='C';
    }
    out[i]='\0';
    return out;

}

int main()

{
    system("color 0B");
    int choice,password;

    printf("\t\t\t BIOLOGICAL DATA ANALYSIS\n");
    printf(" \t\t      _____________________________\n\n");
    printf("Please! Enter Your Password(Password must contain 8 characters): ");
    scanf("%d",&password);

    if(password==10501911)
    {




    printf("\n\n\t\t\tWelcome To The Project Of CSE115\n");
    printf("\t\t      ____________________________________\n\n");
    printf("\n\n\t1.Sequence a GENOME Randomly from Console.\n\n\t2.Sequence a GENOME From File.");
    printf("\n\n\n\n\n\n\n  Choose from the above one to continue...(1/2) : ");
    scanf("%d",&choice);

    if(choice==2)
    {



    FILE *Ain,*Aout;
    printf("\n\n\t\tWe Know GENOME is a String of \"ATGC\". \n\tWe are doing GENOME SEQUENCING using Sanger SEQUENCING Method. \n\tYou can cut a GENOME in Many parts Randomly and Can Get \n \t\t Complement Of That Part Using This Program. ");
    printf("\n\n");
    printf("  We Can Access 10 Parts of GENOME from Below : \n\n");
    printf("\t1.  GENOME phase 1\n\t2.  GENOME phase 2\n\t3.  GENOME phase 3\n\t4.  GENOME phase 4\n\t5.  GENOME phase 5\n\t6.  GENOME phase 6\n\t7.  GENOME phase 7\n\t8.  GENOME phase 8\n\t9.  GENOME phase 9\n\t10. GENOME phase 10\n\n");
    int input;
    printf("\n\nWhich file do you want to Modify: ");
    scanf("%d",&input);
    if(input<=10)
    {

    char fileName[100],temp[10];
    strcpy(fileName,"phase");
    strcat(fileName,itoa(input,temp,10));
    strcat(fileName,".txt");
    //printf("%s",fileName);

    char fileName1[100],temp1[10];
    strcpy(fileName1,"Resultofphase");
    strcat(fileName1,itoa(input,temp1,10));
    strcat(fileName1,".txt");
    //printf("%s",fileName);

    Ain = fopen(fileName,"r");
    Aout= fopen(fileName1,"w");
    char A[40000];

    printf("\n\n\n\n\t\t\t\"%s\" File Opened Successfully!!\n\n\n\n\n",fileName);



    fscanf(Ain,"%[^\n]", A);

    printf("\n\n\t\t\t\"%s\" Contains %d \"ATGC\".",fileName,strlen(A));



    fprintf(Aout,"Data on the file \"%s\" is :\n\n\n%s",fileName, A);
    fclose(Ain);


    int i,j,begi[i],finish,striLEN,striNUM,i1,i2;
        printf("\n\n\n\tPlease! Enter How Many Strings You Want To Choose From The Genome : ");
        scanf("%d",&striNUM);
         printf("\n\n\n\tPlease Enter The Length Of The String, \n\n\tWhich Will Be Taken From The Genome Randomly: ");
        scanf("%d",&striLEN);


        if(striLEN>=strlen(A))
        {
            printf("SORRY!! You Entered Wrong INPUT! Please Try Entering length less than the GENOME! ");
        }
        else
            {

        char str[striLEN];
        fprintf(Aout,"\n\n______________________________________________________________________________________________________________________");
        fprintf(Aout,"\n______________________________________________________________________________________________________________________\n");
        fprintf(Aout,"\n\n\t\t\tNumber Of Strings : %d \n\n\t\t\tLength Of Each String : %d\n\n",striNUM,striLEN);
        fprintf(Aout,"\n\n\n\t\t\tMethod: Sanger Sequencing(1st Generation Sequencing)");
        fprintf(Aout,"\n\n______________________________________________________________________________________________________________________");
        fprintf(Aout,"\n______________________________________________________________________________________________________________________\n\n\n\n");

    for(i=0;i<striNUM;i++)
    {


    finish=rand()%strlen(A);
        if(finish<striLEN)
    {
        i-=1;

    }
    else
    {
    begi[i]=finish-striLEN;

    fprintf(Aout,"String No %d Starts From Index %d And Range is %d\n\n",i+1,begi[i],finish);

    }

    }
    fprintf(Aout,"______________________________________________________________________________________________________________________");
    fprintf(Aout,"\n______________________________________________________________________________________________________________________");


   char output[striNUM][striLEN+1];

    for(i=0;i<striNUM;i++)
    {
        strcpy(output[i],substring(A,begi[i], striLEN));
        fprintf(Aout,"\n\n\t\t\t\tSTRING no %d is %s\n\n",i+1,output[i]);
    }
    fprintf(Aout,"______________________________________________________________________________________________________________________");
     fprintf(Aout,"\n______________________________________________________________________________________________________________________");
    char complementS[striNUM][striLEN+1];


    for(i=0;i<striNUM;i++)
    {
        strcpy(complementS[i],complementfunction(output[i],striLEN));
        fprintf(Aout,"\n\n\t\t\t Complement Of String No %d Is %s\n\n",i+1,complementS[i]);
    }
    fprintf(Aout,"______________________________________________________________________________________________________________________");
    fprintf(Aout,"\n______________________________________________________________________________________________________________________");


   for(i=0;i<striNUM;i++)
   {
       fprintf(Aout,"\nBases Of String No %d is : \n",i+1);
       fprintf(Aout,"***********************************************************************\n");
       for(j=0;j<striLEN;j++)
       {
           fprintf(Aout,"\t\t\t\t\t%c==%c\n",output[i][j],complementS[i][j]);
       }
       fprintf(Aout,"***********************************************************************");
       fprintf(Aout,"\n\n");
   }
   fprintf(Aout,"\n\n\n\n\n\t\t\t\t\t\t\t\t GENOME SEQUENCING in C!! \n\t\t\t\t\t\t\t\t Project by: Monsur Hillas and Shoumik Mahbub Ridoy.\n\t\t\t\t\t\t\t\t University:North South University.\n\t\t\t\t\t\t\t\t ID: 1721911642 and 1721050642.\n\t\t\t\t\t\t\t\t Sec: 5 \n\t\t\t\t\t\t\t\t Faculty: Sharmina Zaman(SAM)\n\t\t\t\t\t\t\t\t\tTHANKS!!");
   fclose(Aout);

   printf("\n\n\n\n*******************************************************************************");

   printf("\n\n\t\t   GENOME SEQUENCED successfully!! \n\n\tPlease Check Your Destined Folder To Get The New File!! \n\n\t\t\t\tTHANKS!!!");
   printf("\n\n*******************************************************************************");
            }

            }
            else printf("\n\n\n\t\t\tWrong INPUT!!\n\n \tTry Entering Number From 1-10 !! ");

    }


    else if (choice==1)
    {


int i,j,num,start,range,genomeRNG;
//printf("\t\t\t\tWELCOME TO THE PROJECT!!! \n\n");
printf("\n\n\n\tYou Entered,\n\n\t\t1.Sequence a GENOME Randomly from Console\n\n\n");
printf("_______________________________________________________________________________\n\n\n");
printf("\tHere you can Learn about Biological Data Analysis. \n\n\tMain Topic Of This Project Is Genome Sequencing. \n\n\tHere We  Have Used a method Called Sanger Sequencing.\n\t This Method is Called a First Generation GENOME SEQUENCING Method!! \n\t\tPlease Proceed!!\n\n");
printf("\tPlease! Enter the length of the Genome which will create randomly : ");
scanf("%d",&genomeRNG);
char s[genomeRNG],*ptr;
printf("\n\n");


start=(int) ('A');


range=(int) ('E') - (int) ('A');

for(ptr=s,i=1;i<=genomeRNG;++ptr,++i)
{
    num=rand() %range;
   if(num==1) {num=6;}
    if(num==3) {num=19;}
    *ptr=(char)(num+start);
}
*ptr='\0';
    printf("   %s\n\n",s);




        int begi[i],finish,striLEN,striNUM,i1,i2;
        printf("\n\tPlease! Enter how many Strings you want to choose from the Genome : ");
        scanf("%d",&striNUM);
         printf("\n\tPlease Enter the length of the String, \n\tWhich will be taken from the Genome Randomly: ");
        scanf("%d",&striLEN);


        if(striLEN>=genomeRNG)
        {
            printf("SORRY!! You Entered Wrong INPUT! Please Try Entering length less than the GENOME! ");
        }
        else
            {

        char str[striLEN];
        printf("-------------------------------------------------------------");
        printf("\n-------------------------------------------------------------\n");

    for(i=0;i<striNUM;i++)
    {


    finish=rand()%genomeRNG;
        if(finish<striLEN)
    {
        i-=1;

    }
    else
    {
    begi[i]=finish-striLEN;

    //printf("String No %d Starts From Index %d and Range is %d\n\n",i+1,begi[i],finish);

    }

    }
    //printf("-------------------------------------------------------------");
    //printf("\n-------------------------------------------------------------");


   char output[striNUM][striLEN+1];

    for(i=0;i<striNUM;i++)
    {
        strcpy(output[i],substring(s,begi[i], striLEN));
        printf("\n\n\t\t\tSTRING no %d is %s\n\n",i+1,output[i]);
    }
    printf("-------------------------------------------------------------");
     printf("\n-------------------------------------------------------------");
    char complementS[striNUM][striLEN+1];


    for(i=0;i<striNUM;i++)
    {
        strcpy(complementS[i],complementfunction(output[i],striLEN));
        printf("\n\n\t\t Complement of string no %d is %s\n\n",i+1,complementS[i]);
    }
    printf("-------------------------------------------------------------");
    printf("\n-------------------------------------------------------------");


  /* for(i=0;i<striNUM;i++)
   {
       printf("\nComplement of String No %d is : \n",i+1);
       printf("**************************************************************\n");
       for(j=0;j<striLEN;j++)
       {
           printf("\t\t\t\t\t%c==%c\n",output[i][j],complementS[i][j]);
       }
       printf("*************************************************************");
       printf("\n\n");
   }*/
            }
    }
    else printf("\n\n\n\t\tWrong Input! Please Try Again!! \n\t\t TIPS: Choose Between 1 and 2 \n\n");


    }

    else printf("\n\n\n*******************************************************************************\n\n\t\tSorry! You Entered Wrong Password!! \n\t\t\t Please Try Again!! ");

    return 0;

}


