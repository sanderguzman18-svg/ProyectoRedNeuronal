#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 30 17:01:07 2026

@author: alexandersue
"""

import pandas as pd
import networkx as nx
from IPython.display import HTML
import matplotlib.pyplot as plt
%matplotlib inline

datos=pd.read_csv('datos_nodo_prueba.csv')
datos.head()

datos.set_index(["nombre"],inplace=True)
datos.head()

rutas=pd.read_csv('nodos_prueba.csv')
rutas.head()

DG=nx.DiGraph()
for filas in rutas.iterrows():
    DG.add_edge(filas[1]["origen"],filas[1]["destino"],peso=filas[1]["peso"])
DG.nodes(data=True)

nx.draw_circular(DG,node_color='lightblue',edge_color='gray',
                 font_size=24,width=4,with_labels=True,node_size=350,)


list(nx.all_shortest_paths(DG,source="A",target="F",weight=None))

list(nx.dijkstra_path(DG,source="A",target="F",weight=None))

list(nx.all_shortest_paths(DG,source="A",target="F",weight="peso"))

datos.loc['F']['ciudad']


def ruta(ruta):
    total_peso=0
    for i in range(len(ruta)-1):
        origen=ruta[i]
        destino=ruta[i+1]
        peso=DG[origen][destino]["peso"]
        total_peso=total_peso+peso
        print(" %s->%s\n Peso: %s " % 
              (datos_nodo.loc[origen]['ciudad'],
               datos_nodo.loc[destino]['ciudad'],peso))
    print("\n Peso total=%s"%(total_peso))


ruta(['A', 'B', 'E', 'F'])