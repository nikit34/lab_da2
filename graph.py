import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import matplotlib


df = pd.read_excel('benchmark.xlsx', 'Лист1', index_col=None, na_values=['NA'])

x = df['test Find'][1:6]
y1 = df['Time (ms)'][1:6]
y2 = df['Unnamed: 3'][1:6]

y1_max = max(y1)
y2_max = max(y2)
y_max = max(y1_max, y2_max)

y1_absolut_error = y1_max * 0.05
y2_absolut_error = y2_max * 0.05

# exit()

fig = plt.figure()
ax = fig.add_subplot(111)

ax.plot(x, y2, c='r', marker="o", alpha=0.5, label="std::map")
ax.plot(x, y1, c='b', marker="o", alpha=0.5, label="AVL tree")
y1_err = np.linspace(y1_absolut_error, y1_absolut_error, len(x))
y2_err = np.linspace(y2_absolut_error, y2_absolut_error, len(x))
plt.errorbar(x, y2, yerr=y2_err, c='r', label='confidence lim map')
plt.errorbar(x, y1, yerr=y1_err, color='b', label='confidence lim AVL')

ax.grid()
ax.set_title('Dependence of lagorithm number of elements on execution time\nfor AVL tree and std::map structure')
plt.ylim(-100, y_max * 1.25 + 100)
plt.xlabel("Counts Log2")
plt.ylabel("Times (ms)")
plt.legend()

plt.savefig('testFind.png')
plt.show()