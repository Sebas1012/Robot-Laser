/*Informacion general:
--------------------------------
Dependencias:
    - Libreria Servo.h

Hardware Usado:
    - Arduino Uno rev3
    - Servo motor SG90 (x2)
    - Laser (x2)
    - Joystick HW-504
    - Pan/Tilt Bracket Nylon

Instrucciones:
--------------------------------
    Variables:
        - servoMotor1 = Permite conectar el servo motor que controla el eje Y atraves del pin digital 11.
        - servoMotor2 = Permite conectar el servo motor que controla el eje X atraves del pin digital 10.
        - angulo1 = Variable que hace map de la lectura del eje Y y los grados de movimiento en el servo.
        - angulo2 = Variable que hace map de la lectura del eje X y los grados de movimiento en el servo.
        - eje_x = Lee los valores del eje X en el joystick atraves del pin analogo A0.
        - eje_y = Lee los valores del eje Y en el joystick atraves del pin analogo A0.

    Funcionalidad:
        - Mas que un "Robot" este programa permite controlar dos servo motores (cada uno con un eje asignado) para que, atraves del joystick 
        podamos moverlo y apuntar con 2 lasers que incorpore en la montura

        - FUNCIONALIDAD DE LASERS AUN NO PROGRAMADA!!
*/


#include <Servo.h>

Servo servoMotor1;
Servo servoMotor2;

int angulo1 = 0;
int angulo2 = 0;
int eje_x = A0;
int eje_y = A1;

void setup() {
    servoMotor1.attach(11);
    servoMotor2.attach(10);
}


void loop() {
    angulo1 = map(analogRead(A1), 0, 1024, 0, 180);
    angulo2 = map(analogRead(A0), 0, 1024, 0, 180);
    servoMotor1.write(angulo1);
    servoMotor2.write(angulo2);
}
