clear all
clc

load("B1654run21.mat")

% IA=0 i FZ=920:840N - DataInterval: 1278:2555 - Display en Blue
% IA=0 i FZ=690:620N - DataInterval: 2556:3833 - Display en Red


figure()
hold on
plot(SA(1278:2555),MZ(1278:2555),"blue")
plot(SA(2556:3833),MZ(2556:3833),"red")
hold off
figure()
hold on
plot(FY(1278:2555),MZ(1278:2555),"blue")
plot(FY(2556:3833),MZ(2556:3833),"red")
hold off
figure()
hold on
plot(TSTC(1278:2555),FY(1278:2555),"blue")
plot(TSTC(2556:3833),FY(2556:3833),"red")
hold off
figure()
hold on
plot(SA(1278:2555),TSTC(1278:2555),"blue")
plot(SA(2556:3833),TSTC(2556:3833),"red")
hold off
figure()
hold on
plot(MZ(1278:2555),TSTC(1278:2555),"blue")
plot(MZ(2556:3833),TSTC(2556:3833),"red")
hold off










