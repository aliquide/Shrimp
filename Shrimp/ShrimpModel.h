
void drawShrimp()
{
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
	for (int i = 0; i < 6; i++)
	{
		if (i != 0){
			glRotatef(15, 1, 0, 0);
			glTranslatef(0, 0, 0.5);
		}
		GLUquadricObj *podstawa = gluNewQuadric();
		gluCylinder(podstawa, 1.0, 0.8, 1, 40, 40);

	}
	glTranslatef(0, 0, 1);
	glutSolidCone(0.9, 2, 40, 40);

	glRotatef(-70, 0, 0, 1);
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
	glPopMatrix();
}