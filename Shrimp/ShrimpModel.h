#include <cmath>
#include <time.h>

void drawShrimp()
{
	glRotatef(45, 0, 0, 1);
	glPushMatrix();
		glPushMatrix();
			glScalef(3, 3, 3);
			glRotatef(180, 1, 0, 0);
			glRotatef(90, 0, 1, 0);
			glRotatef(90, 1, 0, 0);
			glTranslatef(0, -0.3, 0);
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
				glRotatef(5, 1, 0, 0);
				glTranslatef(0, 0.1, 0.5);
			}
			GLUquadricObj *podstawa = gluNewQuadric();
			if (i < 4)
			{
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
					glVertex3f(0.5, -0.2, 0.1);
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
					glVertex3f(-0.5, -0.2, 0.1);
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
			glutSolidSphere(0.3, 30, 30);
			glTranslatef(0, 0, 0.23);
			glutSolidSphere(0.08, 12, 12);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, -0.3, 0);
			glutSolidSphere(0.3, 30, 30);
			glTranslatef(0, 0, 0.23);
			glutSolidSphere(0.08, 12, 12);
		glPopMatrix();
}