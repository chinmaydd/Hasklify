import matplotlib.pyplot as plt
from sys import argv, exit

f = open('cpp/vals.txt', 'r')
x_coordinates_c = []
y_coordinates_c = []
for line in f:
	if '.' in line:
		y_coordinates_c.append(float(line))
	else:
		x_coordinates_c.append(int(line))
f.close()

f = open('haskell/vals.txt', 'r')
x_coordinates_h = []
y_coordinates_h = []
for line in f:
	if '.' in line:
		y_coordinates_h.append(float(line))
	else:
		x_coordinates_h.append(int(line))
f.close()

plt.plot(x_coordinates_h, y_coordinates_h, 'r-', label="Haskell")
plt.plot(x_coordinates_c, y_coordinates_c, 'b-', label="C++")
plt.xlabel('Size of Input')
plt.ylabel('Time (seconds)')
plt.legend(loc=2)
plt.show()
