clear all
clc

load("B1654run35.mat")

% IA=0 ; SA=0 ; FZ=950:750N - DataInterval: 1342:2047 - Display en Cyan
% IA=0 ; SA=0 ; FZ=750:560N - DataInterval: 2048:2769 - Display en Magenta

figure()
hold on
plot(SR(1342:2047),FX(1342:2047),"cyan")
plot(SR(2048:2769),FX(2048:2769),"magenta")
hold off

figure()
hold on
plot(SR(1342:2047),TSTC(1342:2047),"cyan")
plot(SR(2048:2769),TSTC(2048:2769),"magenta")
hold off

