#include <iostream> //to display output on the screen and read input from the keyboard
#include <iomanip> //to defines the manipulator functions
#include <fstream> //to perform input/output operations on a file
using namespace std; //to provide a scope to the identifiers


//prototype of fuctions
bool test(char, char, char, char, char);
double total(char);
double average(double, double);
void display(int, int, int, double, double, double, double, double, double);


int main() //main function
{
	//declaration and initialization of variables
	//to create arrays with the size of the input
	int res, insc, courc, ins, cour;
	double total_Q1 = 0, total_Q2 = 0, total_Q3 = 0, total_Q4 = 0, total_Q5 = 0,
		avg_Q1 = 0, avg_Q2 = 0, avg_Q3 = 0, avg_Q4 = 0, avg_Q5 = 0, ins_avg, size = 0;


	ofstream outputFile("DataOutput.txt", ios::out); //to output a file named as "DataOutput"






//this if condition is to exit program if the file could not be opened
	if (!outputFile) {
		cerr << "File could not be opened \n";
		exit(1);
	}
	//prompt user to enter value
	cout << "Instructor Evaluator." << endl << endl
		<< "Enter number of respondent: ";
	cin >> res;
	cout << "Enter Instructor number: ";
	cin >> ins;
	cout << "Enter Course code: ";
	cin >> cour;
	//to create arrays with the size of the input
	char Q1[res], Q2[res], Q3[res], Q4[res], Q5[res], q[5];
	//this for loop is to enter value into the arrays created
	for (int i = 0; i < res; i++) {
		cout << "\nData set: " << (i + 1) << endl
			<< "Instructor code: " << ins
			<< "\nCourse code: " << cour
			<< "\nE=Excellent   G=Good   A=Average   P=Poor   U=Unsatisfactory\n"
			<< "Enter either 'E', 'G' , 'A', 'P', or 'U' for five questions about the instructor: \n\n"
			<< "Knowledge of Subject Matter: ";
		cin >> Q1[i];
		cout << "Organization: ";
		cin >> Q2[i];
		cout << "Effectiveness: ";
		cin >> Q3[i];
		cout << "Helpfulness: ";
		cin >> Q4[i];
		cout << "Dedication: ";
		cin >> Q5[i];
		//this while loop is to only enter A,E,G,U,P
		while (test(Q1[i], Q2[i], Q3[i], Q4[i], Q5[i]) != true) {
			cout << "Invalid Characters! Only  re-enter either 'E', 'G', 'A', 'P', or 'U' for five questions: " << endl;
			cout << "Knowledge of Subject Matter: ";
			cin >> Q1[i];
			cout << "Organization: ";
			cin >> Q2[i];
			cout << "Effectiveness: ";
			cin >> Q3[i];
			cout << "Helpfulness: ";
			cin >> Q4[i];
			cout << "Dedication: ";
			cin >> Q5[i];
			test(Q1[i], Q2[i], Q3[i], Q4[i], Q5[i]);
		}
		//to change the lowercase to uppercase
		if (islower(Q1[i])) {
			Q1[i] = Q1[i] - 32;
		}
		if (islower(Q2[i])) {
			Q2[i] = Q2[i] - 32;
		}
		if (islower(Q3[i])) {
			Q3[i] = Q3[i] - 32;
		}
		if (islower(Q4[i])) {
			Q4[i] = Q4[i] - 32;
		}
		if (islower(Q5[i])) {
			Q5[i] = Q5[i] - 32;
		}
		//to output in the file
		outputFile << ins << "    " << cour << "  " << (Q1[i]) << " " << (Q2[i]) << " " << (Q3[i]) << " " << (Q4[i]) << " " << (Q5[i]) << endl;
	}

	ifstream inputFile("DataOutput.txt");//obtain the data from the created file
	if (!inputFile)
	{
		cerr << "File could not be opened\n";//error message will pop up if file could not be opened
		exit(1);
	}

	while (inputFile >> insc >> courc >> q[0] >> q[1] >> q[2] >> q[3] >> q[4])
	{
		//to total up the values using fucntion call
		total_Q1 += total(q[0]);
		total_Q2 += total(q[1]);
		total_Q3 += total(q[2]);
		total_Q4 += total(q[3]);
		total_Q5 += total(q[4]);
		size++;
	}


	//use functions to calculate the average for each questions
	avg_Q1 = average(total_Q1, size);
	avg_Q2 = average(total_Q2, size);
	avg_Q3 = average(total_Q3, size);
	avg_Q4 = average(total_Q4, size);
	avg_Q5 = average(total_Q5, size);


	//use formulae to calculate the instructor average
	ins_avg = (0.15 * avg_Q1) + (0.23 * avg_Q2) + (0.08 * avg_Q3) + (0.32 * avg_Q4) + (0.22 * avg_Q5);


	//fucntion call to diplay output
	display(ins, cour, res, avg_Q1, avg_Q2, avg_Q3, avg_Q4, avg_Q5, ins_avg);
	return 0;
}


//funtion to check whether input is within (A,E,G,U,P,)
bool test(char a, char b, char c, char d, char e) {
	bool x;
	if ((a == 'A' || a == 'E' || a == 'G' || a == 'U' || a == 'P' || a == 'a' || a == 'e' || a == 'g' || a == 'u' || a == 'p') &&
		(b == 'A' || b == 'E' || b == 'G' || b == 'U' || b == 'P' || b == 'a' || b == 'e' || b == 'g' || b == 'u' || b == 'p') &&
		(c == 'A' || c == 'E' || c == 'G' || c == 'U' || c == 'P' || c == 'a' || c == 'e' || c == 'g' || c == 'u' || c == 'p') &&
		(d == 'A' || d == 'E' || d == 'G' || d == 'U' || d == 'P' || d == 'a' || d == 'e' || d == 'g' || d == 'u' || d == 'p') &&
		(e == 'A' || e == 'E' || e == 'G' || e == 'U' || e == 'P' || e == 'a' || e == 'e' || e == 'g' || e == 'u' || e == 'p')) {
		x = true;


	}
	else {
		x = false;
	}
	return x;
}


//function to translate a character to a integer value   
double total(char x) {
	int z;
	switch (x) { //swich to check the character and assign a particular integer value
	case 'E':
		z = 4;
		break;
	case 'G':
		z = 3;
		break;
	case 'A':
		z = 2;
		break;
	case 'P':
		z = 1;
		break;
	case 'U':
		z = 0;
		break;
	}
	return z;
}


//function to calculate the average
double average(double x, double y) {
	double z = x / y;
	return z;
}


//function to display output
void display(int a, int b, int c, double d, double e, double f, double g, double h, double i) {
	ofstream outTwo("EvaluationSummary.txt", ios::out);//store the data to "EvaluationSummary.txt"
	if (!outTwo)
	{
		cerr << "File could not be opened\n";//error message will pop up if file could not be opened
		exit(1);
	}
	outTwo << std::fixed << std::setprecision(2) //set two decimal points for double values
		<< "COURSE/INSTRUCTOR EVALUATION SUMMARY" << endl << endl << endl
		<< "INSTRUCTOR NUMBER: " << a << endl
		<< "COURSE NUMBER: " << b << endl
		<< "NUMBER OF PARTICIPANTS: " << c << endl
		<< "AVERAGES:" << endl
		<< "QUESTION 1\t" << d << endl
		<< "QUESTION 2\t" << e << endl
		<< "QUESTION 3\t" << f << endl
		<< "QUESTION 4\t" << g << endl
		<< "QUESTION 5\t" << h << endl
		<< "INSTRUCTOR AVERAGE: " << i;
	cout << "\n\nSummary is stored in File.\nEnd of Program.";


}

