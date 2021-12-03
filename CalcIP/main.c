#include <stdio.h>

void inserirEndIP_(int *endIp){
  printf("Endereço IP v4:\n");
  for (int i=0; i<4; i++){
    do{
      printf("Oct %d:\n", (i+1));
      scanf("%d", &endIp[i]);
    }while(endIp[i]<0 || endIp[i]>255);
  }
  do{
    printf("Máscara:\n");
    scanf("%d", &endIp[4]);
  }while(endIp[4]<0 || endIp[4]>32);
}

void inserirEndIP(int *endIp){
  printf("Endereço IP v4:\n");
  scanf("%d.%d.%d.%d/%d", &endIp[0], &endIp[1],
  &endIp[2], &endIp[3], &endIp[4]);
}

void mostrarEndIP(int *endIp){
  for (int i=0; i<4; i++){
    if(i==0 || i==1 || i==2) printf("%d.", endIp[i]);
    else if(i==3) printf("%d/", endIp[i]);
  }
  printf("%d\n\n", endIp[4]);
}

void converterParaBin(int oct, int *bin){
  int regua[8] = {128, 64, 32, 16, 8, 4, 2, 1};
  for(int i=0; i<8; i++){
    if(oct>=regua[i]){
      bin[i]=1;
      oct=oct-regua[i];
    }
    else{
      bin[i]=0;
    }
  }
}

void mostrarBin(int *bin){
  for(int i=0; i<8; i++){
    printf("%d | ",bin[i]);
  }
  printf("\n");
}

int converteParaDecimal(int *bin){
  int dec=0;
  int regua[8] = {128, 64, 32, 16, 8, 4, 2, 1};
  for(int i=0; i<8; i++){
    dec = dec + (regua[i]*bin[i]);
  }
  return dec;
}

int convertParteRede(int *bin, int bits){
  for(int i=bits; i<8; i++){
    bin[i]=0;
  }
  return converteParaDecimal(bin);
}

int convertParteBroadcast(int *bin, int bits){
  for(int i=bits; i<8; i++){
    bin[i]=1;
  }
  return converteParaDecimal(bin);
}

void calcEndRede(int *endIp, int *endRede){
  int bin[8];
  if(endIp[4]==8){
    endRede[0]=endIp[0];
    endRede[1]=0; endRede[2]=0; endRede[3]=0;
    endRede[4]=endIp[4];
  }
  else if(endIp[4]==16){
    endRede[0]=endIp[0]; endRede[1]=endIp[1];
    endRede[2]=0; endRede[3]=0;
    endRede[4]=endIp[4];
  }
  else if(endIp[4]==24){
    endRede[0]=endIp[0]; endRede[1]=endIp[1]; endRede[2]=endIp[2];
    endRede[3]=0;
    endRede[4]=endIp[4];
  }
  else{
    if(endIp[4]<8){
      converterParaBin(endIp[0], bin);
      //mostrarBin(bin);
      endRede[0]=convertParteRede(bin, (endIp[4]));
      endRede[1]=0; endRede[2]=0; endRede[3]=0;
      endRede[4]=endIp[4];
    }
    else if(endIp[4]>8 && endIp[4]<16){
      converterParaBin(endIp[1], bin);
      endRede[1]=convertParteRede(bin, (endIp[4]-8));
      endRede[0]=endIp[0]; endRede[2]=0; endRede[3]=0;
      endRede[4]=endIp[4];
    }
    else if(endIp[4]>16 && endIp[4]<24){
      converterParaBin(endIp[2], bin);
      endRede[2]=convertParteRede(bin, (endIp[4]-16));
      endRede[0]=endIp[0]; endRede[1]=endIp[1]; endRede[3]=0;
      endRede[4]=endIp[4];
    }
    else{
      converterParaBin(endIp[3], bin);
      endRede[3]=convertParteRede(bin, (endIp[4]-24));
      endRede[0]=endIp[0]; endRede[1]=endIp[1]; endRede[2]=endIp[2];
      endRede[4]=endIp[4];
    }
  }
}

void calcBroad(int *endIp, int *endRede){
  int bin[8];
  if(endIp[4]==8){
    endRede[0]=endIp[0];
    endRede[1]=255; endRede[2]=255; endRede[3]=255;
    endRede[4]=endIp[4];
  }
  else if(endIp[4]==16){
    endRede[0]=endIp[0]; endRede[1]=endIp[1];
    endRede[2]=255; endRede[3]=255;
    endRede[4]=endIp[4];
  }
  else if(endIp[4]==24){
    endRede[0]=endIp[0]; endRede[1]=endIp[1]; endRede[2]=endIp[2];
    endRede[3]=255;
    endRede[4]=endIp[4];
  }
  else{
    if(endIp[4]<8){
      converterParaBin(endIp[0], bin);
      //mostrarBin(bin);
      endRede[0]=convertParteBroadcast(bin, (endIp[4]));
      endRede[1]=255; endRede[2]=255; endRede[3]=255;
      endRede[4]=endIp[4];
    }
    else if(endIp[4]>8 && endIp[4]<16){
      converterParaBin(endIp[1], bin);
      endRede[1]=convertParteBroadcast(bin, (endIp[4]-8));
      endRede[0]=endIp[0]; endRede[2]=255; endRede[3]=255;
      endRede[4]=endIp[4];
    }
    else if(endIp[4]>16 && endIp[4]<24){
      converterParaBin(endIp[2], bin);
      endRede[2]=convertParteBroadcast(bin, (endIp[4]-16));
      endRede[0]=endIp[0]; endRede[1]=endIp[1]; endRede[3]=255;
      endRede[4]=endIp[4];
    }
    else{
      converterParaBin(endIp[3], bin);
      endRede[3]=convertParteBroadcast(bin, (endIp[4]-24));
      endRede[0]=endIp[0]; endRede[1]=endIp[1]; endRede[2]=endIp[2];
      endRede[4]=endIp[4];
    }
  }
}

int main() {
  int endIp[5];
  int endRede[5];
  int endBroad[5];
  inserirEndIP(endIp);
  //printf("Endereço IP v4:\n");
  //mostrarEndIP(endIp);

  calcEndRede(endIp, endRede);
  printf("Endereço de Rede:\n");
  mostrarEndIP(endRede);

  calcBroad(endIp, endBroad);
  printf("Endereço Broadcast:\n");
  mostrarEndIP(endBroad);
  return 0;
}