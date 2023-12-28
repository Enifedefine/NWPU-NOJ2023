#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define N 11
struct locate{
    int a,b,c;
};
locate A,B,C,D;
double t1,t2,t3,t4;
double cc = 299792.458;

void print1(double AA[N],int n) { //输出一个矢量
	int i;
	for (i=0; i<n; i++)
		printf("%.7lf ", AA[i]);
	printf("\n");
}

void print2(double AA[N][N],int n) { //输出一个矩阵
	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++)
			printf("%.7lf ", AA[i][j]);
		printf("\n");
	}
}

// 计算代数余子式函数，结果=dest
int GetCoFactor(double dest[N][N], double src[N][N], int row, int col, int n)
{
	int i, j;
	int colCount=0,rowCount=0;
	for(i=0; i<n; i++ ) {
		if( i!=row ) {
			colCount = 0;
            for(j=0; j<n; j++ )
				if( j != col ) { //当j不是元素时
					dest[rowCount][colCount] = src[i][j];
					colCount++;
				}
			rowCount++;
		}
	}
	return 1;
}
 
// 递归计算行列式，结果=返回值
double CalcDeterminant(double mat[N][N], int n)
{
	int i,j;
	double det = 0; //行列式值
	double minor[N][N]; // allocate 余子式矩阵

    // n 必须 >= 0，当矩阵是单个元素时停止递归
	if( n == 1 ) return mat[0][0];
	for(i = 0; i < n; i++ ) {
		GetCoFactor(minor, mat, 0, i , n);
		det += ( i%2==1 ? -1.0 : 1.0 ) * mat[0][i] * CalcDeterminant(minor,n-1);
	}
	return det;
}
// 伴随矩阵法矩阵求逆 , 结果存放到 inv 数组
void MatrixInversion(double J[N][N], int n)
{
	int i,j;
    double det, temp [N][N], minor[N][N];
    double inv[N][N];
	
	det = 1.0/CalcDeterminant(J,n); //计算行列式
	for(j=0; j<n; j++)
		for(i=0; i<n; i++) {
			// 得到矩阵A(j,i)的代数余子式 
			GetCoFactor(minor,J,j,i,n);
			inv[i][j] = det*CalcDeterminant(minor,n-1);
			if( (i+j)%2 == 1)
				inv[i][j] = -inv[i][j];
		}
	//结果存回J矩阵
	for(j=0; j<n; j++)
		for(i=0; i<n; i++)
			J[i][j] = inv[i][j];
}

// 由Xn计算函数Fn，结果存放到 F
void CalcF(double F[N],double X[N],int n) {
	double f;
	int i;
	for (i=0; i<n; i++) {
		switch (i+1) {
			case 1: 
				f=(X[0] - A.a)*(X[0] - A.a)+(X[1] - A.b)*(X[1] - A.b)+(X[2] - A.c)*(X[2] - A.c)-(cc * (t1-X[3]))*(cc * (t1-X[3])); //(x - A.a)^2+(y - A.b)^2+(z - A.c)^2-(cc*(t1-d))^2
				break;
			case 2: 
				f=(X[0] - B.a)*(X[0] - B.a)+(X[1] - B.b)*(X[1] - B.b)+(X[2] - B.c)*(X[2] - B.c)-(cc * (t2-X[3]))*(cc * (t2-X[3])); //(x - B.a)^2+(y - B.b)^2+(z - B.c)^2-(cc*(t2-d))^2
				break;
			case 3: 
				f=(X[0] - C.a)*(X[0] - C.a)+(X[1] - C.b)*(X[1] - C.b)+(X[2] - C.c)*(X[2] - C.c)-(cc * (t3-X[3]))*(cc * (t3-X[3])); //(x - C.a)^2+(y - C.b)^2+(z - C.c)^2-(cc*(t3-d))^2
				break;
            case 4: 
				f=(X[0] - D.a)*(X[0] - D.a)+(X[1] - D.b)*(X[1] - D.b)+(X[2] - D.c)*(X[2] - D.c)-(cc * (t4-X[3]))*(cc * (t4-X[3])); //(x - D.a)^2+(y - D.b)^2+(z - D.c)^2-(cc*(t4-d))^2
				break;
		}
		F[i]=f;
	}
}

// 由Xn计算偏导数Jacobian矩阵F'n，结果存放到 J
void CalcJ(double J[N][N],double X[N],int n) {
	double f;
	int i,j;
	for (i=0; i<n; i++)
		switch (i+1) {
			case 1:
				for (j=0; j<n; j++) {
					switch (j+1) {
						case 1: f=2*(X[0]-A.a);break; // J1.1=2*(x-A.a)
						case 2: f=2*(X[1]-A.b);break; // J1.2=2*(y-A.b)
						case 3: f=2*(X[2]-A.c);break;  // J1.3=2*(z-A.c)
                        case 4: f=2*cc*cc*(t1-X[3]);break;  // J1.4=2*cc*cc*(t1-d)
					}
					J[i][j]=f;
				}
				break;
			case 2:
				for (j=0; j<n; j++) {
					switch (j+1) {
						case 1: f=2*(X[0]-B.a);break; // J1.1=2*(x-A.a)
						case 2: f=2*(X[1]-B.b);break; // J1.2=2*(y-A.b)
						case 3: f=2*(X[2]-B.c);break;  // J1.3=2*(z-A.c)
                        case 4: f=2*cc*cc*(t2-X[3]);break;  // J1.4=2*cc*cc*(t1-d)
					}
					J[i][j]=f;
				}
				break;
			case 3:
				for (j=0; j<n; j++) {
					switch (j+1) {
						case 1: f=2*(X[0]-C.a);break; // J1.1=2*(x-A.a)
						case 2: f=2*(X[1]-C.b);break; // J1.2=2*(y-A.b)
						case 3: f=2*(X[2]-C.c);break;  // J1.3=2*(z-A.c)
                        case 4: f=2*cc*cc*(t3-X[3]);break;  // J1.4=2*cc*cc*(t1-d)
					}
					J[i][j]=f;
				}
				break;	
            case 4:
				for (j=0; j<n; j++) {
					switch (j+1) {
						case 1: f=2*(X[0]-D.a);break; // J1.1=2*(x-A.a)
						case 2: f=2*(X[1]-D.b);break; // J1.2=2*(y-A.b)
						case 3: f=2*(X[2]-D.c);break;  // J1.3=2*(z-A.c)
                        case 4: f=2*cc*cc*(t4-X[3]);break;  // J1.4=2*cc*cc*(t1-d)
					}
					J[i][j]=f;
				}
				break;								
		}
}

// 计算 J^-1* F，结果存放到 R
void CalcJF(double R[N], double J[N][N], double F[N], int n) {
	int i,j,k;
	for (i=0; i<n; i++) {
		R[i]=0.0;
		for (j=0; j<n; j++)
			R[i] = R[i] + J[i][j]*F[j];
	}
}

// 计算 X=X0-R，结果存放到 X
void CalcX(double X[N],double X0[N],double R[N],int n) {
	int i;
	for (i=0; i<n; i++)
		X[i]=X0[i]-R[i];
}

// 计算 A=B，结果存放到 A
void AequB(double AA[N],double BB[N],int n) {
	int i;
	for (i=0; i<n; i++)
		AA[i]=BB[i];
}

// 计算 F-
double Ferror(double F[N], int n) {
	double m=0;
	int i;
	for (i=0; i<n; i++) {
		double t=fabs(F[i]);
		if (m<t) m = t;
	}
	return m;
}

// Newton–Raphson method 牛顿迭代法求非线性方程组的根，存放到X0
void mvNewtons(double X0[N], int n, double e) {
	// Guess为初始猜测值 e为迭代精度要求
	int k;
	double J[N][N],Y[N][N];
	double X[N],R[N],F[N];
	//X0一开始为初始猜测值
	for (k=1; k<=20; k++) { //限定20次迭代
		//printf("-------------- n=%d\n",k);
		//printf("X\n");
		//print1(X0,n); //输出X0
		CalcF(F,X0,n); //计算F矩阵
		//printf("F\n"); //观察 F
		//print1(F,n); //输出F
		CalcJ(J,X0,n); //计算Jacobian矩阵F'n(x0)
		//printf("J\n");
		//print2(J,n); //观察 J
		MatrixInversion(J, n); // 求J的逆矩阵 J^-1
		CalcJF(R,J,F,n); // R=J^-1 * F
		CalcX(X,X0,R,n); // X=X0-R
		AequB(X0,X,n); // X0=X 下次迭代
		if (Ferror(F,n)<e) break; //达到精度要求，终止迭代
	}
}

int main() {
    cin >> A.a >> A.b >> A.c;
    cin >> B.a >> B.b >> B.c;
    cin >> C.a >> C.b >> C.c;
    cin >> D.a >> D.b >> D.c;
    cin >> t1 >> t2 >> t3 >> t4;
    double x0,y0,z0,d0;
    cin >> x0 >> y0 >> z0 >> d0;
    int n = 4;
	double X[N]={x0,y0,z0,d0};
    mvNewtons(X,n,1e-6);
    printf("%.5f\b,%.5f\b,%.5f\b \n" , X[0] , X[1] , X[2]);
    return 0;
}