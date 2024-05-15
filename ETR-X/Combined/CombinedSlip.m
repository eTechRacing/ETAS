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
RHX1=0;
REX1=-1;
REX2=-0.1;
RCX1=1;
RBX1=5;
RBX2=5;
RBX3=0;
SVX=1;

%Scaling coefficients
LCX=1; %Scale factor of Fx shape factor; valor inventat
LMUX=1; %Scale factor of Fx peak friction coefficient; valor inventat
LEX=1; %Scale factor of Fx curvature factor; valor inventat
LKXk=1; %Scale factor of slip stiffness; valor inventat 
LHX=1; %Scale factor of Fx horizontal shift; valor inventat
LXA=1; %Scale factor of alpha influence on Fx; valor inventat
LYK=1;
LVYK=1;
LMUY=1;

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
RBY1= 5;
RBY2= 2;
RBY3= 0.02;            
RBY4 =0;                
RCY1= 1;                 
REY1= -0.1; 
REY2= 0.1;         
RHY1= 0;             
RHY2= 0;     
RVY1= 0;                
RVY2= 0;        
RVY3= 0;
RVY4= 0;  
RVY5= 0;
RVY6= 0;

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
%--------------------------------------------------------------------------
%Inputs
g=9.81;
m = 320; % vechicle mass in kg 
R = 22.3969*10^-2 ; %efective rolling radius
CAMdeg = 0.9; %inclination angle en graus
CAM = CAMdeg*pi/180; %Camber in radians
VV = (0:5:90)/3.6; %Vehicle Velocity m/s
FZ = m*g/4; % single wheel load 
DFZ = (FZ-1080)/1080; %diferencial de carrega
PI = 0.8; %pressio en bar
DPI = (PI-0.84)/0.84;
%Steering
deltadg=-15:1:15; %Steering angle en graus
SI=deltadg'.*pi/180; %Steering angle en rad
%Slip angle
Betadg=-6:1:6; %Whole car slip angle en graus
VS=Betadg'.*pi/180; %Whole car slip angle rad
sliplim=17*pi/180; %Limit slip angle
%Slip ratio
slip = 0:0.01:1.0; %vehicle slip ratio

%-------------------------------------------------------------------------

%Combined slip for FX
SHXalfa= RHX1;
alfaS= VS+SHXalfa;%VS=alfaF=alfaM Magic Formula Paper
BXalfa= (RBX1+RBX3*CAM^2)*cos(atan(RBX2*slip))*LXA; %kslip= k Magic Formula Paper
CXalfa= RCX1;
EXA= REX1+REX2*DFZ;
GXalfa= (cos(CXalfa.*atan(BXalfa.*alfaS-EXA*(BXalfa.*alfaS-atan(BXalfa.*alfaS)))))/(cos(CXalfa.*atan(BXalfa.*SHXalfa-EXA*(BXalfa*SHXalfa-atan(BXalfa*SHXalfa)))));

%Combined Slip for FY
%Turn slip
DAMP0=0;
DAMP2=1;
DAMP3=1;
DAMP4=1;
%weighting function
SHYK= RHY1+RHY2.*DFZ;
EYK= REY1+REY2.*DFZ;
CYK=RCY1;
BYK= (RBY1+RBY4.*CAM^2).*cos(atan(RBY2.*(VS-RBY3))).^LYK;%VS=alfaF=?alfa
KS=slip+SHYK;%slip=K
GYK= (cos(CYK.*atan(BYK.*KS-EYK.*(BYK.*KS-atan(BYK.*KS)))))./(cos(CYK.*atan(BYK.*SHYK-EYK.*(BYK.*SHYK-atan(BYK.*SHYK)))));
%braking induced plysteer
MUY=PDY1*exp(PDY2*DFZ)*(1+PPY3*DPI+PPY4*DPI^2)*LMUY*(1-PDY3*CAM)
DVYK= MUY*FZ*(RVY1+RVY2*DFZ+RVY3)*cos(atan(RVY4*VS))*DAMP2;%VS=alfaF
SVYK= DVYK*sin(RVY5*atan(RVY6*KS))*LVYK;

FY= GXalfa*FYP+SVYK;

%--------------------------------------------------------------------------
%{
%Downforce
df=2.3*((V/3.6)^2)
dfR=(df*copx)/l %Down Force front
dfF=df-dfR %Down Force rear

%Weight transfer
for i = 1:length(SI);
    for j = 1:length(VS);
        Vy(j)=(V/3.6).*VS(j); 
        w(i,j)=0;
        Ay(i,j)=0;
        for k=1:10
            WF(i,j)=Ay(i,j)*((g*weight/Tf)*((H*Kf/(Kf+Kr))+(b*Zrf/l))); %weight transfer front (La Ay es en g)
            WR(i,j)=Ay(i,j)*((g*weight/Tr)*((H*Kr/(Kf+Kr))+(a*Zrr/l))); %weight transfer rear (La Ay es en g)
            
            WFL(i,j)=WF(i,j);
            WFR(i,j)=-WF(i,j);
            WRL(i,j)=WR(i,j);
            WRR(i,j)=-WR(i,j);

for i = 1:length(slip)
    for j = 1:length(VV)
        Acx(i,j) = 0; %Acceleracio inicial en m/s
        fzr(i,j) = W*cogx/l; % Rear axle load load
        fzf(i,j) = W-fzr(i,j); % Front axle load load
        for k=1:10
            V(i,j) = VV(j)*(slip(i)+1); % Wheel velocity m/s
            k(i,j) = (V(i,j)-VV(j))/VV(j); %slip(i)
            WTx(i,j) = (h/l)*m*Acx(i,j); %Longitudinal weight transfer N
            WTF(i,j) = -WTx(i,j); 
            WTR(i,j) = WTx(i,j);            
            FZf(i,j) = fzf(i,j) + WTF(i,j);% Front axle load + weight transfer
            FZr(i,j) = fzr(i,j) + WTR(i,j);% Rear axle load + weight transfer
            FZFL(i,j) = FZf(i,j)/2; % Front left wheel load
            FZFR(i,j) = FZf(i,j)/2; % Front right wheel load
            FZRL(i,j) = FZr(i,j)/2; % Rear left wheel load
            FZRR(i,j) = FZr(i,j)/2; % Rear right wheel load
            DFZFL(i,j) = (FZFL(i,j)-1080)/1080; %load diferential FL
            DFZFR(i,j) = (FZFR(i,j)-1080)/1080; %load diferential FR
            DFZRL(i,j) = (FZRL(i,j)-1080)/1080; %load diferential RL
            DFZRR(i,j) = (FZRR(i,j)-1080)/1080; %load diferential RR


for k=1:10 %Addition of weighttransfer

%}

































