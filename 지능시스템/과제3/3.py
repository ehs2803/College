import random
import matplotlib.pyplot as plt
import numpy as np

def makePairData(numOfData):
    x=[]
    y=[]

    for i in range(numOfData):
        temp_x=random.uniform(0,3)
        temp_y=(temp_x*temp_x*temp_x)-(4.5*temp_x*temp_x)+(6*temp_x) + 2 + random.uniform(-0.5,0.5)
        x.append(temp_x)
        y.append(temp_y)

    temp = [[a,b] for a, b in zip(x,y)]
    temp.sort(key=lambda x:x[0])
    x=[a[0] for a in temp]
    y=[b[1] for b in temp]

    return x,y

def temp(X, Y, a_current, b_current, c_current, d_current, epochs, learning_rate):
    N=len(Y)
    for i in range(epochs):
        y_current = (a_current*X*X*X)+(b_current*X*X)+c_current*X+d_current
        cost=sum([data**2 for data in (Y-y_current)])/(2*N)
        a_gradient= -(1/N)*sum(X*X*X*(Y-y_current))
        b_gradient= -(1/N)*sum(X*X*(Y-y_current))
        c_gradient = -(1 / N) * sum(X * (Y - y_current))
        d_gradient = -(1 / N) * sum(Y - y_current)

        a_current=a_current-(learning_rate*a_gradient)
        b_current = a_current - (learning_rate * b_gradient)
        c_current = a_current - (learning_rate * c_gradient)
        d_current = a_current - (learning_rate * d_gradient)
    return a_current, b_current, c_current, d_current, cost



def linear_regression(X, Y, a_current, b_current, c_current, d_current, epochs, learning_rate):
    N=len(Y)
    for i in range(epochs):
        cost=0
        a_gradient=0
        b_gradient=0
        c_gradient=0
        d_gradient=0
        y_current=[]
        for j in range(N):
            y_current.append((a_current*X[j]**3)+(b_current*X[j]**2)+(c_current*X[j])+(d_current))
            a_gradient += (X[j]**3) * (Y[j] - y_current[j])
            b_gradient += (X[j]**2) * (Y[j] - y_current[j])
            c_gradient += X[j] * (Y[j] - y_current[j])
            d_gradient += Y[j] - y_current[j]
            cost += (Y[j] - y_current[j]) ** 2

        cost/=(2*float(N))
        a_gradient = -(1 / float(N)) * a_gradient
        b_gradient = -(1 / float(N)) * b_gradient
        c_gradient = -(1 / float(N)) * c_gradient
        d_gradient = -(1 / float(N)) * d_gradient

        a_current = a_current - (learning_rate * a_gradient)
        b_current = b_current - (learning_rate * b_gradient)
        c_current = c_current - (learning_rate * c_gradient)
        d_current = d_current - (learning_rate * d_gradient)
        if i%100==0:
            print('Epoch:' + str(i) + '=============================================\
=====================================================')
            print(f'y = {a_current}x^3 + {b_current}x^2 + {c_current}x + {d_current}')
            print('cost = ' + str(cost))

    print('Epoch:' + '1000' + '=============================================\
=====================================================')
    print(f'y = {a_current}x^3 + {b_current}x^2 + {c_current}x + {d_current}')
    print('cost = ' + str(cost))

    return a_current, b_current, c_current, d_current, cost


numOfData = 300
x,y=makePairData(numOfData)

for i in range(len(x)):
    print(f'{i+1}: {x[i]}, {y[i]}')

a,b,c,d,cost = linear_regression(x,y,0,0,0,0,50000,0.0001)
#a,b,c,d,cost = temp(x,y,0,0,0,0,50000,0.0001)

print()
print('result:')
print(f'a = {a}, b = {b}, c = {c}, d = {d}')

plt.plot(x, y, 'bo')
x_range=[m for m in range(0,4)]
x_range=np.linspace(0,3,300)
y_range=[a*n*n*n+b*n*n+c*n+d for n in x_range]
plt.plot(x_range, y_range)
plt.show()