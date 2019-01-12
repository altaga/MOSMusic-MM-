# MOSMusic-MM-
Portable lighting station synchronized with music.

<img src="https://i.ibb.co/qYfzKdy/IMG-1374.jpg" width="1000">

Always use technology to improve the world, if you are a black hat or gray hat hacker please abstain at this point ......... or at least leave your star to make me feel less guilty XP.

# Table of contents

* [Introduction](#introduction)
* [Materials](#materials)
* [PC Setup](#pc-setup)
* [Management of the IBM Watson IoT Platform](#management-of-the-ibm-watson-iot-platform)
* [Handling of IoT devices using the IBM Watson IoT Platform (specifically ESP8266 using ArduinoIDE)](#handling-of-iot-devices-using-the-ibm-watson-iot-platform)
* [Handling WEB pages with connectivity to IBM Watson IoT Platform](#handling-web-pages-with-connectivity-to-ibm-watson-iot-platform)
* [Connectivity between IoT device and WEB application](#connectivity-between-iot-device-and-web-application)
* [Connectivity between WEB application and IoT device](#connectivity-between-web-application-and-iot-device)
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

## Materials:

- 
