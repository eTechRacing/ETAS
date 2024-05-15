clear all
close all
clc

load('B1654run35.mat');
% P=0.83 bar - DataInterval: 0:26306
% P=0.83 bar SA=0 deg - DataInterval: 0:9600
% P=0.83 bar SA=0 deg IA=0 deg - DataInterval: 0:4140

% P=0.83 bar SA=0 deg IA=0 FZ=850N - DataInterval: 1342:2047 
curveFitter(SL(1342:2047),FX(1342:2047))            
a10=-151.4953; 
a11=294.7851;
b11=2.6429e+03;
a12=-145.1628;
b12=31.3611;
a13=51.4513;   
b13=194.7873;
a14=5.6183;
b14=81.8447;
w1=13.0951;   
f1=@(x1) a10 + a11*cos(x1*w1) + b11*sin(x1*w1) + a12*cos(2*x1*w1) + b12*sin(2*x1*w1) + a13*cos(3*x1*w1) + b13*sin(3*x1*w1) + a14*cos(4*x1*w1) + b14*sin(4*x1*w1);
  
% P=0.83 bar SA=0 deg IA=0 FZ=650N - DataInterval: 2048:2769
    %curveFitter(SL(2048:2769),FX(2048:2769))
a20=-292.4260; 
a21=511.8985;
b21=2.0405e+03;
a22=-353.7651;
b22=44.3478;
a23=185.1617; 
b23=130.7979;
a24=-60.6252;
b24=88.2402;
w2=13.7659;
f2=@(x2)a20 + a21*cos(x2*w2) + b21*sin(x2*w2) + a22*cos(2*x2*w2) + b22*sin(2*x2*w2) + a23*cos(3*x2*w2) + b23*sin(3*x2*w2) + a24*cos(4*x2*w2) + b24*sin(4*x2*w2);

% P=0.83 bar SA=0 deg IA=2 deg - DataInterval: 4141:6883

% P=0.83 bar SA=0 deg IA=2 FZ=850N - DataInterval: 4141:4814
    %curveFitter(SL(4141:4814),FX(4141:4814))
a30=-406.7456; 
a31=718.6507;
b31=2.4306e+03;
a32=-468.8844;
b32=90.5859;
a33=211.1984;  
b33=96.7438;
a34=-51.0081;  
b34=112.5551;
w3=13.7058;
f3=@(x3) a30 + a31*cos(x3*w3) + b31*sin(x3*w3) + a32*cos(2*x3*w3) + b32*sin(2*x3*w3) + a33*cos(3*x3*w3) + b33*sin(3*x3*w3) + a34*cos(4*x3*w3) + b34*sin(4*x3*w3);
 
% P=0.83 bar SA=0 deg IA=2 FZ=650N - DataInterval: 4815:5509
    %curveFitter(SL(4815:5509),FX(4815:5509))
a40=-354.8560;
a41=643.6900;
b41=1.9140e+03;
a42=-422.2033;
b42=101.0665;
a43=208.8595;
b43=82.6496;
a44=-64.2409;
b44=97.3094;
w4=13.4663;
f4=@(x4) a40 + a41*cos(x4*w4) + b41*sin(x4*w4) + a42*cos(2*x4*w4) + b42*sin(2*x4*w4) + a43*cos(3*x4*w4) + b43*sin(3*x4*w4) + a44*cos(4*x4*w4) + b44*sin(4*x4*w4);
