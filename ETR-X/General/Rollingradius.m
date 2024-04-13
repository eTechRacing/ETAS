clear all
clc
load('B1654run21.mat');

%12psi,camber0,NominalLoad200-150
v1=sum(RE(1278:3833));
c0=v1/2555;

%12psi,camber2,NominalLoad200-150
v2=sum(RE(7670:10225));
c2=v2/2555;


RER=(c0 +c2)/2 *10 %in mm

