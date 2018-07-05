#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>

string dirPath;
string currentVersion = "0.0.0";
int input;
using namespace std;

struct stat info;

bool changeDirPath(){
	cout << "Please enter a directory path" << endl;
	cin >> dirPath;
	
	if( stat( dirPath, &info ) != 0 )
		printf( "cannot access %s\n", dirPath );
	else if( info.st_mode & S_IFDIR )  // S_ISDIR() doesn't exist on my windows 
		printf( "%s is a directory\n", dirPath );
	else
		printf( "%s is no directory\n", dirPath );
	
}

bool createPackage(){
	cout << "Failed to create package" << endl;
	return false;
}

bool uploadPackage(){
	cout << "Failed to upload package" << endl;
	return false;
}

void printMenu(){
	system("cls");
	cout << "DOLPHIN LOGGER PACKAGER v" << currentVersion << endl;
	cout << "\t[1] change current directory" << endl;
	cout << "\t[2] create and verify package" << endl;
	cout << "\t[3] upload package contents" << endl;
	cout << "\t[4] exit\n" << endl;
	cout << "Current directory: " << dirPath << endl;
}

void determineFunction(){
	cin >> input;
	switch(input){
		case 1:
			changeDirPath();
			break;
		case 2:
			createPackage();
			break;
		case 3:
			uploadPackage();
			break;
		case default:
			cout << "Invalid input" << endl;
			system("ping www.google.com") > /dev/null;
			break;
	}
}

int main(){
	input = 0;
	while(input != 4){
		printMenu();
		determineFunction();
	}
	return 0;
}