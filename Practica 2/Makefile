DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/
MKDIR_P := mkdir -p

CC := gcc
CFLAGS := -I$(DIRHEA) -c -Wall -ansi
LDLIBS := `pkg-config --libs-only-l glu` -lglut

all: dirs helloOpenGL tetera planetario ejercicio1

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


$(DIROBJ)%.o: $(DIRSRC)%.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) -rf *~ core $(DIROBJ) $(DIREXE) $(DIRHEA)*~ $(DIRSRC)*~
