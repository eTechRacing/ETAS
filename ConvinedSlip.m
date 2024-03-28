clear all
clc
%%

%Longitudinal Coefficients
PCX1= 1.5000;
PDX1=1.9513;
PDX2=-1.0000;
PPX1=-6.7004;
PPX2=-16.5293;
PPX3=-2.1873;
PPX4=-5.6683;
PDX3=15.0000;
PEX1=-7.8385e-13;
PEX2=-0.9950;
PEX3=-0.6000;
PEX4=0.9000;
PKX1=25.1313;
PKX2=-5.7390e-06;
PKX3=-0.6401;
PHX1=6.0893e-04;
PHX2=-0.0018;
%PDXP1=
%PDXP2=
%PDXP3=
%RHX1=
%REX1=
%REX2=
%RCX1=
%RBX1=
%RBX2=
%RBX3=
SVX=1;

%Scaling coefficients
LCX=1; %Scale factor of Fx shape factor; valor inventat
LMUX=1; %Scale factor of Fx peak friction coefficient; valor inventat
LEX=1; %Scale factor of Fx curvature factor; valor inventat
LKXk=1; %Scale factor of slip stiffness; valor inventat 
LHX=1; %Scale factor of Fx horizontal shift; valor inventat
LXA=1; %Scale factor of alpha influence on Fx; valor inventat

%%

%Lateral coefficients
PCY1 = 1.5000; %shape factor (Afilar cantonades i estirar i atxatar)
PDY1 = 2.4360; %estirar o aixafar gràfica
PDY2 = -0.3628;
PDY3 = 10;
PEY1 = -0.0286; %afilar cantonades
PEY2 = 0.0113;
PEY3 = -0.2863; %en negatiu s'afila la dreta i en postiu l'esquerra
PEY4 = 32.0364;
PEY5 = -4.6821e+03;
PKY1 = -35.2758;
PKY2 = 1.7514; %rotar sobre el centre antihorari
PKY3 = 1.0000; 
PKY4 = 2.0000; 
PKY5 = -1.6874; 
PKY6 = 3.5692;
PKY7 = 1.9296;
PHY1 = 0.0043; %Desplaçar lateralment
PHY2 = 0; %Desplaçar lateralment
PVY1 = -0.0216; %pujar i baixar la grafica sencera
PVY2 = 0; %pujar i baixar la grafica sencera
PVY3 = 0.6492; %pujar i baixar la grafica sencera
PVY4 = 2.1293;
PPY1 = 0.2239; 
PPY2 = 0.9444;
PPY3 = -0.9607;
PPY4 = -2;
PPY5 = 0.0000;
Fz0 = 1080;
P0=0.97;
%Turn slip
z0=1;
z1=1;
z2=1;
z3=1;
z4=1;

%Ecuacio MZ(SA) Regressio 
a0m =       2.107;
a1m =      -3.933;
b1m =       61.61;
a2m =     -0.4837;
b2m =       10.06;
a3m =      0.7475;
b3m =        7.31;
a4m =      0.4277;
b4m =      -0.423;
a5m =       1.124;
b5m =       3.801;
wm =      0.2417;

MZ=@(SA)  a0m + a1m*cos(SA*wm) + b1m*sin(SA*wm) + a2m*cos(2*SA*wm) + b2m*sin(2*SA*wm) + a3m*cos(3*SA*wm) + b3m*sin(3*SA*wm) + a4m*cos(4*SA*wm) + b4m*sin(4*SA*wm) + a5m*cos(5*SA*wm) + b5m*sin(5*SA*wm);











































