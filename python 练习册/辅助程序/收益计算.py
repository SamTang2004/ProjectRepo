import matplotlib.pyplot as plt
import numpy as np


x = np.arange(3, 30,0.2)
plt.plot(x, 3000/x/4 * 0.0183)
plt.plot(x, 3000/x/4 * (3 - 0.333*(x/30)) / 60)
plt.show()
