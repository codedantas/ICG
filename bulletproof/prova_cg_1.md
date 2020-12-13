<div align="center">
<h1> Introdução à Computação Gráfica</h1>
</div>

<div align="center"> 
<h2> PROVA I </h2>
</div>

##### Aluno: Matheus Henrique Raposo Dantas
##### Matrícula: 11414179

<div align="center"> <h2>RESPOSTAS</h2> 
</div>

##### Questão 1. 

~~~c
void PreencheRetangulo(int x_min, int x_max, int y_min, int y_max, char r, char g, char b, char a){
    for (int i = x_min; i < x_max; i++)
    {
        for (int j = y_min; j < y_max; j++)
        {
            PutPixel(i, j, char r, char g, char b, char a);
        }
    }
}
`

PutPixel(i, j, char r, char g, char b, char a){
    int pos = 4 * i + 4 * j * 800
    CBInicio[pos] = r;
    CBInicio[pos + 1] = g;
    CBInicio[pos + 2] = b;
    CBInicio[pos + 3] = a;
}

void InitMyGL(void) {
    CBInicio = (unsigned char*)malloc(800 * 600 * 4 * SIZEOF(char));

    for (int i=0; i< 800 * 600; ++1){
        CBInicio[i*4]=0;
        CBInicio[i*4+1]=0;
        CBInicio[i*4+2]=0;
        CBInicio[i*4+3]=255;
    }
}

~~~

##### Questão 2.

<!-- $$ Escala = 
\left(\begin{bmatrix}
2 & 0 & 0 \\
0 & \frac{1}{2} & 0 \\
0 & 0 & 1
\end{bmatrix}\right)
$$ --> 


<div align="center"><img src="svg/SfdNNdxnoW.svg"/></div>
<h5 align="center">Escala</h5>

<!-- $$ Rotação =
\left(\begin{bmatrix} 
cos(210º) & -sen(210º) & 0 \\
sen(210º) & cos(210º) & 0 \\
0 & 0 & 1
\end{bmatrix}\right)
$$ --> 

<div align="center"><img src="svg/qOyhb9AUFy.svg"/></div>
<h5 align="center">Rotação</h5>

<!-- $$ Translação =
\left(\begin{bmatrix} 
1 & 0 & 2 \\
0 & 1 & 3 \\
0 & 0 & 1
\end{bmatrix}\right)
$$ --> 

<div align="center"><img src="svg/e6vWf17fTS.svg"/></div>
<h5 align="center">Translação</h5>

<div align="center"><h5>M = T*R(210º)*E</h5></div>


##### Questão 3.

<div align="center"><img src="svg/intro.png"/></div>

* Posição P = (1,1,0);
* Vetor de direção D = (-1,0,0);
* Vetor up U = (0,1,0).

<h5>Logo temos:</h5>

* Zc = (1,0,0)
* Xc = (0, 0, -1)
* Yc = (0, 1, 0)

<h5 align="center"> Matrizes</h5>

<!-- $$ Rotação =
\left(\begin{bmatrix} 
0 & 0 & -1 & 0 \\
0 & 1 & 0 & 0 \\
1 & 0 & 0 & 0 \\
0 & 0 & 0 & 1
\end{bmatrix}\right)
$$ --> 
<div align="center"><img src="svg/5qF9lS6Dsp.svg"/></div>
<h5 align="center"> Rotação</h5>

<!-- $$ Translação =
\left(\begin{bmatrix} 
1 & 0 & 0 & -1\\
0 & 1 & 0 & -1\\
0 & 0 & 1 & 0\\
0 & 0 & 0 & 1
\end{bmatrix}\right)
$$ --> 
<div align="center"><img src="svg/hUVSRW47ID.svg"/></div>
<h5 align="center"> Translação</h5>

<center>Então, o produto entre <b>Rotação X Translação</b> fica:</center>

<!-- $$ R x T =
\left(\begin{bmatrix} 
0 & 0 & -1 & 0\\
0 & 1 & 0 & -1\\
1 & 0 & 0 & -1\\
0 & 0 & 0 & 1
\end{bmatrix}\right)
$$ --> 
</br>
<div align="center"><img src="svg/jAdoVlflWa.svg"/></div>

<div align="center">
<h5>Coordenada Homogênea:</h5>
</div>

<!-- $$ 
\left(\begin{bmatrix} 
X\\
Y\\
1\\
\end{bmatrix}\right)
$$ --> 

<div align="center"><img src="svg/OHMREO3ck0.svg"/></div>

##### Questão 4.

<!-- $$ 
\left(\begin{bmatrix} 
1 & 0 & 0 & 0\\
0 & 1 & 0 & 0\\
0 & 0 & 1 & 1\\
0 & 0 & -1 & 0
\end{bmatrix}\right)

\left(\begin{bmatrix} 
4\\
6\\
-2\\
1\\
\end{bmatrix}\right)

= 

\left(\begin{bmatrix} 
4\\
6\\
-1\\
2\\
\end{bmatrix}\right)
$$ --> 
<h5 align="center"> 1. pRecorte</h5>
<div align="center"><img src="svg/symzilLi9x.svg"/></div>

<h5 align="center"> 2. pCanônico</h5>

<!-- $$ 
\frac{\left(\begin{bmatrix} 
4\\
6\\
-1\\
2\\
\end{bmatrix}\right)}{2}=\left(\begin{bmatrix} 
2\\
3\\
\frac{-1}{2}\\
1\\
\end{bmatrix}\right)
$$ --> 

<div align="center"><img src="svg/5kf1Nv4zoc.svg"/></div>


##### Referência Bibliográfica:
* Material da disciplina no Youtube / SIGAA
* https://matheuspraxedescg.blogspot.com/2016/10/pipeline-grafico.html