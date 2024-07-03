clear all, close all, clc

load("B1654run35.mat");

%% IA= 0deg, FZ= 22.680kg (50 lbs), P= 0.8274bar (12 psi) 
FZ_22=FZ(3467:4140,1);
FX_22=FX(3467:4140,1);

%% IA =0deg, FZ=68.0389kg (150 lbs), P= 0.8274bar (12 psi)
FZ_68=FZ(2050:2723,1);
FX_68=FX(2050:2723,1);

%% IA= 0deg, FZ=90.718kg (200 lbs), P= 0.8274bar (12 psi)
FZ_90=FZ(1357:2030,1);
FX_90=FX(1357:2030,1);

%% IA= 0deg, FZ=113,380kg (250 lbs), P= 0.8274bar (12 psi)
FZ_113=FZ(7:680,1);
FX_113=FX(7:680,1);

%% Curvefitter
X1=[-1090.22 -874.96 -653.22 -207.11];
Y1=[3076.07 2493.17 2005.22 853.16];
X2=[-1042.9 -834.34 -640.22 -197.25];
Y2=[-3141.21 -2559.71, -1981.7 -830.29];

%curveFitter(X1, Y1)
p1=    -2.4973;
p2=    342.8409;
f1 =@(x) p1*x + p2;
  
%curveFitter(X2, Y2)
p3=    2.7339;
p4=    -272.7735;
f2=@(x) p3*x + p4;

%% Plotting data
figure
plot([FZ_22,FZ_68,FZ_90,FZ_113],[FX_22,FX_68,FX_90,FX_113])
hold on 
fplot(f1)
hold on
fplot(f2)
hold off
legend('IA=0deg, FZ=22.680kg','IA=0deg, FZ=68.039kg','IA=0deg, FZ=90.718kg','IA=0deg, FZ=113.380kg')
xlabel('FZ (N)')
ylabel('FX (N)')
xlim([-1200,0])
ylim([-4000, 4000])
