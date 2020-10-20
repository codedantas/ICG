#include "mygl.h"

unsigned char* fb_ptr = NULL;

void InitMyGl(void) {
    fb_ptr = (unsigned char *)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * 4 * sizeof(char));	

    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; ++i) {
        fb_ptr[i * 4] = 0;
        fb_ptr[i * 4 + 1] = 0;
        fb_ptr[i * 4 + 2] = 0;
        fb_ptr[i * 4 + 3] = 255;
    }    
}

unsigned char* GetFBMemPtr(void) {
	return fb_ptr;
}

void CloseMyGl(void) {
    if (!fb_ptr)
        free(fb_ptr);
}

//
// >>> Caro aluno: defina aqui as funções que você implementar <<<
//
void putPixel(pixel P){

		fb_ptr[(4*P.x) + (4*P.y*IMAGE_WIDTH) + 0] = P.Vermelho; // R = Vermelho
		fb_ptr[(4*P.x) + (4*P.y*IMAGE_WIDTH) + 1] = P.Verde; // G = Verde
		fb_ptr[(4*P.x) + (4*P.y*IMAGE_WIDTH) + 2] = P.Azul; // B = Azul
		fb_ptr[(4*P.x) + (4*P.y*IMAGE_WIDTH) + 3] = P.Alfa; //  A = Alfa
    }

void drawLine(pixel P1, pixel P2){

    int dx = P2.x - P1.x; 
    int dy = P2.y - P1.y; 

    int incre_L, incre_NE; 
    int prox_x, prox_y;

    int D; 

//definindo todos os valores de x e y em todos os 8 octantes
    if(dx > 0){
        prox_x = 1;
    }else{
        prox_x = -1;
    }

    if(dy > 0){
        prox_y = 1;
    }else{
        prox_y = -1;
    }

    putPixel(P1);

    //Cálculo da interpolação
    // abs(x) calcula o valor absoluto de x
    if(dx < 0){ //3º,4º,5º e 6º octantes
        drawLine(P2,P1);
        return;
    }else{
        if(dy > 0){ //1º e 2º octante
            if(abs(dx) > abs(dy)){ //1º octante
                D = (dy-dx)*2;
                incre_L = 2*dy;
                incre_NE = 2*(dy-dx);

                while(P1.x < P2.x){ 
                    if(D > 0){
                        D += incre_L;
                        P1.x += prox_x;
                    }else{
                        D += incre_NE;
                        P1.x += prox_x;
                        P1.y += prox_y;
                    }

                    // interpolacao de cores
                    P1.Vermelho += (float)(P2.Vermelho - P1.Vermelho) / abs(dx);
                    P1.Verde += (float)(P2.Verde - P1.Verde) / abs(dx);
                    P1.Azul += (float)(P2.Azul - P1.Azul) / abs(dx);
                    P1.Alfa += (float)(P2.Alfa - P1.Alfa) / abs(dx);

                    putPixel(P1);
                }
            }else{ // 2º octante
                D = dy - (2*dx);
                incre_L = 2*(dx-dy);
                incre_NE= 2*dx;

                while(P1.y < P2.y) {
                    if(D < 0){
                        D += incre_NE;
                        P1.y += prox_y;
                    }else{
                        D += incre_L;
                        P1.x += prox_x;
                        P1.y += prox_y;
                    }

                    // interpolacao de cores
                    P1.Vermelho += (float)(P2.Vermelho - P1.Vermelho) / abs(dy);
                    P1.Verde += (float)(P2.Verde - P1.Verde) / abs(dy);
                    P1.Azul += (float)(P2.Azul - P1.Azul) / abs(dy);
                    P1.Alfa += (float)(P2.Alfa - P1.Alfa) / abs(dy);

                    putPixel(P1);
                }                               
            }
        }else{ //7º e 8º octantes 
            if(abs(dx) > abs(dy)){ //8º octante
                D = (-2)*dy + dx;
                incre_L = (-2) * dy;
                incre_NE = (-2) * (dy + dx);

                while(P1.x < P2.x){ 
                    if(D > 0){
                        D += incre_L;
                        P1.x += prox_x;
                    }else{
                        D += incre_NE;
                        P1.x += prox_x;
                        P1.y -= prox_y;
                    }

                    // interpolacao de cores
                    P1.Vermelho += (float)(P2.Vermelho - P1.Vermelho) / abs(dx);
                    P1.Verde += (float)(P2.Verde - P1.Verde) / abs(dx);
                    P1.Azul += (float)(P2.Azul - P1.Azul) / abs(dx);
                    P1.Alfa += (float)(P2.Alfa - P1.Alfa) / abs(dx);

                    putPixel(P1);
                }
            }else{ //7º octante                
                D = dy + (2*dx);
                incre_L = 2 * dy;
                incre_NE = 2 * (dy + dx);

                while(P1.y > P2.y){ 
                    if(D < 0){
                        D += incre_L;
                        P1.y -= prox_y;                        
                    }else{
                        D += incre_NE;
                        P1.x += prox_x;
                        P1.y -= prox_y;                         
                    }

                    // interpolacao de cores
                    P1.Vermelho += (float)(P2.Vermelho - P1.Vermelho) / abs(dy);
                    P1.Verde += (float)(P2.Verde - P1.Verde) / abs(dy);
                    P1.Azul += (float)(P2.Azul - P1.Azul) / abs(dy);
                    P1.Alfa += (float)(P2.Alfa - P1.Alfa) / abs(dy);

                    putPixel(P1);
                }                    
            }
        }
    }
}

void DrawTriangle(pixel P1, pixel P2, pixel P3){
    drawLine(P1,P2);
    drawLine(P2,P3);
    drawLine(P3,P1);
}
// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {
    //
    // >>> Caro aluno: chame aqui as funções que você implementou <<<
    //
    pixel P1 = {130, 300, 0, 255, 0, 255};
    pixel P2 = {120,100 , 255, 255, 255, 255};
    pixel P3 = {300, 300, 255, 0, 0, 255};
	//drawLine(P1, P2);
	//putPixel(P1);
	//putPixel(P2);
	//putPixel(P3);

    DrawTriangle(P1,P2,P3);

		

}
