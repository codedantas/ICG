# Atividade 01 - OpenGL (Modern OpenGL Hello World)

O trabalho a seguir refere-se a primeira atividade da disciplina de Introdução a Computação Gráfica ministrada pelo Professor Christian Azambuja Pagot ([Lattes](http://lattes.cnpq.br/4353928200012173)). 

[<img src="https://rawgit.com/eug/awesome-opengl/master/opengl-logo.svg" align="right" width="140">](https://www.opengl.org)

Os objetivos deste trabalho são:

<ol>
    <li>Verificar se o ambiente de desenvolvimento em OpenGL 3.3 está com o funcionamento correto na máquina local;</li>
    <li>Exemplificar o funcionamento do OpenGL moderno e do antigo através de exemplos;</li>
</ol>

## Desenvolvimento

Para a realização deste trabalho, inicialmente, terá que instalar o OpenGL em seu ambiente de desenvolvimento a seguir:

### Pré-requisitos

Caso esteja no Ubuntu, rode os seguintes comandos no terminal para instalar o OpenGl:

```sh
$ sudo apt-get update
$ sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

### Utilização

Para executar o código deve-se criar o arquivo compilado para ser executado:

```sh
$ cd ICG/act01_hello_world_opengl/modern_opengl/
$ gcc main.c -o [nome executável] -lglut -lGLU -lGL
```

Após isso, basta executar o programa:
```sh
$ ./[nome executável]
```

Em seguida, terá que fazer download do programa OpenGL disponível no repositório da disciplina:

https://github.com/capagot/icg/tree/master/01_hello_world_gl/modern_opengl


## Objetivos concluídos

- [x] Verificar se o ambiente de desenvolvimento em OpenGL 3.3 está com o funcionamento correto na máquina local

- [x] Exemplificar o funcionamento do OpenGL moderno e do antigo através de exemplos

## Dificuldades encontradas

Não foram encontradas dificuldade para executar os códigos disponibilizados.

## Resultado

![Figura 1](https://github.com/matheusdantascc/ICG/blob/master/act01_hello_world_opengl/img/modern-opengl.png)

### Autor
<ul>
    <li>Matheus Henrique Raposo Dantas – 11414179 – matheusdantas@cc.ci.ufpb.br</li>
</ul>
