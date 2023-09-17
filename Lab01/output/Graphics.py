import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import os

# Obtener la ruta del directorio actual del script
script_directory = os.path.dirname(os.path.abspath(__file__))

# Cambiar la ruta de trabajo al directorio del script
os.chdir(script_directory)

# Definir una paleta personalizada con tonos naranjas
mi_paleta_naranja = ["#FFA500", "#FF7F50", "#FF6347", "#FF4500"]

# Configurar el esquema de colores de Seaborn
sns.set_palette(mi_paleta_naranja)

# Lista de dimensiones
dimensiones = [10, 50, 100, 500, 1000, 2000, 5000]

# Para cada dimensión, lee los datos desde el archivo de texto y crea visualizaciones
for d in dimensiones:
    filename = f"{d}.txt"
    
    # Leer datos desde el archivo de texto
    with open(filename, "r") as file:
        data = [float(line.strip()) for line in file]
    
    # Calcular la media de los datos
    media = sum(data) / len(data)
    
    # Crear un DataFrame para facilitar la manipulación de datos
    df = pd.DataFrame(data, columns=["Distancias"])
    
    # Crear una figura con un subplot
    fig, ax = plt.subplots(figsize=(8, 5))
    
    # Visualización de la distribución de distancias
    sns.histplot(df, bins=10, kde=True, ax=ax)
    ax.set_title(f"Distribución de Distancias (d={d})")
    ax.set_xlabel("Distancia")
    ax.set_ylabel("Frecuencia")
    ax.set_xlim(0)  # Establecer el límite inferior del eje x en 0
    
    # Agregar la media al gráfico
    ax.axvline(x=media, color='red', linestyle='--', label=f'Media = {media:.2f}')
    ax.legend()  # Mostrar la leyenda con la etiqueta
    
    # Mostrar el gráfico
    #plt.show()
    plt.savefig(f"distribucion_{d}.png")  # Guardar los gráficos como imágenes
    plt.close()
