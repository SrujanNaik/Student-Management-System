#include<stdio.h>
#include<string.h>

void studentDetails();
void newStudent(int);
void deleteStudent(int);
void updateStudent();
int linenumber();

int main(){
	int userchoice;

	char Student_name,USN,Branch,Section;
	int Semester;
	float cgpa;
	int line_number = linenumber();

	printf("\n------------------------Welcome to Student Database---------------------------\n\n");
	while(1){
	printf("\nWhat you are seeaking?\n");
	printf("1.All Student Details \n");
	printf("2.Enter New Student \n");
	printf("3.Delete Exesting Student\n");
	printf("4.Update Student Information \n");
	printf("5.Exit \n");

	printf("\n\n");

	printf("Enter your choice : ");
	scanf("%d",&userchoice);
	printf("\n");

	if(userchoice == 5){
		printf("\nExiting\n");
		break;
	}

	switch(userchoice){
		case 1 :
			printf("\n-----------------------------------------------------------------------------------------\n");
			studentDetails();
			printf("\n-----------------------------------------------------------------------------------------\n");
			break;
		case 2 :
			newStudent(line_number);
			line_number++;
			break;
		case 3 :
			deleteStudent(line_number);
			line_number--;
			break;
		/*
		case 4 : 
			updateStudent();
			break;
			*/
		default :
			printf("\nTry again with valid input\n");
			break;
	}
	}

	printf("\n..............................................................................\n");
	return 0;
}

int linenumber(){
	int line_number = 1;
	FILE *file = fopen("StudentInformation.txt","r");

	if(file == NULL){
		printf("Database is not working try again");
		return -1;
	}

	char line[1024];

	while(fgets(line, sizeof(line), file)){
		char *field = strtok(line, ">");

		while(field){
			field = strtok(NULL, ">");
		}
		line_number++;
	}
	fclose(file);
	return line_number;
}

void newStudent(int line_number){
	FILE *file = fopen("StudentInformation.txt","a");

	if(file == NULL){
		printf("Database is not working try again");
		return;
	}

	char studentName[20],USN[12],Branch[5];
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
	scanf(" %s",Branch);
	printf("\n");
	printf("Student Section : ");
	scanf(" %c",&Section);
	printf("\n");
	printf("Student Semester : ");
	scanf(" %d",&Semester);
	printf("\n");
	printf("Student CGPA : ");
	scanf(" %f",&cgpa);
	printf("\n\n");

	fprintf(file,"%d.|%s\t|%s\t|%s\t|%c\t|%d\t|%.2f\t|>\n",line_number,studentName,USN,Branch,Section,Semester,cgpa);
	
	fclose(file);

	printf("Suscessfull!");
}

void studentDetails(){
	FILE *file = fopen("StudentInformation.txt","r");

	if(file == NULL){
		printf("Database is not working try again");
		return;
	}

	char line[1024];

	while(fgets(line, sizeof(line), file)){
		char *field = strtok(line, ">");

		while(field){
			printf("%s",field);
			field = strtok(NULL, ">");
		}
		printf("\n");
	}
	fclose(file);

}

void deleteStudent(int line_number){

	printf("\n-----------------------------------------------------------------------------------------\n");
	studentDetails();
	printf("\n-----------------------------------------------------------------------------------------\n");

	const char *filename = "StudentInformation.txt";
	FILE *file = fopen(filename,"r");
	FILE *temp = fopen("temp.txt","w");

	if(file == NULL){
		printf("Database is not working try again");
		return;
	}
	if(temp == NULL){
		printf("Database is not working try again");
		return;
	}

	int toRemove;
	printf("\nEnter the line number to be removed\n");
	scanf("%d",&toRemove);

	char buffer[1024];
	int current_line = 1;

	while(fgets(buffer, sizeof(buffer), file)){
		if(current_line != toRemove){
			fputs(buffer, temp);
		}
		current_line++;
	}
	fclose(file);
	fclose(temp);

	remove(filename);
	rename("temp.txt",filename);

	printf("\nLine Removed!\n");
}
