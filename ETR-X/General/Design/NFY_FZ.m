clear all, close all, clc

load("B1654run21.mat");

%% IA= 0deg, FZ= 22.680kg (50 lbs), P= 0.8274bar (12 psi) 
FZ_22=FZ(3835:5111,1);
NFY_22=NFY(3835:5111,1);

%% IA =0deg, FZ=68.0389kg (150 lbs), P= 0.8274bar (12 psi)
FZ_68=FZ(2557:3833,1);
NFY_68=NFY(2557:3833,1);

%% IA= 0deg, FZ=90.718kg (200 lbs), P= 0.8274bar (12 psi)
FZ_90=FZ(1279:2555,1);
NFY_90=NFY(1279:2555,1);

%% IA= 0deg, FZ=113,380kg (250 lbs), P= 0.8274bar (12 psi)
FZ_113=FZ(1:1277,1);
NFY_113=NFY(1:1277,1);

%% Curvefitter
X1= [-1125.1 -898.02 -674.6 -218.43];
Y1= [2.76 2.9 2.93 3.25 ];
a1=    3.3594;
b1=   0.0002;
f1=@(x) a1*exp(b1*x);

X2=[-1064.55 -869.62 -644.54 -196];
Y2=[-2.86 -2.82 -2.91 -3.7];
a2=   -3.8541;
b2 =   0.0003;
f2=@(x) a2*exp(b2*x);

%% Plotting data 
figure
plot([FZ_22,FZ_68,FZ_90,FZ_113],[NFY_22,NFY_68,NFY_90,NFY_113])
hold on
fplot(f1)
hold on
fplot(f2)
hold off
legend('IA=0deg, FZ=22.680kg','IA=0deg, FZ=68.039kg','IA=0deg, FZ=90.718kg','IA=0deg, FZ=113.380kg')
xlabel('FZ (N)')
ylabel('FY/FZ (N)')

%curveFitter(X1,Y1)
%{
%% Curvefitter
X1=[-1122.59 -898.66 -674.6 -214.97];
Y1=[2.75 2.87 2.93 3.24];
X2=[-1064.55 -869.62 -644.54 -196];
Y2=[-2.86 -2.82 -2.91 -3.7];
%curveFitter(X1,Y1)
p1=    0.0005;
p2=    3.3353;
f1 =@(x) p1*x + p2;
%curveFitter(X2,Y2)
p3=    -0.0010;
p4=    -3.7810;
f2 =@(x) p3*x + p4;

%% Plotting data 
figure
plot([FZ_22,FZ_68,FZ_90,FZ_113],[NFY_22,NFY_68,NFY_90,NFY_113])
hold on 
fplot(f1)
hold on
fplot(f2)
hold off
legend('IA=0deg, FZ=22.680kg','IA=0deg, FZ=68.039kg','IA=0deg, FZ=90.718kg','IA=0deg, FZ=113.380kg')
xlabel('FZ (N)')
ylabel('FY/FZ (N)')
%}


