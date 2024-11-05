#include<stdio.h>

void studentDetails();
int newStudent();
void deleteStudent();
void updateStudent();

int main(){
	int userchoice;

	char Student_name,USN,Branch,Section;
	int Semester;
	float cgpa;

	printf("\n------------------------Welcome to Student Database---------------------------\n\n");
	printf("What you are seeaking?\n");
	printf("1.All Student Details \n");
	printf("2.Enter New Student \n");
	printf("3.Delete Exesting Student\n");
	printf("4.Update Student Information \n");
	printf("5.Exit \n");

	printf("\n\n");

	printf("Enter your choice : ");
	scanf("%d",&userchoice);
	printf("\n");

	switch(userchoice){
		/*
		case 1 :
			studentDetails();
			break;
			*/
		case 2 :
			newStudent();
			break;
			/*
		case 3 :
			deleteStudent();
			break;
		case 4 : 
			updateStudent();
			break;
			*/
		default :
			printf("Try again with valid input");
			break;
	}

	printf("..............................................................................\n");
}

int newStudent(){
	FILE *file = fopen("StudentInformation.csv","a");

	if(file == NULL){
		printf("Database is not working try again");
		return 1;
	}

	char studentName[20],USN[10],Branch[5];
	char Section;
	int Semester;
	float cgpa;

	printf("Student name : ");
	scanf("%s",studentName);
	printf("\n");
	printf("Student USN : ");
	scanf("%s",USN);
	printf("\n");
	printf("Student Branch : ");
	scanf("%s",Branch);
	printf("\n");
	printf("Student Section : ");
	scanf(" %c",&Section);
	printf("\n");
	printf("Student Semester : ");
	scanf("%d",&Semester);
	printf("\n");
	printf("Student CGPA : ");
	scanf("%.2f",&cgpa);
	printf("\n\n");

	fprintf(file,"%s,%s,%s,%c,%d,%.2f\n",studentName,USN,Branch,Section,Semester,cgpa);
	
	fclose(file);

	printf("Suscessfull!");
}
