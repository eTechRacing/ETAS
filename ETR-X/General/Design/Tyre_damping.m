clear all, clc
load("B1654run21.mat")

%camber 0, 12 psi
FmZ0=abs(FZ(1)-FZ(2));
RR0=abs(RL(1)*10^-2 -RL(2)*10^-2);
TD0= vpa(FmZ0/RR0)

%camber 2, 12 psi
FmZ2=abs(FZ(7670)-FZ(7671));
RR2=abs(RL(7670)*10^-2 -RL(7671)*10^-2);
TD2= vpa(FmZ2/RR2)

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
