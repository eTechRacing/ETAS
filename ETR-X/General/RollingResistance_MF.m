clear all, close all, clc

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

%Overturning coeficients
QSX1= 0;
QSX2= 1.5;
QSX3= 0.1;
QSX4= 0.1;
QSX5= 0;
QSX6= 0;
QSX7= 0.1;
QSX8= 0;
QSX9= 0;
QSX10= 0;
QSX11= 0;
QSX12= 0;
QSX13= 0;
QSX14= 0;
PPMX1= 0;

%Rolling coefficients
QSY1= 0;                 
QSY2= 0;                 
QSY3= 0;                
QSY4= 0;                
QSY5= 0;                 
QSY6= 0;                
QSY7= 0;                
QSY8= 0; 

%Scaling coefficients
LCX=1; %Scale factor of Fx shape factor; valor inventat
LMUX=1; %Scale factor of Fx peak friction coefficient; valor inventat
LEX=1; %Scale factor of Fx curvature factor; valor inventat
LKXk=1; %Scale factor of slip stiffness; valor inventat 
LHX=1; %Scale factor of Fx horizontal shift; valor inventat
LXA=1; %Scale factor of alpha influence on Fx; valor inventat
LUX=1; %valor inventat
LXalfa=1; %valor inventat
LMY=1;

%Data
g=9.81; % m/s^2
m = 320; % vechicle mass in kg
W = m*g; % vehicle weight in N
h = 0.3; % cog height m
l = 1.53; % wheel base m
cogx= 0.8; % Front axle -> Mass center distance in m
R = 0.223969; %efective rolling radius in m
R0= (18*0.0245)/2; %unloaded radius in m
CAMdeg = 1; %inclination angle en graus
CAM = CAMdeg*pi/180; %Camber in radians
VREF= 40/3.6; %en m/s

%Data for Fx
slip = 1.0:0.02:2.0;
VV = (0:5:90)/3.6; %Vehicle Velocity m/s
FZ = m*g/4; % signle wheel load 
DFZ = (FZ-1080)/1080; %diferencial de carrega
PI = 0.8; %pressio en bar
DPI = (PI-0.84)/0.84;

%Fx MF-Tyre 5.2, 6.0, 6.1
s1=1;
SHX= (PHX1+PHX2*DFZ)*LHX*LUX*s1;

for i = 1:length(slip)
    for j = 1:length(VV)
        
        V(i,j)= VV(j)*slip(i); % Wheel velocity m/s
        Omega(i,j) = V(i,j)/R; %wheel rotational speed %valor inventat
        k(i,j) = (V(i,j)-VV(j))/VV(j); %longitudinal slip

        %Pure Slip
        kx(i,j) = k(i,j)+SHX;
        CX(i,j) = PCX1*LCX;
        U(i,j) = (PDX1+PDX2*DFZ)*(1+PPX3*DPI+PPX4*DPI^2)*(1-PDX3*CAM^2)*LUX;
        DX(i,j) = U(i,j)*FZ*s1;
        Ex(i,j) = (PEX1+PEX2*DFZ+PEX3*DFZ^2)*(1-PEX4*sign(kx(i,j)))*LEX;
        KXk(i,j) = FZ*(PKX1+PKX2*DFZ)*exp(PKX3*DFZ)*(1+PPX1*DPI+PPX2*DPI^2)*LKXk;
        BX(i,j) = KXk(i,j)/(CX(i,j)*DX(i,j));
        
        Gxalfa=1;
        
        %Turn slip
        s1=1;
        Fx(i,j)=(DX(i,j)*sin(CX(i,j)*atan(BX(i,j)*kx(i,j)-Ex(i,j)*(BX(i,j)*kx(i,j)-atan(BX(i,j)*kx(i,j)))))+SVX)*Gxalfa;
        

        %Rolling Resistance MF-Tyre 5.2, 6.0
        My(i,j)=-R0.*FZ.*LMY.*(QSY1+QSY2.*(Fx(i,j)/FZ)+QSY3.*abs(V(i,j)/VREF)+QSY4.*(V(i,j)/VREF).^4);
    end
end

plot(VV,My)