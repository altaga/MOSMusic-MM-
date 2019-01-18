# MOSMusic(MM)
Portable lighting station synchronized with music.

<img src="https://media.giphy.com/media/2A53iheUI58rXtdvs9/giphy.gif" width="1000">

Always use technology to improve the world, if you are a black hat or gray hat hacker please abstain at this point ......... or at least leave your star to make me feel less guilty XP.

# Table of contents

* [Introduction](#introduction)
* [Materials](#materials)
* [The Circuit](#the-circuit)
* [The PCB](#the-pcb)
* [Development](#development)
* [The Final Product](#the-final-product)
* [Comments](#comments)
* [References](#references)

## Introduction:

En el mundo actual los conciertos ya no pueden seguir el mismo esquema tradicional de llegar, tocar e irse.Los fanaticos hoy en dia requieren un nivel mayor de emocion y espectaculo, lo que llevo a los oprganizadores de espectaculos tener que comprar costosos sistemas de control de iluminacion y sonido para lograr el nivel necesario para la espectiva de los fans.

Este tipo de sistemas de iluminacion tienen un complejo y costoso sistema de controles para manejar cada una de las luces, la mayoria de las veces siendo necesario realizar un show de luces con anterioridad para cada una de las canciones, aumentando aun mas el costo de el show.

Algunos productos similares en el mercado de muy baja calidad:

- MICTUNING 2nd-Gen RGB LED: https://www.amazon.com/dp/B01FWXT11I/ref=cm_sw_r_tw_dp_U_x_-DvoCbVYSEJ9S
- LED Strip Lights with Music Sync-Chase: https://www.amazon.com/dp/B07HCH24GL/ref=cm_sw_em_r_mt_dp_U_NCvoCb1G7DEZZ

Ninguno de los productos disponibles en el mercado lo venden por menos de 40 dolares y esto solo permite el control de elementos de baja potencia como lo son los LED'S, pero si en verdad queremos controlar elementos de alta potencia necesitamos un circuito que sea capaz de ello sin arriesgar el controlador de las luces, en esta caso un Arduino.

ENG> 


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

En la primera etapa del circuito tenemos un Transitor 600VCoolMOS de Infineon, el cual nos permitira controlar el optoacoplador exigiendo lo minimo de corriente a la placa Arduino, debido a que el optoacoplador requiere almenos 5 volts a 36mA para poder conducir y esto esta muy al limite de la corriente que puede suministrar la placa Arduino, sin embargo el 600VCoolMOS solo require una señal de 5 volts a 60uA, mostrando asi una excesiva mejora en el consumo que le exige a la placa.

Es sumamente importante este consumo porque no da la posibilidad de poder utilizar literalmente cualquier controlador para realizar eta tarea debido a su bajo consumo y no requerir controladores mas caros que si puedan suministrar dicha potencia en sus puertos.

<img src="https://i.ibb.co/Jx4Jbh9/Infineon.png">
El funcionamiento del MOSFET es aterrizar a tierra el diodo del optoacoplador, una vez este esta activado permite el flujo de energia a travez del DIAC y esto a su vez permitiendo el paso de corriente en el TRIAC conectado al foco y encendiendolo en el proceso.

| Comparison                     | Voltage [V]  | Current [mA] | Max Current I/O Pins [mA]|
|--------------------------------|--------------|--------------|--------------------------|
| **Without MOSFET 600VCoolMOS** | 5.0          | 36.0         | 40.0                     | 
| **With MOSFET 600VCoolMOS**    | 5.0          | 0.06         | 40.0                     |

Otra solucion a este proyecto hubiera sido utilizar relevadores, los cuales tienen como funcion realiar esta tarea pero de forma mecanica y generando un "Click" en cada switcheo, el problema con este tipo de componente es que si usaramos focos dimerizables o la frecuencia de switcheo fuera mayor, el relevador no podria realizar esta tarea, accion que el mosfet, optoacoplador y triac si pueden facilmente.

<img src="https://i.ibb.co/ctHj1N5/Untitled.png">

## The PCB:

Para este proyecto es posible realizar modulos individuales esto con el fin de poder expandir la cantidad de focos o dispositivos de alto voltaje conectados al Arduino o a cualquier otra placa.

<img src="https://i.ibb.co/CbdGKS9/1module.png">

Tambien puedes hacer un modulo completo para 4 salidas AC esto con el fin de integrar todo el sistema en una placa, ambos archivos estan en la carpeta "PBC Files".

<img src="https://i.ibb.co/tZhy2tC/4modules.png">

## Development:

Para el desarrollo de este circuito primero se realizaron pruebas de cada una de las etapas del circuito para demostar su efectividad, el primer circuito que se realizo para probar fue el control de los focos mediante un boton y guantes de seguridad debido al alto voltaje.

[![Test Circuit #1](https://i.ibb.co/MGxsBNS/descarga.png)](https://youtu.be/uqsgAZPN9SU)

Para el segundo circuito ya que el control de foco funciona bien se realizo una plataforma con leds para ver como el Arduino controlaba las luces al ritmo de la musica, el codigo esta en la carpeta "Arduino Code", el codigo esta comentado perfectamente.

[![Test Circuit #2](https://i.ibb.co/0BhfRg8/descarga-1.png)](https://youtu.be/uK5E9QZavhg)

Una vez vimos que funcionaba el control de las luces, realizamos en una protoboard todo el circuito parav el control de los 4 focos y lo conectamos al Arduino.

[![Test Circuit #3](https://i.ibb.co/28DCBnW/descarga-2.png)](https://youtu.be/EiSSqIL-sus)


## The Final Product:

Ya con el circuito funcionando decidimos realizar modulos de control como el que les mostramos en la imagen para no depender de que algun cable fallara en la protoboard.

<img src="https://i.ibb.co/cwBmGVz/Whats-App-Image-2019-01-10-at-17-50-41.jpg" width="400"><img src="https://i.ibb.co/JmDS6tv/Whats-App-Image-2019-01-10-at-17-59-32.jpg" width="400">

La PCB se realizo basandose en la PCB que esta en la carpeta "PCB Files" sin embargo ya que no contabamos con el papel termotranfer tuvimos que optar por realizar el trazo con plumon sharpie, el cual no se borra cuando sumerges la placa en cloruro ferrico, este proceso es el clasico para realizar PCB caseras como se muestra en el siguiente link.

https://www.hackster.io/Junezriyaz/how-to-make-pcb-using-marker-531087

Ya con las 4 PCB realizadas decidimos meter todo el circuito en una caja, forrarlo y ponerle 4 focos identicos para que este fuera un producto mas estetico y facil de transportar.

<img src="https://i.ibb.co/3Yjs6Qz/IMG-1415.jpg">

Con esto logramos el sistema de sincronzacion de luces para elementos electricos (120 o 220 volts).

Video: Click on the image
[![MOSMusic - The Gray Hat - Arduino Music](https://i.ibb.co/cCkXrhZ/1219145071.jpg)](https://www.youtube.com/watch?v=daAjffZg2-g)

Sorry github does not allow embed videos.

## Comments:

Este proyecto se realizo con el fin de demostrar que el control de luces a travez de microcontroladores puede ser eficiente y barato, ya que los sistemas actuales y de mucho menor calidad son vendidos en precios excesivos y por lo tanto no disponibles para todos.

## References:

All the information about the technology used, and direct references are in our wiki:

Wiki: https://github.com/altaga/MOSMusic-MM-/wiki

Top:

* [Table of Contents](#table-of-contents)
