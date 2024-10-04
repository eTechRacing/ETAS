clear all
close all
clc

load('B1654run35.mat');

%%
%DATA INTERVALS

% P=0.83 bar - DataInterval: 0:26306
% P=0.83 bar SA=0 deg - DataInterval: 0:9600
% P=0.83 bar SA=0 deg IA=0 deg - DataInterval: 0:4140
% P=0.83 bar SA=0 deg IA=0 FZ=850N - DataInterval: 1342:2047 
% P=0.83 bar SA=0 deg IA=0 FZ=650N - DataInterval: 2048:2769 
% P=0.83 bar SA=0 deg IA=2 deg - DataInterval: 4141:6883 
% P=0.83 bar SA=0 deg IA=2 FZ=850N - DataInterval: 4141:4814
% P=0.83 bar SA=0 deg IA=2 FZ=650N - DataInterval: 4815:5509


% P=0.69 bar - DataInterval: 26307:51479
% P=0.69 bar SA=0 deg - DataInterval: 26307:34668
% P=0.69 bar SA=0 deg IA=0 deg - DataInterval: 26307:29111
% P=0.69 bar SA=0 deg IA=0 FZ=850N - DataInterval: 26307:27011
% P=0.69 bar SA=0 deg IA=0 FZ=650N - DataInterval: 27012:27728
% P=0.69 bar SA=0 deg IA=2 deg - DataInterval: 29112:31892
% P=0.69 bar SA=0 deg IA=2 FZ=850N - DataInterval: 29112:29816
% P=0.69 bar SA=0 deg IA=2 FZ=650N - DataInterval: 29817:30483

%%
% DATA REGRESSSIONS (FOURIER 4TH DEGREE)
% The regressions return FX inputing Slip ratio, for calculating rolling resistance, we use Slip ratio SL=0 

%{
curveFitter(SL(1342:2047),FX(1342:2047)) 
curveFitter(SL(2048:2769),FX(2048:2769))
curveFitter(SL(4141:4814),FX(4141:4814))
curveFitter(SL(4815:5509),FX(4815:5509))
curveFitter(SL(26307:27011),FX(26307:27011))
curveFitter(SL(27012:27728),FX(27012:27728))
curveFitter(SL(29112:29816),FX(29112:29816))
curveFitter(SL(29817:30483),FX(29817:30483))
%}

% P=0.83 bar SA=0 deg IA=0 FZ=850N - DataInterval: 1342:2047 
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

% P=0.83 bar SA=0 deg IA=2 FZ=850N - DataInterval: 4141:4814
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

% P=0.69 bar SA=0 deg IA=0 FZ=850N - DataInterval: 26307:27011         
a50=-319.2571;
a51=627.2273;
b51=2.4224e+03;
a52=-419.4698;
b52=73.1252;
a53=195.2289;
b53=126.4274;
a54=-61.3976;
b54=110.2534;
w5=13.3648;
f5=@(x5) a50 + a51*cos(x5*w5) + b51*sin(x5*w5) + a52*cos(2*x5*w5) + b52*sin(2*x5*w5) + a53*cos(3*x5*w5) + b53*sin(3*x5*w5) + a54*cos(4*x5*w5) + b54*sin(4*x5*w5);

% P=0.69 bar SA=0 deg IA=0 FZ=650N - DataInterval: 27012:27728
a60=-168.0558;
a61=346.9887;
b61=1.9421e+03;
a62=-245.1400;
b62=4.7800;
a63=112.8840;
b63=139.8988;
a64=-28.3737;
b64=82.7837;
w6=13.8541;
f6=@(x6) a60 + a61*cos(x6*w6) + b61*sin(x6*w6) + a62*cos(2*x6*w6) + b62*sin(2*x6*w6) + a63*cos(3*x6*w6) + b63*sin(3*x6*w6) + a64*cos(4*x6*w6) + b64*sin(4*x6*w6);

% P=0.69 bar SA=0 deg IA=2 FZ=850N - DataInterval: 29112:29816

a70=-312.7210;
a71=606.5760;
b71=2.3389e+03;
a72=-417.7880;
b72=94.2556;
a73=179.9829;
b73=97.4046;
a74=-52.0026;
b74=109.6177;
w7=13.3119;
f7=@(x7) a70 + a71*cos(x7*w7) + b71*sin(x7*w7) + a72*cos(2*x7*w7) + b72*sin(2*x7*w7) + a73*cos(3*x7*w7) + b73*sin(3*x7*w7) + a74*cos(4*x7*w7) + b74*sin(4*x7*w7);

% P=0.69 bar SA=0 deg IA=2 FZ=650N - DataInterval: 29817:30483

a80=-142.9720;
a81=302.1989;
b81=1.8892e+03;
a82=-216.1664;
b82=14.7527;
a83=91.8460;
b83=132.6550; 
a84=-27.0550;
b84=73.1319;
w8=13.4221;
f8=@(x8) a80 + a81*cos(x8*w8) + b81*sin(x8*w8) + a82*cos(2*x8*w8) + b82*sin(2*x8*w8) + a83*cos(3*x8*w8) + b83*sin(3*x8*w8) + a84*cos(4*x8*w8) + b84*sin(4*x8*w8);

%%

%Interpolations between values

W=72; %weight in kg
P=0.75; %pressure in bar
IA=0.9; %camber in deg
w=W*9.81; %weight in N

%Weight interpolation
syms y
vpa(solve((w-850)/(650-850)==(y-f2(0))/(f1(0)-f2(0)),y))

f1(0)
f2(0)
f3(0)
f4(0)
f5(0)
f6(0)
f7(0)
f8(0)
display(y)

%{
%plot(linspace(-0.15,0.15,40),f1(linspace(-0.15,0.15,40)))
%plot(V(29817:30483))
figure(1)
plot(SL(1342:2047),FX(1342:2047))
hold on
title("1342:2047")
figure(2)
plot(SL(2048:2769),FX(2048:2769))
title('2048:2769')
figure(3)
plot(SL(4141:4814),FX(4141:4814))
title('4141:4814')
figure(4)
plot(SL(4815:5509),FX(4815:5509))
title('4815:5509')
figure(5)
plot(SL(26307:27011),FX(26307:27011))
title('26307:27011')
%}

fplot(f1,[-0.15 0.15])
rollingresistance1=zeros(1,length(0:0.01:0.15))
f1positiu=zeros(1,length(0:0.01:0.15))
f1negatiu=zeros(1,length(0:0.01:0.15))

slip=[0:0.01:0.15]

for i=1:length(0:0.01:0.15);
    i
    f1positiu(i)=f1(slip(i));
    f1negatiu(i)=f1(-slip(i));
    rollingresistance1(i)=f1(slip(i))+f1(-slip(i));
end

f1positiu
f1negatiu
rollingresistance1


abs(f1(-0.1))-abs(f1(0.1))


