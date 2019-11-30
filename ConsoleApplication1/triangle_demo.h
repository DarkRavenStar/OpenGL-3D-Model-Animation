#ifndef _TRIANGLE_DEMO_H
#define _TRIANGLE_DEMO_H

#include "demo_base.h"
//#include "cmath>
#include <math.h>

class TriangleDemo : public DemoBase
{
public:
	
	float m_translate;
	float m_value1;
	bool max = false;

	bool reverse = false;
	bool reverse1 = false;
	bool reverse2 = false;
	float m_rotation;
	float m_rotation1;
	float m_rotation2;

	void init()
	{
	}

	void deinit()
	{
	}

	void drawAxis(const Matrix& viewMatrix)
	{
	// ============draw axis.
		glLoadMatrixf((GLfloat*)viewMatrix.mVal);
		glBegin(GL_LINES);
			glColor3f(1.0f, 0.3f, 0.3f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);

			glColor3f(0.3f, 1.0f, 0.3f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 1.0f, 0.0f);

			glColor3f(0.3f, 0.3f, 1.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 1.0f);
		glEnd();
		// ============================
	}


	void drawTriangle(void)
	{
		glBegin(GL_TRIANGLES);								// Drawing Using Triangles

		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f( 1.0f, 1.0f, 0.0f);
		glVertex3f( 1.0f,-1.0f, 0.0f);

		glEnd();	
	}

	void drawRectangle(void)
	{
		glBegin(GL_TRIANGLES);
		// Rectangular
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f( 1.0f, 1.0f, 0.0f);
		glVertex3f( 1.0f,-1.0f, 0.0f);
		glVertex3f( 2.0f,-1.0f, 0.0f);
		glVertex3f(2.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		glVertex3f(2.0f, 1.0f, 0.0f);
		glEnd();
	}

	void drawSquare(void)
	{
		glBegin(GL_TRIANGLES);
		// Square
		glColor3f(1.0f, 1.5f, 1.0f);
		glVertex3f(0.25f, 0.25f, 0.0f);
		glVertex3f(0.25f, -0.25f, 0.0f);
		glVertex3f(-0.25f, -0.25f, 0.0f);

		glVertex3f(0.25f, 0.25f, 0.0f);
		glVertex3f(-0.25f, -0.25f, 0.0f);
		glVertex3f(-0.25f, 0.25f, 0.0f);
		glEnd();
	}

	void drawCircle(float xRadius, float zRadius, float yHeight, float color[3])
	{
		float DEF_D = 1.0f;
		float k = 0.0f;

		glBegin(GL_TRIANGLES);
		glColor3f(color[0], color[1], color[2]);
		for (k = 0; k <= 360; k += DEF_D) {
			glVertex3f(0, yHeight, 0);
			glVertex3f(cos(k) * xRadius, yHeight, sin(k) * zRadius);
			glVertex3f(cos(k + DEF_D * 0.1) * xRadius, yHeight, sin(k + DEF_D * 0.1) * zRadius);
		}
		glEnd();
	}

	void drawCube(float color[3])
	{
		glBegin(GL_TRIANGLES);
		//Cube
		glColor3f(color[0], color[1], color[2]);
		//Side 1
		glVertex3f(0.25f, 0.25f, 0.25f);
		glVertex3f(0.25f, -0.25f, 0.25f);
		glVertex3f(-0.25f, -0.25f, 0.25f);

		glVertex3f(0.25f, 0.25f, 0.25f);
		glVertex3f(-0.25f, -0.25f, 0.25f);
		glVertex3f(-0.25f, 0.25f, 0.25f);

		//Side 2
		glVertex3f(0.25f, 0.25f, -0.25f);
		glVertex3f(0.25f, -0.25f, -0.25f);
		glVertex3f(-0.25f, -0.25f, -0.25f);

		glVertex3f(0.25f, 0.25f, -0.25f);
		glVertex3f(-0.25f, -0.25f, -0.25f);
		glVertex3f(-0.25f, 0.25f, -0.25f);

		//Side 3
		glVertex3f(0.25f, 0.25f, 0.25f);
		glVertex3f(0.25f, -0.25f, 0.25f);
		glVertex3f(0.25f, -0.25f, -0.25f);

		glVertex3f(0.25f, 0.25f, -0.25f);
		glVertex3f(0.25f, -0.25f, -0.25f);
		glVertex3f(0.25f, 0.25f, 0.25f);

		//Side 4
		glVertex3f(-0.25f, 0.25f, 0.25f);
		glVertex3f(-0.25f, -0.25f, 0.25f);
		glVertex3f(-0.25f, -0.25f, -0.25f);

		glVertex3f(-0.25f, 0.25f, -0.25f);
		glVertex3f(-0.25f, -0.25f, -0.25f);
		glVertex3f(-0.25f, 0.25f, 0.25f);

		//Side 5
		glVertex3f(-0.25f, 0.25f, 0.25f);
		glVertex3f(0.25f, 0.25f, 0.25f);
		glVertex3f(0.25f, 0.25f, -0.25f);

		glVertex3f(-0.25f, 0.25f, -0.25f);
		glVertex3f(0.25f, 0.25f, -0.25f);
		glVertex3f(-0.25f, 0.25f, 0.25f);

		//Side 6
		glVertex3f(-0.25f, -0.25f, 0.25f);
		glVertex3f(0.25f, -0.25f, 0.25f);
		glVertex3f(0.25f, -0.25f, -0.25f);

		glVertex3f(-0.25f, -0.25f, -0.25f);
		glVertex3f(0.25f, -0.25f, -0.25f);
		glVertex3f(-0.25f, -0.25f, 0.25f);

		glEnd();
	}

	void drawPyramid(float color[3])
	{
		glBegin(GL_TRIANGLES);
		glColor3f(color[0], color[1], color[2]);
		//Square Base
		glVertex3f(-0.25f, -0.25f, 0.25f);
		glVertex3f(0.25f, -0.25f, 0.25f);
		glVertex3f(0.25f, -0.25f, -0.25f);

		glVertex3f(-0.25f, -0.25f, -0.25f);
		glVertex3f(0.25f, -0.25f, -0.25f);
		glVertex3f(-0.25f, -0.25f, 0.25f);

		// Triangle Side 1
		glVertex3f(-0.25f, -0.25f, 0.25f);
		glVertex3f(0.25f, -0.25f, 0.25f);
		glVertex3f(0.0f, 0.25f, 0.0f);
		// Triangle Side 2
		glVertex3f(-0.25f, -0.25f, -0.25f);
		glVertex3f(0.25f, -0.25f, -0.25f);
		glVertex3f(0.0f, 0.25f, 0.0f);
		// Triangle Side 3
		glVertex3f(-0.25f, -0.25f, -0.25f);
		glVertex3f(-0.25f, -0.25f, 0.25f);
		glVertex3f(0.0f, 0.25f, 0.0f);
		// Triangle Side 4
		glVertex3f(0.25f, -0.25f, -0.25f);
		glVertex3f(0.25f, -0.25f, 0.25f);
		glVertex3f(0.0f, 0.25f, 0.0f);

		glEnd();
	}

	void drawCylinder(float x1Radius, float z1Radius, float x2Radius, float z2Radius, float height, float color[3])
	{
		float DEF_D = 1.0f;
		float k = 0.0f;
		glColor3f(color[0], color[1], color[2]);
		glBegin(GL_TRIANGLES);
		for (k = 0; k <= 360; k += DEF_D) {
			glVertex3f(cos(k) * x2Radius, height, sin(k) * z2Radius);
			glVertex3f(cos(k) * x1Radius, 0, sin(k) * z1Radius);
			glVertex3f(cos(k + DEF_D * 0.1) * x1Radius, 0, sin(k + DEF_D * 0.1) * z1Radius);

			glVertex3f(cos(k) * x1Radius, 0, sin(k) * z1Radius);
			glVertex3f(cos(k) * x2Radius, height, sin(k) * z2Radius);
			glVertex3f(cos(k + DEF_D * 0.1) * x2Radius, height, sin(k + DEF_D * 0.1) * z2Radius);
		}
		glEnd();
		
		drawCircle(x1Radius, z1Radius, 0, color);
		drawCircle(x2Radius, z2Radius, height, color);
	}

	void drawCone()
	{
		int DEF_D = 1;
		int k = 0;

		glBegin(GL_TRIANGLES);
		for (k = 0; k <= 360; k += DEF_D) {
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cos(k), sin(k), 1);
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cos(k) * 0.0, sin(k) * 0.0, 0);
			glColor3f(1.0, 0.0, 0.0);
			glVertex3f(cos(k + DEF_D * 0.1) * 0.0, sin(k + DEF_D  * 0.1) * 0.0, 0);

			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cos(k) * 0.0, sin(k) * 0.0, 0);
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cos(k), sin(k), 1);
			glColor3f(1.0, 0.0, 0.0);
			glVertex3f(cos(k + DEF_D * 0.1), sin(k + DEF_D  * 0.1), 1);
		}
		glEnd();


		/* bottom circle */
		/* rotate back */

		/*
		glRotated(90, 1, 0, 0);
		glBegin(GL_TRIANGLES);
		for (k = 0; k <= 360; k += DEF_D) {
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0, 0, 0);
		glColor3f(1.0, 0.0, 1.0);
		glVertex3f(cos(k), 0, sin(k));
		glColor3f(1.0, 1.0, 0.0);
		glVertex3f(cos(k + DEF_D), 0, sin(k + DEF_D));
		}
		glEnd();

		glRotated(90, 1, 0, 0);
		glBegin(GL_TRIANGLES);
		for (k = 0; k <= 360; k += DEF_D) {
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0, 0, 5);
		glColor3f(1.0, 0.0, 1.0);
		glVertex3f(cos(k), 0, sin(k));
		glColor3f(1.0, 1.0, 0.0);
		glVertex3f(cos(k + DEF_D), 0, sin(k + DEF_D));
		}
		glEnd();
		*/
	}

	
	void normalize(GLfloat *a) {
		GLfloat d = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
		a[0] /= d; a[1] /= d; a[2] /= d;
	}
	void drawTri(GLfloat *a, GLfloat *b, GLfloat *c, int div, float r) {
		if (div <= 0) {
			glNormal3fv(a); glVertex3f(a[0] * r, a[1] * r, a[2] * r);
			glNormal3fv(b); glVertex3f(b[0] * r, b[1] * r, b[2] * r);
			glNormal3fv(c); glVertex3f(c[0] * r, c[1] * r, c[2] * r);
		}
		else {
			GLfloat ab[3], ac[3], bc[3];
			for (int i = 0; i < 3; i++) {
				ab[i] = (a[i] + b[i]) / 2;
				ac[i] = (a[i] + c[i]) / 2;
				bc[i] = (b[i] + c[i]) / 2;
			}
			normalize(ab); normalize(ac); normalize(bc);
			drawTri(a, ab, ac, div - 1, r);
			drawTri(b, bc, ab, div - 1, r);
			drawTri(c, ac, bc, div - 1, r);
			drawTri(ab, bc, ac, div - 1, r);  //<--Comment this line and sphere looks really cool!
		}
	}
	void drawSphere(int ndiv, float radius, float color[3]) {
		float X = .525731112119133606f;
		float Z = .850650808352039932f;

		GLfloat vdata[12][3] = {
			{ -X, 0.0f, Z },{ X, 0.0f, Z },{ -X, 0.0f, -Z },{ X, 0.0f, -Z },
			{ 0.0f, Z, X },{ 0.0f, Z, -X },{ 0.0f, -Z, X },{ 0.0f, -Z, -X },
			{ Z, X, 0.0f },{ -Z, X, 0.0f },{ Z, -X, 0.0f },{ -Z, -X, 0.0f }
		};
		GLuint tindices[20][3] = {
			{ 0,4,1 },{ 0,9,4 },{ 9,5,4 },{ 4,5,8 },{ 4,8,1 },
			{ 8,10,1 },{ 8,3,10 },{ 5,3,8 },{ 5,2,3 },{ 2,7,3 },
			{ 7,10,3 },{ 7,6,10 },{ 7,11,6 },{ 11,0,6 },{ 0,1,6 },
			{ 6,1,10 },{ 9,0,11 },{ 9,11,2 },{ 9,2,5 },{ 7,2,11 } };
		
		glBegin(GL_TRIANGLES);
		glColor3f(color[0], color[1], color[2]);
		for (int i = 0; i < 20; i++)
			drawTri(vdata[tindices[i][0]], vdata[tindices[i][1]], vdata[tindices[i][2]], ndiv, radius);
		glEnd();
	}

	

	
	void draw(const Matrix& viewMatrix)
	{
		// Modify the camera matrix and wasd
		//glLoadMatrixf((GLfloat*)viewMatrix.mVal);
		m_value1 -= 1.0f;
		float colorYellow[3] = { 1.0f, 1.0f ,0.0f };
		float colorYellowGrey[3] = { 0.5f, 0.5f, 0.0f };
		float colorNose[3] = { 0.9f, 0.9f, 0.0f };
		float colorTail[3] = { 1.0f, 0.8f, 0.0f };
		float colorCheek[3] = { 1, 0, 0 };

		if (reverse == false)
		{
			m_rotation += 2.0f;

			if (m_rotation == 50.0f)
			{
				reverse = true;
			}
		}

		if (reverse == true)
		{
			m_rotation -= 2.0f;

			if (m_rotation == 0.0f)
			{
				reverse = false;
			}
		}

		if (reverse1 == false)
		{
			m_rotation1 += 2.0f;

			if (m_rotation1 == 50.0f)
			{
				reverse1 = true;
			}
		}

		if (reverse1 == true)
		{
			m_rotation1 -= 2.0f;

			if (m_rotation1 == -50.0f)
			{
				reverse1 = false;
			}
		}

		if (reverse2 == false)
		{
			m_rotation2 += 2.0f;

			if (m_rotation2 == 30.0f)
			{
				reverse2 = true;
			}
		}

		if (reverse2 == true)
		{
			m_rotation2 -= 2.0f;

			if (m_rotation2 == -20.0f)
			{
				reverse2 = false;
			}
		}

		//enable wireframe mode
		//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
		drawAxis(viewMatrix);

		
		//Main body
		Matrix rotate1 = Matrix::makeRotateMatrix(0.0f, Vector(0.0f, 0.0f, -1.0f));
		Matrix translate1 = Matrix::makeTranslationMatrix(0.0f, 0.0f, -2.0f);
		Matrix scale1 = Matrix::makeScaleMatrix(Vector(1.1f, 2.0f, 0.95f));
		Matrix viewSpaceMatrix1 = viewMatrix * translate1 * rotate1 * scale1;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix1.mVal);
		drawCylinder(1, 1, 1, 1, 1, colorYellow);

		//Lower body
		Matrix rotate2 = Matrix::makeRotateMatrix(0.0f, Vector(0.0f, 1.0f, 0.0f));
		Matrix translate2 = Matrix::makeTranslationMatrix(0.0f, 0.25f, -2.0f);
		Matrix scale2 = Matrix::makeScaleMatrix(Vector(1.1f, 1.1f, 1.0f));
		Matrix viewSpaceMatrix2 = viewMatrix * translate2 *rotate2 * scale2;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix2.mVal);
		drawSphere(2, 1, colorYellow);

		//Left Leg Cheek
		Matrix rotate3 = Matrix::makeRotateMatrix(m_rotation2, Vector(1.0f, 0.0f, 0.0f));
		Matrix translate3 = Matrix::makeTranslationMatrix(-0.45f, -0.1f, -2.0f);
		Matrix scale3 = Matrix::makeScaleMatrix(Vector(0.8f, 0.8f, 1.0f));
		Matrix viewSpaceMatrix3 = viewMatrix * translate3 *rotate3 * scale3;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix3.mVal);
		drawSphere(2, 1, colorYellow);

		Matrix translate17 = Matrix::makeTranslationMatrix(0.0f, -1.25f, 0.0f);
		Matrix scale17 = Matrix::makeScaleMatrix(Vector(0.3f, 0.5f, 0.3f));
		Matrix viewSpaceMatrix17 = viewSpaceMatrix3 * translate17 * scale17;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix17.mVal);
		drawCylinder(1, 1, 1, 1, 1, colorYellow);

		Matrix rotate18 = Matrix::makeRotateMatrix(90.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix translate18 = Matrix::makeTranslationMatrix(0.0f, -6.0f, 0.75f);
		Matrix scale18 = Matrix::makeScaleMatrix(Vector(0.35f, 0.2f, 0.5f));
		Matrix viewSpaceMatrix18 = viewSpaceMatrix3 * scale18 * translate18 * rotate18;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix18.mVal);
		drawCylinder(1, 1, 0.95, 0.95, 1, colorYellow);
		drawSphere(2, 1, colorYellowGrey);

		Matrix translate20 = Matrix::makeTranslationMatrix(0.0f, 1.1f, 0.0f);
		Matrix scale20 = Matrix::makeScaleMatrix(Vector(1.0f, 0.3f, 1.0f));
		Matrix viewSpaceMatrix20 = viewSpaceMatrix18 * translate20 * scale20;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix20.mVal);
		drawSphere(2, 0.95, colorYellow);

		//Right Leg Cheek
		Matrix rotate4 = Matrix::makeRotateMatrix(m_rotation2, Vector(-1.0f, 0.0f, 0.0f));
		Matrix translate4 = Matrix::makeTranslationMatrix(0.45f, -0.1f, -2.0f);
		Matrix scale4 = Matrix::makeScaleMatrix(Vector(0.8f, 0.8f, 1.0f));
		Matrix viewSpaceMatrix4 = viewMatrix * translate4 *rotate4 * scale4;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix4.mVal);
		drawSphere(2, 1, colorYellow);

		Matrix translate21 = Matrix::makeTranslationMatrix(0.0f, -1.25f, 0.0f);
		Matrix scale21 = Matrix::makeScaleMatrix(Vector(0.3f, 0.5f, 0.3f));
		Matrix viewSpaceMatrix21 = viewSpaceMatrix4 * translate21 * scale21;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix21.mVal);
		drawCylinder(1, 1, 1, 1, 1, colorYellow);

		Matrix rotate22 = Matrix::makeRotateMatrix(90.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix translate22 = Matrix::makeTranslationMatrix(0.0f, -6.0f, 0.75f);
		Matrix scale22 = Matrix::makeScaleMatrix(Vector(0.35f, 0.2f, 0.5f));
		Matrix viewSpaceMatrix22 = viewSpaceMatrix4 * scale22 * translate22 * rotate22;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix22.mVal);
		drawCylinder(1, 1, 0.95, 0.95, 1, colorYellow);
		drawSphere(2, 1, colorYellowGrey);

		Matrix translate24 = Matrix::makeTranslationMatrix(0.0f, 1.1f, 0.0f);
		Matrix scale24 = Matrix::makeScaleMatrix(Vector(1.0f, 0.3f, 1.0f));
		Matrix viewSpaceMatrix24 = viewSpaceMatrix22 * translate24 * scale24;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix24.mVal);
		drawSphere(2, 0.95, colorYellow);

		//Head
		Matrix rotate5 = Matrix::makeRotateMatrix(0.0f, Vector(0.0f, 1.0f, 0.0f));
		Matrix translate5 = Matrix::makeTranslationMatrix(0.0f, 2.0f, -2.0f);
		Matrix scale5 = Matrix::makeScaleMatrix(Vector(1.2f, 1.1f, 1.1f));
		Matrix viewSpaceMatrix5 = viewMatrix * translate5 * rotate5 * scale5;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix5.mVal);
		drawSphere(2, 1, colorYellow);

		//Nose
		Matrix rotate6 = Matrix::makeRotateMatrix(0.0f, Vector(0.0f, 1.0f, 0.0f));
		Matrix translate6 = Matrix::makeTranslationMatrix(0.0f, 2.0f, -1.2f);
		Matrix scale6 = Matrix::makeScaleMatrix(Vector(0.7f, 0.5f, 0.4f));
		Matrix viewSpaceMatrix6 = viewMatrix * translate6 * rotate6 * scale6;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix6.mVal);
		drawSphere(2, 1, colorYellow);

		//Hand Right
		Matrix rotate7 = Matrix::makeRotateMatrix(150.0f, Vector(0.0f, 0.0f, 1.0f));
		Matrix rotate7Half = Matrix::makeRotateMatrix(m_rotation1, Vector(-1.0f, 0.0f, 0.0f));
		Matrix translate7 = Matrix::makeTranslationMatrix(1.0f, 1.2f, -2.0f);
		Matrix scale7 = Matrix::makeScaleMatrix(Vector(0.2f, 1.0f, 0.25f));
		Matrix viewSpaceMatrix7 = viewMatrix * translate7 * rotate7Half * rotate7 * scale7;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix7.mVal);
		drawCylinder(1, 1, 1, 1, 1, colorYellow);

		Matrix translate8 = Matrix::makeTranslationMatrix(0.0f, 1.0f, 0.0f);
		Matrix scale8 = Matrix::makeScaleMatrix(Vector(1.0f, 0.5f, 1.0f));
		Matrix viewSpaceMatrix8 = viewSpaceMatrix7 * translate8 * scale8;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix8.mVal);
		drawSphere(2, 1, colorYellowGrey);
		
		Matrix translate9 = Matrix::makeTranslationMatrix(0.0f, -0.4f, 0.0f);
		Matrix scale9 = Matrix::makeScaleMatrix(Vector(1.1f, 0.3f, 1.1f));
		Matrix viewSpaceMatrix9 = viewSpaceMatrix7 * scale9 * translate9;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix9.mVal);
		drawSphere(2, 1, colorYellow);
		
		//Hand Left
		Matrix rotate10 = Matrix::makeRotateMatrix(-90.0f + m_rotation, Vector(0.0f, 0.0f, 1.0f));
		Matrix translate10 = Matrix::makeTranslationMatrix(-1.0f, 1.2f, -2.0f);
		Matrix scale10 = Matrix::makeScaleMatrix(Vector(0.2f, 1.0f, 0.25f));
		Matrix viewSpaceMatrix10 = viewMatrix * translate10 * rotate10 * scale10;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix10.mVal);
		drawCylinder(1, 1, 1, 1, 1, colorYellow);

		Matrix translate11 = Matrix::makeTranslationMatrix(0.0f, 1.0f, 0.0f);
		Matrix scale11 = Matrix::makeScaleMatrix(Vector(1.0f, 0.5f, 1.0f));
		Matrix viewSpaceMatrix11 = viewSpaceMatrix10 * translate11 * scale11;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix11.mVal);
		drawSphere(2, 1, colorYellowGrey);

		Matrix translate12 = Matrix::makeTranslationMatrix(0.0f, -0.4f, 0.0f);
		Matrix scale12 = Matrix::makeScaleMatrix(Vector(1.1f, 0.3f, 1.1f));
		Matrix viewSpaceMatrix12 = viewSpaceMatrix10 * scale12 * translate12;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix12.mVal);
		drawSphere(2, 1, colorYellow);
		
		
		//Left ear
		Matrix rotate13 = Matrix::makeRotateMatrix( m_rotation, Vector(1.0f, 1.0f, -1.0f));
		Matrix translate13 = Matrix::makeTranslationMatrix(-0.6f, 2.8f, -2.0f);
		Matrix scale13 = Matrix::makeScaleMatrix(Vector(0.25f, 1.0f, 0.1f));
		Matrix viewSpaceMatrix13 = viewMatrix * translate13 * rotate13 * scale13;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix13.mVal);
		drawCylinder(1, 1, 1, 1, 1, colorYellow);

		Matrix translate14 = Matrix::makeTranslationMatrix(0.0f, 1.0f, 0.0f);
		Matrix viewSpaceMatrix14 = viewSpaceMatrix13 * translate14;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix14.mVal);
		drawSphere(2, 1, colorYellowGrey);

		//Right ear
		Matrix rotate15 = Matrix::makeRotateMatrix(m_rotation, Vector(1.0f, -1.0f, 1.0f));
		Matrix translate15 = Matrix::makeTranslationMatrix(0.6f, 2.8f, -2.0f);
		Matrix scale15 = Matrix::makeScaleMatrix(Vector(0.25f, 1.0f, 0.1f));
		Matrix viewSpaceMatrix15 = viewMatrix * translate15 * rotate15 * scale15;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix15.mVal);
		drawCylinder(1, 1, 1, 1, 1, colorYellow);

		Matrix translate16 = Matrix::makeTranslationMatrix(0.0f, 1.0f, 0.0f);
		Matrix viewSpaceMatrix16 = viewSpaceMatrix15 * translate16;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix16.mVal);
		drawSphere(2, 1, colorYellowGrey);
		
		
		
		//Left Eyes
		Matrix rotate25 = Matrix::makeRotateMatrix(90.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix rotate25Half = Matrix::makeRotateMatrix(30.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix rotate25HalfHalf = Matrix::makeRotateMatrix(-30.0f, Vector(0.0f, 0.0f, 1.0f));
		Matrix translate25 = Matrix::makeTranslationMatrix(-0.4f,2.5f, -1.1f);
		Matrix scale25 = Matrix::makeScaleMatrix(Vector(0.3f, 0.1f, 0.3f));
		Matrix viewSpaceMatrix25 = viewMatrix * translate25 * rotate25HalfHalf * rotate25Half * rotate25 * scale25;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix25.mVal);
		float color1[3] = { 0.1, 0.1, 0.1 };
		drawSphere(2, 1, color1);

		Matrix rotate26 = Matrix::makeRotateMatrix(-40.0f, Vector(-1.0f, 0.0f, 1.0f));
		Matrix translate26 = Matrix::makeTranslationMatrix(0.0f, -0.8f, 0.0f);
		Matrix scale26 = Matrix::makeScaleMatrix(Vector(0.3f, 0.4f, 0.2f));
		Matrix viewSpaceMatrix26 = viewSpaceMatrix25 * rotate26 * translate26 * scale26;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix26.mVal);
		float color2[3] = { 1, 1, 1 };
		drawSphere(2, 1, color2);

		//Right Eyes
		Matrix rotate27 = Matrix::makeRotateMatrix(90.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix rotate27Half = Matrix::makeRotateMatrix(30.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix rotate27HalfHalf = Matrix::makeRotateMatrix(-30.0f, Vector(0.0f, 0.0f, -1.0f));
		Matrix translate27 = Matrix::makeTranslationMatrix(0.4f, 2.5f, -1.1f);
		Matrix scale27 = Matrix::makeScaleMatrix(Vector(0.3f, 0.1f, 0.3f));
		Matrix viewSpaceMatrix27 = viewMatrix * translate27 * rotate27HalfHalf * rotate27Half * rotate27 * scale27;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix27.mVal);
		drawSphere(2, 1, color1);

		Matrix rotate28 = Matrix::makeRotateMatrix(-40.0f, Vector(-1.0f, 0.0f, 1.0f));
		Matrix translate28 = Matrix::makeTranslationMatrix(-0.3f, -0.8f, 0.0f);
		Matrix scale28 = Matrix::makeScaleMatrix(Vector(0.3f, 0.4f, 0.2f));
		Matrix viewSpaceMatrix28 = viewSpaceMatrix27 * rotate28 * translate28 * scale28;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix28.mVal);
		drawSphere(2, 1, color2);

		//Nose
		Matrix rotate29 = Matrix::makeRotateMatrix(-90.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix rotate29Half = Matrix::makeRotateMatrix(45.0f, Vector(0.0f, 1.0f, 0.0f));
		//Matrix rotate29HalfHalf = Matrix::makeRotateMatrix(-30.0f, Vector(0.0f, 0.0f, -1.0f));
		Matrix translate29 = Matrix::makeTranslationMatrix(0.0f, 2.2f, -0.8f);
		Matrix scale29 = Matrix::makeScaleMatrix(Vector(0.5f, 0.5f, 0.5f));
		Matrix viewSpaceMatrix29 = viewMatrix * translate29* rotate29 *rotate29Half * scale29;// *rotate29Half * rotate29 * scale29;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix29.mVal);
		drawPyramid(color1);

		//Tails
		Matrix translate30 = Matrix::makeTranslationMatrix(0.0f, -0.4f, -2.5f);
		Matrix scale30 = Matrix::makeScaleMatrix(Vector(0.1f, 0.5f, 1.5f));
		Matrix rotate30 = Matrix::makeRotateMatrix(-50.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix viewSpaceMatrix30 = viewMatrix * translate30 * rotate30 * scale30;

		Matrix translate31 = Matrix::makeTranslationMatrix(0.0f, 0.5f, -0.5f);
		Matrix scale31 = Matrix::makeScaleMatrix(Vector(1.2f, 1.2f, 1.2f));
		Matrix rotate31 = Matrix::makeRotateMatrix(-20.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix viewSpaceMatrix31 = viewSpaceMatrix30 * translate31 *scale31  * rotate31;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix31.mVal);
		drawCube(colorTail);

		
		Matrix translate32 = Matrix::makeTranslationMatrix(0.0f, -0.3f, -0.3f);
		Matrix scale32 = Matrix::makeScaleMatrix(Vector(1.2f, 1.2f, 1.5f));
		Matrix rotate32 = Matrix::makeRotateMatrix(-20.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix viewSpaceMatrix32 = viewSpaceMatrix31 * translate32 *scale32;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix32.mVal);
		drawCube(colorTail);

		Matrix translate33 = Matrix::makeTranslationMatrix(0.0f, -0.3f, -0.3f);
		Matrix scale33 = Matrix::makeScaleMatrix(Vector(1.2f, 1.2f, 1.5f));
		Matrix rotate33 = Matrix::makeRotateMatrix(-20.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix viewSpaceMatrix33 = viewSpaceMatrix32 * translate33 *scale33;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix33.mVal);
		drawCube(colorTail);

		Matrix translate34 = Matrix::makeTranslationMatrix(0.0f, -0.3f, -0.3f);
		Matrix scale34 = Matrix::makeScaleMatrix(Vector(1.2f, 1.2f, 1.5f));
		Matrix rotate34 = Matrix::makeRotateMatrix(-20.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix viewSpaceMatrix34 = viewSpaceMatrix33 * translate34 *scale34;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix34.mVal);
		drawCube(colorTail);

		//Left Cheek
		Matrix rotate35 = Matrix::makeRotateMatrix(-100.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix rotate35Half = Matrix::makeRotateMatrix(50.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix rotate35HalfHalf = Matrix::makeRotateMatrix(-90.0f, Vector(0.0f, 0.0f, 1.0f));
		Matrix translate35 = Matrix::makeTranslationMatrix(-0.7f, 2.0f, -1.1f);
		Matrix scale35 = Matrix::makeScaleMatrix(Vector(0.2f, 0.1f, 0.2f));
		Matrix viewSpaceMatrix35 = viewMatrix * translate35 * rotate35HalfHalf * rotate35Half * rotate35 * scale35;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix35.mVal);
		drawSphere(2, 1, colorCheek);

		//Right Cheek
		Matrix rotate36 = Matrix::makeRotateMatrix(-100.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix rotate36Half = Matrix::makeRotateMatrix(50.0f, Vector(1.0f, 0.0f, 0.0f));
		Matrix rotate36HalfHalf = Matrix::makeRotateMatrix(-90.0f, Vector(0.0f, 0.0f, -1.0f));
		Matrix translate36 = Matrix::makeTranslationMatrix(0.7f, 2.0f, -1.1f);
		Matrix scale36 = Matrix::makeScaleMatrix(Vector(0.2f, 0.1f, 0.2f));
		Matrix viewSpaceMatrix36 = viewMatrix * translate36 * rotate36HalfHalf * rotate36Half * rotate36 * scale36;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix36.mVal);
		drawSphere(2, 1, colorCheek);
	}
};

#endif

/*
Matrix rotate6 = Matrix::makeRotateMatrix(m_rotation, Vector(0.0f, 0.0f, 1.0f));
Matrix translate6 = Matrix::makeTranslationMatrix(0.0f, 2.0f, -1.2f);
Matrix scale6 = Matrix::makeScaleMatrix(Vector(0.7f, 0.5f, 0.4f));
Matrix viewSpaceMatrix6 = viewMatrix * translate6 * rotate6 * scale6;
glLoadMatrixf((GLfloat*)viewSpaceMatrix6.mVal);
float color6[3] = { 250, 255, 0 };
drawSphere(3, 1, color6);
float color7[3] = { 250, 255, 255 };
//drawCylinder(1, 1, 1, 1, 2, color7);
Matrix translate7 = Matrix::makeTranslationMatrix(0.0f, 5.0f, 0.0f);
Matrix scale7 = Matrix::makeScaleMatrix(Vector(0.7f, 10.0f, 0.4f));
Matrix viewSpaceMatrix7 = viewSpaceMatrix6 * translate7 * scale7;
glLoadMatrixf((GLfloat*)viewSpaceMatrix7.mVal);
drawCylinder(1, 1, 1, 1, 1, color6);
*/

/*
//enable wireframe mode
//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
drawAxis(viewMatrix);
Matrix rotate1 = Matrix::makeRotateMatrix(m_rotation + 90.0f, Vector(0.0f, 0.0f, -1.0f));
Matrix translate1 = Matrix::makeTranslationMatrix(0.0f, 0.0f, 0.0f);
Matrix scale1 = Matrix::makeScaleMatrix(Vector(0.5f, 1.0f, 0.5f));
Matrix viewSpaceMatrix1 = viewMatrix * translate1 * rotate1 * scale1;
glLoadMatrixf((GLfloat*)viewSpaceMatrix1.mVal);
//drawsphere(3, 1.0f);
//drawPyramid();

//drawsphere(10,1.0f);
//drawCone();
float color1[3] = { 250, 255, 0 };
drawCylinder(1, 1, 1, 1, 1, color1);

Matrix rotate2 = Matrix::makeRotateMatrix(m_rotation + 90.0f, Vector(0.0f, 0.0f, -1.0f));
Matrix translate2 = Matrix::makeTranslationMatrix(-1.0f + sin((m_rotation*0.01) + 0.1), 0.0f - sin((m_rotation*0.01) + 0.1), 0.0f);
Matrix scale2 = Matrix::makeScaleMatrix(Vector(0.5f, 1.0f, 0.5f));
Matrix viewSpaceMatrix2 = viewMatrix * translate2 * rotate2 * scale2;
glLoadMatrixf((GLfloat*)viewSpaceMatrix2.mVal);
//drawsphere(3, 1.0f);
//drawPyramid();

//drawsphere(10,1.0f);
//drawCone();
float color2[3] = { 0, 200, 0 };
drawCylinder(1, 1, 1, 1, 1, color2);
*/

// Cylinder mistake cool effect!
/*
//Effect 0 -> A good float based cylinder face -> don't have cirlces to it
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k) * x2Radius, sin(k) * y2Radius, height);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k) * x1Radius, sin(k) * y1Radius, 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D * 0.1) * x1Radius, sin(k + DEF_D  * 0.1) * y1Radius, 0);

glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k) * x1Radius, sin(k) * y1Radius, 0);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k) * x2Radius, sin(k) * y2Radius, height);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D * 0.1) * x2Radius, sin(k + DEF_D  * 0.1) * y2Radius, height);
}
glEnd();

//Effect 1
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k * 0.1), sin(k * 0.1), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k), sin(k), 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D * 0.1), sin(k + DEF_D * 0.1), 0);
}
glEnd();

//Effect 2
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k), sin(k), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k), sin(k), 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D * 0.1), sin(k + DEF_D * 0.1), 0);
}
glEnd();

//Effect 3
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k), sin(k), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k), sin(k), 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D) * 0.1, sin(k + DEF_D) * 0.1, 0);
}
glEnd();

//Effect 4
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k), sin(k), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k * 0.1), sin(k * 0.1), 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D * 0.1), sin(k + DEF_D * 0.1), 0);
}
glEnd();

//Effect 5
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
//glVertex3f(cos(k), sin(k), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k * 0.1), sin(k * 0.1), 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D * 0.1), sin(k + DEF_D * 0.1), 0);
}
glEnd();

//Effect 6
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
//glVertex3f(cos(k), sin(k), 1);
glColor3f(0.0, 1.0, 1.0);
//glVertex3f(cos(k * 0.1), sin(k * 0.1), 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D * 0.1), sin(k + DEF_D * 0.1), 0);
}
glEnd();

//Effect 7
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
//glVertex3f(cos(k), sin(k), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k * 0.1), sin(k * 0.1), 0);
glColor3f(1.0, 0.0, 0.0);
//glVertex3f(cos(k + DEF_D * 0.1), sin(k + DEF_D * 0.1), 0);
}
glEnd();

//Effect 8
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
//glVertex3f(cos(k), sin(k), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k), sin(k), 0);
glColor3f(1.0, 0.0, 0.0);
//glVertex3f(cos(k + DEF_D * 0.1), sin(k + DEF_D * 0.1), 0);
}
glEnd();

//Effect 9
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k * 0.1), sin(k * 0.1), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k * 0.1), sin(k * 0.1), 0);
glColor3f(1.0, 0.0, 0.0);
//glVertex3f(cos(k + DEF_D * 0.1), sin(k + DEF_D * 0.1), 0);
}
glEnd();

//Effect 10
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k * 0.3), sin(k * 0.3), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k * 0.3), sin(k * 0.3), 0);
glColor3f(1.0, 0.0, 0.0);
//glVertex3f(cos(k + (DEF_D * 0.1)), sin(k + (DEF_D * 0.1)), 0);
}
glEnd();

//Effect 11
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k), sin(k), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k) * 0.1 , sin(k) * 0.1, 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D) * 0.1, sin(k + DEF_D) * 0.1, 0);
}
glEnd();

//Effect 12
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k), sin(k), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k) * 0.1 , sin(k) * 0.1, 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D), sin(k + DEF_D), 0);
}
glEnd();


//Effect 13
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k) * 0.1, sin(k) * 0.1, 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k) * 0.1 , sin(k) * 0.1, 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D), sin(k + DEF_D), 0);
}
glEnd();

//Effect 14
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k * 1.1), sin(k * 1.1), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k) , sin(k) , 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D * 0.1), sin(k + DEF_D * 0.1), 0);
}
glEnd();

//Effect 15
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k)* 0.1, sin(k), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k) * 0.1, sin(k) * 0.1, 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D * 0.1), sin(k + DEF_D * 0.1), 0);
}
glEnd();

//Effect 16
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k)* 0.1, sin(k), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k), sin(k), 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D * 0.1), sin(k + DEF_D * 0.1), 0);
}
glEnd();

//Effect 17
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k)* 0.1, sin(k), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k), sin(k), 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D), sin(k + DEF_D), 0);
}
glEnd();

//Effect 18 thin cylinder roll
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k), sin(k), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k), sin(k), 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D * 0.1), sin(k + DEF_D  * 0.1), 0);

glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k), sin(k), 0);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k), sin(k), 1);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D * 0.1), sin(k + DEF_D  * 0.1), 1);
}
glEnd();


//Effect 19
glBegin(GL_TRIANGLES);
for (k = 0; k <= 360; k += DEF_D) {
glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k) * 0.1, sin(k), 1);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k), sin(k), 0);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D * 0.1), sin(k + DEF_D  * 0.1), 0);

glColor3f(0.0, 0.0, 1.0);
glVertex3f(cos(k), sin(k), 0);
glColor3f(0.0, 1.0, 1.0);
glVertex3f(cos(k) * 0.1, sin(k) * 0.1, 1);
glColor3f(1.0, 0.0, 0.0);
glVertex3f(cos(k + DEF_D * 0.1) * 0.1, sin(k + DEF_D  * 0.1) * 0.1, 1);
}
glEnd();
*/
