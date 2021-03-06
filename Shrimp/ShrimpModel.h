#include <cmath>
#include <time.h>

enum MovementControl
{
	idle = 0,
	bounce = 1,
	crazy = 2,
};

void drawShrimp(MovementControl mov)
{
	glRotatef(45, 0, 0, 1);
	glColor3f(0.4, 0, 0);
	glPushMatrix();
		glPushMatrix();
			glScalef(3, 3, 3);
			glRotatef(180, 1, 0, 0);
			glRotatef(90, 0, 1, 0);
			if (mov == bounce || mov == crazy)
			{
				glRotatef(90 - sin(float(clock()) / 100) * 15, 1, 0, 0);
			}
			else if (mov == idle)
			{
				glRotatef(90, 1, 0, 0);
			}
			glTranslatef(0, -0.3, 0.2);
			glBegin(GL_TRIANGLE_FAN);
				glVertex3f(0, 0, 0);
				glVertex3f(0.5, 0, -0.2);
				glVertex3f(0.4, 0.3, -0.1);
				glVertex3f(0.2, 0.5, -0.2);
				glVertex3f(0, 0.5, 0);
				glVertex3f(-0.2, 0.5, -0.2);
				glVertex3f(-0.4, 0.3, -0.1);
				glVertex3f(-0.5, 0, -0.2);
			glEnd();
		glPopMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, 0, 0.4);
		
		glPushMatrix();
			glTranslatef(0, 0, 0.15);
			glutSolidSphere(0.55, 40, 40);

		glPopMatrix();

		for (int i = 0; i < 10; i++)
		{
			if (i != 0)
			{
				if(mov == bounce) glRotatef(sin(float(clock())/100) * 5+ 5, 1, 0, 0);
				if (mov == crazy) glRotatef(sin(float(clock()) / 100) * 5 + 5, 1, 1, (sin(float(clock()) / 100) * 5 + 5)-1);
				else if (mov == idle) glRotatef(5, 1, 0, 0);
				glTranslatef(0, 0.1, 0.5);
			}
			GLUquadricObj *podstawa = gluNewQuadric();
			if (i < 4)
			{
				glColor3f(0.4 + 0.15*i, 0, 0);
				gluCylinder(podstawa, 0.5 + 0.1*(i+1), 0.4 + 0.1*i, 1, 40, 40);
			}
			else
			{
				gluCylinder(podstawa, 1.0, 0.8, 1, 40, 40);
			}

			glPushMatrix();
				glRotatef(sin(clock() / 50 + i) * 15, 0, 0, 1);
				glTranslatef(0, -0.2, 1);
				glRotatef(90, 0, 1, 0);
				glTranslatef(0, 0, 0.8);
				glRotatef(-90, 0, 1, 0);
				glBegin(GL_TRIANGLE_STRIP);
					glVertex3f(0, 0, 0);
					glVertex3f(-0.1, 0.2, 0);
					glVertex3f(0.2, 0.2, 0);
					glVertex3f(0.3, 0.5, 0);
					glVertex3f(0.5, -0.5, 0.1);
				glEnd();
			glPopMatrix();
			glPushMatrix();
			glRotatef(sin(clock() / 50 + i) * 15, 0, 0, 1);
				glTranslatef(0, -0.2, 1);
				glRotatef(-90, 0, 1, 0);
				glTranslatef(0, 0, 0.8);
				glRotatef(90, 0, 1, 0);
				glBegin(GL_TRIANGLE_STRIP);
					glVertex3f(0, 0, 0);
					glVertex3f(0.1, 0.2, 0);
					glVertex3f(-0.2, 0.2, 0);
					glVertex3f(-0.3, 0.5, 0);
					glVertex3f(-0.5, -0.5, 0.1);
				glEnd();
			glPopMatrix();

		}
		glTranslatef(0, 0, 1);
		glutSolidCone(0.9, 2, 40, 40);

		glPushMatrix();
			glTranslatef(0, -0.2, 1);
			glRotatef(15, 0, 1, 0);
			glTranslatef(0, 0, 0.5);
			glRotatef(15, 0, 1, 0);
			glColor3f(0, 0, 0);
			glBegin(GL_TRIANGLE_STRIP);
				glVertex3f(0, 0, 0);
				glVertex3f(-0.1, 0.2 ,0);
				glVertex3f(0.2, 0.2 ,0);
				glVertex3f(0.3, 0.5 ,0);
				glVertex3f(0.5, -0.2 ,0.1);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, -0.2, 1);
			glRotatef(-15, 0, 1, 0);
			glTranslatef(0, 0, 0.5);
			glRotatef(15, 0, 1, 0);
			glBegin(GL_TRIANGLE_STRIP);
				glVertex3f(0, 0, 0);
				glVertex3f(0.1, 0.2, 0);
				glVertex3f(-0.2, 0.2, 0);
				glVertex3f(-0.3, 0.5, 0);
				glVertex3f(-0.5, -0.2, 0.1);
			glEnd();
		glPopMatrix();
		glRotatef(-90, 0, 0, 1);
		glTranslatef(-0.4, 0, 1);
		glPushMatrix();
			glTranslatef(0, 0.3, 0);
			glColor3f(1, 1, 1);
			glutSolidSphere(0.3, 30, 30);
			glTranslatef(0, 0, 0.23);
			glColor3f(0, 0, 0);
			glutSolidSphere(0.08, 12, 12);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, -0.3, 0);
			glColor3f(1, 1, 1);
			glutSolidSphere(0.3, 30, 30);
			glTranslatef(0, 0, 0.23);
			glColor3f(0, 0, 0);
			glutSolidSphere(0.08, 12, 12);
		glPopMatrix();
}