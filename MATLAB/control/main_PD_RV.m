
clc;
close all;
%%
tspan = 0:0.01:10;
q = [-pi/2; 0];
qp = [0 0];
% qd=[pi/10 pi/30];
% y=zeros(2,1);

l1 = 0.26;
l2 = 0.26;
lc1 = 0.0983;
lc2 = 0.0229;
m1 = 6.5225;
m2 = 2.0458;
I1 = 0.1213;
I2 = 0.0116;
g = 9.81;

% y =[(m1*lc1+m2*l1)*g*sin(q(1))+m2*g*lc2*sin(q(1)+q(2));m2*g*lc2*sin(q(1)+q(2))];
yp = [(m1*lc1+m2*l1)*g*cos(q(1))*qp(1) + m2*g*lc2*cos(q(1)+q(2))*(qp(1)+qp(2));m2*g*lc2*cos(q(1)+q(2))*(qp(1)+qp(2))];
[t,y] = ode45(@c_PD_RV,tspan,yp);
%%

%Error
figure
plot(t,(pi/2)-y(:,1),'--')
title('Position error-PD-RV')
xlabel('t[s]')
ylabel('[rad]')
legend('q1~','q2~')

%Posición
figure
plot(t,y(:,1),'--')
title('Position-PD-RV')
xlabel('t[s]')
ylabel('[rad]')
legend('q1','q2')

%Velocidad
figure
plot(t,y(:,2),'-')
title('Velocidad-PD-RV')
xlabel('t[s]')
ylabel('[rad/s]')
legend('qp1','qp2')

%%

%Gráfica de pendulo

%%
