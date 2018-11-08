#include <GL/glut.h>
/* Función de renderizado */
static GLboolean color = 0;
void render () {
  /* Limpieza de buffers */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  /* Carga de la matriz identidad */
  glLoadIdentity();
  /* Traslación */
  glTranslatef(0.0, 0.0, -4.0);

  /* Renderiza un triángulo blanco */
  glColor3f(1.0, 1.0, 1.0);
  if(color){
    glColor3f(1.0, 0.0, 0.0);
  }
  glBegin(GL_TRIANGLES);
  glVertex3f(0.0, 1.0, 0.0);
  if(color){
      glColor3f(0.0, 1.0, 0.0);
  }
  glVertex3f(-1.0, -1.0, 0.0);
  if(color){
    glColor3f(0.0,0.0, 1.0);
  }
  glVertex3f(1.0, -1.0, 0.0);
  glEnd();

  /* Intercambio de buffers */
  glutSwapBuffers();
}

void teclado(unsigned char key, int x, int y){
  if(key =='c'){
    color=!color;
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

void menu(int value){
  if(value == 1)
    color=1;
  else
    color=0;
  glutPostRedisplay();

}
void init (void) {
  glEnable(GL_DEPTH_TEST);
  glutCreateMenu(menu);
  glutAddMenuEntry ("Tres colores", 1);
  glutAddMenuEntry ("Blanco", 2);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(200, 200);

  glutCreateWindow("Hola Mundo con OpenGL!");

  init();


  /* Registro de funciones de retrollamada */
  glutDisplayFunc(render);
  glutReshapeFunc(resize);
   glutKeyboardFunc(teclado);

  /* Bucle de renderizado */
  glutMainLoop();

  return 0;
}
