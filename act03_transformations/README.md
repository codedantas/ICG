# Atividade 03 - Implemantação do Pipeline Gráfico

O trabalho a seguir refere-se a terceira atividade da disciplina de Introdução a Computação Gráfica ministrada pelo Professor Christian Azambuja Pagot ([Lattes](http://lattes.cnpq.br/4353928200012173)). 

[<img src="https://rawgit.com/eug/awesome-opengl/master/opengl-logo.svg" align="right" width="140">](https://www.opengl.org)

Os objetivos deste trabalho são:

<ol>
    <li>Familiarizar os alunos com os algoritmos de pipeline gráfico em computação gráfica;</li>
    <li>Implementar as transformações geométricas que compõem a estrutura do pipeline gráfico.</li>
</ol>

Para este trabalho utilizaremos as bibliotecas *__glm__* e *__GLEW__* fornecido pelo Prof. Christian Azambuja Pagot e código disponibilizado abaixo depende de softwares de terceiros como as bibliotecas citadas.

Download do repositório do código template: <https://github.com/capagot/icg/tree/master/03_transformations>

## Dependências

Para instalar a biblioteca *__GLEW__*, o seguinte comando deve ser executado:

~~~
$ sudo apt-get install libglew-dev
~~~

A biblioteca *__glm__* está inclusa na forma de submódulo, assim, se faz necessário clonar o repositório do projeto para fazer *__download__* automático do submódulo, execute o seguinte comando:


~~~
$ git clone --recurse-submodules https://github.com/capagot/icg.git
~~~

## Compilação

Após a instalar das dependências, basta acessar o repositório do projeto, abrir o terminal e executar o comando:

~~~
$ make
~~~

Aparecerá alguns *warnings*, mas basta executar o programa da seguinte forma:

~~~ 
$ ./transform_gl
~~~

Se tudo correu bem após compilar, você verá:

![](https://github.com/matheusdantascc/ICG/blob/master/act03_transformations/img/modelopadrao.png)


## :pushpin:  A Atividade

A atividade consiste em alterar, no programa template, os conteúdos das matrizes *__MODEL__*, *__VIEW__* e *__PROJECTION__*, que estão listadas abaixo, de forma que o programa gere as imagens listadas nos exercicios abaixo:

## :clipboard: Exercício 1: Escala

Neste exercício devemos modificar a matriz *Model* de forma que a imagem gerada pelo programa fique como a da figura abaixo:

![](https://github.com/matheusdantascc/ICG/blob/master/act03_transformations/img/exercicio1-escala-modelo.png)

Temos os fatores de escala em __(x,y,z) = (1/3, 3/2, 1)__. Dado isso, a matriz modificada fica da seguinte forma:

~~~c++
    float model_array[16] = {0.333f, 0.0f, 0.0f, 0.0f,
                         0.0f, 1.5f, 0.0f, 0.0f,
                         0.0f, 0.0f, 1.0f, 0.0f,
                         0.0f, 0.0f, 0.0f, 1.0f};
~~~

Após a substituição dos valores e compilação, obtivemos o resultado a seguir:

![](https://github.com/matheusdantascc/ICG/blob/master/act03_transformations/img/exercicio1-escala.png)

## :clipboard: Exercício 2: Translação

Neste exercício devemos modificar novamente a matriz *Model* de forma que a imagem gerada pelo programa fique como a da figura abaixo:

![](https://github.com/matheusdantascc/ICG/blob/master/act03_transformations/img/exercicio2-translacao-modelo.png)

Temos os fatores de translação em __(x,y,z) = (1,0,0)__. Dado isso, a matriz modificada fica da seguinte forma:


~~~c++
    float model_array[16] = {1.0f, 0.0f, 0.0f, 0.0f,
                             0.0f, 1.0f, 0.0f, 0.0f,
                             0.0f, 0.0f, 1.0f, 0.0f,
                             1.0f, 0.0f, 0.0f, 1.0f};
~~~

Após a substituição dos valores e compilação, obtivemos o resultado a seguir:

![](https://github.com/matheusdantascc/ICG/blob/master/act03_transformations/img/exercicio2-translacao.png)


## :clipboard: Exercício 3: Projeção Perspectiva

Neste exercício devemos modificar a matriz *Projection* de forma que a imagem gerada pelo programa fique como a da figura abaixo:

![](https://github.com/matheusdantascc/ICG/blob/master/act03_transformations/img/exercicio3-projecao-modelo.png)

A matriz de projetação usada foi a que estudamos em aula, que considera a câmera na origem do seu sistema de coordenadas e onde *d* é a distância do centro de projetação até a origem do sistema de coordenadas da câmera, logo:

![](https://github.com/matheusdantascc/ICG/blob/master/act03_transformations/img/exercicio3-projeco-mp.png)

A partir disso, atribuimos 1/8 à *d* e a matriz modificada fica da seguinte forma:

~~~c
  float proj_array[16] = {1.0f, 0.0f, 0.0f, 0.0f, 
                          0.0f, 1.0f, 0.0f, 0.0f, 
                          0.0f, 0.0f, 1.0f, -8.0f, 
                          0.0f, 0.0f, 0.125, 0.0f};
~~~

E obtivemos o resultado a seguir:

![](https://github.com/matheusdantascc/ICG/blob/master/act03_transformations/img/exercicio3-projecao.png)


## :clipboard: Exercício 4: Posição da Câmera

Neste exercício devemos modificar a matriz *View* de forma que a imagem gerada pelo programa fique como a da figura abaixo:

![](https://github.com/matheusdantascc/ICG/blob/master/act03_transformations/img/exercicio4-camera-modelo.png)

Para a realização desse exercício, faz-se necessário descobrir as coordenadas x,y e z do espaço da câmera para isso, devemos realizar a transformação do Espaço do Universo para o da Câmera usando as seguintes fórmulas:


![](https://github.com/matheusdantascc/ICG/blob/master/act03_transformations/img/exercicio4-camera-2.png)

Após isso, temos uma nova matriz Mview obtida a partir da matriz resultante da multplicação das matrizes: Bt(ou de rotação) e Translação T, representadas por:

![](https://github.com/matheusdantascc/ICG/blob/master/act03_transformations/img/exercicio4-camera-3.png)

E obtivemos o resultado a seguir:

![](https://github.com/matheusdantascc/ICG/blob/master/act03_transformations/img/exercicio4-camera.png)


## :clipboard: Exercício 5: Transformações Livres

Neste exercício devemos modificar novamente as matrizes *Model*, *View* e *Projection* de forma a gerarem uma cena diferente das geradas anteriormente, assim temos:

Matriz Model
~~~c++
    float model_array[16] = {1.0f, 0.0f, 0.0f, 0.0f,
                            -0.5f, 1.0f, 0.0f, 0.0f,
                            0.0f, 0.0f, 1.0f, 0.0f,
                            0.7f, 0.0f, 0.0f, 1.0f};

Matriz View
~~~c++
    float view_array[16] = {1.0f, -0.4f, 0.0f, 1.0f, 
                            0.5f, -1.2f, 0.0f, -0.1f, 
                            0.5f, 0.2f, 1.0f, 0.0f, 
                            0.0f, 0.0f, 0.3f, 1.0f};
~~~

Matriz Projection
~~~c++
    float proj_array[16] = {0.8f, 0.0f, 0.5f, 0.0f,
                          0.0f, 1.0f, -0.4f, 0.0f,
                          0.8f, -0.2f, 1.0f, 0.0f,
                          0.0f, 0.0f, 0.5, 1.0f};
~~~

Após essas modificações, obtivemos o resultador a seguir:

![](https://github.com/matheusdantascc/ICG/blob/master/act03_transformations/img/exercicio5-transformacoes.png)

## Referências

1. Notas de aula do Professor Christian Azambuja Pagot disponibilizadas no Sigaa.

## Alunos

Kenji Aranha Sato - 11514918

Matheus Henrique Raposo Dantas - 11414179 
