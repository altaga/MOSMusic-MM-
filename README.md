# MOSMusic(MM)
Portable lighting station synchronized with music.

<img src="https://media.giphy.com/media/2A53iheUI58rXtdvs9/giphy.gif" width="1000">

Always use technology to improve the world, if you are a black hat or gray hat hacker please abstain at this point ......... or at least leave your star to make me feel less guilty XP.

# Table of contents

* [Introduction](#introduction)
* [Materials](#materials)
* [The Circuit](#the-circuit)
* [Comments](#comments)
* [References](#references)

## Introduction:

En el mundo actual los conciertos ya no pueden seguir el mismo esquema tradicional de llegar, tocar e irse.Los fanaticos hoy en dia requieren un nivel mayor de emocion y espectaculo, lo que llevo a los oprganizadores de espectaculos tener que comprar costosos sistemas de control de iluminacion y sonido para lograr el nivel necesario para la espectiva de los fans.

Este tipo de sistemas de iluminacion tienen un complejo y costoso sistema de controles para manejar cada una de las luces, la mayoria de las veces siendo necesario realizar un show de luces con anterioridad para cada una de las canciones, aumentando aun mas el costo de el show.

Algunos productos similares en el mercado de muy baja calidad:

- MICTUNING 2nd-Gen RGB LED: https://www.amazon.com/dp/B01FWXT11I/ref=cm_sw_r_tw_dp_U_x_-DvoCbVYSEJ9S
- LED Strip Lights with Music Sync-Chase: https://www.amazon.com/dp/B07HCH24GL/ref=cm_sw_em_r_mt_dp_U_NCvoCb1G7DEZZ

Ninguno de los productos disponibles en el mercado lo venden por menos de 40 dolares y esto solo permite el control de elementos de baja potencia como lo son los LED'S, pero si en verdad queremos controlar elementos de alta potencia necesitamos un circuito que sea capaz de ello sin arriesgar el controlador de las luces, en esta caso un Arduino.

Para ello nosotros realizamos el siguiente sistema de sincronzacion de luces para elementos electricos (120 o 220 volts).

Video: Click on the image
[![MOSMusic - The Gray Hat - Arduino Music](https://i.ibb.co/cCkXrhZ/1219145071.jpg)](https://www.youtube.com/watch?v=daAjffZg2-g)

Sorry github does not allow embed videos.


## Materials:

- Cable                                x 2 Meters.
- IPT60R028G7 (600VCoolMOS)            x 4.
- MOC3021 (Optoisolator Triac Driver)  x 4.
- 2N6073AG (Triac)                     x 4.
- 1uF Cap                              x 4.
- 220 Ω                                x 4.
- 100 kΩ                               x 4.
- 10  kΩ                               x 4.
- 330 Ω                                x 4.
- Lightbulb socket                     x 4.
- Lightbulb                            x 4.
- Plug                                 x 1.
- Protoboard.                          x 1.
- Dupont Cable or Jumpers              To Many.
- Arduino Board.                       x 1.
- 12 Volts Source (For Arduino).       x 1.
- Sound Detection Sensor Module Sensor x 1.

Optional to make the PCB:

- Soldering Station.
- Wire Wrap Cable.
- Soldering Iron.
- Copper Clad Plate
- Ferric Chloride
- Sharpie Pen.
- Alligator Cable x 4.

## The Circuit:

El circuito tiene como finalidad pasar de una señal digital de 5 - 0 V DC a una señal de control de 120 V AC.

En la primera etapa del circuito tenemos un Transitor 600VCoolMOS de Infineon, el cual nos permitira controlar el optoacoplador exigiendo lo minimo de corriente a la placa arduino, debido a que el optoacoplador requiere almenos 5 volts a 36mA para poder conducir y esto esta muy al limite de la corriente que puede suministrar la placa arduino, sin embargo el 600VCoolMOS solo require una señal de 5 volts a 60uA, mostrando asi una excesiva mejora en el consumo que le exige a la placa.

<img src="https://i.ibb.co/Jx4Jbh9/Infineon.png">
El funcionamiento del MOSFET es aterrizar a tierra el diodo del optoacoplador, una vez este esta activado permite el flujo de energia a travez del DIAC y esto a su vez permitiendo el paso de corriente en el TRIAC conectado al foco y encendiendolo en el proceso.

| Comparison                     | Voltage [v]  | Current [mA] | Max Current I/O Pins [mA]|
|--------------------------------|--------------|--------------|--------------------------|
| **Without MOSFET 600VCoolMOS** | 5.0          | 36.0         | 40.0                     | 
| **With MOSFET 600VCoolMOS**    | 5.0          | 0.06         | 40.0                     |

Otra solucion a este proyecto hubiera sido utilizar relevadores, los cuales tienen como funcion realiar esta tarea pero de forma mecanica y generando un "Click" en cada switcheo, el problema con este tipo de componente es que si usaramos focos dimerizables o la frecuencia de switcheo fuera mayor, el relevador no podria realizar esta tarea, accion que el mosfet, optoacoplador y triac si pueden facilmente.

<img src="https://i.ibb.co/ctHj1N5/Untitled.png">

## Comments:

## References:

