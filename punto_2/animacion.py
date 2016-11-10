import numpy as np
import sys
import matplotlib.pyplot as plt
import imageio
import os

y = np.loadtxt('data.dat')
ini = y[:,0]
N = len(ini)

os.mkdir('./imagenes')

for i in range(N):
	if(i%10==0):
		figure = plt.figure()
		plt.plot(np.linspace(0,100,len(y[i,:])),y[i,:])
		plt.title("Movimiento")
		ax =	plt.axes()
		ax.set_xlabel('x')
		ax.set_ylabel('$y(t)$')
		ax.set_ylim([-1.5,1.5])
		plt.savefig('./imagenes/'+'Grafica'+str(i)+'.png', format = 'png')
		plt.close()

with imageio.get_writer('cuerda.gif', mode = 'I') as writer:
	x = np.linspace(0,1000,101)
	print x
	for i in x:
		image = imageio.imread('./imagenes/'+'Grafica'+str(int(i))+'.png')
		writer.append_data(image)

