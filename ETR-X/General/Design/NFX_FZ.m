clear all, close all, clc

load("B1654run35.mat");

%% IA= 0deg, FZ= 22.680kg (50 lbs), P= 0.8274bar (12 psi) 
FZ_22=FZ(3467:4140,1);
NFX_22=NFX(3467:4140,1);

%% IA =0deg, FZ=68.0389kg (150 lbs), P= 0.8274bar (12 psi)
FZ_68=FZ(2050:2723,1);
NFX_68=NFX(2050:2723,1);

%% IA= 0deg, FZ=90.718kg (200 lbs), P= 0.8274bar (12 psi)
FZ_90=FZ(1357:2030,1);
NFX_90=NFX(1357:2030,1);

%% IA= 0deg, FZ=113,380kg (250 lbs), P= 0.8274bar (12 psi)
FZ_113=FZ(7:680,1);
NFX_113=NFX(7:680,1);

%% Curvefitter
X1=[-1049.64 -840.95 -640.22 -207.59];
Y1=[2.99 3.05 3.1 4.12];
%curveFitter(X1, Y1)
a1=    4.3810; 
b1=    0.0004;
f1=@(x) a1*exp(b1*x);

X2=[-1089 -873.08 -673.87 -218.63];
Y2=[-2.83 -2.87 -2.99 -3.82];
curveFitter(X2,Y2)
Fit Name: untitled fit 4

Polynomial Curve Fit (poly1)
f(x) = p1*x + p2

Coefficients and 95% Confidence Bounds
       Value      Lower      Upper  
p1    -0.0012    -0.0025    0.0001 
p2    -3.9744    -4.9666    -2.9822

Goodness of Fit
            Value  
SSE         0.0717
R-square    0.8902
DFE         2.0000
Adj R-sq    0.8354
RMSE        0.1893

%{
%curveFitter(X1,Y1)
p1=    0.0014;
p2=    4.2601;
f1 =@(x) p1*x + p2
%curveFitter(X2,Y2)
p3=    -0.0012;
p4=    -3.9744;
f2 =@(x) p3*x + p4;
%% Plotting data
figure
plot([FZ_22,FZ_68,FZ_90,FZ_113],[NFX_22,NFX_68,NFX_90,NFX_113])
hold on 
fplot(f1)
hold on
fplot(f2)
hold off
legend('IA=0deg, FZ=22.680kg','IA=0deg, FZ=68.039kg','IA=0deg, FZ=90.718kg','IA=0deg, FZ=113.380kg')
xlabel('FZ (N)')
ylabel('FX/FZ (N)')
%}



