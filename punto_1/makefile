placas.pdf : data.dat grafica.py
	python grafica.py

data.dat : a.out
	./a.out > data.dat

a.out : placas.c
	gcc placas.c

clean:
	rm -f a.out data.dat 
