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

%Data
g=9.81; % m/s^2
m = 320; % vechicle mass in kg
W = m*g; % vehicle weight in N
h = 0.3; % cog height m
l = 1.53; % wheel base m
cogx= 0.8; % Front axle -> Mass center distance in m
R = 0.223969; %efective rolling radius
CAMdeg = 1; %inclination angle en graus
CAM = CAMdeg*pi/180; %Camber in radians

%MF-Tyre 5.2
My=-R0.*FZ0.*LMY.*(QSY1+QSY2.*(FX/FZ0)+QSY3.*abs(VX/VREF)+QS4.*(VX/VREF).^4)

