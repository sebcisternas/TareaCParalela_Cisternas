#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <math.h>-
using namespace std;


double media(double A[],double sum1){

 double prom;

 prom=(((1.5*A[0])+(2.5*A[1])+(3.5*A[2])+(4.5*A[3])+(5.5*A[4])+(6.5*A[5]))/sum1);
 return prom;

}

float moda(double A[]){
   int k;
   double mayor=A[0],mod;
   for(int i=0;i<7;i++){
        if(mayor<=A[i]){
           mayor=A[i];
           k=i;
        }
   }

   if(k==0)
    mod=(1.0+((A[0]-0)/((A[0]-0)+(A[0]-0))));

   if(k==1)
    mod=(2.0+((A[1]-A[0])/((A[1]-A[0])+(A[1]-A[2]))));

   if(k==2)
    mod=(3.0+((A[2]-A[1])/((A[2]-A[1])+(A[2]-A[3]))));

   if(k==3)
    mod=(4.0+((A[3]-A[2])/((A[3]-A[2])+(A[3]-A[4]))));

   if(k==4)
    mod=(5.0+((A[4]-A[3])/((A[4]-A[3])+(A[4]-A[5]))));

   if(k==5)
    mod=(6.0+((A[5]-A[4])/((A[5]-A[4])+(A[5]-A[6]))));

  return mod;
}


float mediana(double A[],double B[],double sum1){
      float med;
      if((sum1/2)>=0 & (sum1/2)<B[0])
          med=1.0+((sum1/2)/A[0]);

      if((sum1/2)>=B[0] & (sum1/2)<B[1])
          med=2.0+(((sum1/2)-B[0])/A[1])*1.0;

      if((sum1/2)>=B[1] & (sum1/2)<B[2])
          med=3.0+(((sum1/2)-B[1])/A[2])*1.0;

      if((sum1/2)>=B[2] & (sum1/2)<B[3])
          med=4.0+(((sum1/2)-B[2])/A[3])*1.0;

      if((sum1/2)>=B[3] & (sum1/2)<B[4])
          med=5.0+(((sum1/2)-B[3])/A[4])*1.0;

      if((sum1/2)>=B[4] & (sum1/2)<B[5])
          med=6.0+(((sum1/2)-B[4])/A[5])*1.0;







      return med;
}

float desviacion(double A[],float prom,double sum1){


     double sum2= (pow(1.5-prom,2)*A[0]+pow(2.5-prom,2)*A[1]+pow(3.5-prom,2)*A[2]+pow(4.5-prom,2)*A[3]+pow(5.5-prom,2)*A[4]+pow(6.5-prom,2)*A[5]+pow(7-prom,2));

     float des= sum2/sum1;

     des=sqrt(des);

 return des;

}

int main()
{
    float prom;
    double num,sum=0,sum1=0;
    double A[6],B[6];
    for(int i=0;i<7;i++){
       A[i]=0;
   }

   cout<<"Tarea Paralela"<<endl;
   cout<<"Calculando... "<<endl;

   ifstream fin("numeros.txt");

    string valor,aux;


   while(fin>>valor){

   num=std::stof(valor.c_str());



   sum=sum+num;
   if (num>=1.0 & num<2.0){
    A[0]=A[0]+1;
   }
   if (num>=2.0 & num<3.0){
    A[1]=A[1]+1;
   }
   if (num>=3.0 & num<4.0){
     A[2]=A[2]+1;
   }
   if (num>=4.0 & num<5.0){
    A[3]=A[3]+1;
   }
   if (num>=5.0 & num<6.0){
   A[4]=A[4]+1;
   }
   if (num>=6.0 & num<=7.0){

    A[5]=A[5]+1;
   }


   }


  for(int i=0;i<6;i++){
    std::cout<<std::setprecision(11)<<A[i]<<endl;
    }


   B[0]=A[0];

   for(int i=0;i<6;i++){
      sum1=sum1+A[i];
      cout<<A[i]<<endl;
   }


   for(int i=1;i<6;i++){

       B[i]=B[i-1]+A[i];
    }
   cout<<"Suma Total es = ";
   std::cout<<std::setprecision(11)<<sum<<endl;
   cout<<"Cantidad de Datos es : "<<sum1<<endl;
   cout<<"La media es  = ";
   prom=media(A,sum1);
   cout<<fixed<< setprecision(1)<<prom<<endl;

   cout<<"La moda es = ";
   cout<<fixed<< setprecision(1)<<moda(A)<<endl;
   cout<<"La mediana es = ";
   cout<<mediana(A,B,sum1)<<endl;
   cout<<"La desvacion estandar es = ";
   cout<<desviacion(A,prom,sum1);
   return 0;
}
