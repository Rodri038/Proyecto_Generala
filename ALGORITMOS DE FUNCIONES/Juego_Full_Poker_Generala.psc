Algoritmo DetectarJuegos
	igualesAnterior = 0
	iguales = 0
	cantDeIguales = 1
	auxiliar = 0
	Dimension vNumeros[5]
	Escribir 'ingrese 5 numeros'
	Para i<-0 Hasta 4 Con Paso 1 Hacer
		Leer vNumeros[i]
	FinPara
	auxiliar = vNumeros[0]
	Para i<-1 Hasta 4 Con Paso 1 Hacer
		Si vNumeros[i]==auxiliar Entonces
			Si iguales==0 Entonces
				iguales = iguales+2
			SiNo
				iguales = iguales+1
			FinSi
		SiNo
			auxiliar = vNumeros[i]
			cantDeIguales = cantDeIguales+1
			igualesAnterior = iguales
			iguales = 0
		FinSi
	FinPara
	iguales = iguales+igualesAnterior
	Si (iguales==5)&&(cantDeIguales==1) Entonces
		Escribir 'hubo Generala'
	SiNo
		Si (iguales==5)&&(cantDeIguales==2) Entonces
			Escribir 'Hubo Full'
		SiNo
			Si (iguales==4)&&(cantDeIguales==2) Entonces
				Escribir 'Hubo Poker'
			FinSi
		FinSi
	FinSi
FinAlgoritmo
