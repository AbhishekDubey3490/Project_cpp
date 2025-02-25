# include <iostream>
# include<cmath>
//1. REGULA FALSI
double regula_equ(double h){
    return pow(h,3)-4*h+1;
}
double regula_falsi(){
    double f=0,a,b,d,e,n,o;
    std::cout<<("Enter the value where function give negative value: ");
    std::cin>>a;
    std::cout<<("Enter the value where function give positive value: ");
    std::cin>>b;
    std::cout<<("Enter the value of decimal places");
    std::cin>>n;
    o=1/pow(10,n);
    do{
        d=((a*regula_equ(b))-(b*regula_equ(a)))/(regula_equ(b)-regula_equ(a));
        e=regula_equ(d);
        if(e==0){break;}
        else if(e<0){
            f=a-d;
            a=d;}
        else{
            f=b-d;
            b=d;}
        std::cout<<d<<std::endl;
    }while(f>o);
    std::cout<<"The root of given equation is "<<d;
}
//2. NEWTON RAPSON METHOD

double newton_equ(double x){
    return 2*pow(x,3)-3*x-6;          //DEFINE FUNCTION
}
double newton_der(double x){
    return 6*pow(x,2)-3;            //DEFINE DERIVATIVE OF FUNCTION
}
double newton_dder(double x){
    return 12*x;                    //DEFINE DOUBLE DERIVATIVE OF FUNCTION
}
double newton_rapson(){
    double a,b,c,d,e,f;
    std::cout<<"Enter guess value: ";
    std::cin>>a;
    std::cout<<"Enter the decimal places: ";
    std::cin>>e;
    d=1/(pow(10,e));
    f=newton_equ(a)-newton_dder(a);
    if(f<0){
        f=f*(-1);
    }
    if(f<(pow(newton_der(a),2))){
        do{
        b=a-(newton_equ(a)/newton_der(a));
        c=a-b;
        a=b;
        std::cout<<b<<std::endl;
    }while(c>d);
    std::cout<<"The root of given equation is: "<<b<<std::endl;
    }
    else{
        std::cout<<"Guess value wil not converge toward root";
    }
}

//3. NEWTON'S DIVIDED DIFFERENCE-------------------------------------------
#include <vector>
double newton_divided() {
    int n;
    std::cout << "Enter number of data points: ";
    std::cin >> n;
    std::vector<std::vector<double>> arr(n, std::vector<double>(n + 1, 0.0));
    for (int i = 0; i < n; i++) {
        std::cout << "Enter value of x[" << i << "]: ";
        std::cin >> arr[i][0];
        std::cout << "Enter value of y[" << i << "]: ";
        std::cin >> arr[i][1];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            arr[j][i] = (arr[j + 1][i - 1] - arr[j][i - 1]) / (arr[j + i - 1][0] - arr[j][0]);
        }
    }
    double x;
    std::cout << "Enter the point to interpolate: ";
    std::cin >> x;
    double result = arr[0][1];
    double term = 1.0;
    for (int i = 1; i < n; i++) {
        term *= (x - arr[i - 1][0]);
        result += term * arr[0][i + 1];
    }
    std::cout << "Interpolated value at x = " << x << " is: " << result << std::endl;
    return result;
}
//4. SIMSON'S ONE-THIRD RULE
double simson_fun(float x){
    return 1/((x*x)+(2*x)+10);
}
double simsons(){
    float h,y,a=0;
    int n=0;
    std::cout<<"Enter value of n= ";
    std::cin>>n;
    if(n%2==0){
        std::cout<<"Enter value of h= ";
        std::cin>>h;
        for(int i=0;i<=n;i=i+1){
            std::cout<<"Enter value of X "<<i<<"=";
            std::cin>>y;
            if(i==0 || i==n){
                a=a+((h/3)*simson_fun(y));
            }
            else if(i%2==0){
                a=a+(((2*h)/3)*simson_fun(y));
            }
            else{
                a=a+(((4*h)/3)*simson_fun(y));
            }
        }
        std::cout<<a;
    }
}

//5. PICARD'S METHOD
//for given function Dy/Dx = x+y
double picard(){
    double a,x,d=1.0;
    int e=0;
    std::cout<<"Enter the value of Y(0)= ";
    std::cin>>a;
    std::cout<<"Enter the number of terms: ";
    std::cin>>e;
    std::cout<<"Enter the point for value of function Y(x): ";
    std::cin>>x;
    for(int i=1;i<=e;i++){
        a=a+(pow(x,i)/d)+(pow(x,i+1)/(d*(i+1)));
        d=d*(i+1);
    }
    std::cout<<"Value of Y("<<x<<")is: "<<a<<std::endl;
}

//6. EULER'S METHOD
double eular_fun(double x,double y){
    return x+y;
}
double eulars(){
    float a,b,c,d,e=0;
    int f=0;
    std::cout<<"Enter the value of Y(x): ";
    std::cin>>a;
    e=a;
    std::cout<<"Enter the value of x: ";
    std::cin>>b;
    std::cout<<"Enter the value of h: ";
    std::cin>>d;
    std::cout<<"Enter the number of precision: ";
    std::cin>>f;
    for(int i=0;i<f;i++){
        e=e+(d*eular_fun(b,e));
        std::cout<<"The value of Y"<<i+1<<"="<<e<<std::endl;
        b=b+d;
    }
}

//7. RUNGE-KUTTA METHOD
double runge_fun(double x, double y){
    return pow(x,2)+pow(y,2);
}
double runge(){
    float a,b,c,d,m1,m2,m3,m4,m,y;
    std::cout<<"Enter the value of Y(x): ";
    std::cin>>a;
    std::cout<<"Enter the value of x: ";
    std::cin>>b;
    std::cout<<"Enter the value of h: ";
    std::cin>>c;
    std::cout<<"Enter the point for value of function: ";
    std::cin>>d;
    m1=runge_fun(a,b);
    m2=runge_fun(b+c/2,a+(m1*c/2));
    m3=runge_fun(b+c/2,a+(m2*c/2));
    m4=runge_fun(b+c,a+(c*m3));
    m=(m1+2*(m2+m3)+m4)/6;
    y=a+(m*c);
    std::cout<<"Value of function: "<<y;
}

//8. BICTION METHOD
double bict(){
    float a,b,c,d=0,e,f,g;
    std::cout<<"Enter the value where function give negative value";
    std::cin>>a;
    std::cout<<"Enter the value where function return positive value";
    std::cin>>b;
    std::cout<<"Enter no of decimal places:";
    std::cin>>c;
    g=b-a;
    if (g<0){g=g*(-1);}
    d=((log(g)/2.302585)+c)/(log(2)/2.302585);
    for(float i=0;i<=d+1;i=i+1){
        e=(a+b)/2;
        f=pow(e,3)-(e)-1;                     //Define function here
        if (f==0.00)break;
        else if(f>0.00)b=e;
        else if(f<0.00)a=e;
        std::cout<<e<<std::endl;
    }
    std::cout<<"The root of given equation is: "<<e;
}
//MAIN FUNCTION
int main(){
    std::cout<<"To Apply numerical methods for finding solution of equation \n";
    std::cout<<"Press---1---For Regula-Falsi method to find root of algebraic equation \n";
    std::cout<<"Press---2---For Newton-Raphson method to find root of algebraic equation \n";
    std::cout<<"Press---3---For Newton's Divided Difference formula to find value of a function at a point \n";
    std::cout<<"Press---4---For Numerical Integration by using Simpson's one-third rule \n";
    std::cout<<"Press---5---For Numerical solution of differential equation by Picard's method \n";
    std::cout<<"Press---6---For Numerical solution of differential equation by using Euler's method \n";
    std::cout<<"Press---7---For Numerical solution of differential equation by using Runge - Kutta Method \n";
    std::cout<<"Press---8---For Numerical solution by Bisection method \n";
    int a;
    std::cout<<"Enter any number(1~8):";
    std::cin>>a;
    if (a>=1 && a<9){
        if(a==1){
            regula_falsi();
        }
        if(a==2){
            newton_rapson();
        }
        if(a==3){
            newton_divided();
        }
        if(a==4){
            simsons();
        }
        if(a==5){
            picard();
        }
        if(a==6){
            eulars();
        }
        if(a==7){
            runge();
        }
        if(a==8){
            bict();
        }
    }
    else{
        std::cout << "Invalid choice!" << std::endl;
    }
    return 0;
}