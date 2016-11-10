cuerda.gif : data.dat animacion.py
	python animacion.py

data.dat : a.out
	./a.out > data.dat

a.out : cuerda.c
	gcc cuerda.c -lm

clean :
	rm -f -r a.out data.dat imagenes
