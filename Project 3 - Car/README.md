I am very sick so I couldn't create a nice wiring diagram in time, there is however, my demo in the classroom that you can take a look at

The car uses 4 DC motors, a L298N motor driver and a 9V battery pack.
Please read this guide on how to use the L298N motor driver https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/

You'll notice that the L298N motor driver can control 2 motors at a time but we have 4! That's ok. We want the two left motors to move the same way and the two right motors to move the same way

The motor driver takes 9V. **The Arduino can take 9V in the VIN port ONLY.** 