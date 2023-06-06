import numpy as np
import matplotlib.pyplot as plt
from numpy import newaxis

def compute_mandelbrot(N_max, some_threshold, nx, ny):
# A grid of c-values
    x = np.linspace(-1, 0.5, nx)
    y = np.linspace(-0.75, 0.75, ny)
    c = x[:,newaxis] + 1j*y[newaxis,:]
    
    # Mandelbrot iteration
    z = c
    for j in range(N_max):
        z = z**2 + c
    mandelbrot_set = abs(z) < some_threshold
    return mandelbrot_set

mandelbrot_set = compute_mandelbrot(100, 50., 601, 401)
plt.imshow(mandelbrot_set.T, extent=[-4, 2, -3, 3])
plt.show()
