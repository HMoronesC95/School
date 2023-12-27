%PD Pendulo


function y = c_PD_RV(t,q)
%Datos
% mlc2=1;%[ml^2]
% mglc=1;%[ml^2]
% qd=pi/2;

l1 = 0.26;
l2 = 0.26;
lc1 = 0.0983;
lc2 = 0.0229;
m1 = 6.5225;
m2 = 2.0458;
I1 = 0.1213;
I2 = 0.0116;
g = 9.81;

%Posición articular
% q=[q(1) q(2)];

%Velocidad articular
qp=[1 1];

%Posiciones deseadas
qd=[pi/10 pi/30];

%Error
qtilde =[qd(1)-q(1) qd(2)-q(2)];

%Ganancias
kp=[30 0; 0 30]
kv=[7 0; 0 3];


%%
%Ecuaciones del modelo dinámico
% Mq1 = m1*lc2*g;
% Mq2 = m2*lc2*g;

% gq =[(m1*lc1+m2*l1)*g*sin(q(1))+m2*g*lc2*sin(q(1)+q(2)) m2*g*lc2*sin(q(1)+q(2))];

yp = [(m1*lc1+m2*l1)*g*cos(q(1))*qp(1) + m2*g*lc2*cos(q(1)+q(2))*(qp(1)+qp(2));m2*g*lc2*cos(q(1)+q(2))*(qp(1)+qp(2))];

% ypp = [(m1*lc1+m2*l1)*g*(cos(q(1))*qpp(1) + qp(1)*(-sin(q(1))*qp(1))) + m2*g*lc2*(cos(q(1)+q(2))*(qpp(1)+qpp(2)) + (qp(1)+qp(2))*(-sin(q(1)+q(2))*(qp(1)+qp(2)))); m2*g*lc2*(cos(q(1)+q(2))*(qpp(1)+qpp(2)) + (qp(1)+qp(2))*(-sin(q(1)+q(2))*(qp(1)+qp(2))))];
%%
%Modelo dinámico

%Matriz de inercia
% M1 = Mq1;
% M2 = Mq2;

%Matriz de fuerzas centripetas y coriolis
% C=[C11q_qp C12q_qp;
%    C21q_qp C22q_qp];

%Vector de torque gravitacional
vg=[yp];

%Ecuacion q2puntos
qpp = [kp(1,1)*qtilde(1) - kv(1,1)*yp(1); kp(2,2)*qtilde(2) - kv(2,2)*yp(2)];   

%Vector de salida
y = [qpp(1);qpp(2)];

%%

end