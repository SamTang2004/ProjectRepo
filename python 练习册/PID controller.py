import numpy
import time

from matplotlib import pyplot

# target Rotation/15ms (R/15ms), weights of parts. Adjust weights for quicker adaptation
target = 0.60
kp = 1
ki = 0.21
kd = -0.1

# simulate a motor, input power, output R/15ms
def motor(power):
    # linear motor simulation
    return 0.77 / 128 * power
    # power 0.5 motor simulation
    #return (pow((power/128),0.5)) * 0.77 

# instantiate the variables for the simulation
T1 = time.time() - 0.000001
# using Left Back Motor for simulation, coded L1 in the program

L1 = 0  # RPS of the motor

# accepted error range
acceptedErr = 0.0001
err = 0
proportional = 0
integral = 0
prevsum = 0
expected = 0

pointsX = []
pointsY = []
# in 5 seconds
while time.time() - T1 < 5:
    # get error from current motor output
    if target - L1 > acceptedErr:
        err = target - L1
    # proportional part
    proportional = kp * (err / target)
    
    # integral part
    prevsum += L1 * (time.time() - T1)
    expected += target * (time.time() - T1)
    integral = ki * (expected - prevsum) / (time.time() - T1)

    # set motor speed
    L1 = motor(integral + proportional)      

    # record data for every certain time period
    if int(10 * (time.time() - T1)) % 7 == 0:
        pointsX.append(time.time() - T1)
        pointsY.append(L1)

print(integral + proportional) #  final motor strength

print(pointsY[len(pointsY)-1])# final R/15ms

# show curve and data with matplotlib
pyplot.plot(pointsX, pointsY)
pyplot.show()
