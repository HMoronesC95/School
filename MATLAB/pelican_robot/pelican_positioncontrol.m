clc
clear all

l1 = 0.26;
l2 = 0.26;
lc1 = 0.0983;
lc2 = 0.0229;
m1 = 6.5225;
m2 = 2.0458;
I1 = 0.1213;
I2 = 0.0116;
g = 9.81;

q = [(270)*(pi/180);
     (0)*(pi/180)]

qp = [0;
      0]

kp = [30 0;
      0 30]
kv = [7 0;
      0 3]
qd = [pi/10;
      pi/30]
      

delta=.0001;
count=1;
counte=2;
eulerq1=[];
eulerq2=[];
eulerq1(count,1)=(270)*(pi/180);
eulerq2(count,1)=(0)*(pi/180);
eulerqp1=[];
eulerqp2=[];
eulerqp1(count,1)=0;
eulerqp2(count,1)=0;
vel = [0;
       0];
eulerqt1=[];
eulerqt2=[];
  


for i=0:delta:0.11
qt = [qd(1,1)-q(1,1);
      qd(2,1)-q(2,1)]
eulerqt1(count,1)=qt(1,1);
eulerqt2(count,1)=qt(2,1); 
Mq = [m1*lc1^2+m2*l1^2+m2*l1*lc2*cos(q(2,1))+I1+I2 m2*lc2^2+m2*l1*lc2*cos(q(2,1))+I2;
      m2*lc2^2+m1*lc2*cos(q(2,1))+I2 m2*lc2^2+I2]
Cq = [-2*m2*l1*lc2*qp(2,1)*sin(q(2,1)) -m2*l1*lc2*qp(2,1)*sin(q(2,1));
      m2*l1*lc2*sin(q(2,1)) 0]
gq = [(m1*lc1+m2*l1)*g*sin(q(1,1))+m2*lc2*g*sin(q(1,1)+q(2,1));
      m2*lc2*g*sin(q(1,1)+q(2,1))]
qpp = (Mq^-1)*(kp*qt-kv*qp-Cq*qp-gq) 
acel=qpp;%DERIVADA DE LA velocidad EN CADA PUNTO [X Y]
eulerqp1(counte,1)= eulerqp1(counte-1,1)+(delta*(acel(1,1)));%M.EULER PARA CADA PUNTO
eulerqp2(counte,1)= eulerqp2(counte-1,1)+(delta*(acel(2,1)));%%M.EULER PARA CADA PUNTO
qp(1,1) = eulerqp1(counte,1);
qp(2,1) = eulerqp2(counte,1);
vel = vel + acel*delta;
eulerq1(counte,1)= eulerq1(counte-1,1)+(delta*(vel(1,1)));%M.EULER PARA CADA PUNTO
eulerq2(counte,1)= eulerq2(counte-1,1)+(delta*(vel(2,1)));%%M.EULER PARA CADA PUNTO
q(1,1) = eulerq1(counte,1)
q(2,1) = eulerq2(counte,1)
counte=counte+1;

index(count,1)=count;
count=count+1;
end

%///////////////////////////////////////////////////////////////
% IMPRESION DE TRAYECTORIAS
t=0:0.0001:0.1101;
length(eulerqp1)
length(t)
figure(1)
plot(t,eulerqp1,'color','b','LineWidth',1);
title('qp vs t')
% axis equal
axis tight
grid on
hold on
plot(t,eulerqp2,'color','g','LineWidth',1);
legend({'qp1','qp2'},'Location','southwest')
xlabel('t')
ylabel('qp')
grid on

figure(2)
plot(t,eulerq1,'color','b','LineWidth',1);
title('q vs t')
% axis equal
axis tight
grid on
hold on
plot(t,eulerq2,'color','g','LineWidth',1);
legend({'q1','q2'},'Location','southwest')
xlabel('t')
ylabel('q')
grid on

figure(3)
length(eulerqt1)
length(t)
t=0:0.0001:0.11;
plot(t,eulerqt1,'color','b','LineWidth',1);
title('qt vs t')
% axis equal
axis tight
grid on
hold on
plot(t,eulerqt2,'color','g','LineWidth',1);
legend({'qt1','qt2'},'Location','southwest')
xlabel('t')
ylabel('qt')
grid on
% figure(4)
% axis tight
% grid on
% hold on
% for i=1:1:length(eulerq1)
% Eslabon_1 = line([0 l1*cos(eulerq1(i,1))],[0 l1*sin(eulerq1(i,1))],'Color','b');
% Px=l1*cos(eulerq1(i,1));
% Py=l1*sin(eulerq1(i,1));
% % Eslabon_2 = line([Px Px+100*cosd(theta_vector(2))],[Py Py+100*sind(theta_vector(2))],'Color','g');
% Eslabon_2 = line([Px Px+l2*cos(eulerq1(i,1)+eulerq2(i,1))],[Py Py+sin(eulerq1(i,1)+eulerq2(i,1))],'Color','g');
% % frame = getframe;
% % writeVideo(writerObj,frame);
% % delete(Eslabon_1);
% delete(Eslabon_2);
% pause(0.1)
% end

