import numpy as np
import matplotlib.pyplot as pyplt
import pylab as plt

data = np.loadtxt('data.dat')

V_fin = data[len(data)-1]

h = 0.02
L = 5
n = L/h

V = np.zeros((n+1,n+1))
Ex = np.zeros((n+1,n+1))
Ey = np.zeros((n+1,n+1))

for j in range(0,int(n)):
		for i in range(0,int(n)):
			index = i*(n+1) + j
			V[i,j] = V_fin[index]

for j in range(0,int(n)):
		for i in range(0,int(n)):
			Ex[i,j] = (V[i,j]-V[i,j-1])/h
			Ey[i,j] = (V[i,j]-V[i-1,j])/h

#f=pyplt.figure()
f, (ax1,ax2) = pyplt.subplots(1,2)
ax1.imshow(V)
#plt.colorbar(ax1.imshow(V),orientation='horizontal')

x = np.linspace(0,L,n+1)
y = np.linspace(0,L,n+1)
ax2.streamplot(x, y, Ex, Ey, density=3)

pyplt.savefig('placas.pdf')
pyplt.close()

