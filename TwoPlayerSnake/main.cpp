#include <iostream>
#include "glut.h"
#include <ctime>
#include <windows.h>


using namespace std;

int applesP1 = 0;
int applesP2 = 0;
int players = 2;
char spelplanA[300][300];
void spelplan();
int SnakesP1 = 3;
int SnakesP2 = 3;
float SnakeP1x[301];
float SnakeP1y[301];
float SnakeP2x[301];
float SnakeP2y[301];
char P1Dir = 'U';
char P2Dir = 'U';
double Frames =0;
int z =0;
int k =0;
int z2 =0;
int k2 = 0;
int fruit =0;
int fruitx= 100;
int fruity= 100;





void SKeyboard(int key, int x, int y) {

	switch(key) {

		case GLUT_KEY_UP:
			if (P1Dir != 'D')
			P1Dir = 'U';
			break;	
		case GLUT_KEY_DOWN:
			if (P1Dir != 'U')
			P1Dir = 'D';
			break;
		case GLUT_KEY_LEFT:
			if (P1Dir != 'R')
			P1Dir = 'L';
			break;
		case GLUT_KEY_RIGHT:
			if (P1Dir != 'L')
			P1Dir = 'R';
			break;
		







	}

}          


void keyboard(unsigned char key,int x, int y) {


	switch (key){
		case 'w':
			if (P2Dir != 'D')
			P2Dir = 'U';
			break;
		case 's':
			if (P2Dir != 'U')
			P2Dir = 'D';
			break;
		case 'd':
			if (P2Dir != 'L')
			P2Dir = 'R';
			break;
		case 'a':
			if (P2Dir != 'R')
			P2Dir = 'L';
			break;
		case 27:
			exit(0);
	
	}

	}

void movesnake() {



//P1 body//


	for (int x = SnakesP1; x >= 1; x--) {
		SnakeP1x[x] = SnakeP1x[x-1];
		SnakeP1y[x] = SnakeP1y[x-1];
	}

	if (players == 2) {
// P2 body//
		for (int x = SnakesP2; x >= 1; x--) {
		SnakeP2x[x] = SnakeP2x[x-1];
		SnakeP2y[x] = SnakeP2y[x-1];
	}
	}


//P1 head//
	if(P1Dir == 'U') {
		SnakeP1y[0]=SnakeP1y[0]+20;
	}

	else if(P1Dir == 'D') {
		SnakeP1y[0]=SnakeP1y[0]-20;
	}

	else if(P1Dir == 'L') {
		SnakeP1x[0]=SnakeP1x[0]-20;
	}

	else if(P1Dir == 'R') {
		SnakeP1x[0]=SnakeP1x[0]+20;
	}
	


//P2 head//

	if (players == 2 ) {
	if(P2Dir == 'U') {
		SnakeP2y[0]=SnakeP2y[0]+20;
	}

	else if(P2Dir == 'D') {
		SnakeP2y[0]=SnakeP2y[0]-20;
	}

	else if(P2Dir == 'L') {
		SnakeP2x[0]=SnakeP2x[0]-20;
	}

	else if(P2Dir == 'R') {
		SnakeP2x[0]=SnakeP2x[0]+20;
	}
	}

}

void maincode(){

	
	movesnake();

	spelplan();
	

}


void PauseFunc() {


	Sleep(120);

	Frames += 1;

	glutPostRedisplay();
}

void init() {
	
	glClearColor(255/255.0, 200/255.0, 0/255.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	SnakeP1x[0]=1180;
	SnakeP1y[0]=180;
	SnakeP2x[0]=740;
	SnakeP2y[0]=180;
	



	

}

void Display() {

PauseFunc();
	
	
maincode();

	glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex3f(300/1920.0, 160/1080.0, 0.0);
		glVertex3f(1620/1920.0, 160/1080.0, 0.0);
		glVertex3f(1620/1920.0, 920/1080.0, 0.0);
		glVertex3f(300/1920.0, 920/1080.0, 0.0);
	glEnd();

	
	
	for(int x = 0; x <= SnakesP1; x++) {
	
		glColor3f(255/255.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex3f((SnakeP1x[x]+6)/1920.0, (SnakeP1y[x])/1080.0, 0.0);
		glVertex3f((SnakeP1x[x]+14)/1920.0, (SnakeP1y[x])/1080.0, 0.0);
		glVertex3f((SnakeP1x[x]+20)/1920.0, (SnakeP1y[x]+6)/1080.0, 0.0);
		glVertex3f((SnakeP1x[x]+20)/1920.0, (SnakeP1y[x]+14)/1080.0, 0.0);
		glVertex3f((SnakeP1x[x]+14)/1920.0, (SnakeP1y[x]+20)/1080.0, 0.0);
		glVertex3f((SnakeP1x[x]+6)/1920.0, (SnakeP1y[x]+20)/1080.0, 0.0);
		glVertex3f((SnakeP1x[x])/1920.0, (SnakeP1y[x]+14)/1080.0, 0.0);
		glVertex3f((SnakeP1x[x])/1920.0, (SnakeP1y[x]+6)/1080.0, 0.0);
	glEnd();

	
	}

	if (players == 2) {

	for(int x = 0; x <= SnakesP2; x++) {
	
		glColor3f(0.0, 0.0, 255/255.0);
	glBegin(GL_POLYGON);
		glVertex3f((SnakeP2x[x]+6)/1920.0, (SnakeP2y[x])/1080.0, 0.0);
		glVertex3f((SnakeP2x[x]+14)/1920.0, (SnakeP2y[x])/1080.0, 0.0);
		glVertex3f((SnakeP2x[x]+20)/1920.0, (SnakeP2y[x]+6)/1080.0, 0.0);
		glVertex3f((SnakeP2x[x]+20)/1920.0, (SnakeP2y[x]+14)/1080.0, 0.0);
		glVertex3f((SnakeP2x[x]+14)/1920.0, (SnakeP2y[x]+20)/1080.0, 0.0);
		glVertex3f((SnakeP2x[x]+6)/1920.0, (SnakeP2y[x]+20)/1080.0, 0.0);
		glVertex3f((SnakeP2x[x])/1920.0, (SnakeP2y[x]+14)/1080.0, 0.0);
		glVertex3f((SnakeP2x[x])/1920.0, (SnakeP2y[x]+6)/1080.0, 0.0);
	glEnd();
	}

}

	glColor3f(0.0, 200/255.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex3f(((280+20*fruitx)+6)/1920.0, (140+20*fruity)/1080.0, 0.0);
		glVertex3f(((280+20*fruitx)+14)/1920.0, (140+20*fruity)/1080.0, 0.0);
		glVertex3f(((280+20*fruitx)+20)/1920.0, ((140+20*fruity)+6)/1080.0, 0.0);
		glVertex3f(((280+20*fruitx)+20)/1920.0, ((140+20*fruity)+14)/1080.0, 0.0);
		glVertex3f(((280+20*fruitx)+14)/1920.0, ((140+20*fruity)+20)/1080.0, 0.0);
		glVertex3f(((280+20*fruitx)+6)/1920.0, ((140+20*fruity)+20)/1080.0, 0.0);
		glVertex3f(((280+20*fruitx))/1920.0, ((140+20*fruity)+14)/1080.0, 0.0);
		glVertex3f((280+20*fruitx)/1920.0, ((140+20*fruity)+6)/1080.0, 0.0);
	glEnd();


		glColor3f(255/255.0, 200/255.0, 0/255.0);
	glBegin(GL_POLYGON);
		glVertex3f( 0/1920.0, 0/1080.0, 0.0);
		glVertex3f( 200/1920.0, 0/1080.0, 0.0);
		glVertex3f( 200/1920.0, 200/1080.0, 0.0);
		glVertex3f( 0/1920.0, 200/1080.0, 0.0);
	glEnd();

		glColor3f(20/255.0, 20/255.0, 20/255.0);
	for( int x = 1; x <= 65; x++) {
	glBegin(GL_LINE_STRIP);
		glVertex3f((300+20*x)/1920.0, 920/1080.0, 0.0);
		glVertex3f((300+20*x)/1920.0, 160/1080.0, 0.0);
	glEnd();

	}

		for( int x = 1; x <= 38; x++) {
		


	glBegin(GL_LINE_STRIP);
		glVertex3f(300/1920.0, (160+20*x)/1080.0, 0.0);
		glVertex3f(1620/1920.0, (160+20*x)/1080.0, 0.0);
	glEnd();

	}



	glFlush();
	
	
	
	
}
	
void spelplan(){

	//P1

	// cleaner //
	
	z = (SnakeP1x[SnakesP1]-280) / 20;
	k = (SnakeP1y[SnakesP1]-140) / 20;

	if (Frames >= SnakesP1 && spelplanA[z][k] != 'O'){ 
		spelplanA[z][k] = ' ';
}


	z= (SnakeP1x[0]-280) / 20;
	k= (SnakeP1y[0]-140) / 20;
	
	if (spelplanA[z][k]=='S' && Frames > 5 
	|| SnakeP1x[0] >= 1620 || SnakeP1x[0] <= 280 || SnakeP1y[0] >= 920 || SnakeP1y[0] <= 140){
		system ("color 09");
		if (players == 2) {
		cout << "BLUE WINS!" << endl;
		cout << "BLUE ate: " << applesP2  << " Apples!" << endl;
		cout << "RED  ate: " << applesP1  << " Apples!" << endl;
	
		}
		else {
		cout << "GAME OVER" << endl << "You ate: " << applesP1 << " apples!" << endl;

		}

		cout << "Press any key and ENTER to continue...";
		cin >> z;
		exit(0);

	}

	if (spelplanA[z][k]=='O') {
		SnakesP1 +=2;
		applesP1 +=1;
		fruit = 0;
	}



	spelplanA[z][k] = 'S';
	

	// P2

		// cleaner //
	
	if (players == 2) {


	z2 = (SnakeP2x[SnakesP2]-280) / 20;
	k2 = (SnakeP2y[SnakesP2]-140) / 20;

	if (Frames >= SnakesP2 && spelplanA[z2][k2] != 'O'){ 
		spelplanA[z2][k2] = ' ';
}


	z2= (SnakeP2x[0]-280) / 20;
	k2= (SnakeP2y[0]-140) / 20;
	
	if (spelplanA[z2][k2]=='S' && Frames > 5 
	|| SnakeP2x[0] >= 1620 || SnakeP2x[0] <= 280 || SnakeP2y[0] >= 920 || SnakeP2y[0] <= 140){
		system ("color 0C");
		cout << "RED WINS!" << endl;
		cout << "RED  ate: " << applesP1  << " Apples!" << endl;
		cout << "BLUE ate: " << applesP2  << " Apples!" << endl;
		cout << "Press ENTER to continue...";
		cin >> z;
		exit(0);

	}

	if (spelplanA[z2][k2]=='O') {
		SnakesP2 +=2;
		applesP2 +=1;
		fruit = 0;
	}

	

	spelplanA[z2][k2] = 'S';
	

	}

	//fruit
	if (fruit == 0) {
	srand ( time(NULL) );
	fruitx = (rand() % 65) +1;
	fruity = (rand() % 37) +1;

	spelplanA[fruitx][fruity]='O';

	fruit = 1;
	}
	

	

}

void StartOptions() {
	system ("Color 02");
	char RefreshConsole[] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  |  |  |||||| || ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  |  |  |||||| || |||||||||||||||||||||||||||| |||||||||||||||||||||||||||||||||  |  |  |    | || ||    |   |       ||    |||   ||   ||||||||||||||||||||||||||||      |  |  | || |  |||  |    |  | |  |  |||| ||  |  |||||||||||||||||||||||||||  ||  |   ||| || |  ||   |    |  |     |||||| ||  |  |||||||||||||||||||||||||||  ||  ||    | || ||    |   |  |  |  |    ||||  ||   |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| ||||||||||||||||||||||||||||||||||||||  |||||||||||||| |||||||||||||||||||||||| ||||||||||||||||||||||||||||||||||||||  |||||||||||||   |  |  | ||   ||||||   | ||   |  |  |   |    ||||   |     |   |  |  |    |||||| ||| |  | |  |  ||||| | | |||   | | |  | |  |||||    |  |  ||  |    |  |  |||||| |||  |   |  |  ||||| | | |  |  |   |   ||  ||||||||    |    | |    |   ||||||||  ||  |  |||   ||||||   | |     ||  ||      ||||||   |  |      |  |  |    ||||||||||||||||||||||||||| |||||||||||  |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| ||||||||||  |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	Sleep(3000);
	cout << RefreshConsole;
	cout << "Please enter the number of players (max 2) and press ENTER: ";
	cin >> players;




}

int main(int iArgc, char** cppArgv) {





	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition(0,0);
	StartOptions();
	glutCreateWindow("Snake");
	glutFullScreen();

	init();
	glutSpecialFunc(SKeyboard);
	glutKeyboardFunc(keyboard);

	glutDisplayFunc(Display);
	glutMainLoop();
	

	return 0;
}
