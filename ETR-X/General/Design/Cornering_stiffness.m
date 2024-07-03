clear all, close all, clc

load("B1654run21.mat");

%% SA vs FY
%% IA=0 deg,FZ=68.0389 kg (150 lbs), P= 0.8274 bar (12 psi)
SA_68=SA(2556:3833,1);
FY_68=FY(2556:3833,1);

%% IA=0 deg,FZ=90.718 kg (200 lbs), P= 0.8274 bar (12 psi)
SA_90=SA(1278:2555,1);
FY_90=FY(1278:2555,1);

%% PLotting SA vs FY
figure
plot([SA_68,SA_90],[FY_68,FY_90])
legend('IA=0deg, FZ=22.680kg','IA=0deg, FZ=68.039kg','IA=0deg, FZ=90.718kg','IA=0deg, FZ=113.380kg')
xlabel('SA (deg)')
ylabel('FY (N)')
title('SA vs FY')


%% Curvefitter
%curveFitter(SA_68,FY_68)
a0=    26.9377;
a1=    -58.6404;
b1=    -2.0165e+03;
a2=    80.2803;
b2=    14.3117;
a3=    -34.8995; 
b3=    -168.2555;
a4=    23.6306;
b4=    -74.5574;
w =    0.1619; 
f1 =@(x) a0 + a1*cos(x*w) + b1*sin(x*w) + a2*cos(2*x*w) + b2*sin(2*x*w) + a3*cos(3*x*w) + b3*sin(3*x*w) + a4*cos(4*x*w) + b4*sin(4*x*w);
%curveFitter(SA_90, FY_90)
a20=    84.3900;
a21=    -176.5218;
b21=    -2.6129e+03;
a22=    182.9235;
b22=    28.1781;
a23=    -85.4456;
b23=    -181.0735;
a24=    36.2938;
b24=    -84.8620;
w2=     0.1573;
f2 =@(x) a20 + a21*cos(x*w2) + b21*sin(x*w2) + a22*cos(2*x*w2) + b22*sin(2*x*w2) + a23*cos(3*x*w2) + b23*sin(3*x*w2) + a24*cos(4*x*w2) + b24*sin(4*x*w2);
%--------------------------------------------------------------------------

%% Cornering stiffness
syms x
df1=diff(f1,x);
df2=diff(f2,x);
%% Plotting
figure
fplot(df1)
hold on
fplot(df2)
legend('IA=0deg, FZ=22.680kg','IA=0deg, FZ=68.039kg','IA=0deg, FZ=90.718kg','IA=0deg, FZ=113.380kg')
xlabel('SA (deg)')
ylabel('dFY/dSA (N/deg)')
title('Cornering stiffness')
