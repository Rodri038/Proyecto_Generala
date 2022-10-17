Algoritmo sin_titulo
	posicion = 0
	min = 0
	dimension vDados[5]
	dimension vAux[5]
	Para i<-0 Hasta 4 Con Paso 1 Hacer
		Leer vDados[i]
		vAux[i] = 0
	FinPara
	Para i<-0 Hasta 4 Con Paso 1 Hacer
		Para z<-0 Hasta 4 Con Paso 1 Hacer
			Si vDados[z]>vAux[i] Entonces
				vAux[i] = vDados[z]
				posicion = z
			FinSi
		FinPara
		vDados[posicion] = 0
	FinPara
	Para i<-0 Hasta 4 Con Paso 1 Hacer
		Escribir vAux[i]
	FinPara
FinAlgoritmo
