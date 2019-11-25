// ConsoleApplication1.cpp: archivo de proyecto principal.
#include "stdafx.h"

#include <stdlib.h>

// opengl.cpp: define el punto de entrada de la aplicaci�n de consola.
//

#include <glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

double X = 0.0f;
double Y = 0.0f;
double xCubo = -2.0f;
double yCubo = -2.0f;
double xCubo1 = 0.0f;
double yCubo1 = 0.0f;
float scale = 1.0f;
bool bx=false;
bool by=false;
bool bz=false;
bool bx1=false;
bool by1=false;
bool bz1=false;
bool bx2=false;
bool by2=false;
bool bz2=false;
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
double rotate_y1=0;
double rotate_x1=0;
double rotate_z1=0;
double rotate_y2=0;
double rotate_x2=0;
double rotate_z2=0;



void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void dibujaCubo(){
	glPushMatrix();
	glTranslatef(xCubo, yCubo,0);
	if(bx==true){
		rotate_x += .2;
	}
	if(by==true){
		rotate_y += .2;
	}
	if(bz==true){
		rotate_z += .2;
	}
	glRotatef( rotate_x, 1.0, 0.0, 0.0 );
	glRotatef( rotate_y, 0.0, 1.0, 0.0 );
	glRotatef( rotate_z, 0.0, 0.0, 1.0 );
	glBegin(GL_POLYGON);
	glColor3f( 1.0, 0.0, 0.0 );     
	glVertex3f(  0.5, -0.5, -0.5 );      // P1 es rojo
	//glColor3f( 0.0, 1.0, 0.0 );    
	glVertex3f(  0.5,  0.5, -0.5 );      // P2 es verde
	//glColor3f( 0.0, 0.0, 1.0 );
	glVertex3f( -0.5,  0.5, -0.5 );      // P3 es azul
	//glColor3f( 1.0, 0.0, 1.0 );  
	glVertex3f( -0.5, -0.5, -0.5 );      // P4 es morado
	glEnd();
	// LADO TRASERO: lado amarillo
	glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0, 0.0 );
	glVertex3f(  0.5, -0.5, 0.5 );
	glVertex3f(  0.5,  0.5, 0.5 );
	glVertex3f( -0.5,  0.5, 0.5 );
	glVertex3f( -0.5, -0.5, 0.5 );
	glEnd();
	// LADO DERECHO: lado morado
	glBegin(GL_POLYGON);
	glColor3f(  1.0,  0.0,  1.0 );
	glVertex3f( 0.5, -0.5, -0.5 );
	glVertex3f( 0.5,  0.5, -0.5 );
	glVertex3f( 0.5,  0.5,  0.5 );
	glVertex3f( 0.5, -0.5,  0.5 );
	glEnd();
	// LADO IZQUIERDO: lado verde
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  1.0,  0.0 );
	glVertex3f( -0.5, -0.5,  0.5 );
	glVertex3f( -0.5,  0.5,  0.5 );
	glVertex3f( -0.5,  0.5, -0.5 );
	glVertex3f( -0.5, -0.5, -0.5 );
	glEnd();
	// LADO SUPERIOR: lado azul
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.0,  1.0 );
	glVertex3f(  0.5,  0.5,  0.5 );
	glVertex3f(  0.5,  0.5, -0.5 );
	glVertex3f( -0.5,  0.5, -0.5 );
	glVertex3f( -0.5,  0.5,  0.5 );
	glEnd();
	// LADO INFERIOR: lado verde fuerte
	glBegin(GL_POLYGON);
	glColor3f(   0.0,  0.4,  0.3 );
	glVertex3f(  0.5, -0.5, -0.5 );
	glVertex3f(  0.5, -0.5,  0.5 );
	glVertex3f( -0.5, -0.5,  0.5 );
	glVertex3f( -0.5, -0.5, -0.5 );
	glEnd();
	glPopMatrix();
}
void dibujaTriangulo(){
	glPushMatrix();
	glTranslatef(X, Y,0);	
	if(bx1==true){
		rotate_x1 += .2;
	}
	if(by1==true){
		rotate_y1 += .2;
	}
	if(bz1==true){
		rotate_z1 += .2;
	}
	glRotatef( rotate_x1, 1.0, 0.0, 0.0 );
	glRotatef( rotate_y1, 0.0, 1.0, 0.0 );
	glRotatef( rotate_z1, 0.0, 0.0, 1.0 );
	glColor3f(0.0,1.0,1.0);
	glutWireTeapot(2.3);
	glPopMatrix();
}
void dibujarOtraCosa(){
	glPushMatrix();
	if(bx2==true){
		rotate_x2 += .2;
	}
	if(by2==true){
		rotate_y2 += .2;
	}
	if(bz2==true){
		rotate_z2 += .2;
	}
	glRotatef( rotate_x2, 1.0, 0.0, 0.0 );
	glRotatef( rotate_y2, 0.0, 1.0, 0.0 );
	glRotatef( rotate_z2, 0.0, 0.0, 1.0 );
	glTranslatef(xCubo1, yCubo1,0);
	glColor3f(0.0,0.0,1.0) ;
	glutWireSphere(2.2,20,20) ;
	glPopMatrix();
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	glScalef(scale, scale, scale);
	dibujaCubo();
	dibujaTriangulo();
	dibujarOtraCosa();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}


void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.00, 10.0, 0.1, 20.0);
	glMatrixMode(GL_MODELVIEW);

}
void flechas(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		X+=1;
		break;
	case GLUT_KEY_LEFT:
		X-= 1.0;
		break;
	case GLUT_KEY_UP:
		Y+= 1.0;
		break;
	case GLUT_KEY_DOWN:
		Y-= 1.0;
		break;
	}
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'd':
		xCubo+=1;
		break;
	case 'a':
		xCubo-= 1.0;
		break;
	case 'w':
		yCubo+= 1.0;
		break;
	case 's':
		yCubo-= 1.0;
		break;
	case 'u':
		xCubo1+=1;
		break;
	case 'h':
		xCubo1-= 1.0;
		break;
	case 'k':
		yCubo1+= 1.0;
		break;
	case 'j':
		yCubo1-= 1.0;
		break;
	case 'y':
		if(by==false){
			by=true;
		}
		else{
			by=false;
		}
		break;
	case 'x':
		if(bx==false){
			bx=true;
		}
		else{
			bx=false;
		}
		break;
	case 'z':
		if(bz==false){
			bz=true;
		}
		else{
			bz=false;
		}
		break;  
		case 'p':
		if(by1==false){
			by1=true;
		}
		else{
			by1=false;
		}
		break;
	case 'n':
		if(bx1==false){
			bx1=true;
		}
		else{
			bx1=false;
		}
		break;
	case 'm':
		if(bz1==false){
			bz1=true;
		}
		else{
			bz1=false;
		}
		break;  
		case '1':
		if(by2==false){
			by2=true;
		}
		else{
			by2=false;
		}
		break;
	case '2':
		if(bx2==false){
			bx2=true;
		}
		else{
			bx2=false;
		}
		break;
	case '3':
		if(bz2==false){
			bz2=true;
		}
		else{
			bz=false;
		}
		break; 
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 400);

	glutInitWindowPosition(100, 100);
	glutCreateWindow("Cubo 3D");
	glEnable(GL_DEPTH_TEST);
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutSpecialFunc(flechas);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}