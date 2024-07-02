clear all, close all, clc

load("B1654run21.mat");

%% IA= 0deg, FZ= 22.680kg (50 lbs), P= 0.8274bar (12 psi) 
FZ_22=FZ(3835:5111,1);
FY_22=FY(3835:5111,1);

%% IA =0deg, FZ=68.0389kg (150 lbs), P= 0.8274bar (12 psi)
FZ_68=FZ(2557:3833,1);
FY_68=FY(2557:3833,1);

%% IA= 0deg, FZ=90.718kg (200 lbs), P= 0.8274bar (12 psi)
FZ_90=FZ(1279:2555,1);
FY_90=FY(1279:2555,1);

%% IA= 0deg, FZ=113,380kg (250 lbs), P= 0.8274bar (12 psi)
FZ_113=FZ(1:1277,1);
FY_113=FY(1:1277,1);

%% Curvefitter
X1=[-1068.51, -860.81, -640.36, -198.7 ];
Y1=[2977.67, 2421.8, 1857.26, 690.34];
X2=[-1125.1, -899.95, -671.47, -210.91];
Y2=[-3107.84, -2561.36, -1908.33, -674.86];

%curveFitter(X1,Y1)
p1=-2.6251;
p2= 169.9614;
f1=@(x) p1*x + p2;
%curveFitter(X2,Y2)
p3= 2.6803;
p4=-114.8686;
f2=@(x) p3*x + p4;

%% Plotting data 
figure
plot([FZ_22,FZ_68,FZ_90,FZ_113],[FY_22,FY_68,FY_90,FY_113])
hold on 
fplot(f1,[-1200 100])
hold on
fplot(f2,[-1200 100])
hold off
legend('IA=0deg, FZ=22.680kg','IA=0deg, FZ=68.039kg','IA=0deg, FZ=90.718kg','IA=0deg, FZ=113.380kg')
xlabel('FZ (N)')
ylabel('FY (N)')



