#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* Perceptron Implementation (Ansi C)
 * Marco Aguero
 * Basic NAND implementation 
 * Adding git comment 
*/

//Definitions and prototypes
#define X_ROWS 4
#define X_COLS 3
#define THRESHOLD 0
#define ITERATIONS 100

float dot (int cycle,float[X_ROWS][X_COLS],float []);
float activation(float);

float dot (int cycle,float px[X_ROWS][X_COLS],float wx[])
{float dotp;
  for (int cnt2=0;cnt2<X_COLS;cnt2++)
  { 
    dotp=dotp+(wx[cnt2]*px[cycle][cnt2]);
  }

return dotp;
}

float activation (float dot_p)
{
  float yhat;
  if (dot_p >= THRESHOLD)
  {
    yhat=1;
  }
  else
  {  
    yhat=0;
  }
return yhat;
}



int main ()
{


/* Variable initialization */
/* Features */
/* Weights */
float w[X_COLS];

/* Estimated output y */
float y[]={1,1,1,0};
float errors[]={1,1,1,1};
float yhat_vec[]={0,0,0,0};
float J[ITERATIONS];
int x_sz, w_sz, y_sz =0;
int cnt1, cnt2, cnt3 =0;
int epoch=0;
float x[X_ROWS][X_COLS]={
 		{ 1, 0, 0 },
 		{ 1, 0, 1 },
 		{ 1, 1, 0 },
 		{ 1, 1, 1 }
};
/*Init weights*/
memset(&w[0], 0, sizeof(w));
/*0.20  -0.20  -0.10  0.20 for 1 epoch convergence*/

/*Getting array sizes for later use*/
x_sz=sizeof(x)/sizeof(int);
w_sz=sizeof(w)/sizeof(int);
y_sz=sizeof(y)/sizeof(int);
float dot_p, error=0.0;
float yhat;
//Setting up ETA
float eta=0.1;
float new_weight=0.0;

printf ("Bias \t W1 \t W2 \t DotP \t Yhat \t Y \n\n");

do
{

printf("Epoch(%d)\n",epoch);
for (int x_cnt=0;x_cnt < X_ROWS; x_cnt++)
{

// dot product calculation //
dot_p=dot(x_cnt,x,w);


//Threshold comparison

yhat=activation(dot_p);
yhat_vec[x_cnt]=yhat;
/*printf("\nyhat: %f and dotp is %f\n", yhat, dot_p );*/


error=y[x_cnt]-yhat_vec[x_cnt];
/* Adjusting the weights */
for (int cnt4=0;cnt4<X_COLS;cnt4++)
{
          w[cnt4]=w[cnt4]+eta*(y[x_cnt]-yhat)*x[x_cnt][cnt4];
        printf ("%.2f \t",w[cnt4]);
}
printf ("%.2f \t\t %f \t %f \n", dot_p, y[x_cnt],yhat_vec[x_cnt]);



} 
for (int cnt5=0;cnt5<X_ROWS;cnt5++)
{
  errors[cnt5]= powf(y[cnt5]-yhat_vec[cnt5],2);
  printf("\nError: errors[%d]=%f\n",cnt5, errors[cnt5] );
}

float res=0;
for (int cnt5=0;cnt5<X_ROWS;cnt5++)
{
  res=res+errors[cnt5];
}
J[epoch]=0.5*res;
red();
printf("SSE is: %f\n",J[epoch]);
reset();
printf ("\n");
epoch++;
} /* Iterations loop closure */
while (y[0]!=yhat_vec[0] ||y[1]!=yhat_vec[1] ||y[2]!=yhat_vec[2] ||y[3]!=yhat_vec[3] && epoch <= ITERATIONS);

printf ("\n");
}
