DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/
MKDIR_P := mkdir -p

CC := gcc
CFLAGS := -I$(DIRHEA) -c -Wall -ansi
LDLIBS := `pkg-config --libs-only-l glu` -lglut

all: dirs helloOpenGL tetera planetario ejercicios

ejercicios: ejercicio1 ejercicio3 ejercicio4


dirs:
	$(MKDIR_P) $(DIROBJ) $(DIREXE)

helloOpenGL: $(DIROBJ)helloOpenGL.o
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

tetera: $(DIROBJ)tetera.o
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

planetario: $(DIROBJ)planetario.o
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

ejercicio1:$(DIROBJ)ejercicio1.o
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

ejercicio3:$(DIROBJ)ejercicio3.o
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

ejercicio4:$(DIROBJ)ejercicio4.o
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

ejercicio5:$(DIROBJ)ejercicio5.o
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

ejercicio6:$(DIROBJ)ejercicio6.o
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

ejercicio6bis:$(DIROBJ)ejercicio6bis.o
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

ejercicio7:$(DIROBJ)ejercicio7.o
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)
ejercicio8:$(DIROBJ)ejercicio8.o
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)


$(DIROBJ)%.o: $(DIRSRC)%.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) -rf *~ core $(DIROBJ) $(DIREXE) $(DIRHEA)*~ $(DIRSRC)*~
