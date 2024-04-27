clear all, clc
load("B1654run21.mat")

%camber 0, 12 psi
FmZ0=abs(FZ(1)-FZ(2)); %FZ in N
time0= abs(ET(1)-ET(2)); %time in sec
RR0=abs(RE(1)*10^-2 -RE(2)*10^-2); %Effective radius in m
TD0= vpa((FmZ0*time0)/RR0); %Tyre damping 

%camber 2, 12 psi
FmZ2=abs(FZ(7670)-FZ(7671)); %FZ in N
time2=abs(ET(7670)-ET(7671)); %time in sec
RR2=abs(RE(7670)*10^-2 -RE(7671)*10^-2); %Effective radius in m
TD2= vpa((FmZ2*time2)/RR2); %Tyre damping

%interpolacio
L0=(0.9-2)/(0-2);
L2=(0.9-0)/(0-2);

TD=TD0*L0+TD2*L2 %Tyre damping a 0.9


%{
R= 9*0,0254; %wheel radius in m
%camber 0, 12psi
X=sum(FZ(1:7669)); %FZ
Y=sum(RL(1:7669).*10^-2); %Loaded radius
TD= X/Y


%camber 2, 12psi
X=sum(FZ(7670:14061)); %FZ
Y=sum(RL(7670:14061)].*10^-2; %Loaded radius
%}