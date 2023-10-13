#include<stdio.h>

int main(){
    int a1,a2,b1,b2,c1,c2,d1,d2,e1,e2,f1,f2,x1,y1,x2,y2;

    //F(x,y)=(a1x+a2y,b1x+b2y)
    printf("Enter coefficients of equation 1 : ");
    scanf("%d%d",&a1,&a2);
    printf("Enter coefficients of equation 2 : ");
    scanf("%d%d",&b1,&b2);
    
    //basis s={u1,u2}={(c1,c2),(d1,d2)}
    printf("Enter basis of s:\nu1 = ");
    scanf("%d%d",&c1,&c2);
    printf("u2 = ");
    scanf("%d%d",&d1,&d2);

    //F(u1)=F(c1,c2)
    e1=a1*c1+a2*c2;
    e2=b1*c1+b2*c2;

    //eq1=> c1x+d1y=e1         eq2=>c2x+d2y=e2
    x1=(e1*d2-d1*e2)/(c1*d2-c2*d1);
    y1=(e2*c1-e1*c2)/(c1*d2-c2*d1);

    //F(u2)=F(d1,d2)
    f1=a1*d1+a2*d2;
    f2=b1*d1+b2*d2;

    //eq1=> c1x+d1y=f1         eq2=>c2x+d2y=f2
    x2=(f1*d2-d1*f2)/(c1*d2-c2*d1);
    y2=(f2*c1-f1*c2)/(c1*d2-c2*d1);

    //final answer
    printf("[%d %d]\n[%d %d]",x1,x2,y1,y2);

    return 0;
}