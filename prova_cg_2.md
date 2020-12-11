<div align="center">
<h1> Introdução à Computação Gráfica</h1>
</div>

<div align="center"> 
<h2> PROVA II </h2>
</div>

##### Aluno: Matheus Henrique Raposo Dantas
##### Matrícula: 11414179

<div align="center"> <h2>RESPOSTAS</h2> 
</div>


##### Questão 2

1. Falsa. Se levarmos em consideração apenas uma situação estática, onde os triangulos não se movem, necessariamente teríamos que renderizar de trás pra frente *(back to front)* e resolveríamos o problema da oclusão. __No entanto__, se acontece algum evento não estático, como a mudança da cena ou a movimentação da câmera, necessariamente teremos que reordenar as primitivas. Então, não há garantias que o problema da oclusão seja resolvido necessariamente com a pré-ordenação.

2. Falsa. O controle de profundidade é feito fragmento por fragmento, ou seja, os triangulos serão exibidos na tela conforme a ordem em que foram processados.Desse modo, não é necessário nenhum pré-ordenamento.

3. Verdadeira. Essa técnica apenas resolve o problema de remoção de superfícies ocultas em malhas fechadas que se baseia na orientação determinar sua remoção.

##### Questão 3

1. Quando as formas texturizadas desenhadas nas tela são maiores ou menores do que sua forma original, costumam ficar distorcidas e no mapeamento de textura regular, a aparência fica pixelizada. Logo, a filtragem bilinear busca minimizar essa distorção através de um processamento gráfico a partir da placa de video onde ocorre a suavização das transições entres as cores.


2. A *Filtragem Bilinear* usa quatros elementos de textura (texels) mais próximos do centro do pixel e suas cores são combinadas, calcula a média ponderada de acordo com a distância e em seguida, aplica ao pixel da tela. Portanto, esse processo de suavização é repetido para cada pixel da imagem original.

    Enquanto, a *Nearest Neighbor* usa a cor do elemento da textura mais próximo do centro do pixel para cor do pixel, assim, o processo de suavização acontece de uma interpolação em direção seguida de outra interpolação na outra direção, tornando-a mais simples e mais bruto.

##### Questão 4

1. O *Flat Shading* aplica o modelo de iluminação uma única vez para cada triângulo, o qual gera uma intensidade que é usada para sombrear o triângulo e não representa variações ao longo do triângulo. Apesar de ser muito mais rápido e mais leve, possui pior resultado de forma a gerar uma  borda descontínuada.


2. O *Gouraud Shading* (sombreamento por interpolação de intensidade ou por interpolação de cor) elimina descontinuidades de intensidade, não elimina completamente mudanças de intensidade e estende conceito de sombreamento interpolado, considerando a superfície e não cada triângulo invidualmente.


3. O *Phong Shading* (interpolação do vetor normal) interpola a normal da superfície, ao invés da intensidade. As normais são obtidas a partir das normais dos vértices.

##### Referência Bibliográfica:
* Material da disciplina no Youtube / SIGAA

* [Wikipédia - Bilinear Interpolation](https://en.wikipedia.org/wiki/Bilinear_interpolation)

* [Wikipédia - Back-face culling](https://pt.wikipedia.org/wiki/Back-face_culling#:~:text=Na%20computa%C3%A7%C3%A3o%20gr%C3%A1fica%2C%20Back%2Dface,hor%C3%A1rio%20quando%20projetados%20na%20tela.)
 
* [Unicamp - Visibilidade em Computação Gráfica](http://www.dca.fee.unicamp.br/courses/IA725/1s2011/projetos/vidalon-nakashima/Algoritmos.html#:~:text=O)

* [PUCRS - Iluminação e Sombramento](https://www.inf.pucrs.br/~smusse/CG/PDFs/Iluminacao.pdf)

