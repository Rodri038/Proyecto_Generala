Algoritmo sin_titulo
	posicion = 0
	max = 0
	Dimension vDados[5]
	Dimension vAux[5]
	Para i<-0 Hasta 4 Con Paso 1 Hacer
		Leer vDados[i]
		Si vDados[i]>max Entonces
			max = vDados[i]
		FinSi
		vAux[i] = max+1
	FinPara
	Para i<-0 Hasta 4 Con Paso 1 Hacer
		Para z<-0 Hasta 4 Con Paso 1 Hacer
			Si vDados[z]<vAux[i] Entonces
				vAux[i] = vDados[z]
				posicion = z
			FinSi
		FinPara
		vDados[posicion] = max
	FinPara
	Para i<-0 Hasta 4 Con Paso 1 Hacer
		vDados[i] = vAux[i]
		Escribir vDados[i]
	FinPara
FinAlgoritmo
