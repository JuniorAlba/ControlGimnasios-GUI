# Gestor de Gimnasios en C++

Este es un proyecto de escritorio desarrollado para digitalizar y simplificar la administración del día a día de un gimnasio tradicional. 
Este proyecto fue realizado como proyecto final de la materia Programacion Orientada a Objetos.

## ¿Qué hace el proyecto?

El software se divide en cuatro partes principales:
- **Clientes:** Registro de socios del gimnasio, sus datos personales y el historial de sus planes.
- **Coachs (Entrenadores):** Administración del equipo de trabajo, asignando qué entrenadores están a cargo de cada disciplina o plan de entrenamiento.
- **Planes de Entrenamiento:** Creación de diferentes ofertas para los socios (ej. Musculación, CrossFit, Entrenamiento Funcional) y la posibilidad de armar y modificar las rutinas semana a semana en archivos de texto.
- **Suscripciones:** El núcleo de la facturación. Permite vincular a un cliente con un plan y un coach, registrar pagos y calcular automáticamente las fechas de vencimiento de las cuotas.

## Tecnologías utilizadas

Este proyecto fue construido aplicando principios de Programación Orientada a Objetos y gestión de datos en archivos locales (persistencia binaria), garantizando que todo funcione de manera offline y fluida.

- **Lenguaje:** `C++`
- **Interfaz Gráfica (GUI):** `wxWidgets` (diseñada a través de wxFormBuilder)
- **Persistencia de Datos:** Manejo de archivos locales (`.dat` y `.txt`)
- **Entorno de Desarrollo:** `ZinjaI` / `MinGW`

## Cómo probarlo

Para compilar y ejecutar este proyecto vas a necesitar configurar las librerías de **wxWidgets**. Si utilizas **ZinjaI**, el proyecto ya incluye su archivo de configuración (`wxManage.zpr`) con los parámetros necesarios listos para darle a compilar y correr.


Es posible tambien crear un instalador para no tener que compilar el proyecto cada vez que se quiera ejecutar, esto se puede hacer con herramientas como NSIS.
---

