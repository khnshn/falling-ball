#include <GL/glut.h>
#include <GL/gl.h>
#include <unistd.h>
#include <stdlib.h>

GLfloat xB = 50.0, yB = 420.0,
ha = 200.0, hb = 50.0, hc = 300.0, hd = 100.0,
ya, yb, yc, yd;
int finished = 0, toSleep = 20000, lost = 0;


int random_maker(int less)
{
	int ret = 0;
	srand(time(NULL));
	while (ret == 0)
		ret = rand() % less;
	return ret;
}


int isHole(GLfloat hS, GLfloat xB)
{
	if (xB > hS && xB < hS + 60.0)
		return 1;
	return 0;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_POINT_SMOOTH);

	glColor4f(0.0, 0.0, 0.0, 1.0);
	glLineWidth(10.0);

	glBegin(GL_LINES);


	glVertex2f(0.0, 100.0);
	glVertex2f(500.0, 100.0);

	// glColor4f(0.0, 0.0,0.0,1.0);
	glLineWidth(7.0);

	glVertex2f(0.0, yd);
	glVertex2f(hd, yd);
	glVertex2f(hd + 60.0, yd);
	glVertex2f(500.0, yd);

	glVertex2f(0.0, yc);
	glVertex2f(hc, yc);
	glVertex2f(hc + 60, yc);
	glVertex2f(500.0, yc);

	glVertex2f(0.0, yb);
	glVertex2f(hb, yb);
	glVertex2f(hb + 60.0, yb);
	glVertex2f(500.0, yb);

	glVertex2f(0.0, ya);
	glVertex2f(ha, ya);
	glVertex2f(ha + 60.0, ya);
	glVertex2f(500.0, ya);

	//glColor4f(1.0, 0.0,0.0,1.0);
	glLineWidth(10.0);

	glVertex2f(0.0, 500.0);
	glVertex2f(500.0, 500.0);

	glEnd();

	//glColor4f(0.0, 0.0,0.0,1.0);

	glPointSize(40.0);
	glBegin(GL_POINTS);
	glVertex2f(xB, yB);
	glEnd();


	glRasterPos2i(10, 40);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'D');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'R');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'P');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'P');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'I');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'N');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'G');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'B');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'L');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'L');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'v');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '.');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');

	if (finished == 1)
	{

		if (lost == 1)
		{
			glColor4f(1.0, 0.0, 0.0, 1.0);
			glRasterPos2i(150, 20);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'G');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'M');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'V');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'R');
		}
		else
		{
			glColor4f(0.0, 1.0, 0.0, 1.0);
			glRasterPos2i(150, 20);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'Y');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'U');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'H');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'V');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'W');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'N');
		}
	}

	glutSwapBuffers();
	glutPostRedisplay();
}
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void keySpecialUp(int key, int x, int y)
{
	if (finished == 0){
		if (key == GLUT_KEY_RIGHT)
		{
			xB += 10;
		}
		if (key == GLUT_KEY_LEFT)
		{
			xB -= 10;
		}
		if (yB - 20 == ya && isHole(ha, xB) == 1)
			yB -= 100;
		if (yB - 20 == yb && isHole(hb, xB) == 1)
			yB -= 100;
		if (yB - 20 == yc && isHole(hc, xB) == 1)
			yB -= 100;
		if (yB - 20 == yd && isHole(hd, xB) == 1)
			yB -= 100;
	}
}



void* func1(void* arg)
{
	int i = 0;
	ya = 400.0;
	ha = random_maker(300);
	yb = 300.0;
	hb = random_maker(300);
	while (hb == ha)
		hb = random_maker(300);
	yc = 200.0;
	hc = random_maker(300);
	while (hc == hb)
		hc = random_maker(300);
	yd = 100.0;
	hd = random_maker(300);
	while (hd == hc)
		hd = random_maker(300);

	while (finished == 0)
	{
		if (yB<100 || yB>500)
			finished = 1;
		if (yB<100)
			lost = 0;
		else
			lost = 1;
		usleep(toSleep);
		if (toSleep>10000)
			toSleep -= 10;
		yB++;
		ya++; yb++; yc++; yd++;
		if (ya == 500)
		{
			ya = yb;
			ha = hb;
			yb = yc;
			hb = hc;
			yc = yd;
			hc = hd;
			yd = 100.0;
			hd = random_maker(300);
			while (hd == hc)
				hd = random_maker(300);
		}
	}
}



int main(int argc, char* argv[])
{
	pthread_t th1;
	pthread_create(&th1, 0, func1, 0);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Dropping Ball");
	init();
	glutDisplayFunc(display);
	glutSpecialUpFunc(keySpecialUp);
	glutMainLoop();
	pthread_join(th1, 0);
	return 0;
}
