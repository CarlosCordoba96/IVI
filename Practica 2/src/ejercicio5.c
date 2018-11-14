#include <GL/glut.h>

static GLdouble rotatex = 0.0;
static GLdouble rotatey = 0.0;
static GLdouble rotatez = 0.0;
static GLchar sentido='l';
static GLchar eje ='x';

void render () {
  /* Limpieza de buffers */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  /* Carga de la matriz identidad */
  glLoadIdentity();
  /* Posición de la cámara virtual (position, look, up) */
  gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(rotatex,1.0,0.0,0.0);
  glRotatef(rotatey,0.0,1.0,0.0);
    glRotatef(rotatez,0.0,0.0,1.0);

  /* En color blanco */
  glColor3f( 1.0, 1.0, 1.0 );
  /* Renderiza la tetera */
  glutWireTeapot(1.5);
  /* Intercambio de buffers... Representation ---> Window */
  glutSwapBuffers();
}

void rotari(){

  if (sentido=='l'){
    switch (eje) {
      case 'x':
      rotatex=rotatex-0.1;
      break;
      case 'y':
    rotatey=rotatey-0.1;
      break;
      case 'z':
      rotatez=rotatez-0.1;
      break;

    }
        }else if(sentido=='r'){
    switch (eje) {
      case 'x':
      rotatex=rotatex+0.1;
      break;
      case 'y':
    rotatey=rotatey+0.1;
      break;
      case 'z':
      rotatez=rotatez+0.1;
      break;

  }
}
    glutPostRedisplay();

}

void especiales(int key,int x, int y){
if(key==GLUT_KEY_LEFT){
sentido='l';
}
if(key==GLUT_KEY_RIGHT){
  sentido='r';
}
}


void teclado(unsigned char key, int x, int y){
  eje=key;
switch (key) {
  case 'x':
  glutIdleFunc(rotari);
  break;
  case 'y':
  glutIdleFunc(rotari);
  break;
  case 'z':
  glutIdleFunc(rotari);
  break;
  case 's':
  glutIdleFunc(NULL);
  break;

}
  glutPostRedisplay();
}


void resize (int w, int h) {
  /* Definición del viewport */
  glViewport(0, 0, w, h);

  /* Cambio a transform. vista */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  /* Actualiza el ratio ancho/alto */
  gluPerspective(50., w/(double)h, 1., 10.);

  /* Vuelta a transform. modelo */
  glMatrixMode(GL_MODELVIEW);
}


int main (int argc, char* argv[]) {
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
  glutInitWindowSize(640, 480);
  glutCreateWindow( "IVI - Sesion 2" );
  glEnable (GL_DEPTH_TEST);

  /* Registro de funciones de retrollamada */
  glutDisplayFunc(render);
  glutReshapeFunc(resize);
  /* Intercambio de buffers... Representation ---> Window */
   glutKeyboardFunc(teclado);
   glutSpecialFunc(especiales);
  /* Bucle de renderizado */
  glutMainLoop();

  return 0;
}
